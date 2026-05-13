import importlib
from types import ModuleType


def check_dependencies() -> dict[str, ModuleType]:

    pkg_dict: dict[str, str] = {
        "pandas": "Data manipulation",
        "numpy": "Numerical computation",
        "requests": "Network access",
        "matplotlib": "Visualization"
    }

    modules: dict[str, ModuleType] = {}

    print("Checking dependencies:")
    for pkg in pkg_dict:

        try:
            module: ModuleType = importlib.import_module(pkg)
            modules[pkg] = module
            print(f"[OK] {pkg} ({module.__version__}) - {pkg_dict[pkg]} ready")

        except ImportError as e:
            print(e)

    return modules


def main() -> None:

    print("\nLOADING STATUS: Loading programs...\n")

    modules = check_dependencies()
    print()
    try:
        np = modules["numpy"]
        pd = modules["pandas"]
        plt = modules["matplotlib"]
    except KeyError:
        print("The environment dont have all required dependencies.\n")

        print("To install dependencies with pip, run:")
        print("pip install -r requirements.txt\n")

        print("To install dependencies with poetry, run:")
        print("poetry install\n")
        return

    try:
        import matplotlib.pyplot as plt  # type: ignore
    except ModuleNotFoundError as e:
        print(e)

    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")
    x = np.linspace(-2 * np.pi, 2 * np.pi, 1000)
    y = np.sin(x)

    dataframe = pd.DataFrame({"x": x, "y": y})

    print("Generating visualization...\n")
    plt.plot(dataframe["x"], dataframe["y"])
    plt.title('Plot of y = sin(x)')
    plt.xlabel('x-axis')
    plt.ylabel('y-axis')

    file_name: str = 'matrix_analysis.png'

    plt.savefig(file_name)

    print("Analysis complete!")
    print(f"Results saved to: {file_name}")


if __name__ == '__main__':
    main()

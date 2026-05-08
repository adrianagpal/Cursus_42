import importlib


def check_dependencies() -> None:

    pkg_dict = {
        "pandas": "Data manipulation",
        "numpy": "Numerical computation",
        "requests": "Network access",
        "matplotlib": "Visualization"
    }

    modules = {}

    print("Checking dependencies:")
    for pkg in pkg_dict:

        try:
            module = importlib.import_module(pkg)
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
        print("Module not found.")
        return

    print("Analyzing Matrix data...")
    print("Processing 1000 data points...")
    index = np.arange(1000)
    data = np.random.randint(100, size=(1000))
    
    dataframe = pd.DataFrame({"index": index, "data": data})


if __name__ == '__main__':
    main()

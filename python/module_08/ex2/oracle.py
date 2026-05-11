import os
from dotenv import load_dotenv

load_dotenv()

"""
Python environment variables are key-value pairs stored in our 
operating system that contain configuration data for our applications.
load_dotenv() reads variables from a .env file and sets them in os.environ.
os.getenv() returns None if the variable is not found.
os.environ[] raises KeyError.
"""

print("\nORACLE STATUS: Reading the matrix...\n")

var_dict = {}
if not os.path.isfile('.env'):
    print("Missing configuration file")
else:
    var_dict = {
        "Mode": os.getenv("MATRIX_MODE"),
        "Database": os.getenv("DATABASE_URL"),
        "API Access": os.getenv("API_KEY"),
        "Log Level": os.getenv("LOG_LEVEL"),
        "Zion Network": os.getenv("ZION_ENDPOINT")
    }

for key in var_dict:
    if var_dict[key] is None:
        print(f"Variable {key} not configured.")

if var_dict:
    print("Configuration loaded:")
    for key in var_dict:
        print(f"{key}: {var_dict[key]}")



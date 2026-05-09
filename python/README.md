# Type hints
Type hints are a feature of Python that allows to specify the expected data type of a variable or a function argument. In this way, consistency can be checked with type checkers like mypy. 



To catch an exception, you need to use a try/except block. 

input() function always returns a string. 

The if \_\_name\_\_ == "\_\_main\_\_" block in Python allows you to define code that will only run when the file is executed directly as a script, but not when it's imported as a module into another script. When the script is run directly, the variable \_\_name\_\_ is set to the string "\_\_main\_\_". Therefore, the condition in the if statement evaluates as True, and Python executes the code in the if block.

However, when the module is imported, \_\_name\_\_ is set to the module's name, and the program doesn't execute the if block.

# String interpolation
## F-strings

> print(f"Hola, me llamo {name}")

## % Module

> print("Hola, me llamo %s" % (name))



PascalCase (Upper Camel Case):

In PascalCase, each word in the identifier is capitalized, including the first one. It's often used in programming languages for naming classes, records, and other user-defined types. For example, CustomerService , UserProfile , and AudioSystem 


https://mypy.readthedocs.io/en/stable/class_basics.html


Method chaining: if in a method, I return 'self', then it returns the object and I can chain methods. 

Static method: A static method in Python is a method that belongs to a class rather than an instance of the class. This means it can be called directly on the class itself, without the need to create an instance of the class. 

Class method: A class method is a method that receives the class itself as the first argument, conventionally named cls. It can access and modify class-level data and is often used to define factory methods. A factory method is a method that creates and returns an object of the class.

# Pydantic
The Pydantic library in Python is used for data validation and data parsing using Python type hints.

Before using Pydantic, install it using pip, including the optional settings module:
> pip install pydantic pydantic-settings

A Pydantic model is a Python class that defines the structure of your data using type hints. It automatically checks and converts input values to the correct types. Pydantic still keeps validation in place when you modify values.
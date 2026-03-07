This project has been created as part of 42 curriculum by <adrianag>.

# Description

The objective of the project is to create a static library *libftprintf.a*, which includes a function (*ft_printf*) that recreates the printf function from *stdio.h* library. This function is able to take a format and a variable number of arguments (variadic function). This can be implemented using macros from *stdarg.h* library, such as *va_list*.

The macro *va_start* indicates which is the last fixed argument (in this case, format), and where the variable arguments start.

The function goes through the format and writes each character until it finds a *%*, which is an indicator of format. When that occurs, it calls to another function *return_argument*, which calls to different functions for printing the argument, depending if a match with a format indicator is found.

These functions receive as one of the arguments the result of the macro *va_arg*, that recovers the next argument of *ft_printf* function, specifying the data type according to the format indicator.

Also, the function *ft_printf* should return the number of characters printed. This has been implemented creating a variable *count* that is passed as argument to the functions responsible of printing. 

# Instructions

To use the *printf* function, specify the format of what you want to print after a *%*. This implementation considers the following formats: c (character), s (string), u (unsigned int), i and d (int), p (pointer), x (lowercase hexademical) and X (uppercase hexadecimal).

The makefile includes a rule to create the static library, linking the objects (.o files) with the header file (ft_printf.h). There is also a rule that create the object files from the .c files. 

To create the static library, type *make* or *make re* on the console. There are also rules, such as *clean* to remove the object files or *fclean*, which also removes the static library file. 

To create a program, compile with the following instruction (make sure you have a main in your .c file):
> cc -Wall -Werror -Wextra ft_printf.c aux.c ft_printf.h

Execute the program with the following commmand:
> ./a.out

# Resources

The main resource for this project is Stackoverflow. The use of IA has been kept to a minimum for learning purposes. 




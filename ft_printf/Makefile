NAME = libftprintf.a
COMPILER = cc
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c aux.c
OBJECTS = $(SRCS:.c=.o)
LIB = ft_printf.h

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	ar rcs $(NAME) $(OBJECTS) $(LIB)

%.o: %.c
	$(COMPILER) $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJECTS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re





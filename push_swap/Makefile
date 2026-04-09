PROGRAM = push_swap
COMPILER = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = calculate_lis.c costs.c libft_utils.c list_utils.c parsing.c push.c \
	reverse_rotate.c rotate.c rotations.c swap.c push_swap.c
OBJECTS = $(SRCS:.c=.o)

all: $(PROGRAM)

$(PROGRAM): $(OBJECTS)
	$(COMPILER) $(CFLAGS) $(OBJECTS) -o $@

%.o: %.c
	$(COMPILER) $(CFLAGS) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(PROGRAM)

re: fclean all

.PHONY: clean fclean re
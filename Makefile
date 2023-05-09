CFLAGS  = -Wall -Wextra -Werror
NAME    = get_next_line.a
AR		= ar -rcs
SRC		= get_next_line.c get_next_line_utils.c
OBJ		= ${SRC:.c=.o}
SRCBON	= get_next_line_bonus.c get_next_line_utils_bonus.c
OBJBON	= ${SRCBON:.c=.o}

all: $(NAME)

%.o: %.c
	@gcc $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	@echo -- Compliling All

bonus: $(OBJBON) $(OBJ)
	@$(AR) $(NAME) $(OBJBON) $(OBJ)
	@echo Making bonus...

clean:
	@rm -rf *.o
	@echo -- Deleting All .o
fclean: clean
	@rm -f $(NAME)
	@echo -- Deleting .a

re: fclean all

.PHONY: all clean fclean re
SRCS			=	stack_handlers/a_stack_handlers.c	\
					stack_handlers/b_stack_handlers.c	\
					sorting_algorithm/frank_sort.c		\
					sorting_algorithm/frank_pre_sort.c	\
					sorting_algorithm/simple_sort.c		\
					sorting_algorithm/sort_utils.c		\
					validation/stack_parser.c			\
					validation/validate.c				\
					validation/memory.c					\
					push_swap.c
OBJS			=	${SRCS:%.c=$(OBJS_DIR)%.o}
NAME			=	push_swap
OBJS_DIR		=	objects/
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBS			=	libft/libft.a
RM				=	rm -rf

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I includes

all:		libft $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME) $(LIBS)

test:
	${TESTS}

libft:
			@make -C libft --no-print-directory

libft_fclean:
			@make fclean -C libft --no-print-directory

clean:		libft_fclean
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft


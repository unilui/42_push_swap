SRCS			=	push_swap.c a_stack_handlers.c b_stack_handlers.c \
					radix_sort.c
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

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(OBJS) -o $(NAME)
#			@$(CC) $(OBJS) -o $(NAME) $(LIBS)

libft:
			@make -C libft --no-print-directory

libft_fclean:
			@make fclean -C libft --no-print-directory

#clean:		libft_fclean
clean:
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re libft

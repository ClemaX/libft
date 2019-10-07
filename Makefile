NAME	= libft.a
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
CFLAGS	= -Wall -Wextra -Werror -std=c99 -I$(INCDIR)
SRCS	= $(addprefix $(SRCDIR)/,ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c)
OBJS	= $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

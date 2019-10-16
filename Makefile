NAME	= libft.a
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
OBJDIR	= obj
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR)
SRCS	= $(addprefix $(SRCDIR)/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strrem.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
BNSS	= $(addprefix $(SRCDIR)/, ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c)
BNSO	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(BNSS))

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	ar rcus $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -rf $(OBJDIR)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus: $(OBJDIR) $(OBJS) $(BNSO)
	ar rcus $(NAME) $(OBJS) $(BNSO)

.PHONY = all clean fclean re bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
SOURCES = 		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
				ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c \
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c \
				ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
				ft_split.c ft_strchr.c ft_strdup.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
				ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
				ft_substr.c ft_tolower.c ft_toupper.c
SOURCES_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
				ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c \
				ft_lstnew.c ft_lstsize.c ft_atoi_base.c ft_check_str_for_number.c \
				ft_has_prefix.c ft_isdigit_base.c ft_isspace.c \
				get_next_line.c get_next_line_utils.c
OBJECTS = $(SOURCES:.c=.o)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJECTS) bonus
	ar cr $@ $(OBJECTS)

bonus : $(OBJECTS_BONUS)
	ar cr $(NAME) $(OBJECTS_BONUS)

.PHONY : clean fclean re

clean :
	rm -f $(OBJECTS) $(OBJECTS_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

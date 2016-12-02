NAME = libft.a
PATH_SRC = ./srcs/
SRC = ft_atoi.c ft_bzero.c ft_intlen.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c \
	  ft_isdigit.c ft_isprint.c ft_itoa.c \
	  ft_lstadd.c ft_lstdel.c ft_lstdelone.c \
	  ft_lstiter.c ft_lstmap.c ft_lstnew.c \
	  ft_memalloc.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_memcpy.c ft_memdel.c \
	  ft_memmove.c ft_memset.c ft_putchar.c \
	  ft_putchar_fd.c ft_putendl.c \
	  ft_putendl_fd.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_putstr.c \
	  ft_putstr_fd.c ft_strcat.c \
	  ft_strncat.c ft_strncat.c ft_strlcat.c \
	  ft_strchr.c ft_strclr.c ft_strcmp.c \
	  ft_strcpy.c ft_strdel.c ft_strdup.c \
	  ft_strequ.c ft_striter.c ft_striteri.c \
	  ft_strjoin.c ft_strlen.c ft_strmap.c \
	  ft_strmapi.c ft_strncmp.c ft_strncpy.c \
	  ft_strnequ.c ft_strnew.c ft_strnstr.c \
	  ft_strrchr.c ft_strsplit.c ft_strstr.c \
	  ft_strsub.c ft_strtrim.c ft_tolower.c \
	  ft_toupper.c ft_verif.c ft_lstinsert.c \
	  ft_realloc.c

SRC_FULL = $(addprefix $(PATH_SRC), $(SRC))
HEADER = ./includes/
OBJ = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
EXEC = fillit

all : $(NAME)

$(NAME) :
	@echo "make..."
	@gcc $(FLAG) -I $(HEADER) -c $(SRC_FULL)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	gcc $(FLAG) main.c $(NAME) -o $(EXEC)
	@echo "[OK]\n"

clean :
	@echo "clean..."
	@rm -f $(OBJ)
	@echo "[OK]\n"

fclean :
	@echo "fclean..."
	@rm -f $(OBJ) $(NAME) $(EXEC)
	@echo "[OK]\n"

re : fclean $(NAME)

.PHONY : all clean fclean re

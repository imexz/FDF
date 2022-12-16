NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lmlx -lm -lft -L$(LIBFT_DIR) -L$(MLX_DIR) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIR) -I$(LIBFT_HEADERS) -I$(MLX_HEADERS)

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/
LIBFT_HEADERS = $(LIBFT_DIR)

MLX = $(MLX_DIR)libmlx.a
MLX_DIR = ./mlx/
MLX_HEADERS = $(MLX_DIR)

HEADERS_LIST =	fdf.h
HEADERS_DIR = ./includes/
HEADERS = $(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

SRC_DIR = ./sources/
SRC_LIST =	main.c \
			read_map.c \
			initializations.c \
			util_1.c \
			util_2.c \
			hook_controls.c \
			hook_control_actions.c \
			create_image.c \
			check_input.c \
			image_utils1.c \
			image_utils2.c


SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = ./objects/
OBJ_LIST = $(patsubst %.c, %.o, $(SRC_LIST))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

.PHONY : all bonus clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ_DIR) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) $(OBJ) -o $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	$(MAKE) -sC $(LIBFT_DIR)

$(MLX):
	$(MAKE) -sC $(MLX_DIR)

bonus : all

clean :
	$(MAKE) -sC $(LIBFT_DIR) clean
	$(MAKE) -sC $(MLX_DIR) clean
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -f $(MLX)
	rm -f $(LIBFT)
	rm -f $(NAME)

re : fclean all
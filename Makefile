#---------------------------------------------------------#
CC			=	cc

CFLAGS		=	-Wall -Wextra -Werror

GFLAGS		=	-g

MLX_FLAGS	=	-framework OpenGL -framework AppKit
#---------------------------------------------------------#
SRC_DIR		=	src

SRC_SUBDIRS	=	$(shell find $(SRC_DIR)/* -type d)

SRC			=	$(shell find $(SRC_DIR) -type f -name "*.c")

OBJ_DIR		=	obj

OBJ_SUBDIRS	=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

OBJ			=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
#---------------------------------------------------------#
INC_DIR		=	include

LIBFT_DIR	=	libft

MLX_DIR		=	mlx

CPU		=	$(shell uname -p)

ifeq ($(CPU),arm)
	LIBFT	=	libft_arm.a
	FT		=	ft_arm
	MLX		=	mlx_arm
else
	LIBFT	=	libft_x86.a
	FT		=	ft_x86
	MLX		=	mlx_x86
endif


.PHONY: all lib clean fclean libclean re
#---------------------------------------------------------#
NAME	=	so_long

all:		$(NAME)

lib:		$(LIBFT_DIR)/$(LIBFT)

$(NAME):	$(OBJ) $(LIBFT_DIR)/$(LIBFT) | $(MLX_DIR)/$(MLX)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(OBJ) -o $@ -L$(LIBFT_DIR) -l$(FT) $(MLX_FLAGS) -L$(MLX_DIR) -l$(MLX)

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
$(MLX_DIR)/$(MLX):
	@$(MAKE) -C $(MLX_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUBDIRS) $(OBJ_DIR)
	@echo $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) -I$(INC_DIR) -I$(LIBFT_DIR)/$(INC_DIR) -I$(MLX_DIR) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_SUBDIRS):
	mkdir -p $@
#---------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME)

libclean:
	rm -rf $(LIBFT_DIR)/$(OBJ_DIR)
	rm -rf $(LIBFT_DIR)/$(LIBFT)

re: fclean all

libre: libclean lib
#---------------------------------------------------------#

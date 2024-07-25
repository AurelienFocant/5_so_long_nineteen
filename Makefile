#---------------------------------------------------------#
CC		=	cc

CFLAGS	=	-Wall -Wextra -Werror

GFLAGS	=	-g

DFLAGS	=	-fsanitize=address -fsanitize=undefined

MLX_FLAGS	=	 -lmlx  -framework OpenGL -framework AppKit
#---------------------------------------------------------#
SRC		=	$(shell find $(SRC_DIR) -type f -name "*.c")

OBJ		=	$(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR	=	src

OBJ_DIR	=	obj

SRC_SUBDIRS	=	$(shell find $(SRC_DIR)/* -type d)

OBJ_SUBDIRS	=	$(SRC_SUBDIRS:$(SRC_DIR)%=$(OBJ_DIR)%)

INC_DIR	=	includes

LIB_DIR	=	libft

LIB		=	$(LIB_DIR)/libft.a

.PHONY: all lib clean fclean libclean re
#---------------------------------------------------------#
NAME	=	so_long

all:		$(NAME)

lib:		$(LIB)

$(NAME):	$(OBJ) $(LIB)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) $(OBJ) -o $@ -L$(LIB_DIR) -lft $(MLX_FLAGS)

$(LIB):
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_SUBDIRS) $(OBJ_DIR)
	@echo $(OBJ_SUBDIRS)
	$(CC) $(CFLAGS) $(DFLAGS) $(GFLAGS) -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR) -c $< -o $@ 

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_SUBDIRS):
	mkdir -p $@
#---------------------------------------------------------#
clean:
	rm -rf $(OBJ_DIR)

fclean:		clean
	rm -rf $(NAME) *dSYM 

libclean:
	rm -rf $(LIB_DIR)/$(OBJ_DIR)
	rm -rf $(LIB)

re: fclean all

libre: libclean lib
#---------------------------------------------------------#

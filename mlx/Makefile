
NOM		=	libmlx.a

SRC= mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1=$(SRC:.c=.o)
OBJ=$(OBJ1:.m=.o)
CFLAGS+=-O2 -w

all: $(NOM)

$(NOM):	$(OBJ)
	ar -rcs $(NOM) $(OBJ)
# ranlib $(NOM)

%.o: %.c
	cc -g -c $< -o $@ 2>/dev/null

clean:
	rm -f $(OBJ) *~
	rm -f mlx_app

fclean: clean
	rm -f $(NOM)
re: clean all

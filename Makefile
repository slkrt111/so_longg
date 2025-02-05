SRCS	= parsing.c parsing2.c parsing3.c parsing4.c \
	split.c so_long.c get_next_line.c get_next_line_utils.c \
	ft_itoa.c mouv.c mouv2.c visual.c visual2.c visual3.c

OBJS	= ${SRCS:.c=.o}

CC	= cc

RM	= rm -f

LIB	= printf/libftprintf.a minilibx-linux/libmlx.a

CFLAGS    = -Wall -Wextra -Werror

XFLAGS    = -Lmlx_linux -Imlx_linux -lXext -lX11

NAME    = so_long

all: ${NAME}

${NAME}:    ${OBJS}
				make -C printf
				make -C minilibx-linux
				${CC} ${CFLAGS} ${XFLAGS} ${OBJS} ${LIB} -o ${NAME}
clean:
	make clean -C printf
	make clean -C minilibx-linux
	${RM} ${OBJS}

fclean: clean
	make fclean -C printf
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
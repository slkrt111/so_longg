SRCS	= parsing.c parsing2.c parsing3.c split.c so_long.c get_next_line.c get_next_line_utils.c ft_itoa.c mouv.c mouv2.c visual.c visual2.c

OBJS	= ${SRCS:.c=.o}

CC	= cc

RM	= rm -f

CFLAGS    = -Wall -Wextra -Werror -Lminilibx-linux -lmlx_Linux -lXext -lX11 

NAME    = so_long

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}:    ${OBJS}
				${CC} ${CFLAGS} ${OBJS} -o ${NAME}
clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean fclean all re
NAME			= so_long

LIBFT			= ../libft

MLX				= ../minilibx

SRCS			= main.c \
				  close_window.c \
				  read_map.c \
				  check_map.c \
				  check_path.c \
				  create_map.c \
				  create_images.c \
				  move_player.c \
				  display_output.c

BSRCS			= bonus_main.c \
				  bonus_close_window.c \
				  bonus_read_map.c \
				  bonus_check_map.c \
				  bonus_check_path.c \
				  bonus_create_map.c \
				  bonus_create_images.c \
				  bonus_move_player.c \
				  bonus_display_output.c

OBJS			= ${SRCS:.c=.o}

BOBJS			= ${BSRCS:.c=.o}

CC				= cc

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

${NAME}:		${OBJS} ${LIBFT}/libft.a ${MLX}/libmlx.a
				${CC} ${CFLAGS} ${OBJS} -L ${LIBFT} -lft -L ${MLX} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

${LIBFT}/libft.a:
				make -C ${LIBFT}

${MLX}/libmlx.a:
				make -C ${MLX}

all:			${NAME}

bonus:			${BOBJS} ${LIBFT}/libft.a ${MLX}/libmlx.a
				${CC} ${CFLAGS} ${BOBJS} -L ${LIBFT} -lft -L ${MLX} -lmlx -framework OpenGL -framework AppKit -o ${NAME}
clean:	
				${RM} ${OBJS} ${BOBJS}
				make clean -C ${LIBFT}
				make clean -C ${MLX}

fclean:			clean
				${RM} ${NAME}
				make fclean -C ${LIBFT}
				make clean -C ${MLX}

re:				fclean all

bre:			fclean bonus

.PHONY:			all bonus clean fclean re LIBFT MLX

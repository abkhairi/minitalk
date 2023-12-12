NAME = server client

SRCS = server.c client.c

OBJS = $(SRCS:.c=.o)

PRINTF = finalprintf/libftprintf.a
UTILS = minitalk_utilis.c

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: printf_rule $(NAME)

printf_rule:
	make -C finalprintf

server: server.o finalprintf/ft_printf.h
	$(CC) -o $@ $< $(PRINTF) $(UTILS)

client: client.o finalprintf/ft_printf.h
	$(CC) -o $@ $< $(PRINTF) $(UTILS)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $<

clean:
	make -C finalprintf/ clean
	rm -rf $(OBJS)

fclean: clean
	make -C finalprintf/ fclean
	rm -rf client server

re: fclean all

.PHONY: all clean fclean re
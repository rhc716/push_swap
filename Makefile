PUSH = push_swap
CHECK = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_1 = push_swap.c
SRCS_2 = checker.c
SRCS_3 = massage.c valid.c setting.c action_r.c action_rr.c action_s_p.c sort.c free.c

PATHLIBFT = ./libft
LIBOPTION = -L$(PATHLIBFT) -lft

OBJS_1 = $(SRCS_1:.c=.o)
OBJS_2 = $(SRCS_2:.c=.o)
OBJS_3 = $(SRCS_3:.c=.o)

.c.o: 
	$(CC) $(CFLAGS) -c $^ -o $@

$(PUSH): $(OBJS_1) $(OBJS_3)
		make all -C $(PATHLIBFT)
		$(CC) $(CFLAGS) -o $@ $^ $(LIBOPTION)

$(CHECK): $(OBJS_2) $(OBJS_3)
		make all -C $(PATHLIBFT)
		$(CC) $(CFLAGS) -o $@ $^ $(LIBOPTION)

all: $(PUSH) $(CHECK)

clean: 
	rm -f $(OBJS_1) $(OBJS_2) $(OBJS_3)
	make clean -C $(PATHLIBFT)

fclean: clean
	rm -f $(PUSH) $(CHECK)
	make fclean -C $(PATHLIBFT)

re: fclean all

.PHONY: all clean fclean re

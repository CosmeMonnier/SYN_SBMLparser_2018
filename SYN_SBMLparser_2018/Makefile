NAME	= SBMLparser

CC	= gcc

RM	= rm -f

SRCS	= src/./displayer.c \
	  src/./filler.c \
	  src/./lib.c \
	  src/./main.c \
	  src/./sbmlib.c \
	  src/./str_to_wordtab.c \
	  src/./str_to_wordtab_deluxe.c 

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

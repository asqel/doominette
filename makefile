
SRC = main.c $(wildcard src/*.c src/*/*.c src/*/*/*.c src/*/*/*/*.c src/*/*/*/*/*.c)
OBJ = ${SRC:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -g -D_GNU_SOURCE=1
LDFLAGS =


NAME = doominette

all: $(NAME) build_tests

$(NAME): $(OBJ)
	$(CC) $^ -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

releas: re
	mkdir -p release
	cp $(NAME) release/
	cp tests release/

build_tests:
	make -C tests/


.PHONY: all clean fclean build_tests
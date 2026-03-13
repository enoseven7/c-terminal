TARGET = eno
OBJ = main.c input_parser.c helpers.c builtins.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all:
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)
clean:
	rm -f *-o 
fclean: clean
	rm -f $(TARGET)
re: fclean all

CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
NAME := test/bin/out

SRC_DIR := .
INC_DIR := .

SRC_FILES := get_next_line_utils.c get_next_line.c test/main.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRC_FILES))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(SRC_FILES)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
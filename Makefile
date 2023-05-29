CC := gcc
CFLAGS := -Wall -Wextra -Werror -g
NAME := test/bin/out

SRC_DIR := .
INC_DIR := .

SRC_FILES := get_next_line_utils.c get_next_line.c test/main.c
SRC_BONUS_FILES := get_next_line_utils_bonus.c get_next_line_bonus.c test/main.c

SRCS := $(addprefix $(SRC_DIR)/,$(SRC_FILES))
SRCS_BONUS := $(addprefix $(SRC_DIR)/,$(SRC_BONUS_FILES))

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(SRCS)

bonus:
	$(CC) $(CFLAGS) -I$(INC_DIR) -o $(NAME) $(SRCS_BONUS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus

CC = cc
CFLAGS = -Werror -Wextra -Wall# -g -fsanitize=address,undefined
SRCS = main.c

SRCS += parser/get_next_line.c parser/get_next_line_utils.c parser/parser.c

SRCS += utils/ft_calloc.c utils/ft_memcpy.c

BUILD = build
OBJS = $(patsubst %.c, $(BUILD)/%.o, $(SRCS))
INCS = includes
HEADERS = $(INCS)/parser.h
NAME = cub3d

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo "compiled ✅"

$(BUILD)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@

clean:
	@rm -rf $(BUILD)
	@rm -rf $(BUILD_BONUS)
	@echo "Cleaned up 🧹"

fclean: clean
	@rm -f $(NAME)

re: fclean all

CC = cc
CFLAGS = -Werror -Wextra -Wall -O3# -g -fsanitize=address
SRCS = main.c

SRCS += parser/get_next_line.c parser/get_next_line_utils.c parser/parser.c \
		parser/valid_map.c parser/valid_map_utils.c parser/match_type.c \
		parser/free_info.c parser/parser_utils.c parser/has_ext.c \
		parser/parse_colors.c parser/extract_info.c


SRCS += utils/ft_calloc.c utils/ft_memcpy.c utils/ft_split.c utils/ft_strjoin.c \
		utils/ft_strlen.c utils/ft_memset.c utils/ft_bzero.c utils/ft_strdup.c \
		utils/free2darr.c utils/is_space.c utils/ft_strjoin_deli.c utils/print_error.c \
		utils/ft_putchar_fd.c utils/ft_putstr_fd.c utils/ft_putendl_fd.c utils/ft_strcmp.c \
		utils/ft_strtrim_end.c utils/ft_trimmed_len.c utils/str_empty.c utils/ft_atou.c \
		utils/ft_isunint8.c utils/ft_strsjoin.c utils/get_rgb.c utils/ato_color.c utils/ft_arr_len.c \
		utils/get_direction.c utils/ft_isdirection.c

SRCS += raycaster/draw_square.c

BUILD = build
OBJS = $(patsubst %.c, $(BUILD)/%.o, $(SRCS))
INCS = includes
HEADERS = $(INCS)/parser.h
NAME = cub3D
TOTAL := $(words $(OBJS))
COUNT := 0
MLXDIR = /Users/$(USER)/.lib/mlx
MLXINC = /Users/$(USER)/.lib/incs

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -framework Cocoa -framework OpenGL -framework IOKit -L$(MLXDIR) -lmlx42 -lglfw3 $^ -o $(NAME)
	@echo "compiled ✅"

$(BUILD)/%.o: %.c $(HEADERS)
	@mkdir -p $(dir $@)
	$(call progress)
	@$(CC) $(CFLAGS) -I$(INCS) -I$(MLXINC) -c $< -o $@
	@printf "\33c\e[3J"

clean:
	@rm -rf $(BUILD)
	@rm -rf $(BUILD_BONUS)
	@echo "Cleaned up 🧹"

fclean: clean
	@rm -f $(NAME)

re: fclean all

define progress
        $(eval COUNT=$(shell echo $$(($(COUNT) + 1))))
        @echo "[ $(COUNT)/$(TOTAL) ] [$(CFLAGS)] Compiling: $<\r"
endef

CC = cc
CFLAGS = -Werror -Wextra -Wall -O3# -g -fsanitize=address
SRCS = main.c

PARSER = get_next_line.c get_next_line_utils.c parser.c valid_map.c has_ext.c \
		valid_map_utils.c match_type.c parser_utils.c parse_colors.c extract_info.c \
		


UTILS = ft_calloc.c ft_memcpy.c ft_split.c ft_strjoin.c ft_strlen.c ft_memset.c \
		ft_bzero.c ft_strdup.c free2darr.c is_space.c ft_strjoin_deli.c ft_strcmp.c \
		print_error.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_atou.c \
		ft_strtrim_end.c ft_trimmed_len.c str_empty.c ft_isunint8.c ft_strsjoin.c \
		get_rgb.c ato_color.c get_direction.c ft_isdirection.c lst_to_array.c \
		ft_lstadd_back_bonus.c ft_min.c skip_space.c ft_lstclear_bonus.c ft_arr_len.c \
		ft_lstdelone_bonus.c ft_lstnew_bonus.c trimmify.c free_info.c textures.c

RAYCASTER = raycast.c draw_col.c hray_len.c vray_len.c events.c hook_events.c minimap.c \
			ft_move.c

SRCS += $(addprefix parser/, $(PARSER))
SRCS += $(addprefix utils/, $(UTILS))
SRCS += $(addprefix raycaster/, $(RAYCASTER))

BUILD = build
OBJS = $(patsubst %.c, $(BUILD)/%.o, $(SRCS))
INCS = includes
HEADERS = $(INCS)/parser.h $(INCS)/raycaster.h $(INCS)/types.h $(INCS)/utils.h
NAME = cub3D
TOTAL := $(words $(OBJS))
COUNT := 0
MLXDIR = /Users/$(USER)/.lib/mlx
MLXINC = /Users/$(USER)/.lib/incs

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -framework Cocoa -framework OpenGL -framework IOKit -L$(MLXDIR) $^ -o $(NAME) -lmlx42 -lglfw3
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

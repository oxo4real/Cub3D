CC = cc
CFLAGS = -Werror -Wextra -Wall -O3
SRCS = main_bonus.c

PARSER = get_next_line_bonus.c get_next_line_utils_bonus.c parser_bonus.c valid_map_bonus.c has_ext_bonus.c \
		valid_map_utils_bonus.c match_type_bonus.c parser_utils_bonus.c parse_colors_bonus.c extract_info_bonus.c \
		


UTILS = ft_calloc_bonus.c ft_memcpy_bonus.c ft_split_bonus.c ft_strjoin_bonus.c ft_strlen_bonus.c ft_memset_bonus.c \
		ft_bzero_bonus.c ft_strdup_bonus.c free2darr_bonus.c is_space_bonus.c ft_strjoin_deli_bonus.c ft_strcmp_bonus.c \
		print_error_bonus.c ft_putchar_fd_bonus.c ft_putstr_fd_bonus.c ft_putendl_fd_bonus.c ft_atou_bonus.c \
		ft_strtrim_end_bonus.c ft_trimmed_len_bonus.c str_empty_bonus.c ft_isunint8_bonus.c ft_strsjoin_bonus.c \
		get_rgb_bonus.c ato_color_bonus.c get_direction_bonus.c ft_isdirection_bonus.c lst_to_array_bonus.c \
		ft_lstadd_back_bonus.c ft_min_bonus.c skip_space_bonus.c ft_lstclear_bonus.c ft_arr_len_bonus.c \
		ft_lstdelone_bonus.c ft_lstnew_bonus.c trimmify_bonus.c free_info_bonus.c textures_bonus.c

RAYCASTER = raycast_bonus.c draw_col_bonus.c hray_len_bonus.c vray_len_bonus.c events_bonus.c hook_events_bonus.c minimap_bonus.c \
			ft_move_bonus.c animation_bonus.c animation_utils_bonus.c animation_handler_bonus.c free_animation_bonus.c \
			toggle_door_bonus.c hray_len_door_bonus.c vray_len_door_bonus.c

SRCS += $(addprefix parser_bonus/, $(PARSER))
SRCS += $(addprefix utils_bonus/, $(UTILS))
SRCS += $(addprefix raycaster_bonus/, $(RAYCASTER))

BUILD = build
OBJS = $(patsubst %.c, $(BUILD)/%.o, $(SRCS))
INCS = includes_bonus
HEADERS = $(INCS)/parser_bonus.h $(INCS)/raycaster_bonus.h $(INCS)/types_bonus.h $(INCS)/utils_bonus.h
NAME = ../cub3D
TOTAL := $(words $(OBJS))
COUNT := 0
MLXDIR = /Users/$(USER)/.lib/mlx
MLXINC = /Users/$(USER)/.lib/incs

all: $(NAME)

bonus: all

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

fclean: clean
	@rm -f $(NAME)

echo:
	@echo $(SRCS)
	@echo $(OBJS)

re: fclean all

define progress
        $(eval COUNT=$(shell echo $$(($(COUNT) + 1))))
        @echo "[ $(COUNT)/$(TOTAL) ] [$(CFLAGS)] Compiling: $<\r"
endef

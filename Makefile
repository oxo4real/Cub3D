NAME = cub3D

all:
	@make clean -C ./bonus
	@make -C ./mandatory

$(NAME): all

bonus :
	@make clean -C ./mandatory
	@make bonus -C ./bonus

clean:
	@make clean -C ./mandatory
	@make clean -C ./bonus
	@echo "Cleaned up 🧹"

fclean: clean
	@make fclean -C ./mandatory
	@make fclean -C ./bonus

re : fclean all

.PHONY: all clean fclean re bonus re_bonus re_bonus clean_bonus

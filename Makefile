MAKEFLAGS = --no-print-directory

### colors ###
RESET =  \033[0m
BOLD =   \033[1m
RED =    \033[31m
GREEN =  \033[32m
YELLOW = \033[33m
##############

NAME = minishell

CC = gcc
SRC_DIR = src/
OBJ_DIR = obj/
INC_DIR = includes/ libft/includes

LIBS =  -L./libft -lft
LIBSDEP = ./libft/libft.a

SRC_BONUS = change_str_on_screen_bonus.c \
			clear_bonus.c \
			delete_char_bonus.c \
			double_list_bonus.c \
			escape_sequence_bonus.c \
			home_end_on_screen_bonus.c \
			init_term_bonus.c \
			insert_char_bonus.c \
			insert_delete_on_screen_bonus.c \
			insert_in_history_bonus.c \
			main_bonus.c \
			move_bonus.c \
			move_right_left_on_screen_bonus.c \
			parsing_command_bonus.c \
			read_input_bonus.c \
			up_down_arrow_bonus.c \
			ft_exit_bonus.c \
			cut_copy_paste_bonus.c

SRC_MANDATORY = main.c \
				parsing_command.c \
				read_input.c \
				ft_exit.c

SRC_COMMON = add_word_or_operator2.c \
			 add_word_or_operator.c \
			 add_word_or_operator_extra2.c \
			 add_word_or_operator_extra.c \
			 built_function.c \
			 check_error_syntax.c \
			 free_commands.c \
			 ft_cd.c \
			 ft_cd_utils.c \
			 ft_echo.c \
			 ft_env.c \
			 ft_env_utils.c \
			 ft_error.c \
			 ft_export.c \
			 ft_list_remove_if.c \
			 ft_list_sort.c \
			 ft_pwd.c \
			 ft_unset.c \
			 ft_wildcard.c \
			 heredoc.c \
			 heredoc_utils.c \
			 insert_in_command.c \
			 match.c \
			 new_struct.c \
			 parameter_expansion.c \
			 parse_special_operators2.c \
			 parse_special_operators.c \
			 parse_special_operators_extra.c \
			 process_quotes.c \
			 remove_hidden.c \
			 run_built_in.c \
			 run_command.c \
			 run_command_extra.c \
			 run_command_extra2.c \
			 run_external.c \
			 run_external_extra.c \
			 shell_expansion.c \
			 sort.c \
			 split_command_into_arguments.c \
			 split_command_into_arguments_extra.c \
			 split_into_command.c \
			 wildcard.c \
			 wildcard_expansion.c \
			 wildcard_expansion_extra.c \
			 wildcard_utils.c \
			 ft_export_utils.c \
			 ft_print_export.c

ifdef WITH_BONUS
SRC_FILES = $(SRC_COMMON) $(SRC_BONUS)
LIBS = -ltermcap
else
SRC_FILES = $(SRC_COMMON) $(SRC_MANDATORY)
endif

OBJ_FILES = $(SRC_FILES:.c=.o)
DEP_FILES = $(SRC_FILES:.c=.d)

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))
DEP = $(addprefix $(OBJ_DIR), $(DEP_FILES))

INC = $(addprefix -I, $(INC_DIR)) 
CFLAGS = -Wall -Werror -Wextra

all: libs $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBSDEP) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $^ -o $@  $(LIBS)
	@echo "$(YELLOW)$(BOLD)$(NAME) created!$(RESET)"

-include $(DEP)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(INC) $(CFLAGS) -c $< -o $@ -MMD

bonus:
	@$(MAKE) WITH_BONUS=1 all

 libs:
	@$(MAKE) -C libft/

clean:
	@$(MAKE) -C libft/ clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@echo "$(RED)$(BOLD)$(NAME) deleted!$(RESET)"

re: fclean all

.PHONY: all clean fclean re 

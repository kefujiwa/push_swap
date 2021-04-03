# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kefujiwa <kefujiwa@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 01:31:21 by kefujiwa          #+#    #+#              #
#    Updated: 2021/04/03 15:53:32 by kefujiwa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### MAKEFILE ###

## COLORS ##

# Formats #
_RESET				= \x1b[0m
_BOLD				= \x1b[1m
_DIM				= \x1b[2m
_UNDER				= \x1b[4m
_BLINK				= \x1b[5m
_REV				= \x1b[7m
_HIDDEN				= \x1b[8m

# Foreground Colors #
_GREY				= \x1b[30m
_RED				= \x1b[31m
_GREEN				= \x1b[32m
_YELLOW				= \x1b[33m
_BLUE				= \x1b[34m
_PURPLE				= \x1b[35m
_CYAN				= \x1b[36m
_WHITE				= \x1b[37m

# Background Colors #
_BGREY				= \x1b[40m
_BRED				= \x1b[41m
_BGREEN				= \x1b[42m
_BYELLOW			= \x1b[43m
_BBLUE				= \x1b[44m
_BPURPLE			= \x1b[45m
_BCYAN				= \x1b[46m
_BWHITE				= \x1b[47m


# **************************************************************************** #

## VARIABLES ##

# Compilation #
CC					= gcc
CFLAGS				= -Wall -Wextra -Werror
DEBUG_FLAGS			= -g3 -fsanitize=address
AR					= ar rcs

# Delete #
RM					= rm -rf

# Directories #
HEADER_DIR			= includes/
SRCS_DIR			= srcs/
OBJS_DIR			= objs/
CH_DIR				= checker/
PS_DIR				= push_swap/
UT_DIR				= utils/
LIBFT_DIR			= libft/

# Files #
UT_FILES			= build_stack \
					  display_process \
					  exit_error \
					  is_colored \
					  is_sorted \
					  is_valid_args \
					  push \
					  reverse_rotate \
					  rotate \
					  stack_clear \
					  swap
UT_SRCS				= $(addprefix $(UT_DIR), $(addsuffix .c, $(UT_FILES)))

CH_FILES			= checker \
					  is_option \
					  output_result \
					  parse_option \
					  perform_instruction
CH_SRCS				= $(addprefix $(CH_DIR), $(addsuffix .c, $(CH_FILES))) \
					  $(UT_SRCS)

PS_FILES			= create_partition \
					  display_instruction \
					  get_median \
					  get_partition_end \
					  initial_solver \
					  is_option \
					  push_swap \
					  parse_option \
					  partition_solver_a \
					  partition_solver_b \
					  sort_u3 \
					  quick_sort
PS_SRCS				= $(addprefix $(PS_DIR), $(addsuffix .c, $(PS_FILES))) \
					  $(UT_SRCS)

# Compiled Files #
CH_OBJS				= $(CH_SRCS:%.c=$(OBJS_DIR)%.o)
PS_OBJS				= $(PS_SRCS:%.c=$(OBJS_DIR)%.o)
LIBFT_NAME			= $(LIBFT_DIR)libft.a

# Executable #
CHECKER				= checker
PUSH_SWAP			= push_swap


# **************************************************************************** #

## RULES ##

# Main Rules #
all:				$(CHECKER) $(PUSH_SWAP)

clean:
					@$(MAKE) clean -C $(LIBFT_DIR)
					@echo "$(_RED)Cleaning push_swap objects...\n$(_RESET)"
					@$(RM) $(OBJS_DIR)

fclean:				
					@$(MAKE) fclean -C $(LIBFT_DIR)
					@echo "$(_RED)Cleaning push_swap objects...\n$(_RESET)"
					@$(RM) $(OBJS_DIR)
					@echo "$(_RED)Deleting Executable '$(CHECKER)' and '$(PUSH_SWAP)'...\n$(_RESET)"
					@$(RM) $(CHECKER) $(PUSH_SWAP) *.dSYM test/*.txt

re:					fclean all

debug:				CFLAGS += $(DEBUG_FLAGS)
debug:				re
						@echo "$(_BLUE)Debug build done.$(_RESET)"

test:				fclean all
						@bash ./test/grademe.sh	

# Variable Rules #
$(CHECKER):			$(LIBFT_NAME) $(CH_OBJS)
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(CH_OBJS) $(LIBFT_NAME) -o $(CHECKER)
						@echo "\n\n$(_GREEN)Executable '$(CHECKER)' created.\n$(_RESET)"

$(PUSH_SWAP):		$(LIBFT_NAME) $(PS_OBJS)
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) $(PS_OBJS) $(LIBFT_NAME) -o $(PUSH_SWAP)
						@echo "\n\n$(_GREEN)Executable '$(PUSH_SWAP)' created.\n$(_RESET)"

$(LIBFT_NAME):		FORCE
						@$(MAKE) -C $(LIBFT_DIR)

FORCE:

# Compiled Source Files #
$(CH_OBJS):			$(OBJS_DIR)
$(PS_OBJS):			$(OBJS_DIR)

$(OBJS_DIR)%.o: 	$(SRCS_DIR)%.c
						@printf "$(_YELLOW)Generating push_swap objects... %-33.33s\r$(_RESET)" $@
						@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

$(OBJS_DIR):
						@mkdir -p $(OBJS_DIR)
						@mkdir -p $(OBJS_DIR)$(CH_DIR)
						@mkdir -p $(OBJS_DIR)$(PS_DIR)
						@mkdir -p $(OBJS_DIR)$(UT_DIR)

# Phony #
.PHONY:				all clean fclean re FORCE

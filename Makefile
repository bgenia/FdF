# Project config
NAME	= fdf

SRC_DIR	= src
LIB_DIR	= lib
OBJ_DIR	= obj
BIN_DIR	= .

# Sources
INCLUDE	= include

SRC		!= find $(SRC_DIR) -type f -name '*.c'

OBJ		= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilation
CC			= clang

CCFLAGS		= -g -fsanitize=address
CPPFLAGS	= -Wall -Werror -Wextra

# External libraries
LIBS	+= LIBFT

LIBFT			= $(LIBFT_DIR)/libft.a
LIBFT_DIR		= $(LIB_DIR)/libft
LIBFT_FLAGS		= -L$(LIBFT_DIR) -lft
LIBFT_INCLUDE	= $(LIBFT_DIR)/include

LIBS	+= MLX

MLX				= $(MLX_DIR)/libmlx.a
MLX_DIR			= $(LIB_DIR)/libmlx-linux
MLX_FLAGS		= -L$(MLX_DIR) -lmlx -L/usr/lib -lXext -lX11 -lm -lz
MLX_INCLUDE		= $(MLX_DIR)

# Some magic
LIB_FLAGS	= $(foreach LIB, $(LIBS), $($(LIB)_FLAGS))
LIB_FILES	= $(foreach LIB, $(LIBS), $($(LIB)))

INCLUDE		+= $(foreach LIB, $(LIBS), $($(LIB)_INCLUDE))

CCFLAGS		+= $(addprefix -I, $(INCLUDE))

# Build targets
.PHONY:			all
all:
	$(foreach LIB, $(LIBS),			\
		$(MAKE) -C $($(LIB)_DIR);	\
	)
	$(MAKE) $(NAME)

$(NAME): 		$(OBJ) $(LIB_FILES) | $(BIN_DIR)
	$(CC) $(CCFLAGS) $(filter-out $(LIB_FILES), $?) $(LIB_FLAGS) -o $@

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c | $(OBJ_DIR)
	mkdir -p $(@D)
	$(CC) $(CCFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR) 		$(BIN_DIR):
	mkdir -p $@

# Utility targets
.PHONY:		clean
clean:
	$(RM) -rf $(OBJ)
	$(RM) -rf $(OBJ_DIR)/*

.PHONY:		fclean
fclean:		clean
	$(RM) -rf $(NAME)

.PHONY:		re
re:			fclean
	$(MAKE)

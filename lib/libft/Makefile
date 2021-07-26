SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = .

NAME = $(BIN_DIR)/libft.a

SRC_LIST = 										\
	io/ft_putf_int.c							\
	io/ft_put_character.c						\
	io/ft_put_int.c								\
	io/ft_put_line.c							\
	io/ft_put_string.c							\
	io/ft_writeguard.c							\
	io/get_next_line/ft_get_next_line.c			\
	io/get_next_line/get_next_line_utils.c		\
	io/printf/ft_printf.c						\
	io/printf/parser/parse_flags.c				\
	io/printf/parser/parse_placeholder.c		\
	io/printf/parser/parse_precision.c			\
	io/printf/parser/parse_size.c				\
	io/printf/parser/parse_type.c				\
	io/printf/parser/parse_uint.c				\
	io/printf/parser/parse_width.c				\
	io/printf/printers/print_character.c		\
	io/printf/printers/print_pointer.c			\
	io/printf/printers/print_signed.c			\
	io/printf/printers/print_string.c			\
	io/printf/printers/print_unsigned.c			\
	io/printf/printers/print_value.c			\
	io/printf/_printf.c							\
	io/reader/ft_reader_create.c				\
	io/reader/ft_reader_free.c					\
	io/reader/ft_read_file.c					\
	io/reader/ft_read_line.c					\
	io/reader/ft_read_lines.c					\
	llist/ft_llist_add_back.c					\
	llist/ft_llist_add_front.c					\
	llist/ft_llist_at.c							\
	llist/ft_llist_clear.c						\
	llist/ft_llist_create.c						\
	llist/ft_llist_find.c						\
	llist/ft_llist_for_each.c					\
	llist/ft_llist_for_each_if.c				\
	llist/ft_llist_free.c						\
	llist/ft_llist_from.c						\
	llist/ft_llist_insert_after.c				\
	llist/ft_llist_last.c						\
	llist/ft_llist_map.c						\
	llist/ft_llist_merge.c						\
	llist/ft_llist_remove_if.c					\
	llist/ft_llist_reverse.c					\
	llist/ft_llist_reverse_values.c				\
	llist/ft_llist_size.c						\
	llist/ft_llist_sort.c						\
	llist/ft_llist_sorted_insert.c				\
	llist/ft_llist_sorted_merge.c				\
	llist/ft_llist_swap_elements.c				\
	llist/ft_llist_swap_values.c				\
	math/ft_abs.c								\
	math/ft_clamp.c								\
	math/ft_minmax_float.c						\
	math/ft_minmax_int.c						\
	memory/ft_bzero.c							\
	memory/ft_calloc.c							\
	memory/ft_free.c							\
	memory/ft_free_array.c						\
	memory/ft_free_each.c						\
	memory/ft_nullguard.c						\
	memory/ft_realloc.c							\
	memory/ft_reallocarray.c					\
	string/ft_memccpy.c							\
	string/ft_memchr.c							\
	string/ft_memcmp.c							\
	string/ft_memcpy.c							\
	string/ft_memmove.c							\
	string/ft_memset.c							\
	string/ft_split.c							\
	string/ft_strchr.c							\
	string/ft_strdup.c							\
	string/ft_strjoin.c							\
	string/ft_strlcat.c							\
	string/ft_strlcpy.c							\
	string/ft_strlen.c							\
	string/ft_strmapi.c							\
	string/ft_strncmp.c							\
	string/ft_strnstr.c							\
	string/ft_strrchr.c							\
	string/ft_strtrim.c							\
	string/ft_substr.c							\
	tuples/doublen.c							\
	tuples/intn.c								\
	types/ft_atoi.c								\
	types/ft_basedigit.c						\
	types/ft_isalnum.c							\
	types/ft_isalpha.c							\
	types/ft_isascii.c							\
	types/ft_isdigit.c							\
	types/ft_isprint.c							\
	types/ft_itoa.c								\
	types/ft_tolower.c							\
	types/ft_toupper.c							\
	utils/ft_freepass.c

SRC = $(addprefix $(SRC_DIR)/, $(SRC_LIST))

# SRC != find src -type f -name '*.c'
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDE		= include include-internal

CFLAGS		= -Wall -Werror -Wextra
CPPFLAGS	= $(addprefix -I, $(INCLUDE))

.PHONY: all
all: $(NAME)

$(NAME): $(OBJ) | $(BIN_DIR)
	ar -rs $@ $?

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

.PHONY: clean
clean:
	$(RM) -rf $(OBJ)
	$(RM) -rf $(OBJ_DIR)/*

.PHONY: fclean
fclean: clean
	$(RM) -rf $(NAME)

.PHONY: re
re:
	$(MAKE) fclean
	$(MAKE)

# This is the brain of the whole operation.
# Let's get this ship going!

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT) -I.
LIB_FLAGS = -L$(LIBFT) -lft
RM = rm -rf

LIBFT = ./libft/
SRC_DIR = src
BONUS_DIR = bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

NAME = server
C_NAME = client
BS_NAME = server_bonus
BC_NAME = client_bonus

SSRCS = server.c
CSRCS = client.c
BSSRCS = server_bonus.c
BCSRCS = client_bonus.c

S_OBJECTS = $(addprefix $(OBJ_DIR)/, $(SSRCS:.c=.o))
C_OBJECTS = $(addprefix $(OBJ_DIR)/, $(CSRCS:.c=.o))
BS_OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BSSRCS:.c=.o))
BC_OBJECTS = $(addprefix $(BONUS_OBJ_DIR)/, $(BCSRCS:.c=.o))

all: $(NAME) $(C_NAME)

$(NAME): $(S_OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(NAME) $(S_OBJECTS) $(LIB_FLAGS)
	@echo "server executable ready!!"

$(C_NAME): $(C_OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(C_NAME) $(C_OBJECTS) $(LIB_FLAGS)
	@echo "client executable ready!!"

bonus: $(BS_NAME) $(BC_NAME)

$(BS_NAME): $(BS_OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(BS_NAME) $(BS_OBJECTS) $(LIB_FLAGS)
	@echo "bonus server executable ready!!"

$(BC_NAME): $(BC_OBJECTS) $(LIBFT)/libft.a
	@$(CC) -o $(BC_NAME) $(BC_OBJECTS) $(LIB_FLAGS)
	@echo "bonus client executable ready!!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	@echo "compiling libft!!"
	@$(MAKE) --no-print-directory -C $(LIBFT)

clean:
	@echo "cleaning libft files!!"
	@$(MAKE) --no-print-directory fclean -C $(LIBFT)
	@echo "cleaning files!!"
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@$(RM) $(NAME) $(C_NAME) $(BS_NAME) $(BC_NAME)

re: fclean all

help:
	@echo "Available targets:"
	@echo "  make          - Build the main executables"
	@echo "  make bonus    - Build the bonus executables"
	@echo "  make clean    - Remove object files"
	@echo "  make fclean   - Remove object files and executables"
	@echo "  make re       - Rebuild everything"

.PHONY: all clean fclean re bonus

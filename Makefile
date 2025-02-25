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

MAKE_LIBFT = $(MAKE) -C $(LIBFT)
FCLEAN_LIBFT = $(MAKE) fclean -C $(LIBFT)

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
	$(CC) -o $(NAME) $(S_OBJECTS) $(LIB_FLAGS)

$(C_NAME): $(C_OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(C_NAME) $(C_OBJECTS) $(LIB_FLAGS)

bonus: $(BS_NAME) $(BC_NAME)

$(BS_NAME): $(BS_OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(BS_NAME) $(BS_OBJECTS) $(LIB_FLAGS)

$(BC_NAME): $(BC_OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(BC_NAME) $(BC_OBJECTS) $(LIB_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(BONUS_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT)/libft.a:
	$(MAKE_LIBFT)

clean:
	@$(FCLEAN_LIBFT)
	@$(RM) $(OBJ_DIR) $(BONUS_OBJ_DIR)

fclean: clean
	@$(RM) $(NAME) $(C_NAME) $(BS_NAME) $(BC_NAME)

re: fclean all

.PHONY: all clean fclean re bonus

# This is the brain of the whole operation.
# Let's get this ship going!

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(LIBFT)
LIB_FLAGS = -L$(LIBFT) -lft
RM = rm
RMF = rm -rf

LIBFT = ./libft/

MAKE_LIBFT = $(MAKE) files -C $(LIBFT)
FCLEAN_LIBFT = $(MAKE) fclean -C $(LIBFT)

S_NAME = server
C_NAME = client

SRC_DIR = src
BONUS_DIR = src/bonus
OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj

SRCS =  server.c

CSRCS = client.c

MFILES = $(addprefix $(SRC_DIR)/, $(SRCS))
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(MFILES))

BFILES = $(addprefix $(BONUS_DIR)/, $(CSRCS))
BONUS_OBJECTS = $(patsubst $(BONUS_DIR)/%.c, $(BONUS_OBJ_DIR)/%.o, $(BFILES))

all: $(S_NAME)

$(S_NAME): $(OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(S_NAME) $(OBJECTS) $(LIB_FLAGS)

bonus: $(C_NAME)

$(C_NAME): $(BONUS_OBJECTS) $(LIBFT)/libft.a
	$(CC) -o $(C_NAME) $(BONUS_OBJECTS) $(LIB_FLAGS)

$(LIBFT)/libft.a:
	$(MAKE_LIBFT)

$(OBJ_DIR)/%.o : 	$(SRC_DIR)/%.c
					@mkdir -p $(OBJ_DIR)
					$(CC) $(CFLAGS) -c $^ -o $@

$(BONUS_OBJ_DIR)/%.o :	$(BONUS_DIR)/%.c
					@mkdir -p $(BONUS_OBJ_DIR)
					$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@$(FCLEAN_LIBFT)
	@$(RMF) $(OBJ_DIR) $(BONUS_OBJ_DIR)
	@$(RMF) $(BONUS)

fclean:
	@$(MAKE) clean
	@$(RMF) $(S_NAME) $(C_NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re bonus
# This is the brain of the whole operation.
# Let's get this ship going!

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm
RMF = rm -rf
AR = ar rcs

NAME = libft.a

FILES = ft_isalpha.c ft_toupper.c ft_isdigit.c ft_tolower.c ft_isalnum.c ft_strchr.c ft_isascii.c ft_strrchr.c ft_isprint.c ft_strncmp.c ft_strlen.c ft_memchr.c ft_memset.c ft_memcmp.c ft_bzero.c ft_memcpy.c ft_strnstr.c ft_memmove.c ft_atoi.c ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

FT_PRINTF_FILES = ft_printf.c

GET_NEXT_LINE_FILES = get_next_line.c get_next_line_utils.c

OBJECTS = $(FILES:%.c=%.o)

BONUS_OBJECTS = $(BONUS:%.c=%.o)

PRINTF_OBJECTS = $(FT_PRINTF_FILES:%.c=%.o)

GNL_OBJECTS = $(GET_NEXT_LINE_FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(AR) $(NAME) $^

bonus: $(BONUS_OBJECTS)
	$(AR) $(NAME) $^

printf: $(PRINTF_OBJECTS)
	$(AR) $(NAME) $^

gnl: $(GNL_OBJECTS)
	$(AR) $(NAME) $^

files: $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS)
	$(AR) $(NAME) $^

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMF) $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS)

fclean:
	$(MAKE) clean
	$(RMF) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re a bonus printf gnl
.SECONDARY: $(OBJECTS) $(BONUS_OBJECTS) $(PRINTF_OBJECTS) $(GNL_OBJECTS)

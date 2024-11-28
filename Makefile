NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror 
AR = ar rcs
SRC = 	ft_printf.c		\
		ft_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ && echo "🚀 🔹 Created object file: $@"

$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ) && echo "🏆 🔸 Static library $(NAME) successfully created!"

clean:
	@$(RM) $(OBJ) && echo "🧹 ✨ Object files have been cleaned up!"

fclean: clean
	@$(RM) $(NAME) && echo "💥 🗑️ Removed static library: $(NAME)"

re: fclean all
	@echo "🔄 🔧 Project rebuilt successfully!"

.PHONY: all clean fclean re

CC = gcc -pthread
FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
NAME = philo
SRC = init_philo.c \
	main.c \
	parsing.c \
	philo_utils.c \

OBJ = $(SRC:.c=.o)
HEADER = philosophers.h 


all : $(NAME)

$(NAME) : $(OBJ)  $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.c $(HEADER)
		@$(CC) $(CFLAGS) -c $< -o $@

clean : 
		rm -rf $(OBJ)
fclean : clean
		rm -rf $(NAME)

re : clean fclean all

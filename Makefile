NAME	= philo

FLAGS	= -Wall -Wextra -Werror

SRC		= main.c actions.c helpers.c initiating.c monitoring.c 

OBJS	= ${SRC:.c=.o}

RM		= rm -f

all:
	@echo "Building..."
	gcc -pthread $(SRC) -o $(NAME) $(FLAGS)

clean:
	@echo "Cleaning..."
	$(RM) $(OBJS)

fclean: clean
	@echo "Full Cleaning..."
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
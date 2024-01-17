#--- BASIC ---#

NAME    	= philo
CC      	= gcc
FLAGS   	= -Wall -Werror -Wextra -pthread -fsanitize=thread -g
RM      	= rm -rf

#--- GROUP ---#

SRCS_DIR 	= srcs
OBJS_DIR	= objs


PARSING		=	philo parser check_dig_arg check_sign_arg

PHILO_FUNC	=	init simulation monitoring start_thread time

UTILS		=	ft_atol ext_err print_statement

SRCS		= 	$(addsuffix .c, $(addprefix $(SRCS_DIR)/parsing/, $(PARSING))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/philo_func/, $(PHILO_FUNC))) \
				$(addsuffix .c, $(addprefix $(SRCS_DIR)/utils/, $(UTILS)))

OBJS 		= 	$(addprefix ${OBJS_DIR}/, $(subst srcs/,,$(SRCS:.c=.o))) 

#--- COLOR ---#
BLACK 		= \033[90;1m
RESET 		= \033[0m

#--- TARGET ---#

all: ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
	@mkdir -p ${@D}
	@${CC} ${FLAGS} -c $< -o $@
	@echo "$(BLACK)Compiling: $< "

${NAME}: ${OBJS}
	@${CC} ${FLAGS} -I ${OBJS_DIR} $^ -o ${NAME}
	@echo "$(BLACK)Compilation terminé avec succès!"

clean: 
	@${RM} ${OBJS_DIR}
	@echo "$(BLACK)Nettoyage effectué avec succès !"

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

NAME_CLIENT = client
NAME_SERVER = server

INC_DIR           = includes
BONUS_INC_DIR     = includes_bonus
BIN_DIR		      = binaries

FLAGS_INC   = -I $(INC_DIR)
BONUS_FLAGS_INC   = -I $(BONUS_INC_DIR)

CC = gcc

CFLAGS = -Wall -Wextra -Werror $(FLAGS_INC) -g
SFLAGS = -Wall -Wextra -Werror -fsanitize=address $(FLAGS_INC) -g

BONUS_CFLAGS = -Wall -Wextra -Werror $(BONUS_FLAGS_INC) -g
BONUS_SFLAGS = -Wall -Wextra -Werror -fsanitize=address $(BONUS_FLAGS_INC) -g

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

CLIENT_FILES = client
SERVER_FILES = server
UTILS_FILES = utils1 \
			  utils2

SRC_CLIENT = $(addsuffix .c, $(addprefix sources/, $(CLIENT_FILES))) \
			 $(addsuffix .c, $(addprefix sources/utils/, $(UTILS_FILES)))
SRC_SERVER = $(addsuffix .c, $(addprefix sources/, $(SERVER_FILES))) \
			 $(addsuffix .c, $(addprefix sources/utils/, $(UTILS_FILES)))

BONUS_CLIENT_FILES = client_bonus
BONUS_SERVER_FILES = server_bonus
BONUS_UTILS_FILES = utils1_bonus \
				    utils2_bonus

BONUS_SRC_CLIENT = $(addsuffix .c, $(addprefix sources_bonus/, $(BONUS_CLIENT_FILES))) \
		  		   $(addsuffix .c, $(addprefix sources_bonus/utils/, $(BONUS_UTILS_FILES)))
BONUS_SRC_SERVER = $(addsuffix .c, $(addprefix sources_bonus/, $(BONUS_SERVER_FILES))) \
			 	   $(addsuffix .c, $(addprefix sources_bonus/utils/, $(BONUS_UTILS_FILES)))

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

OBJ_CLIENT = $(SRC_CLIENT:c=client.o)
OBJ_SERVER = $(SRC_SERVER:c=server.o)

BONUS_OBJ_CLIENT = $(BONUS_SRC_CLIENT:c=client.o)
BONUS_OBJ_SERVER = $(BONUS_SRC_SERVER:c=server.o)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

                   # Default #
all: message $(NAME_CLIENT) $(NAME_SERVER)

        # Compiles and clears the screen #
c: clear fclean message $(NAME_CLIENT) $(NAME_SERVER) clean

        # Compiles with fsanitize=address #
f: clear fclean message debug_client debug_server clean

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "\n\033[0;32mCompiling ${NAME_CLIENT}..."
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_CLIENT) $(BIN_DIR)

$(NAME_SERVER): $(OBJ_SERVER)
	@echo "\n\033[0;32mCompiling ${NAME_SERVER}..."
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_SERVER) $(BIN_DIR)

debug_client: $(OBJ_CLIENT)
	@echo "\n\033[0;32mCompiling ${NAME_CLIENT}..."
	@$(CC) $(SFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_CLIENT) $(BIN_DIR)

debug_server: $(OBJ_SERVER)
	@echo "\n\033[0;32mCompiling ${NAME_SERVER}..."
	@$(CC) $(SFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_SERVER) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

%.client.o: %.c
	@printf "\033[0;33mGenerating ${NAME_CLIENT} objects... %s\n" $@
	@${CC} ${FLAGS_INC} ${CFLAGS} -c $< -o $@

%.server.o: %.c
	@printf "\033[0;33mGenerating ${NAME_SERVER} objects... %s\n" $@
	@${CC} ${FLAGS_INC} ${CFLAGS} -c $< -o $@

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

clean: message
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ_CLIENT)
	@rm -f $(OBJ_SERVER)
	@rm -f $(BONUS_OBJ_CLIENT)
	@rm -f $(BONUS_OBJ_SERVER)
	@echo "\033[0m"

fclean: message
	@echo "\nDeleting objects..."
	@rm -f $(OBJ_CLIENT)
	@rm -f $(OBJ_SERVER)
	@rm -f $(BONUS_OBJ_CLIENT)
	@rm -f $(BONUS_OBJ_SERVER)
	@echo "Deleting executables..."
	@rm -f $(BIN_DIR)/$(NAME_CLIENT)
	@rm -f $(BIN_DIR)/$(NAME_SERVER)
	@rmdir binaries || true
	@echo "\033[0m"

re: clear fclean all

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

                   # Bonus #
bonus: message bonus_client bonus_server

bonus_client: $(BONUS_OBJ_CLIENT)
	@echo "\n\033[0;32mCompiling ${NAME_CLIENT}..."
	@$(CC) $(BONUS_CFLAGS) -o $(NAME_CLIENT) $(BONUS_OBJ_CLIENT)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_CLIENT) $(BIN_DIR)

bonus_server: $(BONUS_OBJ_SERVER)
	@echo "\n\033[0;32mCompiling ${NAME_SERVER}..."
	@$(CC) $(BONUS_CFLAGS) -o $(NAME_SERVER) $(BONUS_OBJ_SERVER)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_SERVER) $(BIN_DIR)

bonus_debug_client: $(BONUS_OBJ_CLIENT)
	@echo "\n\033[0;32mCompiling ${NAME_CLIENT}..."
	@$(CC) $(BONUS_SFLAGS) -o $(NAME_CLIENT) $(BONUS_OBJ_CLIENT)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_CLIENT) $(BIN_DIR)

bonus_debug_server: $(BONUS_OBJ_SERVER)
	@echo "\n\033[0;32mCompiling ${NAME_SERVER}..."
	@$(CC) $(BONUS_SFLAGS) -o $(NAME_SERVER) $(BONUS_OBJ_SERVER)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_SERVER) $(BIN_DIR)

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

message:
	@printf "\n"
	@printf "\033[1;36m	!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\033[1;35m		!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\033[1;31m			!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\033[1;38m				!! Makefile by tisantos @42Lisboa !! \e[0m \n"
	@printf "\n"

clear:
	@clear

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

NAME_CLIENT = client
NAME_SERVER = server

INC_DIR     = includes
BIN_DIR		= binaries

FLAGS_INC   = -I $(INC_DIR)

CC = gcc

CFLAGS = -Wall -Wextra -Werror $(FLAGS_INC) -g
SFLAGS = -Wall -Wextra -Werror -fsanitize=address $(FLAGS_INC) -g

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

CLIENT_FILES = client
SERVER_FILES = server
UTILS_FILES = utils1 \
			  utils2

SRC_CLIENT = $(addsuffix .c, $(addprefix sources/, $(CLIENT_FILES))) \
			 $(addsuffix .c, $(addprefix sources/utils/, $(UTILS_FILES)))
SRC_SERVER = $(addsuffix .c, $(addprefix sources/, $(SERVER_FILES))) \
			 $(addsuffix .c, $(addprefix sources/utils/, $(UTILS_FILES)))

#### ######## #### #### ######## #### #### ######## #### #### ######## #### #### ######## ####

OBJ_CLIENT = $(SRC_CLIENT:c=client.o)
OBJ_SERVER = $(SRC_SERVER:c=server.o)

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

%.client.o: %.c
	@printf "\033[0;33mGenerating ${NAME_CLIENT} objects... %s\n" $@
	@${CC} ${FLAGS_INC} ${CFLAGS} -c $< -o $@

%.server.o: %.c
	@printf "\033[0;33mGenerating ${NAME_SERVER} objects... %s\n" $@
	@${CC} ${FLAGS_INC} ${CFLAGS} -c $< -o $@

clean: message
	@echo "\nRemoving binaries..."
	@rm -f $(OBJ_CLIENT)
	@rm -f $(OBJ_SERVER)
	@echo "\033[0m"

fclean: message
	@echo "\nDeleting objects..."
	@rm -f $(OBJ_CLIENT)
	@rm -f $(OBJ_SERVER)
	@echo "Deleting executables..."
	@rm -f $(BIN_DIR)/$(NAME_CLIENT)
	@rm -f $(BIN_DIR)/$(NAME_SERVER)
	@rmdir binaries || true
	@echo "\033[0m"

re: clear fclean all

debug_client: $(OBJ_CLIENT)
	@echo "\n\033[0;32mCompiling ${NAME_CLIENT}..."
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJ_CLIENT)
	@mkdir -p $(BIN_DIR)
	@mv $(NAME_CLIENT) $(BIN_DIR)

debug_server: $(OBJ_SERVER)
	@echo "\n\033[0;32mCompiling ${NAME_SERVER}..."
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJ_SERVER)
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

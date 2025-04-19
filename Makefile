SERV_SRC = server.c utils.c
CLNT_SRC = client.c utils.c

SERV_SRC_BONUS = server_bonus.c utils.c
CLNT_SRC_BONUS = client_bonus.c utils.c

SERV_OBJ = $(SERV_SRC:.c=.o)
CLNT_OBJ = $(CLNT_SRC:.c=.o)

SERV_OBJ_BONUS = $(SERV_SRC_BONUS:.c=.o)
CLNT_OBJ_BONUS = $(CLNT_SRC_BONUS:.c=.o)

SERV = server
CLNT = client

SERV_BONUS = server_bonus
CLNT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERV) $(CLNT)

$(SERV): $(SERV_OBJ)
	$(CC) $(CFLAGS) $(SERV_OBJ) -o $@

$(CLNT): $(CLNT_OBJ)
	$(CC) $(CFLAGS) $(CLNT_OBJ) -o $@

bonus: $(SERV_BONUS) $(CLNT_BONUS)

$(SERV_BONUS): $(SERV_OBJ_BONUS)
	$(CC) $(CFLAGS) $(SERV_OBJ_BONUS) -o $@

$(CLNT_BONUS): $(CLNT_OBJ_BONUS)
	$(CC) $(CFLAGS) $(CLNT_OBJ_BONUS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SERV_OBJ) $(CLNT_OBJ) $(SERV_OBJ_BONUS) $(CLNT_OBJ_BONUS)

fclean: clean
	rm -f $(SERV) $(CLNT) $(SERV_BONUS) $(CLNT_BONUS)

re: fclean all
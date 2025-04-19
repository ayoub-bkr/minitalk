SERV_SRC = server.c utils.c
CLNT_SRC = client.c utils.c

SERV_OBJ = $(SERV_SRC:.c=.o)
CLNT_OBJ = $(CLNT_SRC:.c=.o)

SERV = server
CLNT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERV) $(CLNT)

$(SERV): $(SERV_OBJ)
	$(CC) $(CFLAGS) $(SERV_OBJ) -o $@

$(CLNT): $(CLNT_OBJ)
	$(CC) $(CFLAGS) $(CLNT_OBJ) -o $@

clean:
	rm -f $(SERV_OBJ) $(CLNT_OBJ)

fclean: clean
	rm -f $(SERV) $(CLNT)

re: fclean all
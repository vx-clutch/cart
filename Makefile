CC=gcc
SRC=src/cart.c
CFLAGS=-Werror -Wall

all: cart

cart: $(SRC)
	$(CC) -o cart $(CFLAGS) $(SRC) -Isrc

clean:
	rm cart

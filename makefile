CC=ccsc
CFLAGS=+FH +LN -T -A -M -Z +DF +Y=9 +STDOUT

all: main

main: main.c
	$(CC) $(CFLAGS) main.c

clean:
	rm *.cof *.err *.esym *.hex *.lst
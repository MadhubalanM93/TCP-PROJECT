CC = gcc

all: myls mycat mycp

myls:
	$(CC) src/myls.c -o bin/myls

mycat:
	$(CC) src/mycat.c -o bin/mycat

mycp:
	$(CC) src/mycp.c -o bin/mycp

clean:
	rm -f bin/myls
	rm -f bin/mycat
	rm -f bin/mycp

.PHONY: all clean

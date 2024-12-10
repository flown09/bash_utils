CFLAGS = -Wall -Wextra -Werror -std=c11

all: s21_cat

s21_cat: main.o flag-b.o flag-n.o flag-t.o flag-e.o flag-s.o flag-v.o
	gcc $(CFLAGS) flag-b.o flag-n.o flag-t.o flag-e.o flag-v.o flag-s.o main.o -o s21_cat

flag-b.o: flag-b.c
	gcc $(CFLAGS) -c flag-b.c -o flag-b.o

flag-n.o: flag-n.c
	gcc $(CFLAGS) -c flag-n.c -o flag-n.o

flag-t.o: flag-t.c
	gcc $(CFLAGS) -c flag-t.c -o flag-t.o

flag-e.o: flag-e.c
	gcc $(CFLAGS) -c flag-e.c -o flag-e.o

flag-v.o: flag-v.c
	gcc $(CFLAGS) -c flag-v.c -o flag-v.o

flag-s.o: flag-s.c
	gcc $(CFLAGS) -c flag-s.c -o flag-s.o

main.o: main.c
	gcc $(CFLAGS) -c main.c -o main.o

clean: 
	rm -rf *.o *.exe

rebuild: clean all
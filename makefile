OBJS = integer.o main.o sll.o node.o dll.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : main

main : $(OBJS)
		gcc $(LOPTS) $(OBJS) -o main

integer.o : integer.c integer.h
		gcc $(OOPTS) integer.c

sll.o : node.o sll.c sll.h
		gcc $(OOPTS) sll.c

node.o : node.c node.h
		gcc $(OOPTS) node.c

main.o :	main.c integer.h
		gcc $(OOPTS) main.c

dll.o : node.o dll.c dll.h
		gcc $(OOPTS) dll.c

test : main
		./main

valgrind : main
		valgrind main

clean	:
		rm -f -r $(OBJS) main *.dSYM

memcheck : main
		valgrind --leak-check=yes ./main

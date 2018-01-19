OBJS = integer.o main.o sll.o dll.o stack.o
OOPTS = -Wall -Wextra -g -c
LOPTS = -Wall -Wextra -g

all : main

main : $(OBJS)
		gcc $(LOPTS) $(OBJS) -o main

integer.o : integer.c integer.h
		gcc $(OOPTS) integer.c

stack.o : stack.c stack.h dll.o
		gcc $(OOPTS) stack.c

sll.o : sll.c sll.h
		gcc $(OOPTS) sll.c

main.o :	main.c integer.h
		gcc $(OOPTS) main.c

dll.o : dll.c dll.h
		gcc $(OOPTS) dll.c

test : main
		./main

valgrind : main
		valgrind ./main

clean	:
		rm -f -r $(OBJS) main *.dSYM

memcheck : main
		valgrind --leak-check=yes ./main

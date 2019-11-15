INCLUDE := -I ~/include
LDFLAGS := -L ~/lib -lsense -lm

all: scroll
scroll: main.o display.o input.o
	cc -g -o scroll main.o display.o input.o $(LDFLAGS)
main.o: main.c scroll.h
	cc -g -c main.c $(INCLUDE)
display.o: display.c scroll.h
	cc -g -c display.c $(INCLUDE)
input.o: input.c scroll.h
	cc -g  -c input.c $(INCLUDE)
clean:
	rm scroll *.o
run: scroll
	./scroll

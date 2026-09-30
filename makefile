OBJ:= $(patsubst %.c, %.o, $(wildcard *.c))
Inverted: $(OBJ)
	gcc -o $@ $^  
clean:
	rm *.o *.exe
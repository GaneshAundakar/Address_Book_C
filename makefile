OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
#Build target
Addressbook: $(OBJ)
  gcc -o $@ $^

#Clean build artifacts
clean:
  rm *.exe *.o

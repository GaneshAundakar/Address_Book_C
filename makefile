# method 1

#AdressBook:
#  gcc Main.c validation.c file.c contact.c -o AddressBook.exe

# Method 2 using variable
#$(CC) = gcc
#AdressBook:
#  $(CC) Main.c validation.c file.c contact.c -o AddressBook
#clean:
#  rm *.exe *.o

#Method 3 using pattern rule

# Find all C files and replace .c with .o

OBJ := $(patsubst %.c, %.o, $(wildcard *.c))
#Build target
Addressbook: $(OBJ)
  gcc -o $@ $^
#Clean build artifacts
clean:
  rm *.exe *.o

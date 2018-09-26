CFLAGS=-g -Wall

# "make all" will make the executable
all: PA4

# Create the executable
PA4: PA4.o
	g++ $(CFLAGS) PA4.o -o PA4

# Create the .o file
PA4.o: PA4.cpp
	g++ $(CFLAGS) -c PA4.cpp
	
# Remove the .o files and executable
clean:
	rm -f *.o PA4
	rm -f -r html latex
	
# Generate documentation
docs:
	doxygen
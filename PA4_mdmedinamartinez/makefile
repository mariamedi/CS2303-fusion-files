CFLAGS=-g -Wall

# "make all" will make the executable
all: PA4

# Create the executable
PA4: PA4.o Organism.o Ant.o Doodlebug.o Board.o
	g++ $(CFLAGS) PA4.o Organism.o Ant.o Doodlebug.o Board.o -o PA4

# Create the .o file
PA4.o: PA4.cpp Organism.h Ant.h Doodlebug.h Board.h
	g++ $(CFLAGS) -c PA4.cpp

Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp
	
Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp
	
Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ $(CFLAGS) -c Doodlebug.cpp
	
Board.o: Board.cpp Board.h
	g++ $(CFLAGS) -c Board.cpp

# Remove the .o files and executable
clean:
	rm -f *.o PA4
	rm -f -r html latex
	
# Generate documentation
docs:
	doxygen
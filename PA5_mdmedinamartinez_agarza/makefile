CFLAGS=-g -Wall

# "make all" will make the executable
all: qSim

# Create the executable
qSim: qSim.o 
	g++ $(CFLAGS) qSim.o -o qSim

# Create the .o file
qSim.o: qSim.cpp
	g++ $(CFLAGS) -c qSim.cpp
	
# Remove the .o files and executable
clean:
	rm -f *.o qSim
	rm -f -r html latex
	
# Generate documentation
docs:
	doxygen
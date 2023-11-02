CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Executable name
EXECUTABLE = main

compile:
	$(CXX) $(CXXFLAGS) main.cpp sort.cpp -o $(EXECUTABLE)

run:
	./$(EXECUTABLE)

clean:
	rm -f $(EXECUTABLE)

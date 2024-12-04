CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp FlightGraph.cpp Flight.cpp  # Add Flight.cpp here
OBJ = $(SRC:.cpp=.o)
EXE = main

$(EXE): $(OBJ)
	$(CXX) $(OBJ) -o $(EXE)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXE)

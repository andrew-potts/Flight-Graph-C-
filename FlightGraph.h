#ifndef FLIGHTGRAPH_H
#define FLIGHTGRAPH_H

#include <unordered_map>
#include <vector>
#include <string>
#include "Flight.h"
#include "Airport.h"

class FlightGraph {
private:
    std::unordered_map<std::string, std::vector<Flight>> adjacencyList;

public:
    void addAirport(const std::string& code);
    void addFlight(const std::string& source, const std::string& destination, double cost);
    void removeFlight(const std::string& source, const std::string& destination);
    void displayFlightsFrom(const std::string& code);
    void findShortestPath(const std::string& source, const std::string& destination);
};

#endif // FLIGHTGRAPH_H

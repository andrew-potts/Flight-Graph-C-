#include <iostream>
#include "FlightGraph.h"

int main() {
    FlightGraph graph;

    graph.addAirport("JFK");
    graph.addAirport("LAX");
    graph.addAirport("ORD");

    graph.addFlight("JFK", "LAX", 300.0);
    graph.addFlight("JFK", "ORD", 200.0);
    graph.addFlight("ORD", "LAX", 150.0);

    graph.displayFlightsFrom("JFK");

    graph.findShortestPath("JFK", "LAX");

    graph.removeFlight("JFK", "ORD");
    graph.displayFlightsFrom("JFK");

    return 0;
}

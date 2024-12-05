# Flight Route Planner

This project is a simple flight route planner that uses object-oriented programming (OOP) concepts in C++. It allows users to simulate and manage airports, flights, and find the shortest route between airports based on flight costs. The project utilizes graphs, Dijkstra's shortest path algorithm, and basic data structures like vectors and hash maps.

## Features

- **Add Airports**: Add airports to the system using unique airport codes (e.g., "JFK", "LAX", "ORD").
- **Add Flights**: Add flights between airports with specified costs.
- **Remove Flights**: Remove existing flights from the system.
- **Display Flights**: Display all direct flights from a specific airport.
- **Find Shortest Path**: Use Dijkstra's algorithm to find the shortest path between two airports based on flight costs.
- **OOP Design**: The system is designed using object-oriented principles such as classes, encapsulation, and data abstraction.

## Classes

### Airport
Represents an airport with a name and code.

### Flight
Represents a flight with a destination airport code and flight cost.

### FlightGraph
Manages airports and flights as a graph. Includes methods to add/remove airports and flights, display available flights, and find the shortest path using Dijkstra's algorithm.

## Example Usage

Here is an example main function of how the system works:

### Example

```cpp
int main() {
    FlightGraph graph;

    // Add airports
    graph.addAirport("JFK");
    graph.addAirport("LAX");
    graph.addAirport("ORD");

    // Add flights
    graph.addFlight("JFK", "LAX", 300.0);
    graph.addFlight("JFK", "ORD", 200.0);
    graph.addFlight("ORD", "LAX", 150.0);

    // Display flights from JFK
    graph.displayFlightsFrom("JFK");

    // Find the shortest path from JFK to LAX
    graph.findShortestPath("JFK", "LAX");

    // Remove a flight from JFK to ORD
    graph.removeFlight("JFK", "ORD");

    // Display updated flights from JFK
    graph.displayFlightsFrom("JFK");

    return 0;
}
### Sample output
Airport added: JFK
Airport added: LAX
Airport added: ORD
Flight added from JFK to LAX with cost: 300
Flight added from JFK to ORD with cost: 200
Flight added from ORD to LAX with cost: 150
Flights from JFK:
  -> LAX (Cost: 300)
  -> ORD (Cost: 200)
Shortest path from JFK to LAX is 300
Path: JFK LAX
Flight removed from JFK to ORD
Flights from JFK:
  -> LAX (Cost: 300)


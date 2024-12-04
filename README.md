#Flight Route Planner
This project is a simple flight route planner that uses object-oriented programming (OOP) concepts in C++. It allows users to simulate and manage airports, flights, and find the shortest route between airports based on flight costs. The project utilizes graphs, Dijkstra's shortest path algorithm, and basic data structures like vectors and hash maps.

Features
Add Airports: Add airports to the system using unique airport codes (e.g., "JFK", "LAX", "ORD").
Add Flights: Add flights between airports with specified costs.
Remove Flights: Remove existing flights from the system.
Display Flights: Display all direct flights from a specific airport.
Find Shortest Path: Use Dijkstra's algorithm to find the shortest path between two airports based on flight costs.
OOP Design: The system is designed using object-oriented principles such as classes, encapsulation, and data abstraction.
Technologies Used
C++17: The project is built using C++17 standard.
Data Structures:
Unordered maps for managing airports and their connected flights.
Vectors for storing flight details.
Priority queues to implement Dijkstra's algorithm efficiently.
Classes
Airport:

Represents an airport with a name and code.
Flight:

Represents a flight with a destination airport code and flight cost.
FlightGraph:

Manages airports and flights as a graph.
Includes methods to add/remove airports and flights, display available flights, and find the shortest path using Dijkstra's algorithm.

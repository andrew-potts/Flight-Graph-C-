#include "FlightGraph.h"
#include <iostream>
#include <queue>
#include <limits>
#include <algorithm>

void FlightGraph::addAirport(const std::string& code) {
    if (adjacencyList.find(code) == adjacencyList.end()) {
        adjacencyList[code] = {};
        std::cout << "Airport added: " << code << std::endl;
    } else {
        std::cout << "Airport already exists: " << code << std::endl;
    }
}

void FlightGraph::addFlight(const std::string& source, const std::string& destination, double cost) {
    if (adjacencyList.find(source) != adjacencyList.end()) {
        adjacencyList[source].emplace_back(destination, cost);
        std::cout << "Flight added from " << source << " to " << destination << " with cost: " << cost << std::endl;
    } else {
        std::cout << "Source airport does not exist: " << source << std::endl;
    }
}

void FlightGraph::removeFlight(const std::string& source, const std::string& destination) {
    if (adjacencyList.find(source) != adjacencyList.end()) {
        auto& flights = adjacencyList[source];
        flights.erase(std::remove_if(flights.begin(), flights.end(),
                         [&](const Flight& flight) { return flight.destinationCode == destination; }),
                         flights.end());
        std::cout << "Flight removed from " << source << " to " << destination << std::endl;
    } else {
        std::cout << "Source airport does not exist: " << source << std::endl;
    }
}

void FlightGraph::displayFlightsFrom(const std::string& code) {
    if (adjacencyList.find(code) != adjacencyList.end()) {
        std::cout << "Flights from " << code << ":" << std::endl;
        for (const auto& flight : adjacencyList[code]) {
            std::cout << "  -> " << flight.destinationCode << " (Cost: " << flight.cost << ")" << std::endl;
        }
    } else {
        std::cout << "Airport does not exist: " << code << std::endl;
    }
}

void FlightGraph::findShortestPath(const std::string& source, const std::string& destination) {
    std::unordered_map<std::string, double> distances;
    std::unordered_map<std::string, std::string> previous;
    std::priority_queue<std::pair<double, std::string>, std::vector<std::pair<double, std::string>>, std::greater<>> pq;

    for (const auto& pair : adjacencyList) {
        distances[pair.first] = std::numeric_limits<double>::infinity();
    }
    distances[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [currentDist, currentNode] = pq.top();
        pq.pop();

        if (currentDist > distances[currentNode]) continue;

        for (const auto& flight : adjacencyList[currentNode]) {
            double newDist = currentDist + flight.cost;
            if (newDist < distances[flight.destinationCode]) {
                distances[flight.destinationCode] = newDist;
                previous[flight.destinationCode] = currentNode;
                pq.push({newDist, flight.destinationCode});
            }
        }
    }

    if (distances[destination] == std::numeric_limits<double>::infinity()) {
        std::cout << "No path from " << source << " to " << destination << std::endl;
    } else {
        std::cout << "Shortest path from " << source << " to " << destination << " is " << distances[destination] << std::endl;
        std::string current = destination;
        std::vector<std::string> path;
        while (current != source) {
            path.push_back(current);
            current = previous[current];
        }
        path.push_back(source);
        std::reverse(path.begin(), path.end());
        std::cout << "Path: ";
        for (const auto& node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }
}

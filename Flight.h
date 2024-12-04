#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>

class Flight {
public:
    std::string destinationCode;
    double cost;

    Flight(const std::string& destinationCode, double cost);  // Constructor declaration
};

#endif // FLIGHT_H

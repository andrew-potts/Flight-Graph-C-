#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

class Airport {
public:
    std::string name;
    std::string code;

    Airport(const std::string& name, const std::string& code);
};

#endif // AIRPORT_H

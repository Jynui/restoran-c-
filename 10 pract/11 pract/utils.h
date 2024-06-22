#ifndef UTILS_H
#define UTILS_H

#include <string>

class Utils {
public:
    static int getIntInput(const std::string& prompt);
    static double getDoubleInput(const std::string& prompt);
    static std::string getStringInput(const std::string& prompt);
};

#endif

#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
#include "Source.h"

class RadiationDetector {
private:
    std::string detector_type;
    bool is_on;
    long long total_counts;

public:
    //constructors and destructor
    RadiationDetector(const std::string& type);
    ~RadiationDetector();

    void turnOn();
    void turnOff();
    long long getTotalCounts() const;
    long long detectRadiation(const RadioactiveSource& source);
};

#endif
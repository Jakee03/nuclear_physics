#ifndef DETECTOR_H
#define DETECTOR_H

#include <string>
#include "Source.h"

class RadiationDetector {
private:
    std::string detector_type;
    bool is_on;
    int total_counts;

public:
    //constructors and destructor
    RadiationDetector(const std::string& type);
    ~RadiationDetector();

    void turnOn();
    void turnOff();
    int getTotalCounts() const;
    int detectRadiation(const RadioactiveSource& source);
};

#endif
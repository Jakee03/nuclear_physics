#include "Detector.h"
#include <iostream>
#include <cstdlib> //for rand()

RadiationDetector::RadiationDetector(std::string type)
    : detector_type(type), is_on(false), total_counts(0) {}

RadiationDetector::~RadiationDetector() {}

int RadiationDetector::detectRadiation(const RadioactiveSource source) {
    if (!is_on) return 0; // No counts if the detector is off

    //simulation logic
    int counts = static_cast<int>(source.getActivity() * (rand() % 10) / 100.0);
    total_counts += counts;
    return counts;
}

//setters
void RadiationDetector::turnOn() {
    is_on = true;
}

void RadiationDetector::turnOff() {
    is_on = false;
}
//getters
int RadiationDetector::getTotalCounts() const {
    return total_counts;
}
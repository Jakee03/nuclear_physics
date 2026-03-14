#include "Detector.h"
#include <iostream>
#include <cstdlib> //for rand()

RadiationDetector::RadiationDetector(const std::string& type)
    : detector_type(type), is_on(false), total_counts(0) {

    if (type.empty()) {
        throw std::invalid_argument("Error: Detector type cannot be empty.");
    }
}

RadiationDetector::~RadiationDetector() {}

long long RadiationDetector::detectRadiation(const RadioactiveSource& source) {
    if (!is_on) return 0; // No counts if the detector is off

    //simulation logic
    double act = source.getActivity();
    long long counts = static_cast<long long>(act * ((rand() % 10) + 1) / 100.0);
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
long long RadiationDetector::getTotalCounts() const {
    return total_counts;
}
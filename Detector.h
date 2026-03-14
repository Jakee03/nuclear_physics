#include <string>
#include "Source.h"

class RadiationDetector {
private:
    std::string detector_type;
    bool is_on;
    int total_counts;

public:
    //constructors and destructor
    RadiationDetector(std::string type);
    ~RadiationDetector();

    void turnOn() { is_on = true; }
    void turnOff() { is_on = false; }

    int detectRadiation(const RadioactiveSource source);
};
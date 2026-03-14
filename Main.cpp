#include <iostream>
#include <vector>
#include "Source.h"
#include "Detector.h"

int main() {
    //Create sources PLACEHOLDER VALS
    std::vector<RadioactiveSource> sources;
    sources.push_back(RadioactiveSource("Na-22", "2026-01-01", 100.0));
    sources.push_back(RadioactiveSource("Cs-136", "2026-01-01", 100.0));
    sources.push_back(RadioactiveSource("Co-92", "2026-01-01", 100.0));

    //power on detector
    RadiationDetector Geiger("Geiger");
    Geiger.turnOn();

    //detect radiation from each source
    std::cout<< "--- Starting Lab Measurements ---" << std::endl;
    for (const auto& src : sources) {
        src.printSourceData();
        int counts = Geiger.detectRadiation(src);
        std::cout << "Detected Counts: " << counts << std::endl;
    }

    return 0;
}
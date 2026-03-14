#include <iostream>
#include <vector>
#include <ctime> //for time() for rand()
#include <cstdlib> //for rand()
#include "Source.h"
#include "Detector.h"

int main() {
    std::srand(std::time(0)); // Seed the random number generator

    //Create sources PLACEHOLDER VALS
    std::vector<RadioactiveSource> sources;
    sources.push_back(RadioactiveSource("Na-22", "2026-01-01", 2.31e14));
    sources.push_back(RadioactiveSource("Cs-136", "2026-01-01", 2.75e15));
    sources.push_back(RadioactiveSource("Co-92", "2026-01-01", 100.0));

    //power on detector
    RadiationDetector Geiger("Geiger");
    Geiger.turnOn();

    //detect radiation from each source
    std::cout<< "--- Starting Lab Measurements ---" << std::endl;
    for (const auto& src : sources) {
        src.printSourceData();
        int counts = Geiger.detectRadiation(src);
        std::cout << "Detected Counts: " << counts << "\n" << std::endl;
    }

    return 0;
}
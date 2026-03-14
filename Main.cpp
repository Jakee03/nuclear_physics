#include <iostream>
#include <vector>
#include <ctime> //for time() for rand()
#include <cstdlib> //for rand()
#include <fstream> //file reading
#include <sstream> //for strings 
#include "Source.h"
#include "Detector.h"

int main() {
    std::srand(std::time(0)); // Seed the random number generator

    //Create sources PLACEHOLDER VALS
    std::vector<RadioactiveSource> sources;

    try {
        sources.push_back(RadioactiveSource("Na-22", "01/01/2026", 2.31e14));
        sources.push_back(RadioactiveSource("Cs-136", "01/01/2026", 2.75e15));
        sources.push_back(RadioactiveSource("Co-92", "01/01/2026", 100.0));
    } catch (const std::invalid_argument& e) {
        std::cerr << "Initialisation Failed: " << e.what() << std::endl;
        return 1;
    }

    //power on detector
    RadiationDetector Geiger("Geiger");
    Geiger.turnOn();

    //detect radiation from each source
    std::cout<< "--- Starting Lab Measurements ---" << std::endl;
    for (const auto& src : sources) {
        src.printSourceData();
        double counts = Geiger.detectRadiation(src);
        std::cout << "Detected Counts: " << counts << "\n" << std::endl;
    }

    return 0;
}
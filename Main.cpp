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

    //Create sources vector
    std::vector<RadioactiveSource> sources;

    //read config file
    std::ifstream configFile("Sources.txt");
    if (!configFile.is_open()) {
        std::cerr << "Error: Could not open Sources.txt" << std::endl;
        return 1;
    }

    //read source data from file
    std::string line;
    while (std::getline(configFile, line)) {
        std::istringstream iss(line);
        std::string type, date;
        double activity;
        if (iss >> type >> date >> activity) {
            try {
                sources.push_back(RadioactiveSource(type, date, activity));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Skipping invalid entry in config file: " << e.what() << std::endl;
            }
        }
    }
    configFile.close();
    //power on detector
    RadiationDetector Geiger("Geiger");
    Geiger.turnOn();

    //detect radiation from each source
    std::cout<< "--- Starting Lab Measurements ---" << std::endl;
    for (const auto& src : sources) {
        src.printSourceData();
        long long counts = Geiger.detectRadiation(src);
        std::cout << "Detected Counts: " << counts << "\n" << std::endl;
    }

    return 0;
}
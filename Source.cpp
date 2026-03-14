#include "Source.h"
#include <iostream>
#include <stdexcept> //for exit if error

//Initialise static memeber
int RadioactiveSource::next_id = 1001;
//default constructor
RadioactiveSource::RadioactiveSource() : source_type("Unknown"), acquisition_date("Unknown"), activity(0.0){
    source_id = next_id++;

}
//parametereised constructor
RadioactiveSource::RadioactiveSource(const std::string& type, const std::string& date, double act) {
    if (type.empty() || date.empty()) {
        throw std::invalid_argument("Error: Source type and acquisition date cannot be empty.");
    }
    source_type = type;
    acquisition_date = date;
    setActivity(act);
    source_id = next_id++;
}
//Destructor
RadioactiveSource::~RadioactiveSource() {}
//print data
void RadioactiveSource::printSourceData() const {
    std::cout << "Source ID: " << source_id << " | Type: " << source_type
              << " | Activity: " << activity << " Bq/kg" << std::endl;

}
//getters
double RadioactiveSource::getActivity() const {
    return activity;
}

std::string RadioactiveSource::getSourceType() const {
    return source_type;
}

int RadioactiveSource::getSourceID() const {
    return source_id;
}

//setters
void RadioactiveSource::setSourceType(const std::string& type) {
    source_type = type;
}

void RadioactiveSource::setActivity(double act) {
    if (act < 0) {
        throw std::invalid_argument("Error: Activity cannot be negative.");
    }
    if (act > 1e18) {
        throw std::invalid_argument("Error: Activity exceeds simulation limits.");
    }
    activity = act;
    
}

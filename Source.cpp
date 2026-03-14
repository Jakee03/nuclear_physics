#include "Source.h"
#include <iostream>

//Initialise static memeber
int RadioactiveSource::next_id = 1001;
//default constructor
RadioactiveSource::RadioactiveSource() : source_type("Unknown"), activity(0.0){
    source_id = next_id++;

}
//parametereised constructor
RadioactiveSource::RadioactiveSource(const std::string& type, const std::string& date, double act) {
    source_type = type;
    aquisition_date = date;
    activity = act;
    source_id = next_id++;
}
//Destructor
RadioactiveSource::~RadioactiveSource() {}
//print data
void RadioactiveSource::printSourceData() const {
    std::cout << "Source ID: " << source_id << " | Type: " << source_type
              << " | Activity: " << activity << " bq/kg" << std::endl;

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
    activity = act;
}

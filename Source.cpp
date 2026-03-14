#include "Source.h"
#include <iostream>

//Initialise static memeber
int RadioactiveSource::next_id = 1001;
//constructors
RadioactiveSource::RadioactiveSource() : source_type("Unknown"), activity(0.0){
    source_id = next_id++;

}

RadioactiveSource::RadioactiveSource(std::string type, std::string date, double act) {
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

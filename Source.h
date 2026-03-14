#ifndef SOURCE_H
#define SOURCE_H

#include <iostream>
#include <string>

class RadioactiveSource {
private:
    std::string source_type;
    std::string acquisition_date;
    double activity; // in Becquerels
    int source_id;
    static int next_id; // Static member to keep track of IDs

public:
    //constructors and destructor
    RadioactiveSource();
    RadioactiveSource(const std::string& type, const std::string& date, double act);
    ~RadioactiveSource();

    std::string getSourceType() const;
    double getActivity() const;
    int getSourceID() const;

    //setters
    void setSourceType(const std::string& type);
    void setActivity(double act);

    //display
    void printSourceData() const;
};

#endif
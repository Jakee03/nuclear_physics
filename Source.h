#include <iostream>
#include <string>

class RadioactiveSource {
private:
    std::string source_type;
    std::string aquisition_date;
    double activity; // in Becquerels
    int source_id;
    static int next_id; // Static memeber to keep track of IDs

public:
    //constructors and destructor
    RadioactiveSource();
    RadioactiveSource(std::string type, std::string date, double act);
    ~RadioactiveSource();

    std::string getSourceType() const;
    std::string getAquisitionDate() const;
    double getActivity() const;
    int getSourceID() const;

    //setters
    void setSourceType(const std::string type);
    void setAquisitionDate(const std::string date);
    void setActivity(double act);

    //display
    void printSourceData() const;
};

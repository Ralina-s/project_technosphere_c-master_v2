#ifndef PROJECT_TECHNOSPHERE_C_V2_DATE_H
#define PROJECT_TECHNOSPHERE_C_V2_DATE_H

#include <string>
#include <map>

class Date {
public:
    Date(std::map<std::string, int> &init): year(init["Year"]),
                                            month(init["Month"]),
                                            day(init["Day"]),
                                            hour(init["Hour"]),
                                            minute(init["Minute"]) {}
    void set_date(std::map<std::string, int> &init);
    std::map <std::string, int> get_date() const;
private:
    int year, month, day, hour, minute;
};

#endif //PROJECT_TECHNOSPHERE_C_V2_DATE_H

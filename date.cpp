#include "date.h"

void Date::set_date(std::map<std::string, int> &init) {
    *this = Date(init);
}

std::map <std::string, int> Date::get_date() const {
    std::map <std::string, int> res = {
            {"Year", year},
            {"Month", month},
            {"Day", day},
            {"Hour", hour},
            {"Minute", minute}
    };
    return res;
}
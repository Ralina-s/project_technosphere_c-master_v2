#ifndef PROJECT_TECHNOSPHERE_C_MASTER_V2_DAY_H
#define PROJECT_TECHNOSPHERE_C_MASTER_V2_DAY_H

#include <string>
#include <vector>
#include "case.h"

class Day
{
private:
    Case_List cases;
    Date date;
public:
    Day(Date date)
    : date(date) {}
    Date get_date();
    void add_case(Case& new_case);
    void del_case(int num);
    Case &get_case(int num);
};

#endif //PROJECT_TECHNOSPHERE_C_MASTER_V2_DAY_H

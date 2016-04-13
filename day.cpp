#include "day.h"

Date Day::get_date()
{
    return date;
}

void Day::add_case(Case new_case)
{
    cases.add_case(std::unique_ptr<Case>(new_case));
}

void Day::del_case(int num)
{
    cases.delete_case(num);
}

Case &Day::get_case(int num)
{
    return *cases.get_list().at(num);
}

#include "cost.h"

void Cost::set_amount(double new_amount) {
    amount = new_amount;
}

void Cost::set_description(std::string &new_description) {
    description = new_description;
}

void Cost::set_priority(Priority_t new_priority) {
    priority = new_priority;
}

double Cost::get_amount() const {
    return amount;
}

std::string Cost::get_description() const {
    return description;
}

Priority_t  Cost::get_priority() const {
    return priority.get_priority();
}

void Regular_Outcome::set_frequency(Regularity_t new_frequency) {
    frequency = new_frequency;
}

Regularity_t Regular_Outcome::get_frequency() const {
    return frequency;
}

const std::vector<std::unique_ptr<Cost>> &CostList::get_regular() const {
    return reg;
}

const std::vector<std::unique_ptr<Cost>> &CostList::get_irregular() const {
    return irreg;
}

void CostList::add_regular(std::unique_ptr<Cost> &cost) {
    reg.push_back(std::move(cost));
}

void CostList::add_irregular(std::unique_ptr<Cost> &cost) {
    irreg.push_back(std::move(cost));
}

void CostList::delete_reg(int num) {
    reg.erase(reg.begin() + num);
}

void CostList::delete_irreg(int num) {
    irreg.erase(irreg.begin() + num);
}

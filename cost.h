#ifndef PROJECT_TECHNOSPHERE_C_COST_H
#define PROJECT_TECHNOSPHERE_C_COST_H

#include <string>
#include <vector>
#include "case.h"

class Cost {
public:
    Cost(int new_amount, const std::string &new_description, Priority_t new_priority):
            amount(new_amount),
            description(new_description),
            priority(Priority(new_priority)) {}
    void set_amount(double new_amount);
    void set_description(std::string &new_description);
    void set_priority(Priority_t new_priority);
    double get_amount() const;
    std::string get_description() const;
    Priority_t get_priority() const;
private:
    double amount;
    std::string description;
    Priority priority;
};

class Regular_Outcome: public Cost {
public:
    Regular_Outcome(int new_amount, const std::string &new_description, Priority_t new_priority,
                    Regularity_t new_frequency) : Cost(new_amount, new_description, new_priority),
                                                  frequency(new_frequency) {}
    void set_frequency(Regularity_t new_frequency);
    Regularity_t get_frequency() const;
private:
    Regularity_t frequency;
    bool deficit; // TODO - сделать нехватку
};

class Irregular_Outcome: public Cost {  //TODO - оформить нерегулярные расходы
    Irregular_Outcome(int new_amount, const std::string &new_description, Priority_t new_priority):
            Cost(new_amount, new_description, new_priority) {}
};

// List of costs for days, months and years
class CostList {
public:
    CostList() = default;
    const std::vector<std::unique_ptr<Cost>> &get_regular() const;
    const std::vector<std::unique_ptr<Cost>> &get_irregular() const;
    void add_regular(std::unique_ptr<Cost> &cost); // regular costs
    void add_irregular(std::unique_ptr<Cost> &cost); // irregular costs
    void delete_reg(int num); //take number of cost in list
    void delete_irreg(int num); // -||-
private:
    std::vector<std::unique_ptr<Cost>> reg, irreg; // 2 pointers for lists
    static const std::size_t size_block = 10; // size of block of allocated memory
};

#endif //PROJECT_TECHNOSPHERE_C_COST_H

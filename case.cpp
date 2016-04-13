#include "case.h"

void Status::set_status(Status_t new_status) {
    type_status = new_status;
}

Status_t Status::get_status() const {
    return type_status;
}

void Priority::set_priority(Priority_t new_priority) {
    type_priority = new_priority;
}

Priority_t Priority::get_priority() const {
    return type_priority;
}
void Regularity::set_regularity(Regularity_t new_regularity) {
    type_regularity = new_regularity;
}

Regularity_t Regularity::get_regularity() const {
    return type_regularity;
}

void Color::set_color(Color_t new_color) {
    type_color = new_color;
}

Color_t Color::get_color() const {
    return type_color;
}

void Case::set_case(std::map<std::string, int> &init) {
    priority =  Priority(init["Priority"]);

}

void Case::set_priority(Priority_t new_priority) {
    priority.set_priority(new_priority);
}

void Case::set_regularity(Regularity_t new_regularity) {
    regularity.set_regularity(new_regularity);
}

void Case::set_color(Color_t new_color) {
    color.set_color(new_color);
}

void Case::set_type(Case_t my_type) {
    type = my_type;
}

Priority_t Case::get_priority() const {
    return priority.get_priority();
}

Regularity_t Case::get_regularity() const {
    return regularity.get_regularity();
}

Color_t Case::get_color() const {
    return color.get_color();
}

void Task::set_status(Status_t new_status) {
    status = new_status;
}

void Task::set_description(std::string &new_description) {
    description = new_description;
}

void Task::set_deadline(Date &time) {
    deadline = time;
}

std::string Task::get_description() const {
    return description;
}

Date Task::get_deadline() const {
    return deadline;
}

void Note::set_subject(std::string &new_subject) {
    subject = new_subject;
}

std::string Note::get_subject() const {
    return subject;
}

void Event::set_name(std::string &new_name) {
    name = new_name;
}

void Event::set_time(Date &new_time) {
    time = new_time;
}

std::string Event:: get_name() const {
    return name;
}

Date Event::get_time() const {
    return time;
}

void View::set_description(std::string &new_description) {
    description = new_description;
}

std::string View::get_description() const {
    return description;
}

const std::vector<std::unique_ptr<Case>> &Case_List::get_list() const {
    return list;
}

void Case_List::add_case(std::unique_ptr<Case> &matter) {
    list.push_back(std::move(matter));
}

void Case_List::delete_case(int num) {
    list.erase(list.begin() + num);
}

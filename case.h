#ifndef PROJECT_TECHNOSPHERE_C_CASE_H
#define PROJECT_TECHNOSPHERE_C_CASE_H

#include <string>
#include <vector>
#include "date.h"
#include "enums.h"

class Status {
public:
    Status(Status_t new_status): type_status(new_status) {}
    void set_status(Status_t new_status);
    Status_t get_status() const;
private:
    Status_t type_status;
};

class Priority {
public:
    Priority(Priority_t new_priority): type_priority(new_priority) {}
    Priority(int new_priority): type_priority(static_cast<Priority_t >(new_priority)) {}
    void set_priority(Priority_t new_priority);
    Priority_t get_priority() const;
private:
    Priority_t type_priority;
};

class Regularity {
public:
    Regularity(Regularity_t new_regularity): type_regularity(new_regularity) {}
    Regularity(int new_regularity): type_regularity(static_cast<Regularity_t >(new_regularity)) {}
    void set_regularity(Regularity_t new_regularity);
    Regularity_t get_regularity() const;
private:
    Regularity_t type_regularity;
};

class Color {
public:
    Color(Color_t new_color): type_color(new_color) {}
    Color(int new_color): type_color(static_cast<Color_t>(new_color)) {}
    void set_color(Color_t new_color);
    Color_t get_color() const;
private:
    Color_t type_color;
};

int f()
{
    Color_t c1 = Color_t::RED, c2 = Color_t::YELLOW;
    return c1 > c2;
}

class Case {
public:
    Case(std::map<std::string, int> &init): priority(Priority(init["Priority"])),
                                            regularity(Regularity(init["Regularity"])),
                                            color(Color(init["Color"])),
                                            type(Case_t::UNDEFINED) {}
    void set_case(std::map<std::string, int> &init);
    void set_priority(Priority_t new_priority);
    void set_regularity(Regularity_t new_regularity);
    void set_color(Color_t new_color);
    void set_type(Case_t my_type);
    Priority_t get_priority() const;
    Regularity_t get_regularity() const;
    Color_t get_color() const;
private:
    Priority priority;
    Regularity regularity;
    Color color;
    Case_t type;
};

class Task: public Case {
public:
    Task(std::map<std::string, int> &init, Status_t new_status, std::string &new_description, Date time):
            Case(init),
            status(Status(new_status)),
            description(new_description),
            deadline(time)
    {
        set_type(Case_t::TASK);
    }
    void set_status(Status_t new_status);
    void set_description(std::string &new_description);
    void set_deadline(Date &time);
    std::string get_description() const;
    Date get_deadline() const;
private:
    Status status;
    std::string description;
    Date deadline;
};

class Note: public Case {
public:
    Note(std::map<std::string, int> &init, std::string &new_subject) : Case(init),
                                                                       subject(new_subject)
    {
        set_type(Case_t::TASK);
    }
    void set_subject(std::string &new_subject);
    std::string get_subject() const;
private:
    std::string subject;
};

class Event: public Case {
public:
    Event(std::map<std::string, int> &init, std::string &new_name, Date &new_time): Case(init),
                                                                                    name(new_name),
                                                                                    time(new_time)
    {
        set_type(Case_t::TASK);
    }

    void set_name(std::string &new_name);
    void set_time(Date &new_time);
    std::string get_name() const;
    Date get_time() const;
private:
    std::string name;
    Date time;
};

class View: public Case {
public:
    View(std::map<std::string, int> &init, std::string &new_description): Case(init),
                                                                          description(new_description)
    {
        set_type(Case_t::TASK);
    }
    void set_description(std::string &new_description);
    std::string get_description() const;
private:
    std::string description;
};

class Case_List {
public:
    Case_List() = default;
    const std::vector<std::unique_ptr<Case>> &get_list() const;
    void add_case(std::unique_ptr<Case> &matter);
    void delete_case(int num);
private:
    std::vector<std::unique_ptr<Case>> list;
    static const std::size_t size_block = 10; //Размер блока выделяемой памяти
};

#endif //PROJECT_TECHNOSPHERE_C_CASE_H

#pragma once

#include <string>

typedef unsigned long ID;
class Student 
{
public:
    Student(ID id): m_id(id) {}
    ~Student(){}

    std::string to_string(void) {
        std::string str;
        if(m_id%3==0) {
            str += "Fizz";
        }
        if(m_id%5==0) {
            str += "Buzz";
        }
        if(str.empty()) {
            str=std::to_string(m_id);
        }
        return str;
    }

private:
    ID m_id;
};
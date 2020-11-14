#pragma once

#include <string>
#include <vector>

#include "student.hpp"

class Students {

public:
    Students();
    Students(std::string path_to_records);
    Students(const Students&)=delete;
    Students& operator=(const Students&)=delete;
    virtual ~Students();

    virtual bool read_records(std::string path_to_records);
    virtual void clear_records();

    virtual std::string to_string();

protected:
    void clear_records(std::vector<Student*>& Students);

protected:
    std::vector<Student*> m_pStudents;
};

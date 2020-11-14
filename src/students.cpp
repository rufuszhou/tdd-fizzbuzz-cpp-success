#include <string>
#include <iostream>
#include <fstream>
#include "students.h"


Students::Students() {
}

Students::Students(std::string path_to_records) {
    read_records(path_to_records);
}

Students::~Students() {
    clear_records();
}

bool Students::read_records(std::string path_to_records) {
    bool result = true;
    std::vector<Student*> Students;
    std::ifstream input_file;

    input_file.open(path_to_records);
    if (input_file.is_open()) {
        std::string line;
        while (std::getline(input_file, line)) {
            unsigned long id;
            try {
                id = std::stoul(line);

                Student* p_Student = new Student(id);

                Students.push_back(p_Student);
            } catch (std::invalid_argument & ia) {
                std::cerr<< "Invalid input: " << line << std::endl;
                result = false;
                break;
            } catch (std::out_of_range& oor) {
                std::cerr<< "Invalid input: " << line << std::endl;
                result = false;
                break;
            }
        }
    } else {
        std::cerr<< "Failed to open file: " << path_to_records << std::endl;
        result = false;
    }
    input_file.close();
    if (result) {
        clear_records();
        m_pStudents = Students;
    } else {
        clear_records(Students);
    }
    return result;
}

void Students::clear_records() {
    clear_records(m_pStudents);
}

void Students::clear_records(std::vector<Student*>& Students) {
    for (std::vector<Student*>::iterator it=Students.begin();
            it != Students.end();
            it++) {
        if ( *it != nullptr ) {
            delete *it;
        }
    }
    Students.clear();
}

std::string Students::to_string() {
    std::string output;
    for (std::vector<Student*>::iterator it = m_pStudents.begin();
            it != m_pStudents.end();
            it++) {
        output = output + (*it)->to_string() + "\n";
    }
    return output;
}

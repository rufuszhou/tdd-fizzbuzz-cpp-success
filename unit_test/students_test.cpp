#include <gtest/gtest.h>

#include <string>
#include <fstream>
#include <iostream>

#include "students.h"

#define NON_EXIST_INPUT_FILE "./RANDOM_FILE_NAME_ASDFASDFASFAQFQWASDVW.txt"
#define VALID_INPUT_FILE "./StudentsTestValidInput.txt"
#define INVALID_INPUT_FILE "./StudentsTestInvalidInput.txt"

TEST(StudentsTest, test_default)
{
    Students ts;
    ASSERT_TRUE(ts.to_string().empty());
}

TEST(StudentsTest, test_non_exist_input)
{
    Students ts(NON_EXIST_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}

TEST(StudentsTest, test_one_valid_line)
{
    std::ofstream test_file(VALID_INPUT_FILE);
    test_file<<1<<std::endl;
    test_file.close();

    Students ts(VALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string() == "1\n");
}

TEST(StudentsTest, test_four_valid_lines) 
{
    std::ofstream test_file(VALID_INPUT_FILE);
    test_file<<"1"<<std::endl;
    test_file<<"15"<<std::endl;
    test_file<<"6"<<std::endl;
    test_file<<"5"<<std::endl;
    test_file.close();

    Students ts(VALID_INPUT_FILE);
    std::cout<<ts.to_string();
    ASSERT_TRUE(ts.to_string() == "1\nFizzBuzz\nFizz\nBuzz\n");
}

TEST(StudentsTest, test_one_invalid_lines) 
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file<<"a"<<std::endl;
    test_file.close();

    Students ts(INVALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}


TEST(StudentsTest, test_multiple_invalid_lines_1) 
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file<<"a1111"<<std::endl;          // <-- invalid input
    test_file<<"3"<<std::endl;
    test_file<<"10"<<std::endl;
    test_file<<"2"<<std::endl;
    test_file.close();

    Students ts(INVALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}


TEST(StudentsTest, test_multiple_invalid_lines_2) 
{
    std::ofstream test_file(INVALID_INPUT_FILE);
    test_file<<"1"<<std::endl;         
    test_file<<"9999999999999999999999999999999999999999999999999999999"<<std::endl;     // <-- invalid input
    test_file<<"10"<<std::endl;
    test_file<<"2"<<std::endl;
    test_file.close();

    Students ts(INVALID_INPUT_FILE);
    ASSERT_TRUE(ts.to_string().empty());
}

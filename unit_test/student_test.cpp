#include <gtest/gtest.h>

#include "student.hpp"


TEST(StudentTest, test_1)
{
    Student s(1);
    ASSERT_TRUE(s.to_string() == "1");
}

TEST(StudentTest, test_3)
{
    Student s(3);
    ASSERT_TRUE(s.to_string() == "Fizz");
}

TEST(StudentTest, test_5)
{
    Student s(5);
    ASSERT_TRUE(s.to_string() == "Buzz");
}

TEST(StudentTest, test_15)
{
    Student s(15);
    ASSERT_TRUE(s.to_string() == "FizzBuzz");
}


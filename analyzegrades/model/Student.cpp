#include "Student.h"

namespace model
{

Student::Student()
{

}
Student::Student(const string& firstName, const string& lastName, int grade)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->grade = grade;
}
Student::~Student()
{
    //dtor
}
const string& Student::getFirstName() const
{
    return this->firstName;
}

const string& Student::getLastName() const
{
    return this->lastName;
}
void Student::setFirstName(const string& firstName)
{
    this->firstName = firstName;
}

void Student::setLastName(const string& lastName)
{
    this->lastName = lastName;
}

int Student::getGrade() const
{
    return this->grade;
}
void Student::setGrade(int grade)
{
    this->grade = grade;
}
char Student::getGradeAsLetter()
{
    char letterGrade;
    if (this->grade < 60)
    {
        letterGrade = 'F';
    }
    else if (this->grade < 70)
    {
        letterGrade = 'D';
    }
    else if (this->grade < 80)
    {
        letterGrade = 'C';
    }
    else if (this->grade < 90)
    {
        letterGrade = 'B';
    }
    else if  (this->grade <= 100)
    {
        letterGrade = 'A';
    }
    return letterGrade;
}



}

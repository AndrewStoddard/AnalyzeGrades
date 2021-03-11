#include "Student.h"
namespace model
{
/**
* Constructor
*
*
*
*
* @return Student
*
*/
Student::Student()
{
}
/**
* Constructor
*
* @param string& first name
* @param string& last name
* @param int grade
* @return Student
*
*/
Student::Student(const string& firstName, const string& lastName, int grade)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->grade = grade;
}
/**
* Deconstructor
*
*
*
*
*
*
*/
Student::~Student()
{
    //dtor
}
/**
* Gets the First name
*
*
*
*
* @return string&
*
*/
const string& Student::getFirstName() const
{
    return this->firstName;
}
/**
* Gets the Last Name
*
*
*
*
* @return string&
*
*/
const string& Student::getLastName() const
{
    return this->lastName;
}
/**
* Sets the first name
*
*
*
* @param string& the first name
* @return none
*
*/
void Student::setFirstName(const string& firstName)
{
    this->firstName = firstName;
}
/**
* Sets the last name
*
*
*
* @param string& the last name
* @return none
*
*/
void Student::setLastName(const string& lastName)
{
    this->lastName = lastName;
}
/**
* Gets the grade
*
*
*
*
* @return int
*
*/
int Student::getGrade() const
{
    return this->grade;
}
/**
* Sets the grade
*
*
*
* @param int the grade
* @return none
*
*/
void Student::setGrade(int grade)
{
    this->grade = grade;
}
/**
* Gets a students letter grade
*
*
*
*
* @return char
*
*/
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

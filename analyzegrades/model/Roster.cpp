#include "Roster.h"
#include <vector>
#include "Student.h"
#include <algorithm>
#include <iostream>
using namespace std;
namespace model
{
/**
* Constructor
*
*
*
*
* @return Roster
*
*/
Roster::Roster()
{
    //ctor
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
Roster::~Roster()
{
}
/**
* Sorts roster by grade
*
*
*
*
* @return none
*
*/
void Roster::sortByGrade()
{
    sort(this->students.begin(), this->students.end(), [](Student a, Student b)
    {
        return a.getGrade() > b.getGrade();
    });
}
/**
* Sorts roster by first name
*
*
*
*
* @return none
*
*/
void Roster::sortByFirstName()
{
    sort(this->students.begin(), this->students.end(), [](Student a, Student b)
    {
        return a.getFirstName() < b.getFirstName();
    });
}
/**
* Sorts roster by last name
*
*
*
*
* @return none
*
*/
void Roster::sortByLastName()
{
    sort(this->students.begin(), this->students.end(), [](Student a, Student b)
    {
        return a.getLastName() < b.getLastName();
    });
}
/**
* Removes a student with the first and last name passed in
*
*
* @param string& first name
* @param string& last name
* @return none
*
*/
void Roster::remove(const string& firstName, const string& lastName)
{
    for (int i = 0; i < this->size(); i++)
    {
        if (this->students[i].getFirstName() == firstName && this->students[i].getLastName() == lastName)
        {
            this->students.erase(this->students.begin()+i);
        }
    }
}
/**
* Gets the size of roster
*
*
*
*
* @return int
*
*/
int Roster::size()
{
    return this->students.size();
}
/**
* Adds a student to roster
*
*
*
* @param Student& the student to be added
* @return none
*
*/
void Roster::add(Student& student)
{
    this->students.push_back(student);
}
/**
* Gets all the students that have a letter grade equal to what is passed in
*
*
*
* @param char the letter grade to compare to
* @return vector<Student>
*
*/
vector<Student> Roster::getStudentsWithLetterGrade(char letterGrade)
{
    vector<Student> result;
    for (int i = 0; i < this->size(); i++)
    {
        if (this->students[i].getGradeAsLetter() == letterGrade)
        {
            result.push_back(this->students[i]);
        }
    }
    return result;
}
}

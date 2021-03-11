#include "OutputCreator.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace model;
using namespace std;
namespace view
{
/**
* Constructor
*
*
*
*
* @return OutputCreator
*
*/
OutputCreator::OutputCreator()
{
    this->removedFirstName = "";
    this->removedLastName = "";
    this->output = "";
    this->gFlag = false;
    this->sfFlag = false;
    this->sgFlag = false;
    this->columnNumber = 3;
}
/**
* Creates the output for the roster
*
*
*
* @param Roster the roster to create an output of
* @return none
*
*/
void OutputCreator::makeOutput(Roster& roster)
{
    ostringstream result;
    roster.remove(this->removedFirstName, this->removedLastName);
    if (this->sgFlag)
    {
        roster.sortByGrade();
    }
    else if (this->sfFlag)
    {
        roster.sortByFirstName();
    }
    else
    {
        roster.sortByLastName();
    }
    char letterGrades[5] = {'A', 'B', 'C', 'D', 'F'};
    for (int i = 0; i < 5; i++)
    {
        vector<Student> students = roster.getStudentsWithLetterGrade(letterGrades[i]);

        if(!students.empty())
        {
            result << "Students earning a " << letterGrades[i] << ":" << endl;
            for (vector<Student>::size_type j = 0; j < students.size(); j++)
            {

                result << setw(22) << left << getOutputForStudent(students[j]);
                if ((j + 1) % this->columnNumber == 0 && (j + 1) != students.size())
                {
                    result << endl;
                }

            }
            result << endl;
        }


    }
    this->output = result.str();
}
/**
* Gets an output string for a single student
*
*
*
* @param Student the student
* @return string
*
*/
string OutputCreator::getOutputForStudent(Student student)
{
    ostringstream result;
    result << student.getFirstName() << " " << student.getLastName();
    if (this->gFlag)
    {
        result << " (" << student.getGrade() << ")";
    }

    return result.str();
}

/**
* Deconstructor
*
*
*
*
* @return none
*
*/
OutputCreator::~OutputCreator()
{
}
/**
* Gets the GFlag
*
*
*
*
* @return bool
*
*/
bool OutputCreator::getGFlag() const
{
    return this->gFlag;
}
/**
* Gets the SFFlag
*
*
*
*
* @return bool
*
*/
bool OutputCreator::getSFFlag() const
{
    return this->sfFlag;
}
/**
* Gets the SGFlag
*
*
*
*
* @return bool
*
*/
bool OutputCreator::getSGFlag() const
{
    return this->sgFlag;
}
/**
* Gets the number of columns
*
*
*
*
* @return int
*
*/
int OutputCreator::getColumnNumber() const
{
    return this->columnNumber;
}
/**
* Gets the first name to be removed
*
*
*
*
* @return string&
*
*/
const string& OutputCreator::getRemovedFirstName() const
{
    return this->removedFirstName;
}
/**
* Sets the first name to be removed
*
*
*
* @param string& the first name
* @return none
*
*/
void OutputCreator::setRemovedFirstName(const string& firstName)
{
    this->removedFirstName = firstName;
}
/**
* Gets the last name to be removed
*
*
*
*
* @return string&
*
*/
const string& OutputCreator::getRemovedLastName() const
{
    return this->removedLastName;
}
/**
* Sets the last name to be removed
*
*
*
* @param string& the last name
* @return none
*
*/
void OutputCreator::setRemovedLastName(const string& lastName)
{
    this->removedLastName = lastName;
}
/**
* Sets the GFlag
*
*
*
* @param bool the flag
* @return none
*
*/
void OutputCreator::setGFlag(bool flag)
{
    this->gFlag = flag;
}
/**
* Sets the SFFlag
*
*
*
* @param bool the flag
* @return none
*
*/
void OutputCreator::setSFFlag(bool flag)
{
    this->sfFlag = flag;
}
/**
* Sets the SGFlag
*
*
*
* @param bool the flag
* @return none
*
*/
void OutputCreator::setSGFlag(bool flag)
{
    this->sgFlag = flag;
}
/**
* Sets the number of columns
*
*
*
* @param int the column number
* @return none
*
*/
void OutputCreator::setColumnNumber(int colNumber)
{
    this->columnNumber = colNumber;
}
/**
* Gets the output
*
*
*
*
* @return string&
*
*/
const string& OutputCreator::getOutput() const
{
    return this->output;
}




}


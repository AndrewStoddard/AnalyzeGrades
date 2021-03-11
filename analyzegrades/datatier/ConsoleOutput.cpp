#include "ConsoleOutput.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "Student.h"
using namespace model;
using namespace std;
namespace datatier
{
ConsoleOutput::ConsoleOutput()
{
    this->removedFirstName = "";
    this->removedLastName = "";
    this->output = "";
    this->gFlag = false;
    this->sfFlag = false;
    this->sgFlag = false;
    this->columnNumber = 3;
}

void ConsoleOutput::makeOutput(Roster& roster)
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

string ConsoleOutput::getOutputForStudent(Student student)
{
    ostringstream result;
    result << student.getFirstName() << " " << student.getLastName();
    if (this->gFlag)
    {
        result << " (" << student.getGrade() << ")";
    }

    return result.str();
}


ConsoleOutput::~ConsoleOutput()
{
    //dtor
}

bool ConsoleOutput::getGFlag() const
{
    return this->gFlag;
}
bool ConsoleOutput::getSFFlag() const
{
    return this->sfFlag;
}
bool ConsoleOutput::getSGFlag() const
{
    return this->sgFlag;
}
int ConsoleOutput::getColumnNumber() const
{
    return this->columnNumber;
}

const string& ConsoleOutput::getRemovedFirstName() const
{
    return this->removedFirstName;
}
void ConsoleOutput::setRemovedFirstName(const string& firstName)
{
    this->removedFirstName = firstName;
}
const string& ConsoleOutput::getRemovedLastName() const
{
    return this->removedLastName;
}
void ConsoleOutput::setRemovedLastName(const string& lastName)
{
    this->removedLastName = lastName;
}
void ConsoleOutput::setGFlag(bool flag)
{
    this->gFlag = flag;
}
void ConsoleOutput::setSFFlag(bool flag)
{
    this->sfFlag = flag;
}
void ConsoleOutput::setSGFlag(bool flag)
{
    this->sgFlag = flag;
}
void ConsoleOutput::setColumnNumber(int colNumber)
{
    this->columnNumber = colNumber;
}
const string& ConsoleOutput::getOutput() const
{
    return this->output;
}




}


#include "Student.h"

namespace model
{

Student::Student()
{
    this->name = string();
    this->grade = 0;
}
Student::Student(const string& name, int grade)
{
    this->name = name;
    this->grade = grade;
}
Student::~Student()
{
    //dtor
}

const string& Student::getName() const
{
    return this->name;
}
void Student::setName(const string& name)
{
    this->name = name;
}

int Student::getGrade() const
{
    return this->grade;
}
void Student::setGrade(int grade)
{
    this->grade = grade;
}
char Student::getGradeAsLetter() {
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

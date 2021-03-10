#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

namespace model
{

class Student
{
private:
    string firstName;
    string lastName;
    int grade;

public:
    Student();
    Student(const string& firstName, const string& lastName, int grade);
    virtual ~Student();
    const string& getFirstName() const;
    const string& getLastName() const;
    void setFirstName(const string& firstName);
    void setLastName(const string& lastName);
    int getGrade() const;
    void setGrade(int grade);
    char getGradeAsLetter();
};

}

#endif // STUDENT_H

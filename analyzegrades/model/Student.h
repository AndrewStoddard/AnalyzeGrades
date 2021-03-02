#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

namespace model
{

class Student
{
    private:
        string name;
        int grade;

    public:
        Student();
        Student(const string& name, int grade);
        virtual ~Student();
        const string& getName() const;
        void setName(const string& name);
        int getGrade() const;
        void setGrade(int grade);
};

}

#endif // STUDENT_H

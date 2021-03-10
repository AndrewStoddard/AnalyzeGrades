#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
#include <vector>

using namespace std;
namespace model {

class Roster
{
    public:
        Roster();
        virtual ~Roster();
        void add(Student& student);
        vector<Student> getStudentsWithLetterGrade(char letterGrade);
        void sortByGrade();
        void sortByFirstName();
        void sortByLastName();
        int size();

    protected:

    private:
        vector<Student> students;
};

}



#endif // ROSTER_H

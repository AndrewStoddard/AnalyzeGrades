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
        const vector<Student> getStudents() const;
        void add(Student& student);
        void remove(Student& student);

    protected:

    private:
        vector<Student> students;
};

}



#endif // ROSTER_H

#ifndef ROSTER_H
#define ROSTER_H
#include "Student.h"
#include <vector>
#include "string"
using namespace std;
namespace model
{
class Roster
{
private:
    vector<Student> students;
public:
    Roster();
    virtual ~Roster();
    void add(Student& student);
    vector<Student> getStudentsWithLetterGrade(char letterGrade);
    void sortByGrade();
    void sortByFirstName();
    void sortByLastName();
    int size();
    void remove(const string& firstName, const string& lastName);
};
}
#endif // ROSTER_H

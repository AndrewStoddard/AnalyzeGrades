#include "Roster.h"
#include <vector>
#include "Student.h"
#include <algorithm>
#include <iostream>

using namespace std;

namespace model {

Roster::Roster()
{
    //ctor
}

Roster::~Roster()
{
    //dtor
}
void Roster::sortByGrade() {
    sort(this->students.begin(), this->students.end(), [](Student a, Student b){
        return a.getGrade() > b.getGrade();
    });
}
void Roster::sortByFirstName() {

}
void Roster::sortByLastName() {

}

int Roster::size() {
    return this->students.size();
}

void Roster::add(Student& student) {
    this->students.push_back(student);
}

vector<Student> Roster::getStudentsWithLetterGrade(char letterGrade) {
    vector<Student> result;
    for (int i = 0; i < this->size(); i++) {

        if (this->students[i].getGradeAsLetter() == letterGrade) {
            result.push_back(this->students[i]);
        }
    }
    return result;
}

}


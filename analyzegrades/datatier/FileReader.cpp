#include "FileReader.h"
#include <iostream>
#include <fstream>
#include<sstream>


using namespace model;
using namespace std;
namespace datatier
{
FileReader::FileReader()
{
    this->infile = "";
}

FileReader::~FileReader()
{
    //dtor
}

vector<Student> FileReader::readFile() {
    string line;
    vector<Student> students;
    ifstream studentFileStream(this->infile);
    while (getline(studentFileStream, line)) {
        Student student = this->readStudentFromCSVString(line);
        students.push_back(student);
    }
    return students;
}

Student FileReader::readStudentFromCSVString(string& line) {
    vector<string> items;
    stringstream csvStream(line);
    while(csvStream.good()) {
      string item;
      getline(csvStream, item, ',');
      item[0] = toupper(item[0]);
      items.push_back(item);
   }
   Student student(items[0] + " " + items[1], stoi(items[2]));
   return student;
}

const string& FileReader::getInfile() const {
    return this->infile;
}
void FileReader::setInfile(const string& infile) {
    this->infile = infile;
}

}



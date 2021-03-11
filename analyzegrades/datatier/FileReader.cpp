#include "FileReader.h"
#include <iostream>
#include <fstream>
#include<sstream>
using namespace model;
using namespace std;
namespace datatier
{
/**
* Constructor
*
*
*
*
* @return FileReader
*
*/
FileReader::FileReader()
{
    this->infile = "";
}
/**
* Deconstructor
*
*
*
*
*
*
*/
FileReader::~FileReader()
{
}
/**
* Reads the file into a Roster
*
*
*
*
* @return Roster
*
*/
Roster FileReader::readFile()
{
    string line;
    Roster roster = Roster();
    ifstream studentFileStream(this->infile);
    while (getline(studentFileStream, line))
    {
        Student student = this->readStudentFromCSVString(line);
        roster.add(student);
    }
    return roster;
}
/**
* Reads a string into a Student
*
*
*
* @param string& the string to be read
* @return Student
*
*/
Student FileReader::readStudentFromCSVString(string& line)
{
    vector<string> items;
    stringstream csvStream(line);
    while(csvStream.good())
    {
        string item;
        getline(csvStream, item, ',');
        item[0] = toupper(item[0]);
        items.push_back(item);
    }
    Student student(items[0], items[1], stoi(items[2]));
    return student;
}
/**
* Gets the infile
*
*
*
*
* @return string&
*
*/
const string& FileReader::getInfile() const
{
    return this->infile;
}
/**
* Sets the infile
*
*
*
* @param string& the infile
* @return none
*
*/
void FileReader::setInfile(const string& infile)
{
    this->infile = infile;
}
}

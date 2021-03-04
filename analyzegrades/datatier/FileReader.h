#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>
#include "../model/Student.h"
using namespace model;
using namespace std;
namespace datatier
{
class FileReader
{
public:
    FileReader();
    virtual ~FileReader();

    const string& getInfile() const;
    void setInfile(const string& infile);
    Student readStudentFromCSVString(string& line);
    vector<Student> readFile();

protected:

private:
    string infile;
};

}

#endif // FILEREADER_H

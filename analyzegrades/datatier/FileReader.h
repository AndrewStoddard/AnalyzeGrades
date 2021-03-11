#ifndef FILEREADER_H
#define FILEREADER_H
#include <vector>
#include <string>
#include "Roster.h"
#include "Student.h"
using namespace model;
using namespace std;
namespace datatier
{
class FileReader
{
private:
    string infile;
public:
    FileReader();
    virtual ~FileReader();
    const string& getInfile() const;
    void setInfile(const string& infile);
    Student readStudentFromCSVString(string& line);
    Roster readFile();
};
}
#endif // FILEREADER_H

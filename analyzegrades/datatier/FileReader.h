#ifndef FILEREADER_H
#define FILEREADER_H

#include <string>
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

protected:

private:
    string infile;
};

}

#endif // FILEREADER_H

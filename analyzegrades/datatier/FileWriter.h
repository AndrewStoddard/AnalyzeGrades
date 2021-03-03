#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <string>
using namespace std;
namespace datatier
{
class FileWriter
{
public:
    FileWriter();
    virtual ~FileWriter();

protected:

private:
    string outfile;
    bool autoOverwrite;

};
}


#endif // FILEWRITER_H

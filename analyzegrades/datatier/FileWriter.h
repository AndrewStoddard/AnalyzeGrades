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
    const string& getOutfile() const;
    void setOutfile(const string& outfile);
    void setAutoOverwrite(bool flag);

protected:

private:
    string outfile;
    bool autoOverwrite;

};
}


#endif // FILEWRITER_H

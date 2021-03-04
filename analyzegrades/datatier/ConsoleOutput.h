#ifndef CONSOLEOUTPUT_H
#define CONSOLEOUTPUT_H

#include <string>
using namespace std;
namespace datatier
{
class ConsoleOutput
{
public:
    ConsoleOutput();
    virtual ~ConsoleOutput();
    const string& getRemovedFirstName() const;
    void setRemovedFirstName(const string& firstName);
    const string& getRemovedLastName() const;
    void setRemovedLastName(const string& lastName);
    void setGFlag(bool flag);
    void setSFFlag(bool flag);
    void setSGFlag(bool flag);
    bool getGFlag() const;
    bool getSFFlag() const;
    bool getSGFlag() const;
    int getColumnNumber() const;


    void setColumnNumber(int colNumber);
    const string& getOutput() const;

protected:

private:
    int columnNumber;
    string output;
    bool gFlag;
    bool sfFlag;
    bool sgFlag;
    string removedFirstName;
    string removedLastName;
};
}


#endif // CONSOLEOUTPUT_H

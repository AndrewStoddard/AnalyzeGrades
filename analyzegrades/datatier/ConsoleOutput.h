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

protected:

private:
    int columnNumber;
    string output;
};
}


#endif // CONSOLEOUTPUT_H

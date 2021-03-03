#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H

namespace datatier
{
class ArgumentParser
{
private:
    int argc;
    char* argv[];


public:
    ArgumentParser(char* argv[], int argc);
    virtual ~ArgumentParser();
    void parse();
};
}


#endif // ARGUMENTPARSER_H

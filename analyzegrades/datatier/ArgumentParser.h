#ifndef ARGUMENTPARSER_H
#define ARGUMENTPARSER_H
#include "AnalyzeGradeController.h"
using namespace controller;
namespace datatier
{
class ArgumentParser
{
private:
    int argc;
    char** argv;
    AnalyzeGradeController gradeController;


public:
    ArgumentParser(char**& argv, int argc);
    virtual ~ArgumentParser();
    bool parse();
};
}


#endif // ARGUMENTPARSER_H

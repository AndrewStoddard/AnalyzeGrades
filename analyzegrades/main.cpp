#include <iostream>
#include "ArgumentParser.h"
#include "AnalyzeGradeController.h"
#include <vector>
#include "model/Student.h"
#include "Roster.h"
using namespace model;
using namespace controller;
using namespace datatier;
using namespace std;

int main(int argc, char* argv[])
{

    ArgumentParser parser(argv, argc);
    bool result = parser.parse();
    AnalyzeGradeController controller = parser.getGradeController();

    if(result)
    {
        controller.work();

    }
    else
    {
        controller.printHelp();
    }

    return 0;
}

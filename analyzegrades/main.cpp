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

    if(result) {
        Roster roster = controller.getFileReader().readFile();

        controller.getConsoleOutput().makeOutput(roster);
        cout << controller.getConsoleOutput().getOutput() << endl;
        if(!controller.getFileWriter().getOutfile().empty()) {

            //controller.getFileWriter().writeToFile(output);
            cout << "Wrote to File" << endl;
        }

    }

    return 0;
}

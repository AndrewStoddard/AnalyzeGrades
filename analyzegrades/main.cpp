#include <iostream>
#include "ArgumentParser.h"
#include "AnalyzeGradeController.h"
using namespace controller;
using namespace datatier;
using namespace std;

int main(int argc, char* argv[])
{

    ArgumentParser parser(argv, argc);
    bool result = parser.parse();
    AnalyzeGradeController controller = parser.getGradeController();

    if(result) {
        cout << controller.getConsoleOutput().getRemovedFirstName() << endl;
        cout << controller.getConsoleOutput().getRemovedLastName() << endl;
        cout << controller.getConsoleOutput().getGFlag() << endl;
        cout << controller.getConsoleOutput().getSFFlag() << endl;
        cout << controller.getConsoleOutput().getSGFlag() << endl;
        cout << controller.getConsoleOutput().getColumnNumber() << endl;
        cout << controller.getFileReader().getInfile() << endl;
        cout << controller.getFileWriter().getOutfile() << endl;


    }

    return 0;
}

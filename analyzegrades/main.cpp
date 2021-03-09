#include <iostream>
#include "ArgumentParser.h"
#include "AnalyzeGradeController.h"
#include <vector>
#include "model/Student.h"
using namespace controller;
using namespace datatier;
using namespace std;

int main(int argc, char* argv[])
{

    ArgumentParser parser(argv, argc);
    bool result = parser.parse();
    AnalyzeGradeController controller = parser.getGradeController();

    if(result) {
        vector<Student> students = controller.getFileReader().readFile();
        string output = to_string(students.size());

        output.append("\n");
        for(vector<Student>::size_type i = 0; i < students.size(); i++) {
            output.append(students[i].getName());
            output.append(": ");
            output.append(to_string(students[i].getGrade()));
            output.append("\n");
        }
        cout << output << endl;
        if(!controller.getFileWriter().getOutfile().empty()) {

            controller.getFileWriter().writeToFile(output);
            cout << "Wrote to File" << endl;
        }
    }

    return 0;
}

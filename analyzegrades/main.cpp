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
        cout << students.size() << endl;
        for(vector<Student>::size_type i = 0; i < students.size(); i++) {
            cout << students[i].getName() << ": " << students[i].getGrade() << endl;
        }
    }

    return 0;
}

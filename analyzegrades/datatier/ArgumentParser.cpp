#include "ArgumentParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FileReader.h"
#include "FileWriter.h"
#include "ConsoleOutput.h"
#include <algorithm>
#include "AnalyzeGradeController.h"

using namespace controller;

using namespace std;

namespace datatier
{
ArgumentParser::ArgumentParser(char**& argv, int argc)
{
    this->argc = argc;
    this->argv = argv;
    this->gradeController = AnalyzeGradeController();

}

ArgumentParser::~ArgumentParser()
{
    //dtor
}

const AnalyzeGradeController& ArgumentParser::getGradeController() const {
    return this->gradeController;
}


bool ArgumentParser::parse(){
    bool cFlag = false;
    bool rFlag = false;
    FileReader fileReader = FileReader();
    FileWriter fileWriter = FileWriter();
    ConsoleOutput consoleOutput = ConsoleOutput();
    if(this->argc < 2) {
        return false;
    }
    for (int i = 1; i < this->argc; i++){
        string arg(this->argv[i]);
        if (cFlag) {
            if (arg[0] == '-' || !all_of(arg.begin(), arg.end(), ::isdigit)) {
                cout << "No column amount specified" << endl;
                return false;
            }
            consoleOutput.setColumnNumber(stoi(arg));
            cFlag = false;
        } else if (rFlag) {
            if (arg[0] == '-') {
                cout << "No Name to Remove Specified" << endl;
                return false;
            }
            if (consoleOutput.getRemovedFirstName().empty()) {
                consoleOutput.setRemovedFirstName(arg);
            } else {
                consoleOutput.setRemovedLastName(arg);
                rFlag = false;
            }
        } else if (arg[0] == '-') {
            if (arg == "--help"){
                return false;
            } else if (arg == "-c"){
                cFlag = true;
            } else if (arg == "-g"){
                consoleOutput.setGFlag(true);
            } else if (arg == "-o"){
                fileWriter.setAutoOverwrite(true);
            } else if(arg == "-r"){
                rFlag = true;
            } else if(arg == "-sf"){
                if(consoleOutput.getSGFlag()){
                    cout << "Cannot specify both -sg and -sf" << endl;
                    return false;
                }
                consoleOutput.setSFFlag(true);
            } else if(arg == "-sg"){
                if(consoleOutput.getSFFlag()){
                    cout << "Cannot specify both -sf and -sg" << endl;
                    return false;
                }
                consoleOutput.setSGFlag(true);
            } else {
                return false;
            }
        } else {
            if (fileReader.getInfile().empty()) {
                ifstream infile(arg);
                if (infile.good()) {
                    fileReader.setInfile(arg);
                } else {
                    cout << "Input File Not Found" << endl;
                    return false;
                }

            } else if (fileWriter.getOutfile().empty()) {
                fileWriter.setOutfile(arg);
            } else {
                cout << "No Input File Specified" << endl;
                return false;
            }
        }



    }
    if (fileReader.getInfile().empty()) {
            return false;
    }
    gradeController.setFileReader(fileReader);
    gradeController.setFileWriter(fileWriter);
    gradeController.setConsoleOutput(consoleOutput);
    return true;

}


}

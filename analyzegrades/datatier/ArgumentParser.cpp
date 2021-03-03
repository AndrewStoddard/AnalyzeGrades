#include "ArgumentParser.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FileReader.h"
#include "FileWriter.h"
#include "ConsoleOutput.h"

using namespace std;

namespace datatier
{
ArgumentParser::ArgumentParser(char**& argv, int argc)
{
    this->argc = argc;
    this->argv = argv;
    this->gradeController = new AnalyzeGradeController();

}

ArgumentParser::~ArgumentParser()
{
    //dtor
}


bool ArgumentParser::parse()){
    bool cFlag = false;
    bool rFlag = false;
    FileReader fileReader();
    FileWriter fileWriter();
    ConsoleOutput consoleOutput();
    for (int i = 1; i < argc; i++){
        string arg(argv[i]);
        if (cFlag) {
            consoleOutput.setColNumber(stoi(arg));
            cFlag = false;
        } else if (rFlag) {
            if (arg[0] == "-") {
                return false;
            }
            if (consoleOutput.getRemovedFirstName().empty()) {
                consoleOutput.setRemovedFirstName(arg);
            } else {
                consoleOutput.setRemovedLastName(arg);
                rFlag = false;
            }
        } else if (arg[0] == "-") {
            if (arg == "--help"){
                return false;
            } else if (arg == "-c"){
                cFlag = true;
            } else if (arg == "-g"){
                consoleOutput.setGFlag(true);
            } else if (arg == "-o"){
                fileWriter.setAutoOverwrit(true);
            } else if(arg == "-r"){
                rFlag = true;
            } else if(arg == "-sf"){
                consoleOutput.setSFFlag(true);
            } else if(arg == "-sg"){
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
                    return false;
                }

            } else if (fileReader.getOutfile.empty()) {
                fileReader.setOutFile(arg);
            } else {
                return false;
            }
        }
        gradeController.setFileReader(fileReader);
        gradeController.setFileWriter(fileWriter);
        gradeController.setConsoleOutput(consoleOutput);
        return true;
    }

}

}

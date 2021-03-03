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
    string inputFile;
    string outputFile;
    int colNumber;
    string firstName;
    string lastName;
    for (int i = 1; i < argc; i++){
        string arg(argv[i]);
        if (cFlag) {
            colNumber = stoi(arg);
            cFlag = false;
        } else if (rFlag) {
            if (arg[0] == "-") {
                return false;
            }
            if (firstName.empty()) {
                firstName = arg;
            } else {
                lastName = arg;
                rFlag = false;
            }
        } else if (arg[0] == "-") {
            if (arg == "--help"){
                return false;
            } else if (arg == "-c"){
                cFlag = true;

            } else if (arg == "-g"){

            } else if (arg == "-o"){

            } else if(arg == "-r"){
                rFlag = true;

            } else if(arg == "-sf"){

            } else if(arg == "-sg"){

            } else {
                return false;
            }
        } else {
            if (inputFile.empty()) {
                ifstream infile(arg);
                if (infile.good()) {
                    inputFile == arg;
                } else {
                    return false;
                }

            } else if (outputFile.empty()) {
                outputFile == arg;
            } else {
                return false;
            }
        }
    }
}

}

#include "AnalyzeGradeController.h"


namespace controller
{
AnalyzeGradeController::AnalyzeGradeController()
{

}

AnalyzeGradeController::~AnalyzeGradeController()
{
    //dtor
}


void AnalyzeGradeController::setConsoleOutput(const ConsoleOutput consoleOutput) {
    this->consoleOutput = consoleOutput;
}
void AnalyzeGradeController::setFileReader(const FileReader fileReader) {
    this->fileReader = fileReader;
}
void AnalyzeGradeController::setFileWriter(const FileWriter fileWriter) {
    this->fileWriter = fileWriter;
}

const ConsoleOutput& AnalyzeGradeController::getConsoleOutput() const {
    return this->consoleOutput;
}
FileReader AnalyzeGradeController::getFileReader() const {
    return this->fileReader;
}
const FileWriter& AnalyzeGradeController::getFileWriter() const {
    return this->fileWriter;
}


}

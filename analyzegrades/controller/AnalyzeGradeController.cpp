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


void AnalyzeGradeController::setConsoleOutput(ConsoleOutput consoleOutput) {
    this->consoleOutput = consoleOutput;
}
void AnalyzeGradeController::setFileReader(const FileReader fileReader) {
    this->fileReader = fileReader;
}
void AnalyzeGradeController::setFileWriter(const FileWriter fileWriter) {
    this->fileWriter = fileWriter;
}


ConsoleOutput AnalyzeGradeController::getConsoleOutput() {
    return this->consoleOutput;
}
FileReader AnalyzeGradeController::getFileReader() const {
    return this->fileReader;
}
FileWriter AnalyzeGradeController::getFileWriter() const {
    return this->fileWriter;
}


}

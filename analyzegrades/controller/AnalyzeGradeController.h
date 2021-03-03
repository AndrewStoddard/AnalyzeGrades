#ifndef ANALYZEGRADECONTROLLER_H
#define ANALYZEGRADECONTROLLER_H

#include "FileReader.h"
#include "FileWriter.h"
#include "ConsoleOutput.h"
using namespace datatier;

namespace controller
{

class AnalyzeGradeController
{
private:
    ConsoleOutput consoleOutput;
    FileReader fileReader;
    FileWriter fileWriter;

public:
    AnalyzeGradeController();
    virtual ~AnalyzeGradeController();

    void setConsoleOutput(const ConsoleOutput& consoleOutput);
    void setFileReader(const FileReader& fileReader);
    void setFileWriter(const FileWriter& fileWriter);

    ConsoleOutput& getConsoleOutput() const;
    FileReader& getFileReader() const;
    FileWriter& getFileWriter() const;



};

}

#endif

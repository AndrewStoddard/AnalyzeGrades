#ifndef ANALYZEGRADECONTROLLER_H
#define ANALYZEGRADECONTROLLER_H
#include "FileReader.h"
#include "FileWriter.h"
#include "OutputCreator.h"
using namespace view;
using namespace datatier;
namespace controller
{
class AnalyzeGradeController
{
private:
    OutputCreator outputCreator;
    FileReader fileReader;
    FileWriter fileWriter;
public:
    AnalyzeGradeController();
    virtual ~AnalyzeGradeController();
    void setOutputCreator(const OutputCreator outputCreator);
    void setFileReader(const FileReader fileReader);
    void setFileWriter(const FileWriter fileWriter);
    OutputCreator getOutputCreator();
    FileReader getFileReader() const;
    FileWriter getFileWriter() const;
    void work();
    void printHelp();
};
}
#endif

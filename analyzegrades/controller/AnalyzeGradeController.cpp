#include "AnalyzeGradeController.h"
#include <iostream>
#include <iomanip>
#include "Roster.h"
using namespace model;
namespace controller
{
/**
* Constructor
*
*
*
*
*
*
*/
AnalyzeGradeController::AnalyzeGradeController()
{
}
/**
* Deconstructor
*
*
*
*
*
*
*/
AnalyzeGradeController::~AnalyzeGradeController()
{
}
/**
* Performs the necessary steps to generate and
* write output to console and
* file (if applicable)
*
*
* @return none
*
*/
void AnalyzeGradeController::work()
{
    Roster roster = this->fileReader.readFile();
    this->outputCreator.makeOutput(roster);
    string output = this->outputCreator.getOutput();
    cout << output << endl;
    if(!this->fileWriter.getOutfile().empty())
    {
        this->fileWriter.writeToFile(output);
    }
}
/**
* Prints a help message in console.
*
*
*
*
* @return none
*
*/
void AnalyzeGradeController::printHelp()
{
    cout << "Usage:  analyzegrades infile [outfile] [options]"
         << endl
         << "Performs a simple grade analysis of the students and grades contained in infile."
         << endl
         << setw(22) << left
         << "   infile" << "The input file to analyze the grades." << endl
         << setw(22) << left
         << "   outfile" << "The output file to write the output to." << endl
         << setw(22) << left
         << "options:" << endl
         << setw(22) << left
         << "   --help" << "Displays this usage statement." << endl
         << setw(22) << left
         << "   -c <number>" << "Changes the number of output columns to the number specified.The default number of columns is 3." << endl
         << setw(22) << left
         << "   -g" << "Displays student grade with the output." << endl
         << setw(22) << left
         << "   -o" << "Automatically overwrites the outfile without prompting, if the outfile already exists. If this option is not specified and the outfile exists the user will be prompted on whether to overwrite the outfile." << endl
         << setw(22) << left
         << "   -r <first last>" << "Removes the specified student (case insensitive) from the output.  E.g., -r john doe would delete john doe from the output." << endl
         << setw(22) << left
         << "   -sf" << "Displays the output in alphabetic order by student’s first name.The default order is by student’s last name." << endl
         << setw(22) << left
         << "   -sg" << "Displays the output with the student grade displayed and sorted by the student’s grade in descending order. " << endl;
}
/**
* Sets the outputCreater to passed in value
*
*
*
*@param OutputCreator the output creator
*@return none
*
*/
void AnalyzeGradeController::setOutputCreator(const OutputCreator outputCreator)
{
    this->outputCreator = outputCreator;
}
/**
* Sets the fileReader to the passed value
*
*
*
* @param FileReader the file reader
* @return none
*
*/
void AnalyzeGradeController::setFileReader(const FileReader fileReader)
{
    this->fileReader = fileReader;
}
/**
* Sets the fileWriter to the passed value
*
*
*
* @param FileWriter the file writer
* @return none
*
*/
void AnalyzeGradeController::setFileWriter(const FileWriter fileWriter)
{
    this->fileWriter = fileWriter;
}
/**
* Gets the outputCreator
*
*
*
*
* @return OutputCreator
*
*/
OutputCreator AnalyzeGradeController::getOutputCreator()
{
    return this->outputCreator;
}
/**
* Gets the fileReader
*
*
*
*
* @return FileReader
*
*/
FileReader AnalyzeGradeController::getFileReader() const
{
    return this->fileReader;
}
/**
* Gets the fileWriter
*
*
*
*
* @return FileWriter
*
*/
FileWriter AnalyzeGradeController::getFileWriter() const
{
    return this->fileWriter;
}
}

#include "FileWriter.h"
namespace datatier
{
FileWriter::FileWriter()
{
    this->autoOverwrite = false;
    this->outfile = "";
}

FileWriter::~FileWriter()
{
    //dtor
}

const string& FileWriter::getOutfile() const {
    return this->outfile;
}
void FileWriter::setOutfile(const string& outfile) {
    this->outfile = outfile;
}
void FileWriter::setAutoOverwrite(bool flag) {
    this->autoOverwrite = flag;
}

}

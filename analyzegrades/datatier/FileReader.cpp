#include "FileReader.h"
namespace datatier
{
FileReader::FileReader()
{
    this->infile = "";
}

FileReader::~FileReader()
{
    //dtor
}

const string& FileReader::getInfile() const {
    return this->infile;
}
void FileReader::setInfile(const string& infile) {
    this->infile = infile;
}

}



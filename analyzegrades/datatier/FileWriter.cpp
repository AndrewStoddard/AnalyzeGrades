#include "FileWriter.h"
#include <fstream>
#include <iostream>
using namespace std;
namespace datatier
{
/**
* Constructor
*
*
*
*
* @return FileWriter
*
*/
FileWriter::FileWriter()
{
    this->autoOverwrite = false;
    this->outfile = "";
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
FileWriter::~FileWriter()
{
}
/**
* Asks the user if they want to override the outfile
*
*
*
*
* @return bool true if override false otherwise
*
*/
bool FileWriter::askOverride()
{
    cout << "Are you sure you want to override " << this->outfile <<"?";
    while (true)
    {
        string response;
        cin >> response;
        cout << endl;

        if (response.empty()) continue;
        switch (toupper( response[ 0 ] ))
        {
        case 'Y':
            return true;
        case 'N':
            return false;
        }
        cout << "Are you sure you want to override " << this->outfile <<"?";
    }
}
/**
* Writes output to file
*
*
*
* @param string& the output to be written
* @return none
*
*/
void FileWriter::writeToFile(const string& output)
{
    ifstream outfileIStream(this->outfile);
    bool exists = outfileIStream.good();
    ofstream outfileOStream(this->outfile);

    if(exists)
    {
        if (this->autoOverwrite || askOverride())
        {
            outfileOStream << output;
        }
        else
        {
            cout << "File was not written" << endl;
        }
    }
    else
    {
        outfileOStream << output;
    }

}
/**
* Gets the outfile
*
*
*
*
* @return string&
*
*/
const string& FileWriter::getOutfile() const
{
    return this->outfile;
}
/**
* Sets the outfile
*
*
*
* @param string& outfile
* @return none
*
*/
void FileWriter::setOutfile(const string& outfile)
{
    this->outfile = outfile;
}
/**
* Sets overwrite flag
*
*
*
* @param bool flag to change too
* @return none
*
*/
void FileWriter::setAutoOverwrite(bool flag)
{
    this->autoOverwrite = flag;
}

}

#include "FileWriter.h"
#include <fstream>
#include <iostream>
using namespace std;
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
bool FileWriter::askOverride() {
    cout << "Are you sure you want to override " << this->outfile <<"?";
    while (true) {
        string response;
        cin >> response;
        cout << endl;

        if (response.empty()) continue;
        switch (toupper( response[ 0 ] ))
        {
            case 'Y': return true;
            case 'N': return false;
        }
        cout << "Are you sure you want to override " << this->outfile <<"?";
    }
  }

void FileWriter::writeToFile(const string& output) {
    ifstream outfileIStream(this->outfile);
    bool exists = outfileIStream.good();
    ofstream outfileOStream(this->outfile);

    if(exists) {
        if (this->autoOverwrite || askOverride()){
            outfileOStream << output;
        } else {
            cout << "File was not written" << endl;
        }
    } else {
        outfileOStream << output;
    }

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

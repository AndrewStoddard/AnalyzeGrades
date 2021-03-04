#include "ConsoleOutput.h"
namespace datatier
{
ConsoleOutput::ConsoleOutput()
{
    this->removedFirstName = "";
    this->removedLastName = "";
    this->output = "";
    this->gFlag = false;
    this->sfFlag = false;
    this->sgFlag = false;
    this->columnNumber = 3;
}

ConsoleOutput::~ConsoleOutput()
{
    //dtor
}

bool ConsoleOutput::getGFlag() const {
    return this->gFlag;
}
bool ConsoleOutput::getSFFlag() const {
    return this->sfFlag;
}
bool ConsoleOutput::getSGFlag() const {
    return this->sgFlag;
}
int ConsoleOutput::getColumnNumber() const {
    return this->columnNumber;
}

const string& ConsoleOutput::getRemovedFirstName() const {
    return this->removedFirstName;
}
void ConsoleOutput::setRemovedFirstName(const string& firstName) {
    this->removedFirstName = firstName;
}
const string& ConsoleOutput::getRemovedLastName() const {
    return this->removedLastName;
}
void ConsoleOutput::setRemovedLastName(const string& lastName) {
    this->removedLastName = lastName;
}
void ConsoleOutput::setGFlag(bool flag) {
    this->gFlag = flag;
}
void ConsoleOutput::setSFFlag(bool flag) {
    this->sfFlag = flag;
}
void ConsoleOutput::setSGFlag(bool flag) {
    this->sgFlag = flag;
}
void ConsoleOutput::setColumnNumber(int colNumber) {
    this->columnNumber = colNumber;
}
const string& ConsoleOutput::getOutput() const {
    return this->output;
}


}


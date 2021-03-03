#include "ArgumentParser.h"
#include <iostream>

using namespace std;
namespace datatier
{
ArgumentParser::ArgumentParser(char* argv[], int argc)
{
    this->argc = argc;
    this->argv = argv;
    cout << argc << endl;
    for (int i = 1; i < argc; i++){
        cout << argv[i] << endl;
    }
}

ArgumentParser::~ArgumentParser()
{
    //dtor
}

void ArgumentParser::parse()
{
    cout << argc << endl;
    for (int i = 1; i < argc; i++){
        cout << argv[i] << endl;
    }
}

}

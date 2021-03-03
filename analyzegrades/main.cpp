#include <iostream>
#include "ArgumentParser.h"
using namespace datatier;
using namespace std;

int main(int argc, char* argv[])
{
    cout << argc << endl;
    for (int i = 1; i < argc; i++){
        cout << argv[i] << endl;
    }
    ArgumentParser parser(argv, argc);

    return 0;
}

#include "../../common.hpp"
using namespace AshokProgramming;

int main(int argc, char *argv[])
{
    while(1) {
        string line;
        cout << "Enter q/Q to quit OR input a number for execution: ";
        getline(cin, line);
        if(line == "q" || line == "Q") return 0;
        int num = stoi(line);

        cout << "Entered value is " << num << endl;
    }
    return 0;
}
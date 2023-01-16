#include <iostream>
#include "calculator.h"
using namespace std;
int main(int argc,char** argv) {
    if(argc!=3)
    {
        cerr<<"Invalid arguments <int> <int>.\n";
        return 0;
    }
    string s;
    string sval;
    int joell=atoi(argv[1]);
    int noor=atoi(argv[2]);

    Calculator c(joell,noor);

    cout <<"[1] New observation"<<endl;
    cout <<"[2] Print observation"<<endl;
    cout <<"[3] Expected value vector"<<endl;
    cout <<"[4] Covariance matrix"<<endl;
    cout <<"[5] Exit"<<endl;
    c.choice();

    return 0;
}

//
// Created by D2022 on 13/11/2022.
//

#ifndef HW1_CALCULATOR_H
#define HW1_CALCULATOR_H
#include <string>
using namespace std;
class Calculator
{
private:
    int t ,numt,current,avgindex,size,tnamenum,current2;
//t=memad,numt=nummemad
    string* tname;
    double* avgarr;//the array of averages
    int* darrSize;
    double** darr;//doublearray
public:
    //constructor that gets number of ttsbit and the max number of ttsbit
    Calculator(int t,int numt);
    //function that takes observation name and values
    void func1();
    //function that checks if the observation name is existed or valid
    void func2();
    //function that calculates the vector expected value
    void func3();
    //function that calculates the covariance of the matrix
    void func4();
    double* value_convert(string value);
    void choice() ;
};


#endif //HW1_CALCULATOR_H

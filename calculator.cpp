//
// Created by D2022 on 15/11/2022.
//
#include <iostream>
#include "calculator.h"
#include <cmath>

using namespace std;
string name;
string val;

///////////////////////////////////////////////////
// constructor for the double array and the average array and the things that i need in the program
Calculator::Calculator(int t,int numt){
    this->t=t;
    this->numt=numt;
    this->avgindex=0;
    this->current=0;
    this->tname=new string[numt];//string array to save the names
    darr=new double*[t];//double array to save the vectors
    darrSize=new int[t];//array to save the size of every vector
    this->size=10;//start size (in functions if i needed more size i multiplied by 2)
    this->avgarr=new double[size];// to save the mean in it
    this->tnamenum=0;//number of names i have in the string array
    this->current2=0;//to calculate how much vectors we have
    for(int i=0;i<t;i++)//started the average array by zero values
    {
        avgarr[i]=0;
    }
}

///////////////////////////////////////////////////
//function that converts string to double , i saved the number of the numbers that the user entered in the first index
double* Calculator::value_convert(string value)
{
    int ind=0,point=1;
    string s;
    double* convert=new double[t+1];
    convert[0]=0;
    for (int i = 0; i < value.length(); i++) {
        if ((value[i] <= '9' && value[i] >= '0')) {
            s += value[i];
        }
        if (value[i] == '.' && (value[i + 1] <= '9' && value[i + 1] >= '0')) {
            s += value[i];
        }
        if (value[i] == ' '  && (value[i + 1] <= '9' && value[i + 1] >= '0')) {//if the current is . and the next index is number (if theres .. or . and something else)
            convert[0]++;
            convert[point] = atof(s.c_str());
            s = "";
           // darr[current][ind] = convert[point];
            ind++;
            point++;
        }
        if (i == (value.length() - 1)) {
            //darr[current][ind] = convert[point++];
            ind++;
        }
        if(i==(value.length()-1))//for the last value
        {
            convert[0]++;
            convert[point] = atof(s.c_str());
            s = "";
            // darr[current][ind] = convert[point];
            ind++;
            point++;
        }
    }
    return convert;
}

///////////////////////////////////////////////////
// function that saves the name and value of the vectors
void Calculator::func1() {
    cout << "Enter observation name:"<<endl;
    cin >> name;
    tname[tnamenum]="";
    tname[tnamenum] =name;//saving the name in a string array
    tnamenum++;
    cout << "Enter observation values:"<<endl;
    cin.ignore();
    getline(cin,val);
    // i saved the array length in v[0] when i converted the string to double array
    double *v = value_convert(val);
    auto* v2=new double[t];
    for(int vv=0;vv<t;vv++)
    {
        v2[vv]=0;
    }
    for(int j=0;j< ((int) v[0]) ;j++)
    {
        v2[j]=v[j+1];
    }

    darrSize[avgindex]=((int) v[0]);//darr size to save the length of every array
    int found = -1;
    for (int i = 0; i <tnamenum; i++) {
        if (name == tname[i]) {
            found = i;
            darr[i] = v2;
            current2++;
        }
    }
    if (found == -1) {
            avgindex++;
            tname[current] = name;
            darr[current] = v2;
            current++;
            current2++;
    }
    if (v[0] != t ) {
        cerr << "Invalid observation.\n";
        delete[] v2;
    }
    this->choice();
}



///////////////////////////////////////////////////
// function that prints the value of the vector if the vector saved in the memory
void Calculator::func2(){
    cout << "Enter observation name:"<<endl;
    cin >> name;
    int flag=-1;
    for(int i=0;i<tnamenum+1;i++)
    {
        if(name == tname[i])
        {
            flag=1;
            cout << name <<" = [";
            for(int j=0;j<t;j++)
            {

                cout << " " << darr[i][j] ;
            }
            cout << "]" << endl;
            break;
        }
        else
            continue;
    }
    if(flag==-1)
    {
        cerr << "Invalid or nonexistent observation.\n";
    }
    this->choice();

}

///////////////////////////////////////////////////
//function that calculates the Mean
void Calculator::func3(){
    float sum=0;
    if(darr[0] == nullptr)
    {
        cerr << "Empty calculator.\n" << endl;
        this->choice();
        exit(-1);
    }
    else{
        for(int i=0;i<t;i++)
        {
            for(int j=0;j<current2;j++)
            {
                sum+=((float)darr[j][i]);
            }
            avgarr[i]=sum/((float)current2);
            sum=0;

        }
        cout<<"mean = [";//printing the results
        for(int k=0;k<t;k++)
        {
            cout<<" " << ((float) avgarr[k]);
        }
        cout<<"]"<<endl;
    }
    this->choice();
}

///////////////////////////////////////////////////
void Calculator::func4(){
    float s;
    if(darr[0] == nullptr)
    {
        cerr << "Empty calculator.\n" << endl;
        this->choice();
        exit(-1);
    }
    cout<<"cov = ["<<endl;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<t;j++)
        {
            s=0;
            for(int k=0;k<current2;k++)
            {
                s+=(float)((darr[k][i] - avgarr[i]) * (darr[k][j] - avgarr[j]));
            }
            if(current2==1)//if theres one vector
            {
                cout << " " <<s;
            }
            else {//if theres more than one vector
                cout << " " <<(s/(float)(current2-1));
            }
        }

        cout<<endl;
    }
    cout<<"]";
    this->choice();
}

///////////////////////////////////////////////////
//function that we keep calling it to choose which choice the user want
void Calculator::choice()
{
    int choice=0;
    cin >> choice;
    switch(choice) {
        case 1:
        {
            this->func1();
            break;
        }

        case 2:{
            this->func2();
            break;
        }
        case 3:{
            this->func3();
            break;
        }
        case 4:{
            this->func4();
            break;
        }
        case 5:{
            break;
        }
        default: {
            cerr << "Invalid option.\n";
            Calculator::choice();
        }
    }
}

#include<string>
#include<iostream>
#include<fstream>
#include<stack>
#include "EvaluatePostfix.h"
#include "translate.h"

using namespace std;
double EvaluatePostfix(string expr);

string translation(string s);

int main()
{
    cout << "\nEvaluating the Postfix from input.txt\n\n";
    ifstream ifile;
    ifile.open("input.txt");
    ofstream ofile;
    ofile.open("output.txt");

    if (!ifile.is_open())
    {
        cout << "Unable to open the file." << endl;
        return 0;
    }

    string line;

    while (getline(ifile, line))
    {
        double output = EvaluatePostfix(line);
        ofile << output << "\n";
        cout<<output;
        cout << "\n";
    }
    

    ifile.close();
    ofile.close();

  
    cout << "\nTranslating INFIX TO POSTFIX from input2.txt\n\n";
    ifile.open("input2.txt");

    ofile.open("output2.txt");

    if (!ifile.is_open())
    {
        cout << "Unable to open the file." << endl;
        return 0;
    }

    string line2;

    while (getline(ifile, line2))
    {
        string output2 = translation(line2);
        ofile << output2 << "\n";
        cout << output2<<"\n";

    }


    ifile.close();
    ofile.close();

    return 0;
}
#pragma once
#include<string>
#include<iostream>
#include <stack>
#include "EvaluatePostfix.h"
#include "vector"

using namespace std;

double EvaluatePostfix(string input) {
    vector<char> op = { '*', '/', '%','+','-'}; //THIS ARE THE SUPPORTED OPS
    

    int x, y;
    stack<double> box;  //used as container for evaluating the postfix
    double z = -99; //signaling error if just pushed in blindly
    for (int i = 0; i < input.size(); i++) {
        char curr = input[i];           //check the input char
       
        if (find(op.begin(), op.end(), curr) != op.end()) {
            x = box.top(); box.pop();
            y = box.top(); box.pop();
           
            if (curr == '+')
                z = y + x;
            else if (curr == '-')
                z = y - x;
            else if (curr == '*')
                z = y * x;
            else if (curr == '/')
                z = y / x;
            else if (curr == '%')
                z = y % x;

            box.push(z);
        }
        else if (curr >= 48 && curr <= 48+9) { 
            box.push(int(curr) - 48); //convert ascii to int
        }
    }
    return box.top();
}

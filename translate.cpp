#include<string>
#include<iostream>
#include<fstream>
#include<stack>
#include "translate.h"
#include "vector"

using namespace std;


string translation(string input)
{
	vector<char> higher = { '*', '/', '%' }; //THIS ELEMENTS HAVE HIGHER PRIORITY WHILE CONVERTING
	vector<char> lower = { '+', '-', };

	stack<char> box; 

	string output;
	for (int i = 0; i < input.length(); i++) {
		char curr = input[i];
		
		if (curr >= 48 && curr <= 48+9)			//CHECK NATURE OF EL (Num vs nonnum)
			output += curr;

		else if (curr < 48 || curr > 48 + 9) {  //THIS FOR NON NUM ascii
			bool isEmpty = box.empty();
			
			if (isEmpty == 0) {			//if elements in array then asses priority of char element of input
				int Rank1;
				if (find(higher.begin(), higher.end(), curr) != higher.end()) Rank1 = +10;
				else if (find(lower.begin(), lower.end(), curr) != lower.end()) Rank1 = -10;
				else Rank1 = -20;

			char atTop = box.top();
			int Rank2;
			if (find(higher.begin(), higher.end(), atTop) != higher.end()) Rank2 = +10;
			else if (find(lower.begin(), lower.end(), atTop) != lower.end()) Rank2 = -10;
			else Rank2 = -20;
			
		
			while (isEmpty==0 && Rank1<Rank2){
				output += box.top();			//get the higher priority
				box.pop();
			}
			}
			box.push(curr);			//insert the lower priority op in stack
		}
		if (i == input.size() - 1) {  //empty the remaining stuff in stack when finished reating input
			while (box.empty()==0) { 
				output += box.top();
				box.pop();
			}
		}
	}
	return output;
}

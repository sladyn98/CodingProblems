#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAddToMakeValid(string S) {

        vector<char>charVector,copyCharVector;
        stack <char> charStack; 
        for(int i = 0; i < S.length();i++) {
            charVector.push_back(S[i]);
            copyCharVector.push_back(S[i]);
        }


        int count = 0;
        for(char s:charVector) {
            if(s=='(') {
                // cout << "Pushing (" << endl;
                charStack.push('(');
            }

             // IF stack is empty or top is not (
            else if(s==')' && charStack.empty()) {
                count ++;
            }

            else if(s==')' && !charStack.empty()) {
                // cout << "Popping )" << endl;
                charStack.pop();
            }

            

        }

        // cout<<"Char stack size and count is " << charStack.size() << " " << count << endl; 
        return charStack.size() + count;
    }
};

int main() { 
   
   
    Solution obj;
    string s;
    cin >> s;
    int answer = obj.minAddToMakeValid(s);
    cout << "Answer is " << answer << endl;
    return 0; 
} 



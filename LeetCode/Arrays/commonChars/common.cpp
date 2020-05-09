#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

vector<char> removeDuplicates(vector<char> & A) {
    vector<char>::iterator ip;
    vector<char> temp;
    sort(A.begin(), A.end()); 
    set<char> finalSet(A.begin(), A.end());
    for(char s: finalSet) {
        temp.push_back(s);
    }
    return temp;
}
map<char,int> minFreqMap(vector<string> A) {
    map<char,int> previousCharMap;
    for (int i = 0; i < A.size(); i++) {
        map<char,int> currentCharMap;
        if(i==0) {
            for (int j = 0; j < A[i].length(); j++)  {
                if(previousCharMap.count(A[i][j])==0) {
                    previousCharMap[A[i][j]] = 1;
                } else {
                    int charCount = previousCharMap.at(A[i][j]);
                    charCount = charCount + 1;
                    previousCharMap[A[i][j]] = charCount;
                }
            }          
        } else {
            for (int j = 0; j < A[i].size();j++) {
                if(currentChaMasp.count(A[i][j])==0) {
                    currentCharMap[A[i][j]] = 1;
                } else {
                    int charCount = currentCharMap.at(A[i][j]);
                    charCount = charCount + 1;
                    currentCharMap[A[i][j]] = charCount;
                }
            }    
            for(auto s: previousCharMap) {
                if(currentCharMap.count((char) s.first) != 0) {
                    int currentValue = currentCharMap[(char) s.first];
                    int previousValue = int(s.second);
                    if(currentValue < previousValue) {
                        previousCharMap[s.first] = currentValue;
                     }
                    }
                }
        }
    }
    return previousCharMap;
}
vector<char> setDifference(vector<char> A, vector<char> B) {
    int max_size = A.size() >= B.size() ? A.size():B.size();
    vector<char> v(max_size);
    vector<char> v2 ;
    vector<char>::iterator it,st;
    int size_A = A.size();
    int size_B = B.size();
    it = set_intersection(A.begin(),A.end(),B.begin(), B.end(), v.begin()); 
    for (st = v.begin(); st != it; ++st) 
        v2.push_back(*st);
    return v2;
}
vector<string> commonChars(vector<string>& A) {
     vector<char> previous,current,preFinal;
     vector<string> finalString;
     for(int j = 0; j < A.size() ; j++) {
         vector<char> temp;
         if(j==0) {  
             for (int i = 0; i < A[j].size(); i++) {
                 temp.push_back(A[j][i]);
             }
            previous = removeDuplicates(temp);
         } else {
             for (int i = 0; i < A[j].size(); i++) {
                 temp.push_back(A[j][i]);
             }
         current = removeDuplicates(temp);
         previous = setDifference(previous,current);
        }
    } 
    map<char,int> refMap = minFreqMap(A);
    for(char x: previous) {
        if(refMap.count(x)!=0) {
            int count = refMap[x];
            for(int i = 0 ; i < count; i++) {
                preFinal.push_back(x);
            }
        }
    }
    for(char x: preFinal) {
        string s(1,x);
        finalString.push_back(s);
    }
    return finalString;     
}


int main() {
    cout<<"Enter the number of strings"<< endl;
    int num;
    cin >> num;
    vector<string> words;
    vector<string> returnString;

    for (int i = 0; i < num; i++) {
        string s;
        cin >> s;
        words.push_back(s);
    }
    returnString = commonChars(words);

    for(string s: returnString) {
        cout << s << endl;
    }
    return 0; 
}


#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int>pushStack;
        map<int,int>isPushed;
        int index = 0;

        if(popped.size()==1){
            if(popped[0] == pushed[0]){
                return 1;
            } else {
                return 0;
            }
        }
        else {
            for(int p: popped) {
                isPushed[p] = 1;
                if(index != (pushed.size() - 1 )) {
                    while(pushed[index]!=p && pushStack.top() != p ) {
                        if(isPushed[pushed[index]] != 1) {
                            pushStack.push(pushed[index]);
                        }
                        index++;
                    }
                    if(index == (pushed.size())-1) {
                            break;
                    }

                    if(pushStack.top()==p){
                        pushStack.pop();
                        index++;
                    }
                } else {
                    if(pushStack.top() == p){
                        pushStack.pop();
                    } else {
                        break;
                    }
                }
            }
        }

        if(pushStack.size() == 0) {
            return 1;
        } else {
            return 0;
        }
    }
};



int main() {

    Solution sol;
    int numOfA,numOfB,val;
    vector<int> pushed,popped;
    cin >> numOfA;

    for (int i = 0; i < numOfA; i++) {
        cin >> val;
        pushed.push_back(val);
    }

    cin >> numOfB;
    for (int i = 0; i < numOfB; i++) {
        cin >> val;
        popped.push_back(val);
    }

    int x = sol.validateStackSequences(pushed,popped);

    if(x) {
        cout <<"Correct sequence "<<endl;
    } else {
        cout << "Wrong sequence" <<endl;
    }

}

/*
 2 1 0 ----> Pushed
 1 2 0 ----> Popped

 

 */
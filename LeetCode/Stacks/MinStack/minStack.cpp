#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/min-stack/
class MinStack {
    int stackTop,supportStackTop;
public:
    vector<int> stackVector,supportStackVector;
    MinStack() {
        stackTop = -1;
        supportStackTop = -1;
    }

    void push(int x) {
        // Push into the main stack
        stackVector.push_back(x);
        stackTop++;

        //If support stack is empty push into support stack
        if(supportStackVector.size() == 0) {
            supportStackVector.push_back(x);
            supportStackTop++;
        }

        //Push into the support stack
        else if(x <= supportStackVector[supportStackTop]) {
            supportStackVector.push_back(x);
            supportStackTop++;
        }
    }

    void pop() {


        // cout << "Before popping from main stack" << endl;
        // for(int s : stackVector) {
        //     cout << s << " ";
        // }
        // cout << endl;
        //Pop from the main stack
        int mainValue = stackVector.back();
        stackVector.pop_back();
        stackTop--;

        // cout << "After popping from main stack" << endl;
        // for(int s : stackVector) {
        //     cout << s << " ";
        // }
        // cout << endl;


        // cout << "Before popping from support stack" << endl;
        // for(int s : supportStackVector) {
        //     cout << s << " ";
        // }
        // cout << endl;

        //Pop from the support stack
        int supportValue = supportStackVector.back();
        if(mainValue == supportValue) {
            supportStackVector.pop_back();
            supportStackTop--;
        }

        // cout << "After popping from support stack" << endl;
        // for(int s : supportStackVector) {
        //     cout << s << " ";
        // }
        // cout << endl;
    }

    int top() {
        int returnValue = stackVector[stackTop];
        return returnValue;
    }

    int getMin() {
       int returnValue = supportStackVector[supportStackTop];
       return returnValue;
    }
};

int main() { 
    MinStack* obj = new MinStack();
    obj->push(2147483646);
    obj->push(2147483646);
    obj->push(2147483647);
    cout << "Top is " << obj->top() << endl;
    obj->pop();
    cout << "Min val is " << obj->getMin() << endl;
    obj->pop();
    cout << "Min val is " << obj->getMin() << endl;
    obj->pop();
    obj->push(2147483647);
    cout << "Top is " << obj->top() << endl;
    cout << "Min val is " << obj->getMin() << endl;
    obj->push(-2147483647);
    cout << "Top is " << obj->top() << endl;
    cout << "Min val is " << obj->getMin() << endl;
    obj->pop();
    cout << "Min val is " << obj->getMin() << endl;
    return 0; 
} 



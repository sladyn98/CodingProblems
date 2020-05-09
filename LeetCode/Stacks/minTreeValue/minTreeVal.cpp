#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int size = arr.size();
        int maxOfLeftSubTree=0;
        int finalAnswer = 0;
        stack<int> leavesStack;
        for (int i = size; i >= 0; i--)  {
            leavesStack.push(arr[i]);
        }
        //Pop the top two and set the initial max value
        int firstValue,secondValue;
        firstValue = leavesStack.top();
        leavesStack.pop();
        secondValue = leavesStack.top();
        leavesStack.pop();
        maxOfLeftSubTree = firstValue >= secondValue ? firstValue:secondValue;
        finalAnswer = firstValue * secondValue;
        while(!leavesStack.empty()) {
            finalAnswer += leavesStack.top() * maxOfLeftSubTree;
            // cout << "final answer is" << finalAnswer << " " << leavesStack.top() << " " << maxOfLeftSubTree << endl;
            maxOfLeftSubTree = leavesStack.top() >= maxOfLeftSubTree ? leavesStack.top():maxOfLeftSubTree;
            // cout << "max of left subtree is " << maxOfLeftSubTree << endl;
            leavesStack.pop();
        }
        cout << "Final answer is " << finalAnswer << endl;
        return finalAnswer;
    }
};

int main() {

    int num;
    cin >> num;
    vector<int> leaves;
    for (int i = 0; i < num; i++) {
        int input;
        cin >> input;
        leaves.push_back(input);
    }
    sort(leaves.begin(),leaves.end());
    Solution obj;
    obj.mctFromLeafValues(leaves);

}
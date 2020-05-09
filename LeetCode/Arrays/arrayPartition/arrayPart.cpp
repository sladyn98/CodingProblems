// https://leetcode.com/problems/array-partition-i/

#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

int arrayPairSum(vector<int>& nums) {
    int total = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size();) {      
        total += nums[i];
        i = i+2;
    }
    return total;
}

int main() {
    vector<int> numbers;
    int quantity,i,input;
    cin >> quantity;
    FOR(i,0,quantity) {
        cin >> input;
        numbers.push_back(input);
    } 
   
    cout << arrayPairSum(numbers);    
}
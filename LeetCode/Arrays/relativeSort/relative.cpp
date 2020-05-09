#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
// https://leetcode.com/problems/relative-sort-array


vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        vector<int> set_diff,final_array;
        // Created sets of both the arrays.It would make it easier to construct the
        // final array at the end because the set would keep the elements sorted.
        set<int> s1(arr1.begin(),arr1.end());
        set<int> s2(arr2.begin(),arr2.end());

        // You can use set_difference here to find the difference between array 1 and array 2
        for(int s: s1) {
            if(s2.insert(s).second) {
                set_diff.push_back(s);
            }
        }
        // Create a frequency Map of all elements
        map<int,int> freqMap;
        for(int s : arr1) {
            if(freqMap.count(s) == 0) {
                freqMap[s] = 1;
            } else {
                int count = freqMap[s];
                freqMap[s] = count + 1;
            }
        }

        // Push the elements according to the second array into the final vector
        for(int s : arr2) {
           int count = freqMap[s];
           for (int i = 0; i < count; i++) {
               final_array.push_back(s);
           }
        }

        // Push the remaining elements back into the final array.
        for(int s : set_diff) {
            int count = freqMap[s];
            for (int i = 0; i < count; i++) {
                final_array.push_back(s);
            }
        }
        return final_array;
        
}

int main() {
    vector<int> array1,array2,finalArray;
    int quantity1,quantity2,i,input;
    cin >> quantity1;
    FOR(i,0,quantity1) {
        cin >> input;
        array1.push_back(input);
    } 

    cin >> quantity2;
    FOR(i,0,quantity2) {
        cin >> input;
        array2.push_back(input);
    } 

    finalArray = relativeSortArray(array1,array2);    
    for(int s : finalArray) {
        cout << s << " ";
    }
}
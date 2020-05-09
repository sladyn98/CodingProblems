#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        // Reverse the vector
        for(int i = 0; i < A.size(); i++) {
            reverse(A[i].begin(), A[i].end());
        } 
        // Invert the elements
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A.size(); j++) {
                if(A[i][j]) {
                    A[i][j] = 0;
                } else {
                    A[i][j] = 1;
                }
            }
        } 
        return A;
}

int main() {
    vector<vector<int>> A,B;
    for(int i = 0; i < 4 ;i++) {
        vector<int> temp;
        for (int j = 0; j < 4; j++) {
            int num;
            cin >> num;
            temp.push_back(num);
        }
        A.push_back(temp);
    }

    B = flipAndInvertImage(A);

    cout << "The inverted matrix is" << endl;
    for(int i = 0; i < B.size() ;i++) {
        for (int j = 0; j < B.size(); j++) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
    
}
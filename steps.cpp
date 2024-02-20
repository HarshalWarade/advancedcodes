#include<bits/stdc++.h>
using namespace std;

bool isValid(int *arr) {

    vector<int> ans = {4, 6, 5, 1, 3, 2};
    for(int i = 0; i < 6; i++) {
        if(ans[i] != arr[i]) {
            return false;        
        }
    }
    return true;
    
}

int main() {

    cout << "-- Select the correct order to arrange them --" << endl;
    cout << "1. Intermediate Code Generator" << endl;
    cout << "2. Code Generation" << endl;
    cout << "3. Code Optimisation" << endl;
    cout << "4. Lexical Analyser" << endl;
    cout << "5. Sementic Analysis" << endl;
    cout << "6. Syntax Analysis" << endl << endl;
    cout << "Enter sequence in space separated format, for ex. 1 2 3 .." << endl;

    int arr[6];
    for(int i = 0; i < 6; ++i) {
        cin >> arr[i];
    }
    cout << endl;
    cout << "---------------- RESULT ----------------" << endl;

    if(isValid(arr)) {
        cout << "Correct Answer" << endl;
    } else {
        cout << "Invalid answer, try again" << endl;
    }

    cout << endl;
    
    return 0;
}
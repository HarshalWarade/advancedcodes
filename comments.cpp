#include <bits/stdc++.h>

using namespace std;

void countComments(const string& inp) {
    bool isSingle = false;
    bool isMulti = false;

    int singles = 0;
    int multis = 0;

    for (size_t i = 0; i < inp.size(); ++i) {
        if (inp[i] == '/' && i + 1 < inp.size()) {
            if (inp[i + 1] == '/') {
                isSingle = true;
                ++singles;
            } else if (inp[i + 1] == '*') {
                // Multi-line comment
                isMulti = true;
                ++multis;
                ++i; // Skip the next character
            }
        }

        if (isSingle && inp[i] == '\n') {
            // End of single-line comment
            isSingle = false;
        }

        if (isMulti && inp[i] == '*' && i + 1 < inp.size() && inp[i + 1] == '/') {
            // End of multi-line comment
            isMulti = false;
            ++i; // Skip the next character
        }
    }

    cout << "Single-line comments: " << singles << endl;
    cout << "Multi-line comments: " << multis << endl;
}

int main() {
    string inp;
    
    cout << "Enter your inp (type 'exit' on a new line to finish):\n";
    
    // Read input until // 'exit' is entered // on a new line
    /*
    while (true) {
        string line;
        getline(cin, line);

        if (line == "exit") {
            break;
        }

        inp += line + "\n";
    }
    */
    while (true) {
        string line;
        getline(cin, line);

        if (line == "exit") {
            break;
        }

        inp += line + "\n";
    }

    countComments(inp);

    return 0;
}

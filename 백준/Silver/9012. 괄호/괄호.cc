#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

bool check(const string& input) {
    stack<char> charStack;

    for (char c : input) {
        if (c == '(') {
            charStack.push(c);
        } else if (c == ')' && !charStack.empty() && charStack.top() == '(') {
            charStack.pop();
        } else {
            return false;
        }
    }

    return charStack.empty();
}

int main() {
    int input_num;
    cin >> input_num;
    cin.ignore();

    vector<string> inputs;
    for (int i = 0; i < input_num; i++) {
        string input;
        getline(cin, input);
        inputs.push_back(input);
    }

    for (const string& input : inputs) {
        if (check(input)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

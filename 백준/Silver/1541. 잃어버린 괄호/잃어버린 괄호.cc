#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    string input;
    string num = "";
    cin >> input;
    char minus = '-';
    char plus = '+';
    int isMinus = 0;
    int result = 0;

    for (int i = 0; i <= input.size(); i++) {
        if (input[i] == minus || input[i] == plus || i == input.size()) {

            if (isMinus) {
                result -= stoi(num);
                num = "";
            } else {
                result += stoi(num);
                num = "";
            }

        }else{
            num += input[i];
        }

        if (input[i]==minus){
            isMinus = 1;
        }
    }

    cout << result;

    return 0;

}
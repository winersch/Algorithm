#include <iostream>

using namespace std;

int main() {
    int num = 1;
    string inputStr;
    getline(cin, inputStr);

    for(int i = 0; i < inputStr.length(); i++){
        if (inputStr[i] ==' '){
            num++;
        }
    }
    if (inputStr[0] == ' '){
        num--;
    }
    if (inputStr[inputStr.length()-1] == ' '){
        num--;
    }
    cout << num;
    return 0;
}

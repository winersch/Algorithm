#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    while(true){
        cin >> input;
        if (input == "0"){
            break;
        }

        for (int i = 0; i <= input.length()/2; i++) {
            if (input[i] != input[input.length()-(i+1)]){
                cout << "no" << endl;
                break;
            }
            if (i == input.length()/2){
                cout << "yes" << endl;
            }
        }

    }

    return 0;
}

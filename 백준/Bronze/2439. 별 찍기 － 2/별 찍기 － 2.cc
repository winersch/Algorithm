#include <iostream>

int main() {
    using namespace std;
    int count;
    cin >> count;

    for(int i = 1; i <= count; i++){
        string str;
        for(int j = count; j > i ; j--){
            str.append(" ");
        }
        for (int j = 1; j <= i ; j++) {
            str.append("*");
        }
        cout << str << endl;
    }
    return 0;
}

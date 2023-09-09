#include <iostream>

using namespace std;

int num;


int main() {
    cin >> num;
    if (num>= 90){
        cout << "A";
    } else if (num>= 80){
        cout << "B";
    }else if (num>= 70){
        cout << "C";
    }else if (num>= 60){
        cout << "D";
    }else{
        cout << "F";
    }



    return 0;
}
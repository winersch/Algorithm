#include <iostream>
using namespace std;

int d(int a);

int main() {

    for (int i = 1; i <= 10000; i++) {
        d(i);
    }


}

int d(int a){
    int isSelf = 1;

    for (int i = 0; i < a; i++) {
        if (i/10 == 0){
            if (i+i == a){
                isSelf = 0;
            }
        } else if (i/100 == 0){
            if (i+(i/10)+(i%10) == a){
                isSelf = 0;
            }
        } else if (i/1000 == 0){
            if (i+(i/100)+((i%100)/10)+(i%10) == a){
                isSelf = 0;
            }
        } else{
            if (i+(i/1000)+((i%1000)/100)+((i%100)/10)+(i%10) == a){
                isSelf = 0;
            }
        }
    }
    if (isSelf){
        cout << a << endl;
    }
    return 0;
}

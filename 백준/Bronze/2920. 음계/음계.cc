#include <iostream>

using namespace std;


int main() {
    int n[8];
    int cending = 0; // 0 ascending , 1 descending, 2 mixed;
    for (int i = 0; i < 8; i++) {
        cin >> n[i];
    }
    if (n[0] > n[1]){
        cending = 1;
    }else if (n[0] < n[1]){
        cending = 0;
    }

    for (int i = 1; i < 8; i++) {
        switch (cending){
            case 0:
                if (n[i] < n[i-1]){
                    cout << "mixed";
                    return 0;
                }
                break;
            case 1:
                if (n[i] > n[i-1]){
                    cout << "mixed";
                    return 0;
                }
                break;
        }
    }
    if (cending == 0){
        cout << "ascending";
    }else if(cending == 1){
        cout << "descending";
    }


    return 0;
}

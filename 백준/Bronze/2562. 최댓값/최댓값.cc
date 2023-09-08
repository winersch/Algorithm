#include <iostream>

using namespace std;
int result, result_id;

int main() {

    for (int i = 0; i < 9; i++) {
        int a;
        cin >> a;
        if (a>result){
            result = a;
            result_id = i;
        }

    }

    cout << result << "\n" << result_id+1;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    while(true){
        vector<int> input;
        for (int i = 0; i < 3; i++) {
            int q;
            cin >> q;
            if (q == 0){
                return 0;
            }
            input.push_back(q);
        }
        sort(input.begin(), input.end());

        if (input[2]*input[2] == input[0]*input[0] + input[1]*input[1]){
            cout << "right" << "\n";
        }else{
            cout << "wrong" << "\n";
        }
    }

    return 0;
}


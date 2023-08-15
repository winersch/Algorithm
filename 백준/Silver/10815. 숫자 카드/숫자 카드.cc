#include <iostream>
#include <algorithm>

using namespace std;
int own[500000], input[500000];

int binary_search(int start, int end, int key) {
    if (start > end) {
        return 0;
    }
    int mid = (start + end) / 2;

    if (own[mid] == key){
        return 1;
    } else if (own[mid] > key){
        return binary_search(start, mid-1, key);
    } else{
        return binary_search(mid+1, end, key);
    }

}

int main() {
    int own_num;
    cin >> own_num;
    for (int i = 0; i < own_num; i++) {
        cin >> own[i];
    }

    int input_num;
    cin >> input_num;
    for (int i = 0; i < input_num; i++) {
        cin >> input[i];
    }

    sort(own, own + own_num);

    for (int i = 0; i < input_num; i++) {
        cout << binary_search(0,own_num-1,input[i]) << " ";
    }

    return 0;
}
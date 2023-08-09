#include <iostream>
using namespace std;

int main() {
    int num;
    float max = 0, sum = 0;
    float avg;
    int* score;
    cin >> num;
    score = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> score[i];
        if(score[i] > max){
            max = score[i];
        }
        sum += score[i];
    }
    avg = ((sum/num)/max)*100;
    cout << avg;


}

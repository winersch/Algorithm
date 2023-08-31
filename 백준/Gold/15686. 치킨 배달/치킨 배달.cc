#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;
int n, m, chicken_num, result;
int grid[51][51];
int selected[13];
vector<pair<int, int>> house, chicken, temp;


int check_distance() {
    int sum = 0;
    for (int i = 0; i < house.size(); i++) {
        int x1 = house[i].first;
        int y1 = house[i].second;
        int d = 99999999;

        for (int j = 0; j < temp.size(); j++) {
            int x2 = temp[j].first;
            int y2 = temp[j].second;
            int distance = abs(x2 - x1) + abs(y2 - y1);

            d = min(d, distance);
        }
        sum = sum + d;
    }
    return sum;
}

void find(int index, int count) {

    if (count == m) {
        result = min(result, check_distance());
    }
    for (int i = index; i < chicken_num; i++) {
        if (selected[i]){
            continue;
        }
        selected[i] = 1;
        temp.push_back(chicken[i]);
        find(i, count+1);
        selected[i] = 0;
        temp.pop_back();
    }

}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                house.push_back(make_pair(i, j));
            }
            if (grid[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
                chicken_num++;
            }
        }
    }
    result = 1000000;
    find(0, 0);

    cout << result;
    return 0;
}

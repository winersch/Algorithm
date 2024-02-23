#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>


#define inf 0x3f3f3f3f
#define mod 1000000000
#define ll long long
using namespace std;
int n, m, ans;
pair<int, int> goal;
vector<string> board;
typedef struct bb {
    pair<int, int> red;
    pair<int, int> blue;
    vector<string> b;
};


pair<int, bb> left(vector<string> &v, pair<int, int> red, pair<int, int> blue) {
    vector<string> b = v;
    b[red.first][red.second] = '.';
    b[blue.first][blue.second] = '.';
    bool isRed = false;
    bool isBlue = false;
    if (red.first == blue.first) {
        if (red.second > blue.second) {
            while (true) {
                if (b[blue.first][blue.second - 1] != '.') {
                    if (b[blue.first][blue.second - 1] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first][blue.second - 1] == '#' || b[blue.first][blue.second - 1] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.second--;
            }
            while (true) {
                if (b[red.first][red.second - 1] != '.') {
                    if (b[red.first][red.second - 1] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first][red.second - 1] == '#' || b[red.first][red.second - 1] == 'B') {
                        b[red.first][red.second] = 'A';
                        break;
                    }
                }
                red.second--;
            }
        } else {
            while (true) {
                if (b[red.first][red.second - 1] != '.') {
                    if (b[red.first][red.second - 1] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first][red.second - 1] == '#' || b[red.first][red.second - 1] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.second--;
            }
            while (true) {
                if (b[blue.first][blue.second - 1] != '.') {
                    if (b[blue.first][blue.second - 1] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first][blue.second - 1] == '#' || b[blue.first][blue.second - 1] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.second--;
            }
        }
    } else {
        while (true) {
            if (b[red.first][red.second - 1] != '.') {
                if (b[red.first][red.second - 1] == 'O') {
                    isRed = true;
                    break;
                }
                if (b[red.first][red.second - 1] == '#' || b[red.first][red.second - 1] == 'B') {
                    b[red.first][red.second] = 'R';
                    break;
                }
            }
            red.second--;
        }
        while (true) {
            if (b[blue.first][blue.second - 1] != '.') {
                if (b[blue.first][blue.second - 1] == 'O') {
                    isBlue = true;
                    break;
                }
                if (b[blue.first][blue.second - 1] == '#' || b[blue.first][blue.second - 1] == 'R') {
                    b[blue.first][blue.second] = 'B';
                    break;
                }
            }
            blue.second--;
        }
    }
    if (isBlue) {
        return {-1, {red, blue, b}};
    }
    if (isRed) {
        return {2, {red, blue, b}};
    }
    return {1, {red, blue, b}};
}

pair<int, bb> right(vector<string> &v, pair<int, int> red, pair<int, int> blue) {
    vector<string> b = v;
    b[red.first][red.second] = '.';
    b[blue.first][blue.second] = '.';
    bool isRed = false;
    bool isBlue = false;
    if (red.first == blue.first) {
        if (red.second > blue.second) {
            while (true) {
                if (b[red.first][red.second + 1] != '.') {
                    if (b[red.first][red.second + 1] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first][red.second + 1] == '#' || b[red.first][red.second + 1] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.second++;
            }
            while (true) {
                if (b[blue.first][blue.second + 1] != '.') {
                    if (b[blue.first][blue.second + 1] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first][blue.second + 1] == '#' || b[blue.first][blue.second + 1] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.second++;
            }
        } else {
            while (true) {
                if (b[blue.first][blue.second + 1] != '.') {
                    if (b[blue.first][blue.second + 1] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first][blue.second + 1] == '#' || b[blue.first][blue.second + 1] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.second++;
            }
            while (true) {
                if (b[red.first][red.second + 1] != '.') {
                    if (b[red.first][red.second + 1] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first][red.second + 1] == '#' || b[red.first][red.second + 1] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.second++;
            }
        }
    } else {
        while (true) {
            if (b[blue.first][blue.second + 1] != '.') {
                if (b[blue.first][blue.second + 1] == 'O') {
                    isBlue = true;
                    break;
                }
                if (b[blue.first][blue.second + 1] == '#' || b[blue.first][blue.second + 1] == 'R') {
                    b[blue.first][blue.second] = 'B';
                    break;
                }
            }
            blue.second++;
        }
        while (true) {
            if (b[red.first][red.second + 1] != '.') {
                if (b[red.first][red.second + 1] == 'O') {
                    isRed = true;
                    break;
                }
                if (b[red.first][red.second + 1] == '#' || b[red.first][red.second + 1] == 'B') {
                    b[red.first][red.second] = 'R';
                    break;
                }
            }
            red.second++;
        }
    }
    if (isBlue) {
        return {-1, {red, blue, b}};
    }
    if (isRed) {
        return {2, {red, blue, b}};
    }
    return {1, {red, blue, b}};
}

pair<int, bb> up(vector<string> &v, pair<int, int> red, pair<int, int> blue) {
    vector<string> b = v;
    b[red.first][red.second] = '.';
    b[blue.first][blue.second] = '.';
    bool isRed = false;
    bool isBlue = false;
    if (red.second == blue.second) {
        if (red.first > blue.first) {
            while (true) {
                if (b[blue.first - 1][blue.second] != '.') {
                    if (b[blue.first - 1][blue.second] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first - 1][blue.second] == '#' || b[blue.first - 1][blue.second] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.first--;
            }
            while (true) {
                if (b[red.first - 1][red.second] != '.') {
                    if (b[red.first - 1][red.second] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first - 1][red.second] == '#' || b[red.first - 1][red.second] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.first--;
            }
        } else {
            while (true) {
                if (b[red.first - 1][red.second] != '.') {
                    if (b[red.first - 1][red.second] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first - 1][red.second] == '#' || b[red.first - 1][red.second] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.first--;
            }
            while (true) {
                if (b[blue.first - 1][blue.second] != '.') {
                    if (b[blue.first - 1][blue.second] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first - 1][blue.second] == '#' || b[blue.first - 1][blue.second] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.first--;
            }
        }
    } else {
        while (true) {
            if (b[blue.first - 1][blue.second] != '.') {
                if (b[blue.first - 1][blue.second] == 'O') {
                    isBlue = true;
                    break;
                }
                if (b[blue.first - 1][blue.second] == '#' || b[blue.first - 1][blue.second] == 'R') {
                    b[blue.first][blue.second] = 'B';
                    break;
                }
            }
            blue.first--;
        }
        while (true) {
            if (b[red.first - 1][red.second] != '.') {
                if (b[red.first - 1][red.second] == 'O') {
                    isRed = true;
                    break;
                }
                if (b[red.first - 1][red.second] == '#' || b[red.first - 1][red.second] == 'B') {
                    b[red.first][red.second] = 'R';
                    break;
                }
            }
            red.first--;
        }
    }
    if (isBlue) {
        return {-1, {red, blue, b}};
    }
    if (isRed) {
        return {2, {red, blue, b}};
    }
    return {1, {red, blue, b}};
}

pair<int, bb> down(vector<string> &v, pair<int, int> red, pair<int, int> blue) {
    vector<string> b = v;
    b[red.first][red.second] = '.';
    b[blue.first][blue.second] = '.';
    bool isRed = false;
    bool isBlue = false;
    if (red.second == blue.second) {
        if (red.first > blue.first) {
            while (true) {
                if (b[red.first + 1][red.second] != '.') {
                    if (b[red.first + 1][red.second] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first + 1][red.second] == '#'||b[red.first + 1][red.second] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.first++;
            }
            while (true) {
                if (b[blue.first + 1][blue.second] != '.') {
                    if (b[blue.first + 1][blue.second] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first + 1][blue.second] == '#'||b[blue.first + 1][blue.second] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.first++;
            }
        } else {
            while (true) {
                if (b[blue.first + 1][blue.second] != '.') {
                    if (b[blue.first + 1][blue.second] == 'O') {
                        isBlue = true;
                        break;
                    }
                    if (b[blue.first + 1][blue.second] == '#'||b[blue.first + 1][blue.second] == 'R') {
                        b[blue.first][blue.second] = 'B';
                        break;
                    }
                }
                blue.first++;
            }
            while (true) {
                if (b[red.first + 1][red.second] != '.') {
                    if (b[red.first + 1][red.second] == 'O') {
                        isRed = true;
                        break;
                    }
                    if (b[red.first + 1][red.second] == '#'||b[red.first + 1][red.second] == 'B') {
                        b[red.first][red.second] = 'R';
                        break;
                    }
                }
                red.first++;
            }
        }
    } else {
        while (true) {
            if (b[blue.first + 1][blue.second] != '.') {
                if (b[blue.first + 1][blue.second] == 'O') {
                    isBlue = true;
                    break;
                }
                if (b[blue.first + 1][blue.second] == '#'||b[blue.first + 1][blue.second] == 'R') {
                    b[blue.first][blue.second] = 'B';
                    break;
                }
            }
            blue.first++;
        }
        while (true) {
            if (b[red.first + 1][red.second] != '.') {
                if (b[red.first + 1][red.second] == 'O') {
                    isRed = true;
                    break;
                }
                if (b[red.first + 1][red.second] == '#'||b[red.first + 1][red.second] == 'B') {
                    b[red.first][red.second] = 'R';
                    break;
                }
            }
            red.first++;
        }
    }
    if (isBlue) {
        return {-1, {red, blue, b}};
    }
    if (isRed) {
        return {2, {red, blue, b}};
    }
    return {1, {red, blue, b}};
}

void bfs(pair<int, int> r, pair<int, int> b) {
    queue<pair<int, bb>> q;
    q.push({0, {r, b, board}});
    while (!q.empty()) {
        vector<string> curr = q.front().second.b;
        int cnt = q.front().first;
        pair<int, int> red = q.front().second.red;
        pair<int, int> blue = q.front().second.blue;
        if (cnt == 10) {
            q.pop();
            continue;
        }
        pair<int, bb> p = left(curr, red, blue);
        if (p.first != -1) {
            if (p.first == 2) {
                ans = cnt + 1;
                return;
            }
            q.push({cnt + 1, p.second});
        }
        curr = q.front().second.b;
        p = right(curr, red, blue);
        if (p.first != -1) {
            if (p.first == 2) {
                ans = cnt + 1;
                return;
            }
            q.push({cnt + 1, p.second});
        }
        curr = q.front().second.b;
        p = up(curr, red, blue);
        if (p.first != -1) {
            if (p.first == 2) {
                ans = cnt + 1;
                return;
            }
            q.push({cnt + 1, p.second});
        }
        curr = q.front().second.b;
        p = down(curr, red, blue);
        if (p.first != -1) {
            if (p.first == 2) {
                ans = cnt + 1;
                return;
            }
            q.push({cnt + 1, p.second});
        }
        q.pop();
    }
    ans = -1;
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    pair<int, int> red;
    pair<int, int> blue;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        board.push_back(s);
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == 'O') {
                goal = {i, j};
            }
            if (s[j] == 'R') {
                red = {i, j};
            }
            if (s[j] == 'B') {
                blue = {i, j};
            }
        }
    }

    bfs(red, blue);

    cout << ans;

    return 0;
}

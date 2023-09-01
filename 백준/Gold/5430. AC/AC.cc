#include <iostream>
#include <algorithm>
#include <queue>


using namespace std;

void print(vector<int> &x) {
    string output;
    output.push_back('[');
    if (x.empty()) {
        output.push_back(']');
        cout << output << "\n";
        return;
    }
    while (!x.empty()) {
        output.append(to_string(x.back()));
        x.pop_back();
        output.push_back(',');
    }

    output.pop_back();
    output.push_back(']');
    cout << output << "\n";
    return;
}

void ac() {
    string str;
    int n, reverse = 0;
    deque<int> x;
    queue<char> ac_queue;
    vector<int> result;
    getline(cin, str);

    for (int j = 0; j < str.length(); j++) {
        ac_queue.push(str[j]);
    }
    cin >> n;
    cin.ignore();
    getline(cin, str);
    int i = 0;
    string temp;
    temp = "";
    while (true) {
        if (str[i] == '[') {
            i++;
        } else if (str[i] >= '0' && str[i] <= '9') {
            temp.push_back(str[i]);
            i++;
        } else if (str[i] == ',') {
            x.push_back(stoi(temp));
            temp = "";
            i++;
        } else if (str[i] == ']') {
            if (!temp.empty()){
                x.push_back(stoi(temp));
            }
            break;
        }
    }


    while (!ac_queue.empty()) {
        char p = ac_queue.front();
        ac_queue.pop();

        if (p == 'R') {
            if (reverse) {
                reverse = 0;
            } else {
                reverse = 1;
            }
        } else if (p == 'D') {
            if (x.empty()) {
                cout << "error" << "\n";
                return;
            }
            if (reverse) {
                x.pop_back();
            } else {
                x.pop_front();
            }
        }
    }

    if (!reverse) {
        while (!x.empty()) {
            result.push_back(x.back());
            x.pop_back();
        }
    } else {
        while (!x.empty()) {
            result.push_back(x.front());
            x.pop_front();
        }
    }
    print(result);
    return;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {
        ac();
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    string time_string, distance_string;
    ifstream input("input.txt");
    getline(input, time_string);
    time_string += " ";
    getline(input, distance_string);
    distance_string += " ";
    input.close();
    vector <int> time, distance;
    string num = "", num1 = "", num2 = "";
    for (int i = 0; i < time_string.size(); i++) {
        if (time_string[i] >= '0' && time_string[i] <= '9') {
            num += time_string[i];
            num1 += time_string[i];
        }
        if (time_string[i] == ' ' && num != "") {
            time.push_back(stoi(num));
            num = "";
        }
    }

    for (int i = 0; i < distance_string.size(); i++) {
        if (distance_string[i] >= '0' && distance_string[i] <= '9') {
            num += distance_string[i];
            num2 += distance_string[i];
        }
        if (distance_string[i] == ' ' && num != "") {
            distance.push_back(stoi(num));
            num = "";
        }
    }   
    //----------part 1---------------
    int answer = 1;
    for (int i = 0; i < time.size(); i++) {
        int high = 0;
        for (int j = 1; j < time[i]; j++) {
            int dist = (time[i] - j) * j;
            if (dist > distance[i]) high++;
        }
        answer *= high;
    }
    printf("%d\n", answer);

    //------------part 2--------------
    ll answer2 = 0;
    ll ktime = stoll(num1);
    ll kdist = stoll(num2);
    for (ll j = 1; j < ktime; j++) {
        ll dist = (ktime - j) * j;
        if (dist > kdist) answer2++;
    }
    printf("%lld\n", answer2);
    return 0;
}
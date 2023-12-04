#include <bits/stdc++.h>
using namespace std;

long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

bool binary_search(int n, vector<int> &lucky) {
    int l = 0, h = (int) lucky.size() - 1;
    int mid, ans;
    while (l <= h) {
        mid = (l + h) / 2;
        if (lucky[mid] == n) {
            return 1;
        }
        else if (lucky[mid] < n) {
            l = mid + 1;
        }
        else {
            h = mid - 1;
        }
    }
    return 0;
}

int main() {
    ifstream input("input.txt");
    string l;
    long long ans = 0ll;
    map<int,pair<int,int>> mp;
    int index = 1;
    while (getline(input, l)) {
        l += ' ';
        int n = (int) l.size();
        int num = 0;
        vector <int> lucky, available;
        bool state = 0, fl = 0;
        for (int i = 0; i < n; i++) {
            if (l[i] >= '0' && l[i] <= '9') {
                num = num * 10 + (l[i] - '0');
                fl = 1;
            }
            else if (l[i] == ' ' && fl == 1) {
                if (!state) lucky.push_back(num);
                else available.push_back(num);
                num = 0;
                fl = 0;
            }
            else if (l[i] == '|') {
                state = 1;
                fl = 0;
            }
            else {
                num = 0;
                fl = 0;
            }
        }
        int found = 0;
        sort(lucky.begin(), lucky.end());
        sort(available.begin(), available.end());
        for (int it : available) {
            if (binary_search(it, lucky)) {
                found++;
            }
        }
        if (found != 0) {
            ans += binpow(2, found - 1);
        }
        mp[index] = {found, 1};
        index++;
    }
    cout << ans <<'\n';
    for (int i = 1; i <= (int) mp.size(); i++) {
        int t = 0;
        for (int j = i + 1; j <= (int) mp.size(); j++) {
            if (t == mp[i].first) break;
            mp[j].second += mp[i].second;
            t++;
        }
    }
    int res = 0;
    for (auto x : mp) res += x.second.second;
    cout << res << '\n';
}

//224365
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const string cards = "AKQJT98765432";

bool comp(tuple<string, int, int> a, tuple<string, int, int> b) {
    string s1, s2;
    s1 = get<0>(a);
    s2 = get<0>(b);
    int cat1, cat2;
    cat1 = get<2>(a);
    cat2 = get<2>(b);
    if (cat1 != cat2) return (cat1 < cat2);
    for (int i = 0; i < 5; i++) {
        if (s1[i] != s2[i]) {
            if (cards.find(s1[i]) <= cards.find(s2[i])) return false;
            else return true;   
        }
    }
    return false;
}

int main()
{
    ifstream input("input.txt");
    string l;
    vector <tuple<string, int, int>> v;
    while (getline(input, l)) {
        string s = l.substr(0,5);
        int num = stoi(l.substr(6,l.size() - 6));
        map <char, int> mp;
        for (auto x : s) {
            mp[x]++;
        }
        for (int i = 0; i < 5; i++) {
            if (s[i] == 'J') {
                if (mp['J'] == 5) break;
                int val = 0;
                char c;
                for (auto x : mp) {
                    if (x.second >= val) {
                        val = x.second;
                        c = x.first;
                    }
                }
                mp['J']--;
                mp[c]++;
                s[i] = c;
            }
        }    
        int cat;
        int arr[6] = {0};
        for (auto x : mp) {
            if (x.second == 5) arr[5]++;
            if (x.second == 4) arr[4]++;
            if (x.second == 3) arr[3]++;
            if (x.second == 2) arr[2]++;
            if (x.second == 1) arr[1]++;
        }

        if (arr[5] == 1) cat = 7;
        else if (arr[4] == 1) cat = 6;
        else if (arr[3] == 1) {
            if (arr[2] == 1) cat = 5;
            else cat = 4;
        } 
        else if (arr[2] == 2) cat = 3;
        else if (arr[2] == 1) cat = 2;
        else cat = 1;
        //cout << cat << "\n";

        v.push_back({s,num,cat});
    }   
    sort(v.begin(), v.end(), comp);
    //for (auto x : v) {
      //  cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << '\n';
    //}
    int r = 1;
    ll ans = 0ll;
    for (auto x : v) {
        ans += 1ll * (r * get<1>(x));
        r++;
    }
    cout << ans << '\n';
    return 0;
}
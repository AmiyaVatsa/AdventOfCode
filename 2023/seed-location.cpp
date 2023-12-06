#include <bits/stdc++.h>
using namespace std;
#define ll long long
vector <vector<ll>> seed_soil;
vector <vector<ll>> soil_fertilizer;
vector <vector<ll>> fertilizer_water;
vector <vector<ll>> water_light;
vector <vector<ll>> light_temperature;
vector <vector<ll>> temperature_humidity;
vector <vector<ll>> humidity_location;

ll calculateLocation(vector<ll>seeds);


int main() {
    ifstream input("sample.txt");
    string s;
    vector<ll> seeds;
    ll max_value = 0ll;
    //-----------extraction starts here--------------------------------
    int state = 0;
    while (getline(input,s)) {
        s += " ";
        string num = "";
        vector <ll> temp;
        for (int i = 0; i < (int) s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') num+=s[i];
            else if (s[i] == ' ' && num != "") {
                if (state == 0) {
                    seeds.push_back(stoll(num));
                    max_value = max(stoll(num), max_value);
                }
                else {
                    temp.push_back(stoll(num));
                    max_value = max(stoll(num), max_value);
                }
                num = "";
            }
            else num = "";
        }
        if (temp.size() == 3) {
            if (state == 1) seed_soil.push_back(temp);
            else if (state == 2) soil_fertilizer.push_back(temp);
            else if (state == 3) fertilizer_water.push_back(temp);
            else if (state == 4) water_light.push_back(temp);
            else if (state == 5) light_temperature.push_back(temp);
            else if (state == 6) temperature_humidity.push_back(temp);
            else humidity_location.push_back(temp);
        } 
        if (s.substr(0,5) == "seed-") state = 1;
        else if (s.substr(0,4) == "soil") state = 2;
        else if (s[0] == 'f') state = 3;
        else if (s[0] == 'w') state = 4;
        else if (s[0] == 'l') state = 5;
        else if (s[0] == 't') state = 6;
        else if (s[0] == 'h') state = 7;
    }
    //-------------------------Extraction ends here------------------------
    vector <ll> seeds2;
    for (ll i = 0; i < seeds.size(); i+=2) {
        for (ll j = seeds[i]; j < seeds[i] + seeds[i + 1]; j++) seeds2.push_back(j);
    }

    
    ll answer1 = calculateLocation(seeds);
    ll answer2 = calculateLocation(seeds2);
    
    cout << answer1 << '\n';
    cout << answer2 << '\n';
    return 0;
}

ll calculateLocation(vector<ll>seeds) {
    ll answer = LLONG_MAX;
    for (auto seed : seeds) {
        ll soil, fertilizer, water, light, temperature, humidity, location;
        bool fl = 0;
        for (auto y : seed_soil) {
            if (y[1] <= seed && seed <= y[1] + y[2]) {
                soil = y[0] + (seed - y[1]);
                fl = 1;
            }
        }
        if (!fl) soil = seed;
        fl = 0;
        for (auto y : soil_fertilizer) {
            if (y[1] <= soil && soil <= y[1] + y[2]) {
                fertilizer = y[0] + (soil - y[1]);
                fl = 1;
            }
        }
        if (!fl) fertilizer = soil;
        fl = 0;
        for (auto y : fertilizer_water) {
            if (y[1] <= fertilizer && fertilizer <= y[1] + y[2]) {
                water = y[0] + (fertilizer - y[1]);
                fl = 1;
            }
        }
        if (!fl) water = fertilizer;
        fl = 0;
        for (auto y : water_light) {
            if (y[1] <= water && water <= y[1] + y[2]) {
                light = y[0] + (water - y[1]);
                fl = 1;
            }
        }
        if (!fl) light = water;
        fl = 0;
        for (auto y : light_temperature) {
            if (y[1] <= light && light <= y[1] + y[2]) {
                temperature = y[0] + (light - y[1]);
                fl = 1;
            }
        }
        if (!fl) temperature = light;
        fl = 0;
        for (auto y : temperature_humidity) {
            if (y[1] <= temperature && temperature <= y[1] + y[2]) {
                humidity = y[0] + (temperature - y[1]);
                fl = 1;
            }
        }
        if (!fl) humidity = temperature;
        fl = 0;
        for (auto y : humidity_location) {
            if (y[1] <= humidity && humidity <= y[1] + y[2]) {
                location = y[0] + (humidity - y[1]);
                fl = 1;
            }
        }
        if (!fl) location = humidity;
        answer = min(answer, location);
    }
    return answer;
}
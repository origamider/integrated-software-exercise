#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int m;
    map<string,int> mp;
    for(int i = 0; i < n; i++){
        cin >> m;
        string p;
        for(int j = 0; j < m; j++){
            cin >> p;
            mp[p]++;
        }
    }
    vector<pair<int,string>> data;
    for(auto [key,val] : mp){
        data.push_back({val,key});
    }
    sort(data.rbegin(),data.rend(),[&](pair<int,string> &data1,pair<int,string> &data2){
        return data1.first < data2.first && data1.second < data2.second;
    });
    // for(auto [ct,bread] : data){
    //     cout << ct << " " << bread << endl;
    // }
    int q;
    cin >> q;
    vector<int> a(q),b(q);
    for(int i = 0; i < q; i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    for(int i = 0; i < q; i++){
        for(int j = a[i]; j <= b[i]; j++){
            cout << data[j].first << " " << data[j].second << endl;
        }
    }
}
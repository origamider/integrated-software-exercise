#include <bits/stdc++.h>
using namespace std;
struct bread_pair{
    int ct;
    string bread1;
    string bread2;
};
int main(){
    int n;
    cin >> n;
    int m;
    map<pair<string,string>,int> mp;
    for(int i = 0; i < n; i++){
        cin >> m;
        vector<string> data(m);
        for(int j = 0; j < m; j++){
            cin >> data[j];
        }
        for(int j = 0; j < m; j++){
            for(int k = j+1; k < m; k++){
                string s,t; //s<t
                if(data[j]<data[k]){
                    s = data[j];
                    t = data[k];
                }else{
                    s = data[k];
                    t = data[j];
                }
                mp[{s,t}]++;
            }
        }
    }
    vector<pair<int,pair<string,string>>> data;
    for(auto [val,ct] : mp){
        data.push_back({ct,val});
    }
    sort(data.begin(),data.end(),[&](pair<int,pair<string,string>> &A, pair<int,pair<string,string>> &B){
        if(A.first!=B.first) return A.first > B.first;
        if(A.second.first != B.second.first) return A.second.first < B.second.first;
        return A.second.second < B.second.second;
    });
    for(auto [ct, val] : data){
        cout << ct << " " << val.first << " " << val.second << endl;
    }
    
}
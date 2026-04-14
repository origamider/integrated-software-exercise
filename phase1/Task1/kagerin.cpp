//方針
//二次元配列に文字列を入れて、同じ単語がでたらmapを使ってカウントする。
#include <bits/stdc++.h>
using namespace std;
const int N = 100;
const int M = 10;
const int P = 10;
const int Q = 10;

int main(){
    string s[N][M];
    int n;
    int m[N];
    //4/8日
    // int m;だと、最後の入力がmに入るから、出力の時に実際のmじゃなくて、
    //最後の入力のmになってしまい、出力がバグったから、mを配列にしてみた。
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> m[i];
        for(int j = 0; j < m[i] ; j++){ cin >> s[i][j];
        }
    }
    map<string, int> count_map;
    //mapは勉強中

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m[i] ; j++){
            count_map[s[i][j]]++;
        }
    }

    vector<pair<int, string>> index;
    for(auto count : count_map){
        pair<int, string> data = {count.second, count.first};
        index.push_back(data);
    }

    /*sort(index.begin(),index.end(),[&](pair<int, string> &A,pair<int, string> &B){
        if(A.first > B.first) return true;
        else if(A.first == B.first){
            if(A.second < B.second) return true;
            else false;
        }
    });
    */
    /*上のコードは、A.second < B.secondの時の処理が書いてなかったからバグった*/

    sort(index.begin(),index.end(),[&](pair<int, string> &A,pair<int, string> &B){
        if(A.first != B.first){
            return A.first > B.first;
        }
        else return A.second < B.second;
    });

    int q;
    cin >> q;
    vector<pair<int, int>> query;
    for(int i = 0 ; i < q ; i++){
        int a, b;
        cin >> a >> b;
        query.push_back({a, b});
    }

    for(int i = 0 ; i < q ; i++){
        int start = query[i].first - 1;
        int end = query[i].second;
        for(int j = start ; j < end ; j++){
            cout << index[j].first << " " << index[j].second << endl;
        }
    }

}
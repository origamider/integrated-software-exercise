//方針
/*文字をトリガーとして、別の文字との回数をカウントする。Task1だとmapを
使っていたが、今回は、そこに文字が加わるからそこをどう実装するかがポイント。
*/

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
   
    cin >> n;
    for(int i = 0; i < n ; i++){
        cin >> m[i];
        for(int j = 0; j < m[i] ; j++){ cin >> s[i][j];
        }
    }
    //4/12
    map<pair<string, string>,  int> count_map;

    //4/13
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m[i] ; j++){
            for(int k = j + 1; k < m[i] ; k++){

                string s1 = s[i][j];
                string s2 = s[i][k];

                if(s1 > s2){swap(s1, s2);}
                count_map[{s1, s2}]++;
            }
        }
    }

    vector<pair<int, pair<string, string>>> index;
    for(auto count : count_map){
        pair<int, pair<string, string>> data = {count.second, count.first};
        index.push_back(data);
    }

    sort(index.begin(),index.end(),[&](pair<int, pair<string, string>> &A, pair<int, pair<string, string>> &B){
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
            cout << index[j].first << " " << index[j].second.first << " "<< index[j].second.second << endl;
        }
    }

}
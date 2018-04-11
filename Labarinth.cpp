There is a labyrinth on a matrix 
n
×
m
. Each cell is either empty (denoted by a dot), or contains an obstacle (denoted by an asterisk).
A robot can only move through empty cells, and can move only to any of four cells that share an edge with current one.
Print the total number of connected components of empty cells and their sizes, in non-decreasing order.


#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back


int n, m;

int dfs(int i, int j, vector<string>& s, vector<vector<bool> >& v){
    if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '*' || v[i][j]) return 0;
    int ans = 1;
    v[i][j] = true;
    ans += dfs(i - 1, j,s,v);
    ans += dfs(i + 1, j, s, v);
    ans += dfs(i, j - 1, s, v);
    ans += dfs(i, j + 1, s, v);
    return ans;
}


int main()
{
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<bool> > v(n, vector<bool>(m, 0));

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<int> cc;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!v[i][j]){
                int a = dfs(i, j, s, v);
                if (a) cc.pb(a);
            }
        }
    }

    sort(cc.begin(), cc.end());
    cout << cc.size() << endl;
    for(int x : cc){
        cout << x << " ";
    }
    cout << endl;


    return 0;
}

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back

vector<int> color;

int n, m;

vector<vector<int> > g;
vector<int> top;

void dfs(int i)
{
    color[i] = GR;
    for(int j = 0; j < g[i].size(); j++){
        if(color[g[i][j]] == WH){
            dfs(g[i][j]);
        }
        else if(color[g[i][j]] == GR) {
            cout << "NO" << endl;
            exit(0);
        }
    }
    color[i] = BL;
    top.push_back(i);
}


int main()
{
    cin >> n >> m;

    g.resize(n + 1);
    color.resize(n + 1);


    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
    }

    for(int i = 0; i < n; i++){
        if(color[i] == WH){
            dfs(i);
        }
    }
    cout << "YES" << endl;
    for(int i = top.size() - 1; i >= 0; i--){
        cout << top[i] << ' ';
    }
    cout << endl;
    return 0;
}

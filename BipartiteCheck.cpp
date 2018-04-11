#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back

vector<bool> visited;
vector<bool> color;
vector<vector<int> > g;


int n, m;

void dfs(int i, bool c){
    visited[i] = true;
    color[i] = c;

    for(int x : g[i]){
        if(!visited[x]){
            dfs(x, !c);
        }
        else {
            if(color[x] == c){
                cout << "NO" << endl;
                exit(0);
            }
        }
    }

}



int main()
{
    int n;
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    color.resize(n + 1);
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i, 0);
    }
        
    cout << "YES" << endl;
    return 0;
}

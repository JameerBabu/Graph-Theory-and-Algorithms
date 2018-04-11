#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back
#define pii pair<int, int>

vector<bool> visited;
vector<int> fup;
vector<int> disc;
vector<vector<int> > g;

set<int> vtc;

int n, m, t;

void dfs(int i, int p){
    visited[i] = true;
    fup[i] = disc[i] = t++;

    int c = 0;

    for(int x : g[i]){
        if(x == p) continue;
        if(!visited[x]){
            c++;
            dfs(x, i);
            fup[i] = min(fup[i], fup[x]);

            if(i == p && c > 1){
                vtc.insert(i);
            }

            if(i != p && fup[x] >= disc[i])
                vtc.insert(i);
        }
        else {
            fup[i] = min(fup[i], disc[x]);
        }
    }
}



int main()
{
    int n;
    cin >> n >> m;
    g.resize(n + 1);
    visited.resize(n + 1);
    fup.resize(n + 1);
    disc.resize(n + 1);

    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i,i);
    }

    cout << vtc.size() << endl;
    for(auto& x : vtc){
        cout << x << " ";
    }
    cout << endl;
    
    return 0;
}

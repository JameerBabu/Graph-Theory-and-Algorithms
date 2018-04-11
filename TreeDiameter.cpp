You are given a tree. You need to ﬁnd its diameter.
A diameter of a graph is the largest integer 
d
 such that there is a pair of vertices such that the distance between them is equal to 
d
. Distance between a pair of vertices is the number of edges in the shortest path between them.

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
vector<int> path;

int n, m, f, maxdepth;
bool flag = false;

vector<vector<int> > g;

void dfs(int i, int d)
{
    if(d> maxdepth)
    {
        maxdepth = d;
        f = i;
    }
    visited[i] = true;
    for(int j = 0; j < g[i].size(); j++){
        if(!visited[g[i][j]]){
            dfs(g[i][j], d + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    g.resize(n + 1);
    visited.resize(n + 1);
    for(int i = 2; i <= n; ++i)
    {
        int x;
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }
    dfs(1, 0);
    visited.clear();
    visited.resize(n + 1);
    dfs(f, 0);
    cout << maxdepth << endl;
    return 0;
}

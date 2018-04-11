You are given an undirected graph consisting of 
n
 vertices.
You have to ﬁnd the path from the vertex 
a
 to the vertex 
b
 using depth-ﬁrst search. Use an implementation that iterates over adjacent vertices of current vertex in ascending order of indices. Only paths that are produced by this version of the algorithm will be accepted.
 
 #include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;

#define pb push_back


bool visited[200001];
bool v2[200001];
int cc[200001];

vector<int> path;
int n, m;

vector<vector<int> > g;

int dfs1(int i)
{
    visited[i] = true;
    int ans = 1;
    for(int j = 0; j < g[i].size(); j++){
        if(!visited[g[i][j]]){
            ans += dfs1(g[i][j]);
        }
    }
    return ans;
}

void dfs2(int i, int ans)
{
    v2[i] = true;
    cc[i] = ans;
    for(int j = 0; j < g[i].size(); j++){
        if(!v2[g[i][j]]){
            dfs2(g[i][j], ans);
        }
    }
    return;
}

int main()
{
    cin >> n >> m;
    g.resize(n+1);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);

    }

    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            int a = dfs1(i);
            dfs2(i, a);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << cc[i] << " ";
    }
    cout << endl;
    return 0;
}

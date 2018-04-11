You are given an undirected graph consisting of 
n
 vertices and 
m
 edges. You have to ﬁnd all edges, which are bridges. I.e. the edges, removing which leads to increasing the number of connected components.
Input format
The ﬁrst line contains two integer numbers 
n
 and 
m
 (
1
≤
n
≤
2
⋅
1
0
5
, 
0
≤
m
≤
2
⋅
1
0
5
) — number of vertices and edges.
The following 
m
 lines contains edges: edge 
i
 is given as a pair of vertices 
v
i
, 
u
i
 (
1
≤
v
i
,
u
i
≤
n
, 
u
i
≠
v
i
). There is no multiple edges in the given graph, i.e. for each pair (
v
i
,
u
i
) there no other pairs (
v
i
,
u
i
) and (
u
i
,
v
i
) in the list of edges.

Output format
In the ﬁrst line of output print the number of bridges. In the second line, print indices of edges which are bridges in any order.



#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back
#define pii pair<int, int>

vector<bool> visited;
vector<int> fup;
vector<vector<int> > g;

vector<pii> edges;

int n, m;

void dfs(int i, int p, int d){
    visited[i] = true;
    fup[i] = d;

    for(int x : g[i]){
        if(x == p) continue;
        if(!visited[x]){
            dfs(x, i, d + 1);
            fup[i] = min(fup[i], fup[x]);
            if(fup[x] > d){
                edges.pb(make_pair(i, x));
//                cout << i << "," << x << endl;
            }
        }
        else {
            fup[i] = min(fup[i], fup[x]);
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

    map<pii, int> mp;
    for(int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
        mp[make_pair(a, b)] = i;
        mp[make_pair(b, a)] = i;
    }

    for(int i = 1; i <= n; i++){
        if(!visited[i])
            dfs(i,i, 0);
    }

    cout << edges.size() << endl;
    for(auto& x : edges){
        cout << mp[x] + 1 << " ";
    }
    cout << endl;
    
    return 0;
}

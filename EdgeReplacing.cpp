You are given an undirected graph containing 
n
 vertices and 
m
 edges. It is guaranteed that graph doesn’t contains loops and multiple edges.
You have to replace some minimal number of edges to transform this graph to the tree. Replacing the edge means adding it to the graph if there is no such edge and erasing it from the graph otherwise

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back
#define pii pair<int,int>

vector<bool> visited;
vector<int> path;
set<pii>  edges;
int n, m;

vector<vector<int> > g;

void dfs(int i, int p)
{
    visited[i] = true;
    for(int x : g[i]){
        if(!visited[x]){
            dfs(x,i);
        }
        else if (x != p){
            if(edges.find(make_pair(x, i)) == edges.end() && edges.find(make_pair(i,x)) == edges.end())
            edges.insert(make_pair(i, x));
        }
    }
}


int main()
{

    cin >> n >> m;

    g.clear();
    g.resize(n + 1);

    visited.resize(n + 1);


    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }


    int prev = 0;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            if (prev) edges.insert(make_pair(prev, i));
            dfs(i,i);
            prev = i;
        }
    }

    cout << edges.size() << endl;
    for(auto x : edges){
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}

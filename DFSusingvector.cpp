#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int adj[500][500];
bool visited[500];
vector<int> path;
int n, a, b;

void dfs(int vertex)
{
    visited[vertex] = true;
    path.push_back(vertex);
    if(vertex == b)
    {
        cout << path.size() - 1 << endl;
        for(int& x : path)
            cout << x + 1 << ' ';
        exit(0);
    }
    for(int i = 0; i < n; ++i)
    {
        if(adj[vertex][i] && !visited[i])
            dfs(i);
    }
    path.pop_back();
}

int main()
{
    cin >> n >> a >> b;
    --a, --b;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
        cin >> adj[i][j];
    dfs(a);
    cout << -1 << endl; 
    return 0;
}

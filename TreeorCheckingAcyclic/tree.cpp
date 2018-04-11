#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
int adj[500][500];
bool visited[500];
int n, a, b;

void dfs(int vertex, int parent)
{
    visited[vertex] = true;
    for(int i = 0; i < n; ++i)
    {
        if(i == parent) continue;
        if(adj[vertex][i])
        {
            if(!visited[i])
                dfs(i, vertex);
            else
            {
                cout << "NO" << endl;
                exit(0);
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i)
    for(int j = 0; j < n; ++j)
        cin >> adj[i][j];
    dfs(0, -1);
    for(int i = 0; i < n; ++i)
    if(!visited[i])
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}

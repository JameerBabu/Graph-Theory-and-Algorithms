You are given an rooted tree with root vertex 
1
.
You have to answer 
m
 queries (
a
i
, 
b
i
), and you have to ﬁnd relative position of vertices 
a
i
 and 
b
i
, i. e. state one of the following:

a
i
 is an ancestor of 
b
i
;
b
i
 is an ancestor of 
a
i
;
vertices are non-comparable.
Input format
The ﬁrst line of input contains one integer number 
n
 (
1
≤
n
≤
3
⋅
1
0
5
) — the number of vertices.
The second line contains 
n
−
1
 integer numbers 
p
2
,
p
3
,
…
,
p
n
 (
1
≤
p
i
≤
n
), where 
p
i
 is a parent of the vertex 
i
.
The third line contains one integer number 
m
 (
0
≤
m
≤
3
⋅
1
0
5
) — the number of queries.
Next 
m
 lines contains queries in the format 
a
i
b
i
 (
1
≤
a
i
,
b
i
≤
n
, 
a
i
≠
b
i
).

Output format
Print 
m
 numbers, one in one line — the answers for the queries. The 
i
-th number must be equal to 
1
, if 
a
i
 is an ancestor of 
b
i
, must be equal to 
2
, if 
b
i
 is an ancestor of 
a
i
, and 
3
 otherwise.
 
 
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
vector<int> tin;
vector<int> tout;

int n, m, t;

vector<vector<int> > g;

void dfs(int i)
{
    visited[i] = true;
    tin[i] = t++;
    for(int j = 0; j < g[i].size(); j++){
        if(!visited[g[i][j]]){
            dfs(g[i][j]);
        }
    }
    tout[i] = t++;
}


int main()
{
    cin >> n;

    g.resize(n + 1);
    tin.resize(n + 1);
    tout.resize(n + 1);
    visited.resize(n + 1);


    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        g[x].pb(i);
        g[i].pb(x);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    cin >> m;
    while(m--)
    {
        int x, y;
        cin >> x >> y;
        if(tin[x] < tin[y] && tout[x] > tout[y])
            cout << 1 << endl;
        else if(tin[x] > tin[y] && tout[x] < tout[y])
            cout << 2 << endl;
        else
            cout << 3 << endl;
    }
    return 0;
}

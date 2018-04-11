You are given a forest which is represented as a rectangular grid of size 
n
×
m
. The forest containing the empty cells (which are represented as ’.’), trees (’#’), rabbits (’R’) and carrots (’C’).
Your problem is to calculate for each rabbit the maximum number of carrots that he can eat if he can move to adjacent cells (adjacent cell is a cell sharing a side) and can’t move to a cell containing a tree. The answer for each rabbit must be calculated independently.

Input format
The ﬁrst line of the input contains two integer numbers 
n
 and 
m
 (
1
≤
n
,
m
≤
5
0
0
) — the size of the forest.
The next 
n
 lines contain 
m
 characters each. The character 
c
i
,
j
 is equal to ’.’ if the cell at position (
i
, 
j
) is empty, ’#’ if the cell at the position (
i
, 
j
) is a tree, ’R’ if the cell at the position (
i
, 
j
) is a rabbit and ’C’ if the cell at the position (
i
, 
j
) is a carrot.

Output format
Print 
k
 numbers (
k
 is equals to the number of rabbits). For the 
i
-th rabbit print the maximum number of carrots that he can eat. The rabbits are numbered in the order of input (the rabbit with position (
x
1
, 
y
1
) has lesser number than the rabbit with position (
x
2
, 
y
2
) if 
x
1
<
x
2
 or 
x
1
=
x
2
 and 
y
1
<
y
2
).

#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
#include<map>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back
#define pii pair<int,int>


int n, m;

int dfs(int i, int j, vector<string>& s, vector<vector<bool> >& v){
    if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '#' || v[i][j]) return 0;
    int ans = (s[i][j]=='C');
    v[i][j] = true;
    ans += dfs(i - 1, j, s, v);
    ans += dfs(i + 1, j, s, v);
    ans += dfs(i, j - 1, s, v);
    ans += dfs(i, j + 1, s, v);
    return ans;
}

map<pii, int> mp;

void dfs2(int i, int j, int& ans, vector<string>& s, vector<vector<bool> >& v2){
    if(i < 0 || i >= n || j < 0 || j >= m || s[i][j] == '#' || v2[i][j]) return;
    
    if(s[i][j] == 'R') mp[make_pair(i, j)] = ans;
    v2[i][j] = true;
    dfs2(i - 1, j, ans, s, v2);
    dfs2(i + 1, j, ans, s, v2);
    dfs2(i, j - 1, ans, s, v2);
    dfs2(i, j + 1, ans, s, v2);
    return;
}


int main()
{
    cin >> n >> m;
    vector<string> s(n);
    vector<vector<bool> > v(n, vector<bool>(m, 0));
    vector<vector<bool> > v2(n, vector<bool>(m, 0));

    for(int i = 0; i < n; i++){
        cin >> s[i];
    }

    vector<int> cc;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!v[i][j]){
                int a = dfs(i, j, s, v);
                dfs2(i, j, a, s, v2);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'R') cout << mp[make_pair(i, j)] << " ";
        }
    }
    cout << endl;
    return 0;
}

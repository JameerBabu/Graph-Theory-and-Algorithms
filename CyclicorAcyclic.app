#include<iostream>
#include<algorithm>
#include<vector>
#include<sstream>
using namespace std;
#define WH 0
#define GR 1
#define BL 2

#define pb push_back

vector<int> color;
vector<int> path;

int n, m;
bool flag = false;

vector<vector<int> > g;

void dfs(int i)
{
    if(flag) return;
    color[i] = GR;
    path.pb(i);
    for(int j = 0; j < g[i].size(); j++){
        if(flag) break;
        if(color[g[i][j]] == WH){
            dfs(g[i][j]);
        }
        else if(color[g[i][j]] == GR) {
            path.pb(g[i][j]);
            color[i] = BL;
            flag = true;
            return;
        }
    }
    color[i] = BL;
    if (!flag) path.pop_back();
}


int main()
{
    int t;
    cin >> t;
    while(t-- > 0){

        cin >> n >> m;

        g.clear();
        g.resize(n + 1);

        color.clear();
        color.resize(n + 1);

        flag = false;

        for(int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            g[x].pb(y);
        }

        path.clear();


        for(int i = 1; i <= n; i++){
            if(color[i] == WH){
                dfs(i);
                if(flag){
                    cout << "NO" << endl;

                    int start = path.back();
                    int j = 0;
                    while(path[j] != start){
                        j++;
                    }

                    cout << path.size() - j-1 << endl;

                    while(j < path.size()){
                        cout << path[j++] << " ";
                    }
                    cout << endl;
                    break;
                }
            }
        }

        if(!flag) cout << "YES" << endl;
    }
    return 0;
}

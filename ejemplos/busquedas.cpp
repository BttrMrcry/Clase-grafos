#include <bits/stdc++.h>
using namespace std;

#define endl            '\n'
#define MODC            1000000007
#define FO(i, b)        for (int i = 0; i < (b); i++)
#define vi              vector<int>
#define ll              long long


// -----------------------------------------------------------------------------
// Here begins our solution
// -----------------------------------------------------------------------------
void setIO(){
    string file = __FILE__;
    file = string(file.begin(),file.end()-3);
    string input_file = file+"in";
    string output_file =file+"out";
    freopen(input_file.c_str(), "r", stdin);
    freopen(output_file.c_str(), "w", stdout);
}


//dfs recursivo
void dfs(int cur, const vector<vector<int>> &g, vector<int> &visited){
    if(visited[cur])
        return;
    visited[cur] = 1;
    
    cout <<"visitando nodo: "<<cur <<endl;

    for(int u: g[cur]){
        dfs(u, g, visited);
    }
    
}

//dfs iterativo
void dfs(int ori, const vector<vector<int>> &g){
    stack<int> s;
    vector<int> visited(g.size());
    s.push(ori);
    while(!s.empty()){
        int cur = s.top();
        s.pop();
        if(visited[cur])
            continue;
        visited[cur] = 1;
        cout <<"visitando nodo: "<<cur <<endl;
        for(int u: g[cur]){
            s.push(u);
        }
    }
}

//bfs iterativo
void bfs(int ori, const vector<vector<int>> &g){
    queue<int> q;
    vector<int> visited(g.size());
    q.push(ori);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(visited[cur])
            continue;
        visited[cur] = 1;
        cout <<"visitando nodo: "<<cur <<endl;
        for(int u: g[cur]){
            q.push(u);
        }
    }
}


inline void solve() {

                //0 -> 1
                //0 -> 3

                //1 -> 2
                //1 -> 0

                /*
                    2 -> 3
                    2-> 1
                */

                /*
                    3 -> 2
                */


/*
0    1  3 
1   2   0
2   3   1
3   2
*/




    vector<vector<int>> g = {{1, 3}, {2, 0}, {3, 1}, {2}};
    vector<int> visited(g.size());
    dfs(2, g, visited); 
    cout << endl;
    dfs(2, g);
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}
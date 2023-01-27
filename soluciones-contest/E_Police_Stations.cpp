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


/*
    La forma intuitiva de ver esta solución es pensar que no tiene sentido tener una carretera a un nodo se si puede llegar a ese mismo 
    nodo de manera más rápida desde otra estación de policias. Se debe hacer un BFS donde cada estación de policias es un punto de inicio 
    y cerrado cualquier carretera que vaya a algún nodo ya visitado antes. 
*/


inline void solve() {
    int n, k, d;
    cin >> n >> k >> d;
    queue<pair<int, int>> q;

    for(int i = 0; i < k; i++){
        int p;
        cin >> p;
        q.push({p - 1, -1});
    }
    vector<list<pair<int, int>>> g(n);
    for(int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        g[u - 1].push_back({v - 1, i});
        g[v - 1].push_back({u - 1, i});
    }

    
    vector<bool> visited(g.size(), 0);
    list<int> sol;

    while(!q.empty()){
        auto u = q.front();
        q.pop();
        if(visited[u.first])
            continue;
        visited[u.first] = 1;
        for(auto v: g[u.first]){
            if(visited[v.first] == 1 && u.second != v.first){
                sol.push_back(v.second);
                continue;
            }
            q.push(make_pair(v.first, u.first));
            
        }
    }

    cout << sol.size() << endl;
    for(auto i: sol){
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}
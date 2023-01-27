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
Se debe encontrar el número de componentes conexas y posteriormente el número de puentes necesarios para unirlas.
Dos nodos (snow drift) son adyacentes si comporten la misma columna o fila. El número de puentes es el número de 
componentes conexas - 1.
*/

struct coor {
    int x;
    int y;
};

void dfs(const coor cur, array<array<int, 1000>, 1000> &m){
    m[cur.y][cur.x] = 0;
    
    FO(i, 1000){
        if(m[cur.y][i] == 1) dfs({i, cur.y}, m);
    }
    FO(i, 1000){
        if(m[i][cur.x] == 1) dfs({cur.x, i}, m);
    }
}


inline void solve() {
    array<array<int, 1000>, 1000> m = {0};
    int n;
    cin >> n;
    FO(i, n){
        int x, y;
        cin >> x >> y;
        m[y - 1][x - 1] = 1; 
    }

    int count = 0;
    FO(i, 1000){
        FO(j, 1000){
            if(m[i][j] == 0)
                continue;
            count++;
            dfs({j, i}, m);
        }
    }

    cout << count - 1 << endl;
}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}
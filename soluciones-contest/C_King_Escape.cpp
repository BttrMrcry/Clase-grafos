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
    Se marcan en el tablero las posiciones donde la reina puede atacar. Una vez marcadas las posiciones,
    se hace dfs en busca de una ruta al destino. Si se escuentra, imprimimos YES y si no NO.

    *hay una solución en O(1) que problemente es a la que llegaste.
*/


struct coor{
    int x;
    int y;
};


bool dfs(const coor &c, const coor cur, vector<vector<int>> &board){
    if(cur.x < 0 || cur.x >= board.size())
        return false;
    if(cur.y < 0 || cur.y >= board.size())
        return false;
    if(board[cur.y][cur.x]){
        return false;
    }
    if(cur.y == c.y && cur.x == c.x)
        return true;

    board[cur.y][cur.x] = 1;
    
    coor next = cur;
    next.x++;
    if(dfs(c, next, board))
        return true;

    next = cur;
    next.x--;
    if(dfs(c, next, board))
        return true;
    
    next = cur;
    next.y++;
    if(dfs(c, next, board))
        return true;
    
    next = cur;
    next.y--;
    if(dfs(c, next, board))
        return true;
    
    next = cur;
    next.x++;
    next.y++;
    if(dfs(c, next, board))
        return true;
    
    next = cur;
    next.x--;
    next.y--;
    if(dfs(c, next, board))
        return true;
    
    next = cur;
    next.x++;
    next.y--;
    if(dfs(c, next, board))
        return true;
    
    next = cur;
    next.x--;
    next.y++;
    if(dfs(c, next, board))
        return true;

    return false;
}

inline void solve() {
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n));
    coor q, k, c;
    cin >> q.x >> q.y;
    cin >> k.x >> k.y;
    cin >> c.x >> c.y;

    q.x--;
    q.y--;
    k.x--;
    k.y--;
    c.x--;
    c.y--;

    board[q.y][q.x] = 1;
    
    FO(i, n){
        board[q.y][i] = 1;
    }

    FO(i, n){
        board[i][q.x] = 1;
    }

    for(int i = 1; q.y - i >= 0 && q.x + i < n; i++){
        board[q.y - i][q.x + i] = 1;
    }

    for(int i = 1; q.y + i < n && q.x + i < n; i++){
        board[q.y + i][q.x + i] = 1;
    }
    
    for(int i = 1; q.y + i < n && q.x - i >= 0; i++){
        board[q.y + i][q.x - i] = 1;
    }

    for(int i = 1; q.y - i >= 0 && q.x - i >= 0; i++){
        board[q.y - i][q.x - i] = 1;
    }


    if(dfs(c, k, board))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;


}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}
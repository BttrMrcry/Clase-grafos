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
    Para este problema de crea un arreglo que representa a los buckets.
    Para obtener el indice conrrespondiente a cada x se realiza la 
    operación dir = x % p. Si el espacio ya está ocupado, se imprime el 
    indice, si no está ocupado, se marca como ocupado.
*/


inline void solve() {
    int p, n;
    cin >> p >> n;
    array<int, 300> buckets = {0};
    FO(i, n){
        int x;
        cin >> x;
        int dir = x % p;
        if(buckets[dir] == 0){
            buckets[dir] = 1;
        }else{
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}
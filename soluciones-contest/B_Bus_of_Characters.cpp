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
    Para esta solución se utilizan dos colas de prioridad, una para los asientos de los 
    introvertidos y otra para los extrovertidos. Para la cola de los intrvertidos, se ordenan los 
    elementos de menor a mayor con respecto al tamaño del asiento. cuando se utiliza un asiento de los introvertidos, 
    se pasa a la cola de extrovertidos, que está ordenada de mayor a menor con respecto al tamaño del asiento. 

    El problema también se podia resolver utilizando un stack y ordenando la entrada
*/

inline void solve() {
    int n;
    cin >> n;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> wintro;  //Del mas pequeño al más grande
    priority_queue<pair<int, int>> wextro; //Del más grande al más pequeño.
    
    FO(i, n){
        int next;
        cin >> next;
        wintro.push({next, i + 1});
    }

    FO(i, 2*n){
        char c;
        pair<int, int> row;
        cin >> c;
        if(c == '0'){
            row = wintro.top();
            wintro.pop();
            wextro.push(row);
        }else{
            row = wextro.top();
            wextro.pop();
        }
        cout << row.second << " ";
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
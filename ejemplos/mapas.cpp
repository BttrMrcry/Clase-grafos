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


inline void solve() {
    unordered_map<int, int> m1 = {{1, 6},{4, 7}};
    map<int, int> m2 = {{2,5},{7,4},{1,8}};
    unordered_set<int> s1 =  {3, 7 ,5 ,2, 0, -1};
    set<int> s2 = {3, 7 ,5 ,2, 0, -1};

    //insertar en un mapa
    m1[9] = 1;
    m1.insert({6,10});
    //saber si alguna llave existe en el mapa
    cout << "existe 4: " << (m1.count(4) ? "Si" : "NO") << endl;
    cout << "exite 6: " << (m1.find(6) != m1.end() ? "Si" : "NO") << endl; 
    //eliminar de un mapa
    m1.erase(1);

    //iterar sobre mapa
    for(auto p: m2){
        cout << p.first <<" "<< p.second << endl;
    }

    //iterar sobre set
    for(auto e: s1){
        cout << e << endl;
    }

}

int main() {
    if(getenv("CP_IO")) setIO();
    int T = 1;
    FO(tc, T){
        solve();
    }
    return 0;
}
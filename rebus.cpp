/* Simple program that solve rebus send+more=money
 * Where we need find all replaces same letters with some digits that
 * this expression is correct.
 * 
 * First we define function getKey which return unical id of each
 * permutation (we put it to used_end). Next we checking that current
 * permutation is correct;
 * (c) Aleksey Lobanov
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdint>


using namespace std;

int getKey(uint8_t a1, uint8_t a2, uint8_t a3, uint8_t a4, uint8_t a5, uint8_t a6, uint8_t a7, uint8_t a8) {
    return a1 + a2*10 + a3*100 + a4*1000 + a5*10000 + a6*100000 + a7*1000000 + a8*10000000;
}

int main() {
    set< int > used_end;
    vector< uint8_t > digs = {0,1,2,3,4,5,6,7,8,9};    
    int cn = 0; 
    do {
        if ( used_end.find(getKey(digs[0],digs[1],digs[2],digs[3],digs[4],digs[5],digs[6],digs[7])) != used_end.end() )
            continue;
        used_end.insert(getKey(digs[0],digs[1],digs[2],digs[3],digs[4],digs[5],digs[6],digs[7]));
        
        auto s = digs[0];
        auto e = digs[1];
        auto n = digs[2];
        auto d = digs[3];
        auto m = digs[4];
        auto o = digs[5];
        auto r = digs[6];
        auto y = digs[7];
        
        // first digit isn't a zero
        if ( (s == 0) || (m == 0) )
            continue;
        
        int send  =           s*1000 + e*100 + n*10 + d;
        int more  =           m*1000 + o*100 + r*10 + e;
        int money = m*10000 + o*1000 + n*100 + e*10 + y;
        
        if ( send + more == money )
            cout << send << " + " << more << " = " << money << " is OK" << endl;
        else
            continue;
        
        ++cn;
    } while ( next_permutation(digs.begin(), digs.end()) );
    cout << "Number of variants is " << cn << endl;
    return 0;
}

/*

Kokoro wo Moyase, Genkai wo Koeru!

*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int , null_type ,  less_equal<int> , rb_tree_tag , tree_order_statistics_node_update> ordered_multiset;

bool neighbour(bitset<15> a , bitset<15> b){
    bitset<15> c = a^b;
    return c.count() == 1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout.precision(20);
    int n;
    while (cin >> n){
        bitset<15> c[1<<n];
        int w[1<<n] , ans[1<<n];
        for (int i = 0; i < (1<<n) ; ++i) {
            cin >> w[i];
            bitset<15> tmp(i);
            c[i] = tmp;
        }
        for (int i = 0; i < (1<<n); ++i) {
            int pot = 0;
            for (int j = 0; j < (1<<n); ++j) {
                if(i!=j){
                    if(neighbour(c[i],c[j])) pot+=w[j];
                }
            }
            ans[i] = pot;
        }
        int mx = 0;
        for (int i = 0; i < (1<<n); ++i) {
            for (int j = i+1; j < (1<<n); ++j) {
                mx = max(mx, neighbour(c[i],c[j]) ? ans[i]+ans[j] : 0);
            }
        }
        cout << mx << '\n';
    }
    return 0;
}

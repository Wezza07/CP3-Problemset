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

const int N = 2e5+10 , M = 998244353;

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    cout.precision(20);
    int n;
    while (cin >> n){
        bitset<32> a(n);
        cout <<  n << " converts to ";
        for (int i = 0; i < 8; ++i) {
            int tmp = a[i];
            a[i] = a[24+i];
            a[24+i] = tmp;
            tmp = a[i+8];
            a[i+8] = a[16+i];
            a[16+i] = tmp;
        }
        cout << (int) a.to_ulong() << '\n';
    }
    return 0;
}

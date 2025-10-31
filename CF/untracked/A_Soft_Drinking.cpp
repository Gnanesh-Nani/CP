#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

int32_t main() {
    int n,k,l,c,d,p,nl,np;
    cin>>n; //  n friends
    cin>>k; //  k bottels
    cin>>l; //  l ml of water
    cin>>c; //  c limes
    cin>>d; //  d slices
    cin>>p; //  p grams
    
    cin>>nl; // 1 toast -> nl ml of water
    cin>>np; //            np gram of salts
    

    int total_ml_water = l * k;
    int total_piece_slices = c * d;
    int no_of_toast = min(total_ml_water/nl,min(total_piece_slices,p/np));
    cout<< (no_of_toast/n);
    return 0;
}

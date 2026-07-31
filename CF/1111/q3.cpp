#include <bits/stdc++.h>
using namespace std;
#define enl     '\n'
#define sz(s)   (int)s.size()
#define all(v)  (v).begin(),(v).end()

const long long mod = 1e9+7;
const long long inf = 1e17;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);

    for(auto &u: a) {
        cin >> u;
    }

    for(auto &u: b) {
        cin >> u;
    }

    int cnt = 0;
    bool diff = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] != b[i]) {
            cnt += a[i];
            diff = true;
        }
    }

    if(!diff) {
        cout << 0 << enl;
        return;
    }

    if(cnt % 2 == 1) {
        cout << 1 << enl;
        return;
    }
    else if(cnt > 1) {
        cout << 2 << enl;
        return;
    }
    else {
        bool zero = false, one = false;
        for(int i = 0; i < n; i++) {
            if(a[i] == b[i]) {
                if(a[i] == 0) zero = true;
                if(a[i] == 1) one = true;
            }
        }
        if(zero && one) {
            cout << 2 << enl;
        }
        else {
            cout << -1 << enl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
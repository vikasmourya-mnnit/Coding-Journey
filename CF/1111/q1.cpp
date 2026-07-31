#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    long long sum = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    
    
    if (sum % 4 != 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
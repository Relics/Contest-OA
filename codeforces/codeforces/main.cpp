#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int findServer(vector<int>& servers, int t, int k, int d) {
    int size = (int)servers.size();
    if (size < k) {
        return -1;
    } else {
        int ans = 0;
        int counts = 0;
        for (int i=0; i<size && counts < k; ++i) {
            if (servers[i] <= t) {
                ans += i + 1;
                servers[i] = t + d;
                ++counts;
            }
        }
        if (counts == k) return ans;
        else return -1;
    }
}

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> servers(n, 0);
    while (q--) {
        int t, k, d;
        cin >> t >> k >> d;
        int ans = findServer(servers, t, k, d);
        cout << ans << endl;
    }
    return 0;
}

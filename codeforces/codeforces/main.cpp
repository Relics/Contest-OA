#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int status = 0;
    int ans = 0;
    int coldCounts = 0;
    vector<int> whether(n);
    int index = 0;
    int size = n;
    while (size--) {
        int temp;
        cin >> temp;
        whether[index++] = temp;
        if (temp < 0) ++coldCounts;
        
        if (temp < 0 && status == 0) {
            ++ans;
            status = 1;
        } else if (temp >= 0 && status == 1) {
            ++ans;
            status = 0;
        }
    }
    if (coldCounts == 0) cout << 0 <<endl;
    else if (k == n) cout << 1 << endl;
    else if (coldCounts > k) cout << -1 << endl;
    else {
        int remain = k - coldCounts;
        if (remain == 0) {
            cout << ans << endl;
            return 0;
        }
        vector<int> next(n+1, -1);
        whether.push_back(-1);
        int lastIndex = -1;
        for (int i=0; i<n+1; ++i) {
            if (whether[i] >= 0) {
                continue;
            } else {
                if (lastIndex == -1) {
                    lastIndex = i;
                } else {
                    next[i] = i - lastIndex - 1;
                    lastIndex = i;
                }
            }
        }
        int ans1 = ans, ans2 = ans;
        int tempremain = remain;
        if (next[n] > 0 && tempremain >= next[n]) {
            tempremain -= next[n];
            ans1 -= 1;
            sort(next.begin(), next.end()-1);
            for (int i=0; i<n; ++i) {
                if (next[i] == -1 || next[i] == 0) {
                    continue;
                } else {
                    if (tempremain >= next[i]) {
                        ans1 = ans1 - 2;
                        tempremain -= next[i];
                    } else {
                        break;
                    }
                }
            }
        }
        sort(next.begin(), next.end()-1);
        for (int i=0; i<n; ++i) {
            if (next[i] == -1 || next[i] == 0) {
                continue;
            } else {
                if (remain >= next[i]) {
                    ans2 = ans2 - 2;
                    remain -= next[i];
                } else {
                    break;
                }
            }
        }
        ans = min(ans1, ans2);
        cout << ans << endl;
    }
    return 0;
}

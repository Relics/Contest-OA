#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

class UnionFind{
public:
    vector<int> rank;
    vector<int> pa;
    vector<int> unionNum;
    vector<int> edges;
    
    // Ini
    UnionFind(int n) {
        for (int i=0; i<n; ++i) {
            rank.push_back(0);
            pa.push_back(i);
            edges.push_back(0);
            unionNum.push_back(1);
        }
    }
    
    // Find the root
    int root(int i) {
        while (i != pa[i]) {
            pa[i] = pa[pa[i]];
            i = pa[i];
        }
        return i;
    }
    
    // Judge the connectivity
    bool isConnected(int x, int y) {
        return root(x) == root(y);
    }
    
    // Merge the sets
    void merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (rank[x] > rank[y]) {
            pa[y] = x;
            edges[x] += 1;
            edges[x] += edges[y];
        } else {
            pa[x] = y;
            if (rank[x] == rank[y]) ++rank[y];
            edges[y] += 1;
            edges[y] += edges[x];
        }
    }
};

vector<int> ks;
unordered_set<int> kk;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    UnionFind a(n);
    for (int i=0; i<k; ++i) {
        int temp;
        cin >> temp;
        ks.push_back(temp-1);
        kk.insert(temp-1);
    }
    for (int i=0; i<m; ++i) {
        int e1, e2;
        cin >> e1 >> e2;
        if (!a.isConnected(e1-1, e2-1)) {
            a.merge(e1-1, e2-1);
        } else {
            int r = a.root(e1-1);
            ++a.edges[r];
        }
    }
    
    for (int i=0; i<n; ++i) {
        int r = a.root(i);
        if (i != r) {
            ++a.unionNum[r];
        }
    }
    
    
    int maxIndex = ks[0];
    int maxNum = a.unionNum[a.root(ks[0])];
    
    for (int i=1; i<k; ++i) {
        int tempNum = a.unionNum[a.root(ks[i])];
        if (tempNum > maxNum) {
            maxNum = tempNum;
            maxIndex = ks[i];
        }
    }
    int ans = 0;
    vector<bool> visited(n, false);
    if (k > 0) {
        for (int i=0; i<n; ++i) {
            int r = a.root(i);
            int r2 = a.root(maxIndex);
            if (!visited[r] && r != r2 && kk.find(r) == kk.end()) {
                ans += maxNum * a.unionNum[r];
                visited[r] = true;
            }
        }
    }
    for (int i=0; i<k; ++i) {
        int r = a.root(ks[i]);
        int cedges = a.edges[r];
        int tedges = a.unionNum[r] * (a.unionNum[r]-1) / 2;
        ans += tedges - cedges;
    }
    cout << ans << endl;
    return 0;
}

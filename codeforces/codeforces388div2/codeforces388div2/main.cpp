#include <iostream>
#include <string>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool checkEdge(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
    if (x1 == x && x3 == x2) return true;
    if (x1 == x || x3 == x2) return false;
    return (y1-y)*1.0/(x1-x) == (y3-y2)*1.0/(x3-x2);
}

double edge(int x, int y, int x1, int y1){
    double sq1 = (y1-y) * (y1-y);
    double sq2 = (x1-x) * (x1-x);
    double ans = sqrt(sq1 + sq2);
    return ans;
}

int main() {
    int x1, y1;
    int x2, y2;
    int x3, y3;
    cin >> x1 >> y1;
    cin >> x2 >> y2;
    cin >> x3 >> y3;
    vector<pair<int, int>> ans;
    
    int x, y;
    int dummy = 0;
    x = x1+x2-x3;
    y = y1+y2-y3;
    if ((x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3)) ++dummy;
    else ans.push_back(make_pair(x, y));
    
    x = x2+x3-x1;
    y = y2+y3-y1;
    if ((x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3)) ++dummy;
    else ans.push_back(make_pair(x, y));
    
    x = x1+x3-x2;
    y = y1+y3-y2;
    if ((x == x1 && y == y1) || (x == x2 && y == y2) || (x == x3 && y == y3)) ++dummy;
    else ans.push_back(make_pair(x, y));
    
    cout << (int)ans.size() << endl;
    for (auto hehe : ans) {
        cout << hehe.first << " " << hehe.second << endl;
    }
    return 0;
}

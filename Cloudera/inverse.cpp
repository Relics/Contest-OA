class Solution {
public:
    int reverse (int a) {
        string num = "";
        if (a == 0) num = "1";
        while (a) {
            if (a & 1) {
                num = "0" + num;
            } else {
                num = "1" + num;
            }
            a = a >> 1;
        }
        cout << num << endl;
        int ans = 0, size = (int)num.size();
        for (int i=0; i<size; ++i) {
            ans = ans << 1;
            if (num[i] == '1') {
                ans += 1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    string multiply(string num1, string num2) {
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string ans = "0";
        for (size_t i = 0; i < num1.size(); i++) {
            int acc = 0;
            for (size_t j = 0; j < num2.size(); j++) {
                int dig = (num1[i] - '0') * (num2[j] - '0') + acc;
                if (i + j < ans.size()) {
                    dig += ans[i + j] - '0';
                }
                acc = dig / 10;
                dig %= 10;
                if (i + j < ans.size()) {
                    ans[i + j] = '0' + dig;
                } else if (dig) {
                    ans.resize(i + j + 1, '0');
                    ans[i + j] = '0' + dig;

                }
            }
            if (acc) {
                if (i + num2.size() < ans.size()) {
                    ans[i + num2.size()] = '0' + acc;
                } else if (acc) {
                    ans.resize(i + num2.size() + 1, '0');
                    ans[i + num2.size()] = '0' + acc;
                }
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

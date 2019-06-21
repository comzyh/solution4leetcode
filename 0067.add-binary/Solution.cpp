class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        if (a.length() < b.length()) {
            swap(a, b);
        }
        int carry = 0;
        for (int i = 0; i < b.size() || carry; i++) {
            if (i < a.length()) {
                carry += a[i] - '0';
            }
            if (i < b.length()) {
                carry += b[i] - '0';
            }
            if (i >= a.size()) {
                a.resize(i + 1, '0');
            }
            a[i] = '0' + carry % 2;
            carry /= 2;
        }
        reverse(a.begin(), a.end());
        return a;
    }
};

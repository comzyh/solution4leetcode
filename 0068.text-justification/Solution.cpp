class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        for (size_t start = 0; start < words.size();) {
            size_t len = words[start].size();
            size_t end = start + 1;
            while(end < words.size() && len + 1 + words[end].length() <= maxWidth) {
                len += 1 + words[end++].size();
            }
            string line = words[start];
            int count = end - start;
            if (end == words.size()) {
                for (size_t i = start + 1; i < end; i++) {
                    line += ' ' + words[i];
                }
            } else if (count == 1) {
                line += string(maxWidth - len, ' ');
            } else {
                count --;
                int space = maxWidth - len + count;
                string inter(space / count, ' ');
                for (size_t  i = start + 1; i < end; i++) {
                    line += inter;
                    if (i - start - 1 < space % count) {
                        line += " ";
                    }
                    line += words[i];
                }
            }
            if (line.length() < maxWidth) {
                line += string(maxWidth - line.length(), ' ');
            }
            ans.push_back(line);
            start = end;
        }
        return ans;
    }
};

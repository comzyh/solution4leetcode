class Solution {
public:
    string simplifyPath(string path) {
        vector<string> store;
        for (size_t i = 0; i < path.length(); i++) {
            size_t next_s = path.find('/', i);
            if (next_s == string::npos) {
                next_s = path.length();
            }
            string name = path.substr(i, next_s - i);
            if (name == "." || name.length() == 0) {
            } else if (name == "..") {
                if (store.size()) {                    
                    store.pop_back();
                }
            } else {
                store.push_back(name);
            }
            i = next_s;
        }
        string ans;
        for (string &name : store) {
            ans += '/' + name;
        }
        if (ans == "") {
            return "/";
        }
        return ans;
    }
};

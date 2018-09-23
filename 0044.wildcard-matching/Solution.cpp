#include <string>
#include <set>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        set<size_t> state;
        state.insert(0);
        closure(state, p);
        for (size_t  i = 0; i < s.size(); i++) {
            const char c = s[i];
            set<size_t> new_state;
            for (auto it = state.begin(); it != state.end(); it++) {
                switch (p[*it]) {
                case '*':
                    new_state.insert(*it);
                    break;
                case '?':
                    new_state.insert(*it + 1);
                    break;
                default:
                    if (s[i] == p[*it]) {
                        new_state.insert(*it + 1);
                    }
                }
            }
            state = new_state;
            closure(state, p);
        }
        for (auto it = state.begin(); it != state.end(); it++) {
            if (*it == p.size()) {
                return true;
            }
        }
        return false;
    }
private:
    void closure(set<size_t> &state, const string &p) { // NFA closure
        bool finish = false;
        while (!finish) {
            finish = true;
            for (auto it = state.begin(); it != state.end(); it++) {
                if (p[*it] == '*' && state.count(*it + 1) == 0) {
                    finish = false;
                    state.insert(*it + 1);
                }
            }
        }
    }
};

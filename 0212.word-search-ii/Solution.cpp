#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <set>
struct Trie_Node {
    int next[26];
    int index;
    Trie_Node() {
        std::fill(next, next + 26, -1);
        index = -1;
    }
};
const int dx[] = { -1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

class Solution {
public:
    vector<Trie_Node> trie;
    int rows, cols;
    set<int> ans;
    void build_trie(string &word, int index) {
        if (trie.size() == 0) {
            trie.push_back(Trie_Node());
        }
        int cur = 0;
        for (auto &c : word) {
            if (trie[cur].next[c - 'a'] == -1) {
                trie[cur].next[c - 'a'] = trie.size();
                trie.push_back(Trie_Node());
            }
            cur = trie[cur].next[c - 'a'];
        }
        trie[cur].index = index;
    }
    void dfs(int x, int y, int cur, set<pair<int, int> > &history, vector<vector<char> >& board) {
        Trie_Node &h = trie[cur];
        if (h.index != -1) {
            ans.insert(h.index);
        }
        history.insert(make_pair(x, y));
        for (int d = 0; d < 4; d++) {
            int tx = x + dx[d];
            int ty = y + dy[d];
            if (tx < 0 || ty < 0 || tx >= rows || ty >= cols) {
                continue;
            }
            int p = trie[cur].next[board[tx][ty] - 'a'];
            if (p != -1 && history.count(make_pair(tx, ty)) == 0) {
                dfs(tx, ty, p, history, board);
            }
        }
        history.erase(make_pair(x, y));
    }

    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        trie.resize(0);
        for (size_t i = 0; i < words.size(); i++) {
            build_trie(words[i], i);
        }
        rows = board.size();
        cols = board[0].size();
        ans.clear();


        for (int row = 0; row < rows; row ++) {
            for (int col = 0; col < cols; col ++) {
                if (trie.size() == 0) {
                    continue;
                }
                int p = trie[0].next[board[row][col] - 'a'];
                if (p != -1) {
                    set<pair<int, int> > his;
                    dfs(row, col, p, his, board);
                }
            }
        }
        vector<string> ret;
        for (auto &i : ans) {
            ret.push_back(words[i]);
        }
        return ret;
    }
};

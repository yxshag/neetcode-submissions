struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = "";
};

class Solution {
private:
    TrieNode* buildTrie(const vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            TrieNode* node = root;
            for (char c : w) {
                int idx = c - 'a';
                if (!node->children[idx]) {
                    node->children[idx] = new TrieNode();
                }
                node = node->children[idx];
            }
            node->word = w; // Store full word at terminal node
        }
        return root;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';

        // Base case: if cell is visited or char path doesn't exist in Trie
        if (ch == '#' || !node->children[idx]) return;

        node = node->children[idx];

        // Found a word
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Avoid duplicate entries
        }

        board[r][c] = '#'; // Mark current cell as visited

        // Direction vectors for moving Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size() && board[nr][nc] != '#') {
                dfs(board, nr, nc, node, result);
            }
        }

        board[r][c] = ch; // Backtrack / restore state
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildTrie(words);
        vector<string> result;

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root, result);
            }
        }

        return result;
    }
};
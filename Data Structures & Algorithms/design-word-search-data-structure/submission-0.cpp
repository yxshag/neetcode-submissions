class WordDictionary {
public:
    bool isEnd;
    WordDictionary *letters[26];
    
    WordDictionary() {
        isEnd = false;
        for(int i = 0; i < 26; i++){
            letters[i] = nullptr;
        }
    }
    
    void addWord(string word) {
        WordDictionary* current = this;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(current->letters[index] == nullptr){
                current->letters[index] = new WordDictionary();
            }
            current = current->letters[index];
        }
        current->isEnd = true;
    }

    bool search(string word) {
        return dfs(word, 0, this);
    }

private:
    //basically does a recursive depth first search
    bool dfs(const string& word, int idx, WordDictionary* current) {
        if (idx == word.size()) {
            return current->isEnd;
        }

        if (word[idx] == '.') {
            for (int i = 0; i < 26; i++) {
                if (current->letters[i] != nullptr) {
                    if (dfs(word, idx + 1, current->letters[i])) {
                        return true; 
                    }
                }
            }
            return false; 
        } 
        else {
            int index = word[idx] - 'a';
            if (current->letters[index] == nullptr) {
                return false;
            }
            return dfs(word, idx + 1, current->letters[index]);
        }
    }
};
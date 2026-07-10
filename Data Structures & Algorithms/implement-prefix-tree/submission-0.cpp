class PrefixTree {
public:
    //variables
    bool isEnd;
    PrefixTree *letters[26];

    PrefixTree() {
        //constructor
        isEnd=false;
        for(int i=0;i<26;i++){
            letters[i]=nullptr;
        }
    }
    
    void insert(string word) {
        PrefixTree* current=this;
        for(int i=0;i<word.size();i++){
            if(current->letters[word[i]-'a']!=nullptr){
                current=current->letters[word[i]-'a'];
            }
            else{
                PrefixTree *node=new PrefixTree();
                current->letters[word[i]-'a']=node;
                current=node;
            }
            if(i==word.size()-1){
                current->isEnd=true;
            }
        }
    }
    
    bool search(string word) {
        PrefixTree* current = this;
        
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (current->letters[index] == nullptr) {
                return false;
            }
            current = current->letters[index];
        }
        return current->isEnd;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* current = this;
        
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (current->letters[index] == nullptr) {
                return false;
            }
            current = current->letters[index];
        }
        return true;
    }
};

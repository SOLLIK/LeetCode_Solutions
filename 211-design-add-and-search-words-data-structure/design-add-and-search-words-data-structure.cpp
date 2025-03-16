class WordDictionary {
private:
    unordered_map<int, unordered_set<string>> hashmap;
public:
    WordDictionary() {}
    
    void addWord(string word) {
        int n = word.size();
        hashmap[n].insert(word);
        if(!hashmap[-2].empty())hashmap[-2].clear();
        return;
    }
    
    bool search(string word) {
        int n = word.size();
        if(hashmap[n].count(word)||hashmap[-1].count(word))return true;
        if(hashmap[-2].count(word))return false;
        for(const auto& s:hashmap[n]){
            for(int i=0;i<n;++i){
                if(word[i]!=s[i] && word[i]!='.')break;
                if(i==n-1){
                    hashmap[-1].insert(word);
                    return true;
                }
            }
        }
        hashmap[-2].insert(word);
        return false;
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
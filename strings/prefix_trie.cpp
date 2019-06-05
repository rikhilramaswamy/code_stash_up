class ntrie;
typedef unordered_map<char, ntrie*> myMap;
typedef pair<char, ntrie*> myMap_pair;
typedef vector<string> vs;
typedef vector<char> vc;
typedef stack<char> sc;

#define pb push_back

class ntrie{
private:
        myMap m1;
        bool end_of_word;
public: 
        ntrie() {
                end_of_word = false;
        }

        void insert_word(string inp) {
                ntrie *t = this;
                for(auto ch : inp) {
                        auto itr = t->m1.find(ch);
                        if(itr == t->m1.end()) {
                                ntrie *temp = new ntrie();
                                t->m1.insert(myMap_pair(ch,temp));
                                t = temp;
                        } else {
                                t = itr->second;
                        }
                }
                t->end_of_word = true;
        }
        
        bool find_prefix_or_word(string prefix) {

                ntrie *t = this;
                for(auto ch : prefix) {
                        auto itr = t->m1.find(ch);
                        if(itr == t->m1.end()){
                                return false;
                        } else {
                                t = itr->second;
                        }
                }

                return true;
        }
        
        void  dfs_over_trie(ntrie *t, sc & sc1){
            if(t->end_of_word){
                // print all chars in stack
                sc sc2 = sc1;
                vc vc1;
                
                while(!sc2.empty()){
                    vc1.pb(sc2.top());
                    sc2.pop();
                }
                
                
                for(int i = vc1.size()-1; i >=0; i--)
                    cout<<""<<vc1[i];
                cout<<"\n";
            }
            
            for(auto elem : t->m1){
                sc1.push(elem.first);
                dfs_over_trie(elem.second, sc1);
                sc1.pop();
            }
        }
        
        void  all_words_for_prefix(string prefix){
            ntrie *t = this;
            sc sc1;
            for(auto ch: prefix){
                 auto itr = t->m1.find(ch);
                 if(itr == t->m1.end()){
                     return;
                 } else {
                     t = itr->second;
                     sc1.push(ch);
                 }
            }
            
            dfs_over_trie(t, sc1);
        }
};

/*
 * Complete the join_words_to_make_a_palindrome function below.
 */
vector<string> join_words_to_make_a_palindrome(vector<string> words) {
    /*
     * Write your code here.
     */
     vs res;
     ntrie *t1 = new ntrie();
     
     t1->insert_word("cap");
     t1->insert_word("cat");
     t1->insert_word("catts");
    // t1->insert_word("ca");
     
     bool r1 = t1->find_prefix_or_word("california");
     cout<<"\n r1: "<<r1;
     r1 = t1->find_prefix_or_word("cat");
     cout<<"\n r1: "<<r1<<"\n";
     t1->all_words_for_prefix("ca");
     return res;

}



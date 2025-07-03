class Trie{
private:
    Trie* set, * unset;
    int currMin;
public: 
    Trie(){
        set = NULL;
        unset = NULL;
        currMin = INT_MAX;
    }

    void insert(Trie *root, int number){
        long long nth = 34;
        Trie* curr = root;
        long long one = 1;
        for(long long i=nth; i>=0;i--){
            curr -> currMin = min(number, curr->currMin);
            bool isSet = number&(one<<i);
            if(isSet){
                if(curr->set == NULL){
                    curr->set = new Trie();
                }
                // curr-> setMin = min(curr->setMin, number);
                curr = curr->set;

            }else{
                if(curr->unset == NULL){
                    curr->unset = new Trie();
                }
                // curr-> unsetMin = min(curr->unsetMin, number);
                curr = curr->unset;
            }
        }
        curr -> currMin = min(number, curr->currMin);
    }

    int solveQuery(Trie* root, int number, int limit){
        long long nth = 34;
        Trie* checkCurr = root;
        // int smallerBitFound = false;
        long long ans =0;
        long long one = 1;
        for(long long i=nth; i>=0;i--){      
            bool isSet =  number&(one<<i);  
            // bool limitBit = limit&(one<<i);
            if(isSet && checkCurr->unset != NULL && checkCurr -> unset->currMin <=limit){
                ans |= 1<<i;
                checkCurr = checkCurr->unset;
                // if(limitBit)smallerBitFound = true;
            }else if(checkCurr->set!= NULL && checkCurr -> set -> currMin<=limit){
                if(!isSet)
                    ans |= 1<<i;
                checkCurr = checkCurr->set;
            } else if(checkCurr->unset != NULL  && checkCurr -> unset->currMin <=limit){
                checkCurr = checkCurr->unset;
                // if(limitBit)smallerBitFound = true;
            } else {
                return -1;
            }
        }

        return ans;
    }
};



class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie * trie = new Trie();

        for(auto num: nums)trie->insert(trie, num);

        vector<int> ans;
        for(auto query: queries){
            ans.push_back(trie->solveQuery(trie, query[0], query[1]));
        }

        return ans;
    }
};

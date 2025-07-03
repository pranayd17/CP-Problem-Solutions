class Solution {
public:
    int distinctEchoSubstrings(string s) {
        unordered_set<string> res;
        int n = s.size();

        for (int len=1; len<=n/2; len++){
            int count = 0;

            for (int l=0, r=len; r<n; l++, r++){
                if (s[l] == s[r]){
                    count++;
                }else{
                    count = 0;
                }

                if (count == len){
                    res.insert(s.substr(l-len+1, len));
                    count--;
                }
            }
        }

        return res.size();
    }
};

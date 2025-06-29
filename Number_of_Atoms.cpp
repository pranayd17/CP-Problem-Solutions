class Solution {
public:
    class Formula {
        public:
        string atom;
        int count;
        Formula(string atom, int count) {
            this->atom = atom;
            this->count = count;
        }
    };

    string countOfAtoms(string formula) {
        stack<Formula> st;
        int i = 0;
        int n = formula.size();

        while(i<n) {

            if(formula[i]>='A' && formula[i]<= 'Z') {

                  string atom = string() + formula[i];

                  while(i+1< n && formula[i+1] >='a' && formula[i+1]<='z') {
                      i++;
                      atom+= formula[i];
                  }
                  int count = 0;

                  while(i+1<n && formula[i+1]>='0' && formula[i+1]<='9') {
                     i++;
                    count = count*10 + (formula[i]-'0');
                  }
                  if(count ==0) count = 1;
                  st.push(Formula(atom,count));
                  i++;
                  continue;
            }

            if(formula[i] =='(') {
                st.push(Formula(string() + formula[i],1));
                i++;
                continue;
            }

            if(formula[i] ==')') {
                int count = 0;
                while(i+1< n && formula[i+1] >='0' && formula[i+1]<='9') {
                    i++;
                    count = count* 10 + (formula[i]-'0');
                }
                i++;
                if(count ==0) count = 1;
                vector<Formula> toPush;
                while(st.top().atom != "(") {
                    auto top = st.top();
                    top.count *= count;
                    toPush.push_back(top);
                    st.pop();
                }
                st.pop();
                int sz = toPush.size();
                for(int j= sz-1;j>=0;j--) {
                    st.push(toPush[j]);
                }
            }
        }

        map<string,int> mp;
        while(!st.empty()) {
            auto top = st.top();
            st.pop();
            mp[top.atom]+= top.count;
        }
        string ans = "";

        for(auto entry: mp) {
            ans+= entry.first;
            if(entry.second > 1)
            ans+= to_string(entry.second);
        }

        return ans;
    }
};

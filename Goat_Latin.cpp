class Solution {
public:
    string toGoatLatin(string sentence) {
        string as="a", t="",s,p;
        unordered_set<string> s1;
        s1.insert("a"),s1.insert("e"),s1.insert("i"),s1.insert("o"),s1.insert("u"),s1.insert("A"),
        s1.insert("E"),s1.insert("I"),s1.insert("O"),s1.insert("U");
        for(int i=0;i<sentence.size();i++){
            bool f=0;
            if(sentence[i]==' '){
                f=1;
            }
            else {
                t+=sentence[i];
            }
            p=t;
            if(f){
                if(s1.count(t.substr(0, 1))){

                    s+=t;
                    s+="ma";
                    s+=as;
                    as+="a";
                }
                else{
                   s+=t.substr(1,t.size());
                    s+=t[0];
                    s+="ma";
                    s+=as;
                    as+="a";
                }
                t="";
                s+=" ";
            }
        }
        if(s1.count(t.substr(0, 1))){
                    s+=p;
                    s+="ma";
                    s+=as;  
                }
                else{
                   s+=p.substr(1,p.size());
                    s+=p[0];
                    s+="ma";
                    s+=as;
                   
                }
        return s;
    }
};

class Solution {
public:
    int getPosition(char ch) {
        return (ch - 'a' + 1);
    }
    void getString(string& s, int k, int i) {
        if(i < 0){
             s = "";
             return;
        }
        char nextChar = s[i] + 1;
        int posOfNextChar = getPosition(nextChar);
        if(posOfNextChar > k) {
            nextChar = 'a';
            s[i] = 'a';
            getString(s, k, i-1);
        }
        else {
            s[i] = nextChar;
        }
        if((i-1 >= 0 && s[i-1]==nextChar) || (i-2>=0 && s[i-2]==nextChar)) {
            getString(s, k, i);
        }
    }
    string smallestBeautifulString(string s, int k) {
        string original = s;
        int n = s.length();
        getString(s, k, n-1);

        return s;
    }
};

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        int n = secret.size();
        
        // Count bulls
        for (int i = 0; i < n; i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                secret[i] = '-';
                guess[i] = '-';
            }
        }
        
        // Count remaining characters in secret
        unordered_map<char, int> countSecret, countGuess;
        for (int i = 0; i < n; i++) {
            if (secret[i] != '-') {
                countSecret[secret[i]]++;
            }
            if (guess[i] != '-') {
                countGuess[guess[i]]++;
            }
        }
        
        // Count cows
        for (auto &entry : countSecret) {
            char ch = entry.first;
            if (countGuess.find(ch) != countGuess.end()) {
                cows += min(entry.second, countGuess[ch]);
            }
        }
        
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

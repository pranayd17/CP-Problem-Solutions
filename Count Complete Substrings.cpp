class Solution {
public:
    int countCompleteSubstrings(string word, int k) {
        int len = word.length();
        vector<int> starts(len);
        iota(starts.begin(), starts.end(), 0);
        int s = 0;
        for (int i = 1; i < len; ++i) {
            if (abs(word[i] - word[i - 1]) <= 2) {
                starts[i] = s;
            } else {
                s = i;
            }
        }
        vector<vector<int>> pos(26);
        for (int i = 0; i < len; ++i) {
            pos[word[i] - 'a'].push_back(i);
        }
        vector<int> vec(26, -1);
        int result = 0;
        for (int i = 0; i < len; ++i) {
            vector<int> possiblePos;
            vec[word[i] - 'a']++;
            for (int ch = 0; ch < 26; ++ch) {
                if (vec[ch] >= (k - 1)) {
                    possiblePos.push_back(pos[ch][vec[ch] - k + 1]);
                }
            }
            sort(possiblePos.begin(), possiblePos.end(), greater<int>());
            for (int j = 0; j < possiblePos.size(); ++j) {
                if (possiblePos[j] < starts[i]) {
                    break;
                }
                int cnt = j + 1;
                if (i - possiblePos[j] + 1 == cnt * k) {
                    ++result;
                }
            }
        }
        return result;
    }
};

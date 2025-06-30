// Brute Force - approach for this is to maintain a alphabet count array of length 26 and traverse through each substring and check if this 
// substring has the same frequencies as the given word, this approach takes O(n^2)*m , n^2 for searching each substring and m for 
// each ith word in the vector<string> words

// Optimal approach - (Sliding Window) , we don't need to check frequencies of every substring for every word ! We just need to check
// substrings of the same length as the given ith word. As window is of constant length, it takes O(n) time to scan a string and 
// total time complexity = O(n*m) where m is number of words
// good explanation - https://www.youtube.com/watch?v=fYgU6Bi2fRg

// Further Optimization - You might have noticed that for two words example "abc" "def" of same length, we are repeating the exact same
// same sliding window process ! We can optimize further by pre-calculating the alphabet frequencies of all words in words list and
// sorting them according to their length in a map, now for each length present in our map we run a sliding window and check that window's
// frequency with each frequency count present in our map of that length [you will also need to store the index of the word[i] along with
// with it's frequency so that you can later use that index to incriment in answer]

// Ultimate Optimization - While sliding the window over string s, we are checking each alphabet count of each letter for each window and
// comparing it to with our words[i] alphabet count, this take O(26) each time, we can further optimize this comparison process by to 
// O(1) using String Hashing by frequency. basically for any substring like "efg" hash(efg) gives a unique number in the sense of frequency of letters
// and not order.

// This can be achieved by assigning some well distributed prime numbers to each letter
// hash(efg) = hash(feg) = hash(gef) = hash(egf) = some unique sum of prime numbers
// We create an array hashed[] where hashed[i] stores hash(substring from start of s to s[i])
// with help of this if we need to find, in a string "abcde" unique hash value of sub string "de", 
// we need to do hash(abcde) - hash(abc) i.e hashed[index of e] - hashed[index of c]

int prime[26] = {130651,169627,95789,197101,104803,176509,113909,172597,6221,86269,188999,166867,4271,177787,172709,79151,155153,40897,156781,26459,176087,86243,164309,40597,181397,39791};
long long int hashed[200005];

vector<int> Solution::solve(string s, vector<string>& words) {
    int m = words.size();
    vector<int> ans(m);
    for(int i = 0; i < s.size(); i++){
        hashed[i] = (i ? hashed[i-1] : 0) + prime[s[i]-'a']; 
        // prime number corresponding to the character + previous hash value is stored in hashed[i]
        // this method gives lowest probablity of collision between any substring of different
        // as for i = 0, hashed[0] does not have previous value, we do 0 + p[s[i]-'a']
    }
    unordered_map<int,vector<pair<long long int,int>>> hashed_by_length;
    // repeating the same procedure as above for every element in vector<string> B or words list, and storing the hashed array for B[i]
    // in map along with its length and with its index (so that we )
    
    for(int i = 0; i < m; i++){
        long long int hash_of_word = 0;
        for(char &j:words[i]){
            hash_of_word += prime[j-'a'];
        }
        hashed_by_length[words[i].size()].push_back({hash_of_word, i});
        // stored hashes of word B[i] along with its index i in correspondence to its length
    }
    
    // now taking hashes of each word[i] grouped together with respect of their length
    for(auto &i:hashed_by_length){
        int len = i.first;
        vector<pair<long long int,int>> hashes_of_len = i.second;
        
        // we will slide a window of length len from our hashed[] of string s
        // But when we encounter any element that was present in hashes_of_len, we need to increase its occurene count
        // But searching that particular hash will take time
        // so we create a map of all the hashes present in hashes_of_len and there occurence so time complexity to search becomes O(1)
        unordered_map<long long, int> count_of_hashes;
        for(auto j:hashes_of_len){
            count_of_hashes[j.first] = 0;
        }
        
        // now sliding a window of length len through j = 0 to j+len-1, till j+len-1 < s.size()
        // in a string abcde to obtain hash(de) we need to do hash(abcde) - hash(abc)
        // in this context it's basically to obtain hash(of word from j to j+len-1) we do hash(j+len-1) - hash(j-1)
        for(int j = 0; j+len-1 < (int)(s.size()) ; j++){
            long long int hash_search = hashed[j+len-1] - (j ? hashed[j-1] : 0);
            // checking for case j = 0, then hash = hash(j+len-1) only
            
            // if hash search is present in count_of_hashes, we increase it's count by 1
            if(count_of_hashes.count(hash_search)){
                count_of_hashes[hash_search]++;
            }
        }
        
        // storing our result in ans, now storing index along with the hash number of b[i] is coming in handy
        for(auto j:hashes_of_len){
            ans[j.second] = count_of_hashes[j.first];
        }
    }
    return ans;
}

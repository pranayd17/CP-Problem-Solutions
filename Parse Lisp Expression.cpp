class Solution {
private:
    class NestedMap {
    private:
        struct TreeNode {
            stack<long long> valueStack;
            unordered_map<char, TreeNode*> nextNodes;
            TreeNode() {}
            ~TreeNode() { for (auto& node : nextNodes) delete node.second; }
        };

        TreeNode* rootNode;

        TreeNode* navigateToNode(const string& key) {
            TreeNode* currentNode = rootNode;
            for (char ch : key) {
                if (!currentNode->nextNodes.count(ch)) {
                    currentNode->nextNodes[ch] = new TreeNode();
                }
                currentNode = currentNode->nextNodes[ch];
            }
            return currentNode;
        }

    public:
        NestedMap() : rootNode(new TreeNode()) {}
        ~NestedMap() { delete rootNode; }

        void storeValue(const string& variable, long long value) {
            navigateToNode(variable)->valueStack.push(value);
        }

        void removeValue(const string& variable) {
            navigateToNode(variable)->valueStack.pop();
        }

        long long fetchValue(const string& variable) {
            return navigateToNode(variable)->valueStack.top();
        }
    };

public:
    int evaluate(string expr) const {
        const int len = expr.size();
        stack<int> parenthesesStack;
        vector<int> matchedParentheses(len, -1);
        int index = 0;

        while (index < len) {
            if (expr[index] == '(') {
                parenthesesStack.push(index);
            } else if (expr[index] == ')') {
                matchedParentheses[parenthesesStack.top()] = index;
                parenthesesStack.pop();
            } else if (expr[index] == '-' || isdigit(expr[index]) || isalpha(expr[index])) {
                int start = index;
                while (index < len - 1 && (isdigit(expr[index + 1]) || isalpha(expr[index + 1]))) index++;
                matchedParentheses[start] = index;
            }
            index++;
        }

        NestedMap variableMap;
        function<long long(int, int)> evaluateSegment = [&](int left, int right) -> long long {
            if (expr[left] == '-' || isdigit(expr[left])) {
                return stoll(expr.substr(left, right - left + 1));
            } else if (isalpha(expr[left])) {
                return variableMap.fetchValue(expr.substr(left, right - left + 1));
            } else if (expr[left + 1] != 'l') {
                bool isAddition = expr[left + 1] == 'a';
                int firstStart = left + (isAddition ? 5 : 6);
                int firstEnd = matchedParentheses[firstStart];
                int secondStart = firstEnd + 2;
                int secondEnd = matchedParentheses[secondStart];
                return isAddition ? evaluateSegment(firstStart, firstEnd) + evaluateSegment(secondStart, secondEnd)
                                   : evaluateSegment(firstStart, firstEnd) * evaluateSegment(secondStart, secondEnd);
            }

            int idx = left + 5;
            while (matchedParentheses[idx] != right - 1) {
                int keyStart = idx;
                int keyEnd = matchedParentheses[keyStart];
                int valueStart = keyEnd + 2;
                int valueEnd = matchedParentheses[valueStart];
                variableMap.storeValue(expr.substr(keyStart, keyEnd - keyStart + 1), evaluateSegment(valueStart, valueEnd));
                idx = valueEnd + 2;
            }

            long long result = evaluateSegment(idx, matchedParentheses[idx]);

            idx = left + 5;
            while (matchedParentheses[idx] != right - 1) {
                variableMap.removeValue(expr.substr(idx, matchedParentheses[idx] - idx + 1));
                idx = matchedParentheses[matchedParentheses[idx] + 2] + 2;
            }

            return result;
        };

        return evaluateSegment(0, len - 1);
    }
};

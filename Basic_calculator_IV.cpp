class Solution {
    using Term = map<string, int>;
    using Poly = map<vector<string>, int>;

    Poly combine(const Poly& a, const Poly& b, char op) {
        Poly res;
        if (op == '+') {
            res = a;
            for (auto& [k, v] : b) res[k] += v;
        } else if (op == '-') {
            res = a;
            for (auto& [k, v] : b) res[k] -= v;
        } else { // '*'
            for (auto& [ak, av] : a) {
                for (auto& [bk, bv] : b) {
                    vector<string> key = ak;
                    key.insert(key.end(), bk.begin(), bk.end());
                    sort(key.begin(), key.end());
                    res[key] += av * bv;
                }
            }
        }
        return res;
    }

    Poly parse(string s, unordered_map<string, int>& eval) {
        stack<Poly> stk;
        stack<char> ops;
        int i = 0, n = s.size();
        while (i < n) {
            if (s[i] == ' ') {
                ++i;
            } else if (isdigit(s[i])) {
                int j = i;
                while (j < n && isdigit(s[j])) ++j;
                int num = stoi(s.substr(i, j - i));
                stk.push({{{}, num}});
                i = j;
            } else if (isalpha(s[i])) {
                int j = i;
                while (j < n && isalnum(s[j])) ++j;
                string var = s.substr(i, j - i);
                if (eval.count(var)) {
                    stk.push({{{}, eval[var]}});
                } else {
                    stk.push({{{var}, 1}});
                }
                i = j;
            } else if (s[i] == '(') {
                ops.push('(');
                ++i;
            } else if (s[i] == ')') {
                while (ops.top() != '(') {
                    auto b = stk.top(); stk.pop();
                    auto a = stk.top(); stk.pop();
                    char op = ops.top(); ops.pop();
                    stk.push(combine(a, b, op));
                }
                ops.pop();
                ++i;
            } else {
                while (!ops.empty() && precedence(ops.top()) >= precedence(s[i])) {
                    auto b = stk.top(); stk.pop();
                    auto a = stk.top(); stk.pop();
                    char op = ops.top(); ops.pop();
                    stk.push(combine(a, b, op));
                }
                ops.push(s[i++]);
            }
        }

        while (!ops.empty()) {
            auto b = stk.top(); stk.pop();
            auto a = stk.top(); stk.pop();
            char op = ops.top(); ops.pop();
            stk.push(combine(a, b, op));
        }

        return stk.top();
    }

    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*') return 2;
        return 0;
    }

    vector<string> format(Poly poly) {
        vector<pair<vector<string>, int>> terms;
        for (auto& [vars, coeff] : poly) {
            if (coeff != 0) terms.emplace_back(vars, coeff);
        }

        sort(terms.begin(), terms.end(), [](auto& a, auto& b) {
            if (a.first.size() != b.first.size())
                return a.first.size() > b.first.size();
            return a.first < b.first;
        });

        vector<string> result;
        for (auto& [vars, coeff] : terms) {
            string term = to_string(coeff);
            for (string& var : vars) term += "*" + var;
            result.push_back(term);
        }
        return result;
    }

public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        unordered_map<string, int> eval;
        for (int i = 0; i < evalvars.size(); ++i) {
            eval[evalvars[i]] = evalints[i];
        }
        Poly poly = parse(expression, eval);
        return format(poly);
    }
};

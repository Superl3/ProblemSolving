class Solution {
    string dials[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
    void letterComboTraverse(int depth, vector<int>& select, vector<string>& combinations, const string& digits) {
        if(depth == digits.length()) {
            string combination = "";
            for(int idx = 0; idx < select.size() ; idx ++)                
                combination += dials[digits[idx]-'2'][select[idx]];
            combinations.push_back(combination);
            return;
        }
        for(int idx = 0 ; idx < dials[digits[depth]-'2'].length(); idx++) {
            select[depth] = idx;
            letterComboTraverse(depth+1, select, combinations, digits);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        vector<int> select(digits.length());
        if(digits.length() > 0)
            letterComboTraverse(0, select, combinations, digits);
        return combinations;
    }
};
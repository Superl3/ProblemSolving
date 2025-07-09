class Solution {
    void createSubset(int idx, vector<int> &subset, vector<vector<int>> &subsets, const vector<int>& nums) {
        subsets.push_back(subset);
        for(;idx < nums.size(); idx++) {
            subset.push_back(nums[idx]);
            createSubset(idx+1, subset, subsets, nums);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsetContainer;
        vector<int> placeholder;
        createSubset(0, placeholder, subsetContainer, nums);
        return subsetContainer;
    }
};
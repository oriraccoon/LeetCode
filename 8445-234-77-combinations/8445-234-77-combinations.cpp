class Solution {
public:
    void combi(int n, int k, vector<int> &nums, vector<vector<int>> &answer, int re) {
        if (nums.size() == k) {
            answer.push_back(nums);
            return;
        }
        for (int j = re; j < n; j++) {
            nums.push_back(j + 1);
            combi(n, k, nums, answer, j + 1);
            nums.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<vector<int>> answer;
        combi(n, k, nums, answer, 0);

        return answer;
    }
};
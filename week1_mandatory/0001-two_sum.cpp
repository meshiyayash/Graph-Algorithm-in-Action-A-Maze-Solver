class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());
        int l = 0, r = tmp.size() - 1;
        while (l < r) {
            int x = tmp[l] + tmp[r];
            if (x == target) {
                break;
            }
            if (x < target) {
                l++;
            } else {
                r--;
            }
        }
        int a = tmp[l];
        int b = tmp[r];
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == a || nums[i] == b) {
                ans.push_back(i);
            }
        }
        return ans;
    }
}
class Solution {

private:
    void subset(vector<vector<int>> &ans,vector<int>& a, vector<int>&nums, int i){
        if(i<0){
            ans.push_back(a);
            return;
        } 

        a.push_back(nums[i]);
        subset(ans,a,nums,i-1);
        a.pop_back();
        subset(ans,a,nums,i-1);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> a;
        subset(ans,a,nums,nums.size()-1);
        return ans;
    }
};

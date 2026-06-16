class Solution {

private:
    void c(vector<vector<int>>&ans,vector<int>&nums,vector<int>&a,int target,int i){
        if(target == 0){
            ans.push_back(a);
            return;
        } 

        if(target < 0 || i<0){
            return;
        }

        if(target<nums[i]){
            c(ans,nums,a,target,i-1);
        } else {
            a.push_back(nums[i]);
            c(ans,nums,a,target-nums[i],i);
            a.pop_back();
            c(ans,nums,a,target,i-1);
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> a;
        c(ans,candidates,a,target,candidates.size()-1);
        return ans;
    }
};

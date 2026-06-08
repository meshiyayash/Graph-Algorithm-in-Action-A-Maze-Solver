class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int j,k;
        for(int i=0;i+2<nums.size();i++){
            if(i!=0 && nums[i]==nums[i-1]){continue;}
            j=i+1;
            k=nums.size()-1;
            int t=-nums[i];
            while(j<k){
                if(nums[j]+nums[k]<t){j++;}
                else if(nums[j]+nums[k]>t){k--;}
                else if(nums[j]+nums[k]==t){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k--;
                while(nums[k]==nums[k+1] && j<k){
                    k--;
                }                    
                }
            }
        }      
        return ans;
    }
};
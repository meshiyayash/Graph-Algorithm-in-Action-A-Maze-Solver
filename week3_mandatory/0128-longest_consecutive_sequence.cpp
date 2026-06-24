class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int>s;
        int ans=1;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        for(auto a:s){
            if(s.find(a-1)==s.end()){
                int x=a;
                int freq=1;
                while(s.find(x+1) != s.end()){
                    x++;
                    freq++;
                }
                ans=max(ans,freq);
            }
        }
        return ans;
    }
};

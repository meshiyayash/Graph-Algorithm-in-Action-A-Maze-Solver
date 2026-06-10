class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> p;
        p.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            p.push_back(p[i-1]+nums[i]);
        }

        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(p[i]==k){ans++;}
            int tar=p[i]-k;
            if(m.find(tar) != m.end()){
                ans+=m[tar];
            }

            if(m.find(p[i]) == m.end()){
                m[p[i]]=0;
            }
            m[p[i]]++;
        }
        return ans;
    }
};
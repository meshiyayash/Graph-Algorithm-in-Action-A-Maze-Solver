class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> l,r;
        int lm=0,rm=0;
        for(int i=0;i<height.size();i++){
            lm=max(lm,height[i]);
            rm=max(rm,height[height.size()-i-1]);
            l.push_back(lm);
            r.push_back(rm);
        }
        reverse(r.begin(),r.end());
        int ans=0;
        for(int i=0;i<height.size();i++){
            ans+=(min(l[i],r[i])-height[i]);
        }
        return ans;
    }
};
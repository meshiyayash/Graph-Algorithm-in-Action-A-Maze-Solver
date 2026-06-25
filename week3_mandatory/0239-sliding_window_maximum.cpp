class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;

        for(int i=0;i<k;i++){
            while(!d.empty() && d.back()<nums[i]){
                d.pop_back();
            }
            d.push_back(nums[i]);
        }

        ans.push_back(d.front());
        if(d.front()==nums[0]){
            d.pop_front();
        }

        for(int i=k;i<nums.size();i++){
            while(!d.empty() && d.back()<nums[i]){
                d.pop_back();
            }
            d.push_back(nums[i]);
            ans.push_back(d.front());
            if(d.front()==nums[i-k+1]){
                d.pop_front();
            }          
        }

        return ans;
    }
};

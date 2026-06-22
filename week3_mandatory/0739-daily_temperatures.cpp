class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack <int> s;
        int i=temperatures.size()-1;
        while(i>=0){
            if(s.empty()){
                ans[i]=0;
                s.push(i);
                i--;
            } else {
                if(temperatures[s.top()]>temperatures[i]){
                    ans[i]=s.top()-i;
                    s.push(i);
                    i--;
                } else {
                    while(!s.empty() && temperatures[s.top()]<=temperatures[i]){
                        s.pop();
                    }
                }
            }
        }
        return ans;
    }
};

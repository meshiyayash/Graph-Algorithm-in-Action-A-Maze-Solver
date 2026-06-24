class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack <int> s;
        vector<int> r(heights.size());
        int ptr=heights.size()-1;
        int n=heights.size();
        r[ptr]=heights.size();
        s.push(ptr--);
        while(ptr>=0){
            if(s.empty()){
                r[ptr]=heights.size();
                s.push(ptr--);
            }
            else if(heights[s.top()]<heights[ptr]){
                r[ptr]=s.top();
                s.push(ptr--);
            } else {
                while(!s.empty()&&heights[s.top()]>=heights[ptr]){
                    s.pop();
                }
            }
        }

        s=stack <int> ();
        vector<int> l(heights.size());
        ptr=0;
        l[ptr]=-1;
        s.push(ptr++);
        while(ptr<n){
            if(s.empty()){
                l[ptr]=-1;
                s.push(ptr++);
            }
            else if(heights[s.top()]<heights[ptr]){
                l[ptr]=s.top();
                s.push(ptr++);
            } else {
                while(!s.empty()&&heights[s.top()]>=heights[ptr]){
                    s.pop();
                }
            }
        }
        int ans=0;
        for(int i=0;i<heights.size();i++){
            ans=max(ans,heights[i]*(r[i]-l[i]-1));
        }
        return ans;
    }
};

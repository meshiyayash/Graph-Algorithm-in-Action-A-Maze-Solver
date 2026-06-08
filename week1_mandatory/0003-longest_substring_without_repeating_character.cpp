class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> s1;
        if(s.length()<=1){return s.length();}
        int i=0,j=1;
        int count=1,ans=0;
        s1.insert(s[i]);
        while(j<s.length()){
            if(!s1.count(s[j])){
                s1.insert(s[j]);
                j++;
                count++;
            }
            else {
                ans=max(ans,count);
                while(s[i]!=s[j]){
                    s1.erase(s[i]);
                    i++;
                    count--;
                }
                s1.erase(s[i]);
                i++;
                count--;
                ans=max(ans,count);
            }
        }
        ans=max(ans,count);
        return ans;
    }
};
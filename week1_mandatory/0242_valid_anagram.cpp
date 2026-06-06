class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()){return 0;}
        int b[26]={0};
        for(int i=0;i<s.length();i++){
            b[int(s[i]-'a')]++;
        }
        for(int i=0;i<t.length();i++){
            b[int(t[i]-'a')]--;
        }
        for(int i=0;i<26;i++){
            if(b[i]!=0){return 0;}
        }
        return 1;
    }
};

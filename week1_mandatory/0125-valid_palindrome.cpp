class Solution {
public:
    bool isPalindrome(string s) {
        if(!s.length()){return 1;}
        string y="";
        for(int i=0;i<s.length();i++){
            if(s[i]-'a'>=0 && 'z'-s[i]>=0){
                y+=s[i];
            } else if (s[i]-'A'>=0 && 'Z'-s[i]>=0){
                y+=(s[i]-'A'+'a');
            } else if (s[i]<='9' && s[i]>='0'){
                y+=(s[i]);
            }
        }
        if(!y.length()){return 1;}
        int i=0,j=y.length()-1;
        while(i<j){
            if(y[i]!=y[j]){return 0;}
            else{i++;j--;}
        }
        return 1;
    }
};

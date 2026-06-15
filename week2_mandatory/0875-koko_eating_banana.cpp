class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1,r=*max_element(piles.begin(),piles.end());
        long long k=INT_MAX,mid,sum=0;
        while(l<=r){
            sum=0;
            mid=l+(r-l)/2;
            for(auto i:piles){
                sum+=((i/mid) + (i%mid != 0));
            }
            if(sum>h){
                l=mid+1;
            } else{
                k=min(k,mid);
                r=mid-1;
            } 
        }
        return k;
    }
};
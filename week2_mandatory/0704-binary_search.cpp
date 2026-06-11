class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid=(l+r)/2;
        while(l<mid){
            if(nums[mid]<target){l=mid;mid=(l+r)/2;}
            else if (nums[mid]>target){r=mid;mid=(l+r)/2;}
            else {return mid;}
        }
        if(nums[l]==target){return l;}
        else if (nums[r]==target){return r;}
        else {return -1;}
    }
};

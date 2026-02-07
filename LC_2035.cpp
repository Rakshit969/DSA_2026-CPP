#include<iostream>
#include<vector>
using namespace std;

int helper(vector<int>& nums,int i,int sum1,int sum2,int cnt1,int cnt2,int n) {
    if(i==nums.size()){
        if(cnt1 ==n/2 && cnt2==n/2) return abs(sum1 - sum2);
        return INT_MAX;
    }
    int ans=INT_MAX;
    if(cnt1<n/2) ans=min(ans,helper(nums,i+1,sum1+nums[i],sum2,cnt1+1,cnt2,n));
   
    if(cnt2<n/2) ans=min(ans,helper(nums,i+1,sum1,sum2+nums[i],cnt1,cnt2+1,n));

    return ans;
}

int minimumDifference(vector<int>& nums) {
    return helper(nums,0,0,0,0,0,nums.size());
}

int main(){
    vector<int> nums={1,5,6,11};
    cout<<minimumDifference(nums);
}
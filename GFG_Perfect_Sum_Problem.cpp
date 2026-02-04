#include<iostream>
#include<vector>
using namespace std;

// recursion
    // int helper(vector<int> & arr,int target,int n, int i){
        
    //     if(i>=n){
    //         if(target==0) return 1;
    //         else return 0;
    //     }
    //     if(arr[i]<= target){
    //         return helper(arr,target-arr[i],n,i+1)+helper(arr,target,n,i+1);
    //     }
    //     else return helper(arr,target,n,i+1);
    // }
    
    
    
    
    // dynamic programming
    int helper(vector<int>& arr,int n,int target,vector<vector<int>> dp){
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                dp[i][j]=dp[i-1][j];
                if(arr[i-1]<=j){
                    dp[i][j]+=dp[i-1][j-arr[i-1]];
                }
                
            }
        }
        return dp[n][target];
    }
    
    int perfectSum(vector<int>& arr, int target) {
        
        // code here
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        return helper(arr,n,target,dp);
    }

    int main(){}
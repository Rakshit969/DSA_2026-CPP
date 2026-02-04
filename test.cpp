#include<iostream>
#include<vector>
using namespace std; 
    
int helper(string s1,string s2,int n,vector<vector<int>>dp){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    }
    return dp[n][n];
}
int longestPalindromeSubseq(string s) {
    string s2=s;
    reverse(s2.begin(),s2.end());
    int n=s.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    return helper(s,s2,n,dp);
}

int main(){
    int ans=longestPalindromeSubseq("abaabaab");
    cout<<ans;
}
#include<iostream>
#include<vector>
using namespace std;

void helper(vector<int>& candidates, int target,vector<vector<int>> & ans,vector<int> & temp,int start){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        for(int i=start;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            helper(candidates,target-candidates[i],ans,temp,i);
            temp.pop_back();

        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>  temp;
        helper(candidates,target,ans,temp,0);
        return ans;
    }

    int main(){}
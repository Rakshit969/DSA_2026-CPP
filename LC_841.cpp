#include<iostream>
#include<vector>
#include<queue>
using namespace std;


bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int m=rooms.size();
        vector<bool> visited(m,false);
        queue<int> q;

        visited[0]=true;
        q.push(0);
        while(!q.empty()){
            int n=q.front();
            q.pop();
            for(int x:rooms.at(n)){
                if(visited[x]!=true){
                    q.push(x);
                    visited[x]=true;
                }
            }
        }
        for(int i=0;i<visited.size();i++){
            if(visited[i]==false) return false;
        }
        return true;
}

int main(){}
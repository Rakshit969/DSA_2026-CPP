#include<iostream>
#include<vector>
#include<queue>
#include <algorithm>

using namespace std;

int main(){

    int n,m;
    cin>> n >> m;

    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1,0);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;

    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> parent(n+1,-1);
    vector<int> countCities(n+1,0);

    countCities[1]=1;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:adj[u]){
            if(countCities[u]>0 && countCities[u]+1>countCities[v]){
                countCities[v]=1+countCities[u];
                parent[v]=u;
            }
            indegree[v]--;
            if(indegree[v]==0){
                q.push(v);
            }
        }
    }
    if(countCities[n]==0){
        cout<<"IMPOSSIBLE";
        return 0;
    }

    vector<int> path;
     for(int curr=n;curr!=-1;curr=parent[curr]){
        path.push_back(curr);
    }

    reverse(path.begin(),path.end());
    cout<<countCities[n]<<endl;
    for(int n:path){
        cout<<n<<" ";
    }


}
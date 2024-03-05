#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> BellmanFord(int V , vector<vector<int>>&edges ,int src){
	// Create a vector to store the shortest
	vector<int>distance(V,INT_MAX);
	distance[src]=0;
	// v-1 travels for longest possible path
	for(int i=0;i<V-1;i++){
		for(auto it : edges){
			int u = it[0];
			int v = it[1];
			int w = it[2];

			if(distance[u]!=INT_MAX and distance[v] > distance[u]+w) distance[v]=distance[u]+w;
		}
	}

	// vth traversal for checking any negitive cycle
	for(auto it : edges){
			int u = it[0];
			int v = it[1];
			int w = it[2];

			if(distance[u]!=INT_MAX and distance[v] > distance[u]+w) return {-1};
		}
	return  distance;
}
int main(){
	int n,m;
	cin>>n>>m;// n-> number of edges ,,,, m-> number of vertices 
	vector<vector<int>>edges;
	for(int i=0;i<m;i++){
		int u,v,w;// u,v are vertices and w is weight  between them
		cin>>u>>v>>w;
		edges.push_back({u,v,w});
	}

	 int src;
	 cin>>src;

	 vector<int>ans = BellmanFord(n,edges,src);

	 for(auto it : ans) cout<<it<<" ";
	return 0;
}

/*

3 4
0 1 5
1 0 3
1 2 -1
2 0 1
2

*/
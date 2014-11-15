/**
Kruskal's algorithm is used to find minimum spanning tree in a graph.
It is an edge based greedy algorithm, where we try to find the subset of edges
that would give us the minimum spanning tree.
Time complexity - O(ElogE + VlogE)
Space complexity - O(E+V)
Data Structures Used- Pair of(weight, Pair of(a, b)) for each edge a, b of weight w, Union And Find, Priority Queue.
Output - Minimum Spanning Tree with its cost.
**/

#include <iostream>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
//function to be used in sorting the edges on the basis of their weights.
bool compare(const pair<int, pair<int, int> > &p1, const pair<int, pair<int, int> >&p2)
{
	return p2.first > p1.first;
}
// to retrace back the path from a vertex
int parent[10000];
//This function returns the parent of a perticular node.
//this is the find function of Union-Find Data structure
int findParent(int x){
	if(x!= parent[x])
		findParent(parent[x]);
	return parent[x];
}
int main()
{
	vector <pair<int , pair<int , int> > > graph, mst; // graph and minimum spanning tree
	int n,m; // graph with n vertices and m edges
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a, b, w; // edge a to b of weight 'w'
		cin>>a>>b>>w;
		graph.push_back( pair<int, pair<int, int> >( w, pair <int, int> (a, b)));
	}
	//we initially set the parent of each node as the node itself.
	//this helps us to check for the graph completition.
	for(int i=0;i<n;i++)
		parent[i]=i;
    //sorted according to the weight of the edges
	sort(graph.begin(), graph.end(), compare);
	int k=0;
	int i=0;
	int totalLength = 0;
	//we find the n-1 edges that could possibly make the minimum spanning tree
	while(k != n-1)
	{
		int u = graph[i].second.first;
		int v = graph[i].second.second;
		int w = graph[i].first;

		int pu = findParent(u);
		int pv = findParent(v);
        //they can not have same parent, in which case, the edge is not included
        // in the minimum spanning tree.
		if(pu != pv){
			mst.push_back( pair < int , pair <int, int> > (w, pair<int , int> (u, v) ));
			totalLength += w;
			k++;
            //make one's parent equal to the others
			parent[u]=parent[v];
		}
		i++;
	}
	//total length
	cout<< totalLength<< endl;
	return 0;
}

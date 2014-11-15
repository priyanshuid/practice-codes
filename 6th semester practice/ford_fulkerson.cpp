#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
typedef struct vec_node vec_node;
using namespace std;
int it;
int pi[1000000];
struct vec_node
{
    int dest;
    int w;
};
bool bfs(vector <vec_node> Graph[], int n, int s, int t)
{

}
void fo_fu(vector <vec_node> Graph[], int n, int s, int t)
{
    bool v=bfs(Graph, n, s, t);
    if(v==true)
    {

    }

}
int main()
{
    int n,m;
    it=0;
    scanf("%d %d" , &n, &m);
    vector <vec_node>graph[n];
    for(int i=0;i<m;i++)
    {
        int a, b,w;
        vec_node vn;
        scanf("%d %d %d", &a, &b, &w);
        vn.dest=b;
        vn.w=w;
        graph[a].push_back(vn);
    }
    return 0;
}

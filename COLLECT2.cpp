#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define mod 3046201
typedef long long ll;
using namespace std;
long fact[3000001]={0};
long inv[3000001]={0};
vector<ll> modIn(3000001,0);
long highi=1;
long highf=1;
ll mulmod(ll a,ll b,ll c){
    ll x = 0,y=a%c;
    while(b > 0){
        if(b&1){
            x = (x+y)%c;
        }
        y=y<<1;
        y%=c;
        b=b>>1;
    }
    return x%c;    
}
ll modulo(ll a,ll b,ll c){
    ll x=1,y=a; 
    while(b > 0){
        if(b&1){
            x=mulmod(x,y,c);
        }
        y = mulmod(y,y,c); // squaring the base
        b/=2;
    }
    return x%c;
}
ll getfact(long n){
        if(fact[n]!=0)
        return fact[n];
        for(long i=highf+1;i<=n;i++)
                fact[i]=mulmod(fact[i-1],i,mod);
        highf=n;
        return fact[n];
}
ll getinv(long n){
        if(inv[n]!=0)
        return inv[n];
        for(long i=highi+1;i<=n;i++){
                inv[i]=mulmod(inv[i-1],modIn[i],mod);
        }
        highi=n;
        return inv[n];
}
long getMid(long s,long e){ return s+(e-s)/2;}
/*  A recursive function to get the sum of values in given range of the array.
    The following are parameters for this function.
 
    st    --> Polonger to segment tree
    index --> Index of current node in the segment tree. Initially 0 is
             passed as root is always at index 0
    ss & se  --> Starting and ending indexes of the segment represented by
                 current node, i.e., st[index]
    qs & qe  --> Starting and ending indexes of query range */
long getSumUtil( long*st, long ss, long se, long qs, long qe, long index)
{
    // If segment of this node is a part of given range, then return the 
    // sum of the segment
    if (qs <= ss && qe >= se)
        return st[index];
 
    // If segment of this node is outside the given range
    if (se < qs || ss > qe)
        return 0;
 
    // If a part of this segment overlaps with the given range
    long mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
/* A recursive function to update the nodes which have the given index in
   their range. The following are parameters
    st, index, ss and se are same as getSumUtil()
    i    --> index of the element to be updated. This index is in input array.
   diff --> Value to be added to all nodes which have i in range */
void updateValueUtil(long *st, long ss, long se, long i, long diff, long index)
{
    // Base Case: If the input index lies outside the range of this segment
    if (i < ss || i > se)
        return;
 
    // If the input index is in range of this node, then update the value
    // of the node and its children
    st[index] = st[index] + diff;
    if (se != ss)
    {
        long mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
// The function to update a value in input array and segment tree.
// It uses updateValueUtil() to update the value in segment tree
void updateValue(long arr[], long *st, long n, long i, long new_val)
{
    // Check for erroneous input index
    /*if (i < 0 || i > n-1)
    {
        prlongf("Invalid Input");
        return;
    }*/
 
    // Get the difference between new value and old value
    long diff = new_val - arr[i];
 
    // Update the value in array
    arr[i] = new_val;
 
    // Update the values of nodes in segment tree
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
// Return sum of elements in range from index qs (quey start) to
// qe (query end).  It mainly uses getSumUtil()
long getSum(long *st, long n, long qs, long qe)
{
    // Check for erroneous input values
    /*if (qs < 0 || qe > n-1 || qs > qe)
    {
        prlongf("Invalid Input");
        return -1;
    }
 */
    return getSumUtil(st, 0, n-1, qs, qe, 0);
}
 
// A recursive function that constructs Segment Tree for array[ss..se].
// si is index of current node in segment tree st
long constructSTUtil(long arr[], long ss, long se, long *st, long si)
{
    // If there is one element in array, store it in current node of
    // segment tree and return
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    // If there are more than one elements, then recur for left and
    // right subtrees and store the sum of values in this node
    long mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
/* Function to construct segment tree from given array. This function
   allocates memory for segment tree and calls constructSTUtil() to
   fill the allocated memory */
long *constructST(long arr[], long n)
{
    // Allocate memory for segment tree
    long x = (long)(ceil(log2(n))); //Height of segment tree
    long max_size = (1<<(x+1)) - 1; //Maximum size of segment tree
    long *st = new long[max_size];
 
    // Fill the allocated memory st
    constructSTUtil(arr, 0, n-1, st, 0);
 
    // Return the constructed segment tree
    return st;
}
vector<ll> inverseArray() {
    vector<ll> modInverse(1500001,0);
    modInverse[1] = 1;
    for(long i = 2; i <= 1500001; i++) {
        modInverse[i] = (-(mod/i) * modInverse[mod % i]) % mod + mod;
    }
    return modInverse;
}
//------------------------  MAIN--------------------------------------------------
int main(){
        fact[1]=1;
        fact[0]=1;
        inv[1]=1;
        inv[0]=1;
        long n,bush[100001],q,a,b,l,r;
        ll way,way2,way1,berry,peep,c1,c2,c3;
        char str[100];
        modIn[1] = 1;
        ll i,f=1;
    for(i = 2; i <= 1500001; i++) {
        modIn[i] = (-(mod/i) * modIn[mod % i]) % mod + mod;
    }
		/*for(i=2;i<=3000000;i++){
                f=mulmod(fact[i-1],i,mod);
                fact[i]=f;
        }*/
//      -----------------------------------------------program start----------------------------------
        scanf("%d",&n);
        for(i=0;i<n;i++)
                scanf("%d",&bush[i]);
        long *st=constructST(bush,n);
        /*for(i=0;i<7;i++){
                cout<<st[i]<<" ";
        }
        cout<<"\n";*/
        scanf("%d",&q);
        while(q--){
                way=1;
                scanf("%s %d %d",str,&a,&b);
                if(str[0]=='c'){
                        updateValue(bush,st,n,a-1,b);
                        /*for(i=0;i<6;i++)
                        cout<<bush[i]<<" ";
                        cout<<"\n";*/
                }
                else{
                        l=a;
                        r=b;
                        berry=getSum(st,n,l-1,r-1);
                        peep=r-l+1;
                        way=1;
                        way2=1;
                        if(berry==peep)
                        way=getfact(berry);
                        else if(berry<peep){
                                way=mulmod(getfact(peep),getinv(peep-berry),mod);
                        }
                        else if(berry>peep){
                                way2=1;
                                way1=getfact(berry);
                                c1=berry%peep;
                                c2=peep-c1;
                                c3=berry/peep;
                                for(i=1;i<=c1;i++)
                                        way2=mulmod(getinv(c3+1),way2,mod);
                                //way1=mulmod(way1,way2,mod);
                                //way2=1;
                                for(i=1;i<=c2;i++)
                                        way2=mulmod(getinv(c3),way2,mod);
                                way1=mulmod(way1,way2,mod);
                                way1=mulmod(way1,getfact(peep),mod);
                                if(c1==0)
                                way2=1;
                                else
                                way2=mulmod(getinv(c1),getinv(c2),mod);
                                way=mulmod(way1,way2,mod);
                        }
                        printf("%ld \n",way);
                }
        }
        return 0;
}



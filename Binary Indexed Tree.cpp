
// time complexity : update O(NlogN)  : N = number of elements
//                   query  O(QlogN)  : Q = number of query


#include<bits/stdc++.h>
using namespace std;
#define sz 100000
int a[sz];
int tree[sz];

void update(int idx,int val,int n)
{
   while(idx<=n)
   {
      tree[idx]+=val;
      idx+=(idx & -idx);
   }
}

int query(int idx)
{
   int sum = 0;

   while(idx>0)
   {
      sum+=tree[idx];
      idx-=(idx & -idx);
   }

   return sum;
}

int main()
{
   int i,n,q;
   cin>>n;

   for(i=1;i<=n;i++)
   {
      cin>>a[i];
      update(i,a[i],n);
   }


   cin>>q;

   cout<<"Result of Query : \n";

   for(i=0;i<q;i++)
   {
      int idx;
      cin>>idx;
      cout<<query(idx)<<endl;
   }
}
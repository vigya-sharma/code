#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int ceilloc(int a[], int l, int h, int k){
   int m;
   while(l<=h){
      m=(l+h)/2;
      if(a[m]<=k)
         l=m+1;
      else
         h=m-1;
   }
   return l;
}

int main(){
   int a[] = {3,4,5,5,6,8,7,8,7,8};
   vector<int> b(a, a+7);
   for(int i:b)
      cout<<i<<" ";
   cout<<endl;
   return 0;
}
/*
int main(){
   int n,t,i,c;
   int a[100000];
   cin>>t;
   while(t--){
      cin>>n;
      for(i=0;i<n;i++)
         cin>>a[i];
      c=0;
      sort(a,a+n);
      for(i=0;i<n-1;i++)
         c+= n-ceilloc(a,0,n-1,a[i]);
      cout<<c<<endl;
   }

   return 0;
}
*/

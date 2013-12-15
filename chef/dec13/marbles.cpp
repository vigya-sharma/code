#include <iostream>
using namespace std;

long int cfreq(long int tree[], int i){
   long int sum=0;
   while(i>0){
      sum+= tree[i];
      i-= (i&-i);
   }
   return sum;
}

int main(){
   int n,q;
   cin>>n>>q;

   int i,j;
   long int arr[n+1];
   long int tree[n+1];
   long int prev=0;
   for(i=1; i<=n; i++){
      cin>>arr[i];
      arr[i]+= prev;
      prev=arr[i];
   }


   //create tree
   tree[1] = arr[1];
   for(i=2; i<=n; i++){
      int s = i - (i & -i);
//      cout<<s<<endl;
      if(s==0)
         tree[i] = arr[i];
      else
         tree[i] = arr[i]-arr[s];
   }


   char c; int a,b; long int ans;
   while(q--){
      cin>>c>>a>>b;
//      cout<<c<<a<<b<<endl;
      a++; 
      if(c=='G'){
         while(a<=n){
            tree[a]+= b;
            a+= (a & -a);
         }
      }
      else if(c=='T'){
         while(a<=n){
            tree[a]-= b;
            a+= (a & -a);
         }
      }
      else{
         b++;
         if(a==1)
            ans = cfreq(tree, b);
         else
            ans = cfreq(tree, b) - cfreq(tree, a-1);
         cout<<ans<<endl;
      }
   }
   return 0;
}

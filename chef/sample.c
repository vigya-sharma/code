#include <stdio.h>
#include <stdlib.h>

inline void rd(int *t){
   register char c=0;
   while(c<33)
      c=getchar_unlocked();
   *t=0;
   while(c>33){
      *t = *t*10+c-'0';
      c = getchar_unlocked();
   }
}

int main()
{
   int n,b; int *arr; int min,l,r,i,q; float ans;
   rd(&n);
   arr = malloc(n*sizeof(int));
   for(i=0;i<n;i++)
      rd(&arr[i]);
   rd(&q);
   while(q--){
      rd(&l); rd(&r);
      min = arr[r];
      for(i=l;i<r;i++)
         min = (arr[i]<min)?arr[i]:min;
      ans=0;
      for(i=0;i<n;i++){
         if(i>=l && i<=r){
            ans = (ans<(float)min+((float)arr[i]-(float)min)/2)? (float)min+((float)arr[i]-(float)min)/2 : ans;
         }
         else
            ans = (ans<min+arr[i])?min+arr[i]:ans;
      }
      printf("%.1f\n",ans);
   }
   
   return 0;
}

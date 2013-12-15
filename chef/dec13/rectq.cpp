#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

struct distinct{
   int hash[10];
};

int main(){
   int n,q;
   scanf("%d", &n);
   int a[n+1][n+1];
   distinct d[n+1][n+1];
   int i,j;

   for(i=1;i<=n;i++){
      memset(d[i][0].hash, 0, sizeof(int)*10);
      for(j=1; j<=n; j++){
         scanf("%d", &a[i][j]);
         memcpy(d[i][j].hash, d[i][j-1].hash, sizeof(int)*10);
         d[i][j].hash[a[i][j]-1]++;
      }
   }


   scanf("%d", &q);
   int x1,x2,y1,y2;
   int ans[10];

   while(q--){
      scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
      memset(ans, 0, sizeof(ans));
      for(i=x1; i<=x2; i++){
         for(j=0; j<10; j++)
            ans[j]+= d[i][y2].hash[j] - d[i][y1-1].hash[j];
      }
      int c=0;
      for(i=0;i<10;i++)
         if(ans[i]>0)
            c++;
      printf("%d\n",c);
   }
   return 0;
}

#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

struct fset{
   int f;
   int c;
};

bool compare(const fset& a, const fset& b){
   if(a.f==b.f)
      return a.c>b.c;
   return a.f>b.f;
}

int main(){
   int t;
   cin>>t;

   int fcount[26];
//   char mapping[30], code[30];
   string mapping, code;
   string s,tmp;
   fset P[26];

   getline(cin, tmp);

   while(t--){
      getline(cin, code);
      getline(cin, s);
      memset(fcount, 0, sizeof(fcount));

//      cout<<"s:\n";
  //    cout<<s<<endl;
  //    cout<<"code:\n";
//      cout<<code<<endl;

      for(int i=0;i<s.length(); i++){
         if(s[i]>='a' && s[i]<='z')
            fcount[s[i]-'a']++;
         else if(s[i]>='A' && s[i]<='Z')
            fcount[s[i]-'A']++;
      }

      int k=0;
      for(int i=0; i<26; i++){
         if(fcount[i]>0){
            P[k].f = fcount[i];
            P[k].c = i;
            k++;
         }
      }
      sort(P, P+k, compare);
      for(int i=0; i<k; i++)
         mapping[P[i].c] = code[25-i];

      for(int i=0; i<s.length(); i++){
         if(s[i]>='a' && s[i]<='z')
            s[i] = mapping[s[i]-'a'];
         else if(s[i]>='A' && s[i]<='Z')
            s[i] = toupper(mapping[s[i]-'A']);
      }
      cout<<s<<endl;
   }
   return 0;
}

#include<bits/stdc++.h>
using namespace std;
int solve(int prev,int x,int y,int z){
      if(x==0 && y==0 && z==0){
         return 1;
      }
       int one=0,two=0,three=0;
      if(prev==1){
          if(x>0)
          one=solve(prev,x-1,y,z);
          if(y>0)
          two=solve(2,x,y-1,z); 
      }else if(prev==2){
        if(x>0)
          one=solve(1,x-1,y,z);
          if(y>0)
          two=solve(2,x,y-1,z); 
          if(z>0)
          three=solve(3,x,y,z-1);
      }else{
        if(y>0)
          two=solve(2,x,y-1,z); 
          if(z>0)
          three=solve(3,x,y,z-1);
      }
      return one+two+three;
}
int main (){
int x,y,z;
cin>>x>>y>>z;
cout<<solve(1,x-1,y,z)+solve(2,x,y-1,z)+solve(3,x,y,z-1);
return 0;
}
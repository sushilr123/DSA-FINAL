#include<bits/stdc++.h>
using namespace std;
int dp(int index,int count,string str,vector<vector<int>>&memo){
       if(index>str.size())return 0;
       if(index==str.size()){
            if(count==0)return 1;
            else return 0;
       }
       if(count<0)return 0;
       if(memo[index][count]!=-1)return memo[index][count];
       int x;
       if(str[index]=='('){
          x=dp(index+1,count+1,str,memo);
       }else if(str[index]==')'){
          x=dp(index+1,count-1,str,memo);
       }else{
        x=dp(index+1,count+1,str,memo)+dp(index+1,count-1,str,memo);
       }
       return memo[index][count]=x;
}
int main (){
string str;
cin>>str;
int n=str.size();
vector<vector<int>>memo(n+1,vector<int>(n+1,-1));
cout<<dp(0,0,str,memo);
cout<<'\n';
return 0;
}
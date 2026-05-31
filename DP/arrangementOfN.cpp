#include<bits/stdc++.h>
using namespace std;
int dp(int index,int val ,int target,vector<vector<int>>&mat){
    /*Invalid condition */
     if(index >target|| val>target){
         return 0;
     }
     /*matching condition*/
     if(val==target){
        return 1;
     }
     /*check if value is already calculated or not*/
     if(mat[index][val]!=-1){
        return mat[index][val];
     }
     /*Here i have two option contiune with same index or move to next index ..thats why i add here both the possibility then save and return*/

     return mat[index][val]=dp(index,val+index,target,mat)+dp(index+1,val+index,target,mat);
}
int main (){
int n;
cin>>n;
vector<vector<int>>mat(n+1,vector<int>(n+1,-1));
/*
mat[index][val]==>total arrangement of value val starting from index ;

*/
cout<<dp(1,0,n,mat);
return 0;
}



// // C++ implementation of above approach
// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the number
// // of partitions of N
// long long partitions(int n)
// {
//     vector<long long> p(n + 1, 0);

//     // Base case
//     p[0] = 1;

//     for (int i = 1; i <= n; ++i) {
//         int k = 1;
//         while ((k * (3 * k - 1)) / 2 <= i) {
//             p[i] += (k % 2 ? 1 : -1) * p[i - (k * (3 * k - 1)) / 2];

//             if (k > 0)
//                 k *= -1;
//             else
//                 k = 1 - k;
//         }
//     }

//     return p[n];
// }

// // Driver code
// int main()
// {
//     int N;
//     cin>>N;
//     cout << partitions(N);
//     return 0;
// }
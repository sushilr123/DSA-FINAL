/*
C - Four Variables  / 
Time Limit: 2 sec / Memory Limit: 1024 MiB

Score : 
300 points

Problem Statement
You are given a positive integer 
N.
Find the number of quadruples of positive integers 
(A,B,C,D) such that 
AB+CD=N.

Under the constraints of this problem, it can be proved that the answer is at most 
9×10^18
 .

Constraints
2≤N≤2×10^5
 
N is an integer.
Input
The input is given from Standard Input in the following format:
N
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
    
	int N;
	cin>>N;
	
	long long ans = 0;
	
	for(int i=1;i<N;i++){
		int X = i,Y = N-i;
		long long x = 0,y = 0;
		for(int j=1;j*j<=X;j++){
			if(X%j==0){
				x++;
				if(X!=j*j)x++;
			}
		}
		for(int j=1;j*j<=Y;j++){
			if(Y%j==0){
				y++;
				if(Y!=j*j)y++;
			}
		}
		ans += x * y;
	}
	
	cout<<ans<<endl;
	
	return 0;
}

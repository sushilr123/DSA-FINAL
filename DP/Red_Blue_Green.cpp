/*Description

You are given a string S of length N. You have to find the minimum number of characters you should change in S so that there will be a substring of length K in S that is also a substring of the infinite string "RGBRGBRGB ...".

Input Format

The first line of the input contains one integer T - the number of test cases. Then T test cases follow.

The first line of each test case contains two space-separated integers N, K.

The second line of each test case contains one string S.

Sum of N across all test cases ≤10^6.

Output Format

For each test case, print the minimum number of characters you should change in S so that there will be a substring of length K in S that is also a substring of the infinite string "RGBRGBRGB ...".

Constraints

1≤ T ≤ 100

1 ≤ K≤ N ≤ 2*105

Sum of N across all test cases ≤10^6.

Sample Input 1
3
4 1
BRRG
4 4
BBBG
2 2
GR
Sample Output 1
0
2
1
*/
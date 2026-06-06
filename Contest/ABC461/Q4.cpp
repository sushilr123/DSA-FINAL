#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector<string> grid(n);

    for(int i=0;i<n;i++)
        cin>>grid[i];

    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            a[i][j]=grid[i][j]-'0';

    long long ans=0;

    for(int top=0;top<n;top++)
    {
        vector<int> col(m,0);

        for(int bottom=top;bottom<n;bottom++)
        {
            for(int c=0;c<m;c++)
                col[c]+=a[bottom][c];

            unordered_map<long long,int> mp;
            mp[0]=1;

            long long pref=0;

            for(int c=0;c<m;c++)
            {
                pref+=col[c];

                if(mp.count(pref-k))
                    ans+=mp[pref-k];

                mp[pref]++;
            }
        }
    }

    cout<<ans<<"\n";
}
#include<bits/stdc++.h>
using namespace std;

int main (){

    int x;
    int q;

    cin >> x >> q;

    int curr = x;

    priority_queue<int, vector<int>, greater<int>>large;
    priority_queue<int> small;

    for(int i = 0; i < q; i++){

        int a, b;
        cin >> a >> b;
        int c=a+b;
        a=min(a,b);
        b=c-a;
        if(a <= curr){
            small.push(a);
        }else{
            large.push(a);
        }

        if(b <= curr){
            small.push(b);
        }else{
            large.push(b);
        }

        if(small.empty()){

            cout << large.top() << '\n';

            small.push(curr);

            curr = large.top();

            large.pop();

        }
        else if(large.empty()){

            cout << small.top() << '\n';

            large.push(curr);

            curr = small.top();

            small.pop();

        }
        else if(a <= curr &&  b>= curr){

            cout << curr << '\n';

        }
        else if(a<curr && b< curr){

            cout << small.top() << '\n';

            large.push(curr);

            curr = small.top();

            small.pop();

        }
        else{

            cout << large.top() << '\n';

            small.push(curr);

            curr = large.top();

            large.pop();
        }
    }

    return 0;
}
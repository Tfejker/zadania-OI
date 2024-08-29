#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m, a, b, how_far[200002], town[200002];
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>town[i];
    }
    int high_level=0;
    for(int i=1; i<=m; i++){
        high_level=0;
        cin>>a>>b;
        for(int j=a; j<=b; j++){
            if(town[j]==high_level+1) high_level++;
        }
        cout<<high_level<<endl;
    }

    return 0;
}
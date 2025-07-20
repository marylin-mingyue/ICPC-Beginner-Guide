#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> &a, pair<int,int> &b) {
    if (a.first!=b.first) return a.first<b.first;
    return a.second<b.second;

}
void solve() {
    int n;
    cin>>n;
    vector <pair <int,int>> a(n);
    vector <pair <int,int>> d(n);
    for (int i=0;i<n;i++) {
        int b,c;
        cin>>b>>c;
        a[i]={b+c,i};
        d[i]={b-c,i};
    }
    sort(a.begin(),a.end(),cmp);
    sort(d.begin(),d.end(),cmp);
    for (auto num:a) cout<<num.first<<" "<<num.second<<"|";
    cout<<endl;
    for (auto num:d) cout<<num.first<<" "<<num.second<<"|";
    cout<<endl;
    deque <pair <int,int>> dqa(a.begin(),a.end());
    deque <pair<int,int>> dqd (d.begin(),d.end());
    vector <int> vis(n);
    for (int i=0;i<n/2;i++) {
        int f=dqa.front().second;
        int g=dqd.front().second;
        int f1=dqa.back().second;
        int g1=dqd.back().second;
        while (vis[f]) {
            dqa.pop_front();
            f=dqd.front().second;
        }
        while (vis[g]) {
            dqd.pop_front();
            g=dqd.front().second;
        }
        while (vis[f1]) {
            dqa.pop_back();
            f1=dqd.back().second;
        }
        while (vis[g1]) {
            dqd.pop_back();
            g1=dqd.back().second;
        }
        int add_max=dqa.back().first-dqa.front().first;
        int diff_max=dqd.back().first-dqd.front().first;
        if (add_max>diff_max) {
            cout<<dqa.front().second+1<<" "<<dqa.back().second+1<<endl;

            vis[dqa.front().second]=1;
            vis[dqa.back().second]=1;
            dqa.pop_front();
            dqa.pop_back();
        }
        else {
            cout<<dqd.front().second+1<<" "<<dqd.back().second+1<<endl;

            vis[dqd.front().second]=1;
            vis[dqd.back().second]=1;
            dqd.pop_front();
            dqd.pop_back();
        }
    }


}
int main() {
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    int t; cin>>t;
    while (t--) {
        solve();
    }
}
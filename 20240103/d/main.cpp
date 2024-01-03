#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;
int main() {
    int N;
    cin >> N;
    vector<int> w(N);
    for (int i = 0; i < N; i++) {
        cin >> w[i];
    }
    vector<priority_queue<int>> pq(1);
    pq[0].push(-w[0]);
    for (int i = 1; i < N; i++) {
        int tmin = INF;
        int tmp = -1;
        for (int ip = 0; ip < (int)pq.size(); ip++) {
            int top = pq[ip].top();
            if (-top >= w[i]) {
                int ttm = min(tmin, -top - w[i]);
                if (ttm < tmin) {
                    tmin = ttm;
                    tmp = ip;
                }
            }
        }
        if (tmp == -1) {
            priority_queue<int> newone;
            newone.push(-w[i]);
            pq.push_back(newone);
        } else {
            pq[tmp].push(-w[i]);
        }
    }
    cout << pq.size() << endl;
}

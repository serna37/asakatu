#include <bits/stdc++.h>
using namespace std;
template <typename T> vector<T> divisors(T a) {
    vector<T> ans;
    for (T i = 1; i * i <= a; i++) {
        if (a % i != 0) continue;
        ans.push_back(i);
        if (a / i != i) ans.push_back(a / i);
    }
    return ans;
}
int main() {
    long long N;
    cin >> N;
    vector<long long> a = divisors(N);
    int M = a.size();
    long long sum = 0;
    for (int i = 0; i < M; i++) {
        if (a[i] == N) {
            continue;
        }
        sum += a[i];
    }
    if (sum > N) {
        cout << "Abundant" << endl;
    } else if (sum == N) {
        cout << "Perfect" << endl;
    } else {
        cout << "Deficient" << endl;
    }
}

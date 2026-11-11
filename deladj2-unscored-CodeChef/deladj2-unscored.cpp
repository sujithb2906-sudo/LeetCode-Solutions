
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        long long ans = 0;

        for (int L = 0; L < N; L++) {
            priority_queue<int> pq;
            long long sum = 0;
            long long selected = 0;

            for (int R = L; R < N; R++) {
                sum += A[R];
                pq.push(A[R]);
                selected += A[R];

                int len = R - L + 1;
                int need = len / 2;

                while ((int)pq.size() > need) {
                    selected -= pq.top();
                    pq.pop();
                }

                ans += sum - 2 * selected;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
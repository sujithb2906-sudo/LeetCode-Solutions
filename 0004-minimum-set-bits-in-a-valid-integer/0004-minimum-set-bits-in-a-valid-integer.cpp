class Solution {
public:
    int minSetBits(vector<int>& nums, int k) {
        const int B = 17, N = 1 << B;
        vector<int> cnt(B, 0), bad(N, 0);

        for (int i = 0; i < nums.size(); i++) {
            int mask = 0;
            for (int b = 0; b < B; b++) {
                cnt[b] += (nums[i] >> b) & 1;
                if (i >= k)
                    cnt[b] -= (nums[i-k] >> b) & 1;
                if (cnt[b] == k) mask |= 1 << b;
            }
            if (i >= k-1) {
                if (!mask) return -1;
                bad[mask] = 1;
            }
        }

        for (int b = 0; b < B; b++)
            for (int m = 0; m < N; m++)
                if (m & (1 << b))
                    bad[m] |= bad[m ^ (1 << b)];

        int ans = B;
        for (int y = 1; y < N; y++)
            if (!bad[(N-1) ^ y])
                ans = min(ans, __builtin_popcount(y));

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
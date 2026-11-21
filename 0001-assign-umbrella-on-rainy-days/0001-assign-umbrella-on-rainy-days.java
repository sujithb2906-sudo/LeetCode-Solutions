class Solution {
    public String[] assignUmbrella(int[] rain) {
        int n = rain.length;
        String[] answer = new String[n];

        int alice = 0;
        int bob = 0;

        for (int i = 0; i < n; i++) {
            if (rain[i] == 0) {
                answer[i] = "None";
            }
            else if (i < n - 1 && rain[i + 1] == 1) {
                if (alice <= bob) {
                    answer[i] = "Alice";
                    alice++;
                } else {
                    answer[i] = "Bob";
                    bob++;
                }
            }
            else {
                answer[i] = "Bob";
                bob++;
            }
        }

        return answer;
    }
}

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
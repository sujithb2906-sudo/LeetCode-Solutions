class Solution {
public:
      
      int minMoves(vector<int>&nums){

        int mx=-1;
        for (int i=0;i<nums.size();i++)
        {
            if(nums[i]> mx)
            {
                mx=nums[i];
            }
        }
        // The above loop finds the maximum value, but you need the minimum.
        // To find the minimum, initialize int mn = INT_MAX; and update when
        // nums[i] < mn.
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            // The statement sum+=mx=nums[i]; assigns nums[i] to mx and then
            // adds that value to sum, which is not the intended calculation.
            // After finding the minimum (mn), you should add (nums[i] - mn)
            // to sum for each element.
            sum+=mx-nums[i];
        }
        // The returned sum currently does not represent the required number
        // of moves. Replace the logic with the difference-to-minimum approach.
        return sum;
    // Note: The method's closing brace was missing in the original code.
    }
};
// Ensure the class definition ends with a closing brace and semicolon.

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
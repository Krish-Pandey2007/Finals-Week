### Hints

**Hint 1:** The minimum of the medians has to be maximized; this strongly suggests using binary search on the answer.

**Hint 2:** How do you check if the overall efficiency can be made >= x?

**Hint 3:** Find the minimum number of shots it takes to make the median of a particular l length subarray >= x.

**Hint 4:** To find the number of shots it takes to make the median of a subarray exceed x, replace all the elements < x by -1 and elements >= x by +1. 
The median exceeds x if the sum of the modified subarray strictly exceeds 0. 

**Hint 5:** Use dynamic programming to minimize the cost (total shots used) required to select k non overlapping sessions with median >= x. If this cost is <= M, it means an efficiency of x is achievable.

**Hint 6:** After finding the maximal efficiency, backtrack to find the optimal schedule.

---

### Solution

We binary search on the answer to find the maximum efficiency. To check if an efficiency >= x is possible, first pre-compute the number of shots it takes to make the median of every contiguous subarray of length L at least x. 

This can be done by replacing elements < x with -1, and elements >= x with +1. Let the sum of this modified subarray be S. We require S + 2 * cost[i] > 0 for the subarray to have a median >= x, where cost[i] is the minimum number of shots required to make the median of the subarray ending at the i-th index at least x.

We then compute the minimum number of shots required to make the overall efficiency at least x using dynamic programming. Define dp[i][j] as the minimum number of shots it takes to make the medians of j non-overlapping, L-length subarrays at least x, considering the first i elements of the array. Hence, dp[N][K] gives us the minimum number of shots required to achieve an overall efficiency >= x. 

The transition is as follows:

$$dp[i][j] = \min(dp[i-1][j], dp[i-L][j-1] + cost[i])$$

If dp[N][K] <= M, then an efficiency of x is achievable. This allows us to find the required maximum efficiency. 

To get the optimal sequence, backtrack through the DP grid while greedily choosing the sessions to start as late as possible.  


**Time Complexity:** `O(NKlog(max(a_i)))`  

**Space Complexity:** `O(NK)`

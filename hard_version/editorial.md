### Hints

**Hint 1:** The minimum of the medians has to be maximized; this strongly suggests using binary search on the answer.

**Hint 2:** How do you check if the overall efficiency can be made $\ge x$?

**Hint 3:** Find the minimum number of shots it takes to make the median of a particular $L$-length subarray $\ge x$.

**Hint 4:** To find the number of shots it takes to make the median of a subarray of length $L$ at least $x$, replace all elements $< x$ with $-1$ and elements $\ge x$ with $+1$. The median is $\ge x$ if the sum of the modified subarray strictly exceeds $0$.

**Hint 5:** Use WQS binary search (Alien's Trick) to find the minimum number of shots required to make the minimal median of the $K$ chosen subarrays $\ge x$.

---

### Solution

We binary search on the answer to find the maximum efficiency. To check if an efficiency $\ge x$ is possible, we first compute the minimum number of shots required to make the median of every contiguous subarray of length $L$ at least $x$. 

This can be done by replacing elements $< x$ with $-1$, and elements $\ge x$ with $+1$. Let the sum of this modified subarray be $S$. A single shot changes a $-1$ to a $+1$, increasing the sum by $2$. We require $S + 2 \cdot \text{cost}[i] > 0$ for the subarray to have a median $\ge x$. Thus, the minimum shots required for a valid subarray ending at index $i$ is $\text{cost}[i] = \max(0, \lfloor \frac{2 - S}{2} \rfloor)$.

We then compute the minimum number of shots required to construct exactly $K$ valid subarrays using WQS binary search and dynamic programming.

Let $f(p)$ be the minimum number of shots required to choose exactly $p$ valid subarrays of length $L$. The function $f(p)$ is convex because picking additional subarrays forces us to use increasingly suboptimal segments, meaning $f(p+1) - f(p) \ge f(p) - f(p-1)$. We are interested in finding $f(K)$. 

Because $f(p)$ is convex, we can remove the state dimension for $K$ by introducing a penalty (or reward since we are aiming to minimize) $\lambda$ for choosing a subarray, and instead minimize $f(p) - \lambda \cdot p$ globally. Given a $\lambda$, we define $dp[i]$ as the minimum cost using a prefix of length $i$ assuming that adding a subarray costs $\lambda$, and $cnt[i]$ as the maximum number of subarrays chosen to achieve this optimal cost:

$$dp[i] = \min(dp[i-1], dp[i-L] + \text{cost}[i] - \lambda)$$

If $dp[i-L] + \text{cost}[i] - \lambda \le dp[i-1]$, we transition from $i-L$ and update $cnt[i] = cnt[i-L] + 1$. Otherwise, $cnt[i] = cnt[i-1]$.

Higher values of $\lambda$ encourage the DP to select **more** subarrays. Lower values of lambda discourage selecting more subarrays as cost[i]>=0. Thus, we can binary search for the optimal $\lambda$ such that $cnt[N] \ge K$. 

Once the optimal $\lambda$ is found, the minimum number of shots to choose exactly $K$ subarrays is computed by removing the applied rewards: $f(K) = dp[N] + \lambda \cdot K$. If $f(K) \le M$, the efficiency $x$ is achievable, and the check function returns true.

**Time Complexity:** $\mathcal{O}(N \log(\max A_i) \log(\max\lambda))$  
**Space Complexity:** $\mathcal{O}(N)$

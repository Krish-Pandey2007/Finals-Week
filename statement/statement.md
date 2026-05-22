# E. The Finals Week

**Time Limit:** 3.0 seconds  
**Memory Limit:** 256 megabytes  

## Problem Description

The finals week at IITK has arrived, and productivity in the hostel study rooms has become wildly inconsistent.

The productivity throughout the week is represented by an array $A$ of $N$ integers, where $A_i$ denotes the productivity level during the $i$-th hour.

As endsems approach, a group of students decided that carefully designing the perfect study plan is considerably more important than opening any actual course material. They decide that their study plan must consist of exactly $K$ non-overlapping study sessions, where each individual session must span exactly $L$ consecutive hours.

The median productivity of a study session of length $L$ is defined as the element at position

```math
\left\lfloor \frac{L+1}{2} \right\rfloor
```

after sorting all elements of the session in non-decreasing order.

Fortunately, the students still have access to $M$ emergency caffeine shots. A single caffeine shot can be used during any hour $i$, permanently changing the productivity value $A_i$ to $10^9$.

The overall efficiency of the study plan is defined as the minimum median productivity among all $K$ selected sessions. The K selected sessions should be contiguous and non overlapping.

The students want to follow a schedule that maximizes this overall efficiency. They may use atmost M caffeine shots to attain this maximal efficiency. Because the students are master procrastinators, if there are multiple optimal schedules, they will always choose to delay their studying as much as possible. Formally, this means that amongst all sequences with the maximal efficiency, the chosen sequence is the lexicographically largest one when read from right to left. 


Your task is to print the starting positions of the sessions that achieve the optimal schedule.

---

## Input Format

The first line contains a single integer $T$ — the number of test cases.

For each test case:

- The first line contains four space-separated integers:
  - $N$ — total number of hours available.
  - $K$ — the exact number of non-overlapping study sessions required.
  - $L$ — the fixed duration (in hours) of each study session.
  - $M$ — the maximum number of caffeine shots available.

- The second line contains $N$ space-separated integers

```math
A_1, A_2, \dots, A_N
```

representing the baseline productivity levels for each hour.

---

## Output Format

For each test case, output one line:

- The line should contain $K$ space-separated integers in increasing order — the 1-based starting indices of the $K$ chosen sessions that form the optimal schedule.

---

## Constraints

```math
1 \le T \le 10
```

```math
1 \le N \le 2 \times 10^4
```

```math
1 \le K \le 100
```

```math
1 \le L \le N
```

```math
K \times L \le N
```

```math
0 \le M \le N
```

```math
1 \le A_i \le 10^8
```

---

## Sample Input

```text
1
5 2 2 1
2 1 4 3 5
```

---

## Sample Output

```text
2 4
```

---

## Explanation

We have:

```math
A = [2, 1, 4, 3, 5]
```

We need to select:

- $K = 2$ non-overlapping sessions,
- each of length $L = 2$,
- using at most $M = 1$ caffeine shot.

For $L = 2$, the median is the

```math
\left\lfloor \frac{2+1}{2} \right\rfloor = 1
```

st smallest element, i.e. the minimum element of the session.

If we apply one caffeine shot to the second hour ($A_2$), the array becomes:

```math
[2, 10^9, 4, 3, 5]
```

We choose:

- the first session starting at index $2$:
  
```math
[10^9, 4]
```

Its median is:

```math
\min(10^9, 4) = 4
```

- the second session starting at index $4$:

```math
[3, 5]
```

Its median is:

```math
\min(3, 5) = 3
```

Therefore, the overall efficiency is:

```math
\min(4, 3) = 3
```

No other valid configuration can achieve a higher minimum median.

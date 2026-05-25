# F. The Finals Week- Hard Version  

**Time Limit:** 3.0 seconds  
**Memory Limit:** 256 megabytes  

## Problem Description

The difference between this version and the easy version is that the constraints are larger, and in the easy version you need to output the optimal schedule, whereas in this version you must output the maximum possible overall efficiency.   

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

The students want to follow a schedule that maximizes this overall efficiency. They may use at most $M$ caffeine shots to achieve this value.

If multiple schedules attain the same overall efficiency, the students will always prefer the one that uses fewer caffeine shots.

Since the students are master procrastinators, if multiple valid schedules still remain, they will postpone studying as much as possible.

Formally, when comparing two schedules, the students prioritize the following criteria in order:

1. A schedule with a higher overall efficiency is always preferred.
2. If the overall efficiencies are equal, the schedule using fewer caffeine shots is preferred.
3. If both of the above are also equal, the students — being master procrastinators — choose the schedule whose sequence of starting indices is lexicographically largest when read from right to left.


Your task is to print the maximum overall efficiency.  

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

For each test case, output one integer- the maximum possible overall efficiency.  

---

## Constraints

```math
1 \le T \le 50
```

```math
1 \le N \le 2 \times10^5
```

```math
1 \le K \le N
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

```math
\text{The sum of } N \text{ over all test cases does not exceed } 5 \times 10^6
```

## Sample Input

```text
1
5 2 2 1
2 1 4 3 5
```

---

## Sample Output

```text
3
```

---

## Explanation

If we apply one caffeine shot to the second hour ($A_2$), the array becomes:

```math
[2, 10^9, 4, 3, 5]
```

We choose:

- the first session starting at index $2$:
  
```math
[10^9, 4]
```

- the second session starting at index $4$:

```math
[3, 5]
```

Therefore, the overall efficiency is:

```math
\min(4, 3) = 3
```

It can be proven that this configuration is optimal. 

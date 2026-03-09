# DSA — Count Subarrays of Length 3 in Arithmetic Progression

A focused C++ implementation that counts the number of **contiguous subarrays of length 3** that form an **Arithmetic Progression (AP)**. This problem is a great exercise in recognizing mathematical patterns embedded inside array traversal — a skill that shows up repeatedly in problems involving sequences, sliding windows, and difference arrays.

---

## Problem Statement

Given an array of `n` integers, count the number of **contiguous triplets** `(arr[i], arr[i+1], arr[i+2])` such that the three elements are in **Arithmetic Progression**.

**Example Input:**
```
Enter the number of elements in the array: 6
Enter the elements of the array: 1 3 5 7 5 3
```

**Example Output:**
```
The number of subarrays of length three satisfying the condition is: 3
```

---

## The Core Idea — What Makes Three Numbers an AP?

Three numbers `a`, `b`, `c` are in **Arithmetic Progression** if the difference between consecutive terms is constant:

```
b - a == c - b
```

Rearranging:

```
a + c == 2 * b
```

This is exactly the condition used in the code:

```cpp
if(arr[i] + arr[i+2] == 2 * arr[i+1])
```

This is both mathematically clean and computationally efficient — no division, no floating-point, just integer arithmetic.

---

## The Code

```cpp
#include<iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    for(int i = 0; i < n - 2; i++)
    {
        if(arr[i] + arr[i+2] == 2 * arr[i+1])
        {
            count++;
        }
    }

    cout << "The number of subarrays of length three satisfying the condition is: " << count;
    return 0;
}
```

---

## How It Works

1. **Read input** — The user enters the array size `n` and its elements.
2. **Slide a window of size 3** — The loop runs from `i = 0` to `i = n - 3` (i.e., `i < n - 2`), checking every consecutive triplet.
3. **AP check** — For each triplet `(arr[i], arr[i+1], arr[i+2])`, the condition `arr[i] + arr[i+2] == 2 * arr[i+1]` is evaluated.
4. **Count** — Every triplet that satisfies the condition increments `count`.
5. **Output** — The final count is printed.

---

## Algorithm (Pseudocode)

```
read n
read arr[0..n-1]

count ← 0

for i from 0 to n-3:
    if arr[i] + arr[i+2] == 2 * arr[i+1]:
        count ← count + 1

print count
```

---

## Dry Run

**Input:** `arr[] = {1, 3, 5, 7, 5, 3}`, `n = 6`

| `i` | Triplet      | Condition (`a + c == 2b`)         | AP? |
|-----|--------------|-----------------------------------|-----|
| 0   | (1, 3, 5)    | 1 + 5 = 6 == 2×3 = 6              | ✅  |
| 1   | (3, 5, 7)    | 3 + 7 = 10 == 2×5 = 10            | ✅  |
| 2   | (5, 7, 5)    | 5 + 5 = 10 ≠ 2×7 = 14            | ❌  |
| 3   | (7, 5, 3)    | 7 + 3 = 10 == 2×5 = 10            | ✅  |

**Output:** `The number of subarrays of length three satisfying the condition is: 3`

---

## Complexity Analysis

| Metric | Complexity |
|--------|------------|
| Time   | **O(n)** — single pass, one comparison per iteration |
| Space  | **O(n)** — array of size `n` allocated on the stack (VLA) |

The loop runs exactly `n - 2` times. There are no nested loops, no sorting, no auxiliary structures — just one clean linear scan.

> **Note on VLA:** `int arr[n]` is a Variable Length Array — a GCC extension (C99 standard) that is not part of standard C++. It compiles correctly with `g++` but may not compile on MSVC. For portable C++, prefer `std::vector<int> arr(n)`.

---

## Edge Cases

| Scenario | Behavior |
|----------|----------|
| `n < 3` | The loop condition `i < n - 2` handles this safely — the loop simply doesn't execute, and `count = 0` is printed |
| All elements equal (e.g., `{5, 5, 5}`) | Every triplet qualifies — common difference is `0`, which is a valid AP |
| Strictly increasing AP (e.g., `{2, 4, 6, 8}`) | All overlapping triplets are counted |
| No triplets qualify | `count` remains `0` — correct output |

**Example — All Equal:**
```
Input:  5 5 5 5
Output: The number of subarrays of length three satisfying the condition is: 2
```
*(Triplets: (5,5,5) at i=0 and (5,5,5) at i=1 — both valid APs with common difference 0)*

---

## Repository Structure

```
DSA-Subarrays-AP/
│
├── subarrays_ap.cpp      # Main C++ implementation
└── README.md             # Project documentation
```

---

## How to Compile and Run

**Prerequisites:** GCC / G++

```bash
# Clone the repository
git clone https://github.com/rishita-ops/DSA-Subarrays-AP.git
cd DSA-Subarrays-AP

# Compile
g++ subarrays_ap.cpp -o subarrays_ap

# Run
./subarrays_ap
```

**On Windows:**
```bash
g++ subarrays_ap.cpp -o subarrays_ap.exe
subarrays_ap.exe
```

---

## Key Concepts Covered

- **Arithmetic Progression (AP)** — a sequence where the difference between consecutive terms is constant
- **AP condition rewritten as** `a + c == 2b` — avoids subtraction, works cleanly with integers
- **Fixed-size sliding window of length 3** — iterating over every contiguous triplet in O(n)
- **Loop boundary** — `i < n - 2` ensures `arr[i+2]` never goes out of bounds, a critical correctness detail
- **VLA usage** — runtime-sized stack arrays in C with GCC

---

## Why This Problem Matters in DSA

This problem sits at the intersection of **math** and **array traversal**. The underlying patterns it builds:

| Concept | How It Connects |
|---------|-----------------|
| Fixed-size sliding window | Directly — a window of exactly 3 elements slides across the array |
| Difference Array | The AP check is essentially verifying that the first difference is constant |
| Sequence problems | AP/GP detection appears in problems on LeetCode, Codeforces, and FAANG interviews |
| Pattern recognition | Translating a math condition (`b - a == c - b`) into code (`a + c == 2b`) is a key interview skill |

The habit of **reformulating a condition** before coding it (turning subtraction into addition here to keep it integer-safe and readable) is something senior engineers do instinctively — this problem is a clean first exposure to that mindset.

---

## Contributing

Contributions are welcome. Consider adding:
- A version that also **prints the qualifying triplets**, not just the count
- A version that finds **subarrays of length > 3** in AP
- Implementations in Python, Java, or JavaScript

```bash
git checkout -b feature/your-feature
git commit -m "Add: your feature description"
git push origin feature/your-feature
# Then open a Pull Request
```

---

## License

This project is open-source and available under the [MIT License](LICENSE).

---

*Part of a structured DSA practice series — fundamentals, done right.*

# Problem A: A-Skew-ed Reasoning

**Source:** ICPC World Finals 2025 — Problem A
**Contest:** 49th ICPC World Championship
**Original problem statement:** ICPC Foundation (see official ICPC archive for the authoritative PDF)
**Time limit:** 2 seconds

> This is a paraphrased summary written for personal study and documentation purposes.
> Original problem statement and sample data are the property of the ICPC Foundation
> and are credited here, not claimed as original content.

## Summary (in my own words)

A **skew heap** is a binary min-heap: every node's value is less than or equal to the
values of its children, but unlike a normal heap it doesn't have to be balanced or
"complete" — left and/or right children can be missing at any node.

**Insertion rule** (inserting value `x` into heap `H`):
- If `H` is empty → `x` becomes a single-node heap.
- Otherwise, let `y` be the root's value:
  - If `y < x` → **swap the root's two children**, then recursively insert `x` into
    the (new) left subtree.
  - If `y >= x` → create a new node containing `x`, and make the old heap `H` its
    **left child** (the new node becomes the root).

The twist: given only the **final tree shape** that resulted from inserting some
permutation of `1..n` one value at a time into an empty heap, work backwards to find:

1. The lexicographically **smallest** permutation that could have produced this tree.
2. The lexicographically **largest** permutation that could have produced this tree.
3. If no permutation could have produced it, output `impossible`.

## Input format

- Line 1: integer `n` (1 ≤ n ≤ 2×10^5) — number of nodes.
- Next `n` lines: the `i`-th line gives `l_i` and `r_i`, the left and right child of
  the node storing value `i` (`0` means no child). Node values are guaranteed to be
  `1..n` exactly, and the data is guaranteed to describe a valid binary tree.

## Output format

- Two lines: the lex-min permutation, then the lex-max permutation (they may be equal
  — still print both).
- Or, if no valid permutation exists: a single line containing `impossible`.

## Sample 1

Input:
```
7
2 3
4 5
6 7
0 0
0 0
0 0
0 0
```
Output:
```
1 3 2 7 5 6 4
7 1 5 3 2 6 4
```

## Sample 2

Input:
```
2
0 2
0 0
```
Output:
```
impossible
```

## Sample 3

Input:
```
3
2 0
3 0
0 0
```
Output:
```
2 3 1
3 2 1
```


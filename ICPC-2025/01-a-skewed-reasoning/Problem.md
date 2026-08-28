# Problem A: A-Skew-ed Reasoning

**Source:** ICPC World Finals 2025 — Problem A
**Contest:** 49th ICPC World Championship
**Original problem statement:** © ICPC Foundation (see official ICPC archive for the authoritative PDF)
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

## Approach

Since the heap satisfies the min-heap property over distinct values `1..n`,
node `1` is always the final root — nothing else could have stayed on top.

The core difficulty is that the insertion rule swaps a node's children on
every insertion that passes through it, so a subtree isn't stably "the
left subtree" across the whole insertion history. The key observation:
once some node `u` becomes the root of the little heap it sits atop
(i.e. the point where it got inserted with everything-so-far as its old
heap), every element inserted *after* that point alternates strictly
between `u`'s two children, since each such insertion swaps children
before recursing.

That means: if `k` elements were inserted before `u`, everything after
is forced to alternate onto the two sides, starting from whichever side
inherits the pre-existing heap. Given `leftSize` and `rightSize` (from
the final subtree sizes), this alternation must land exactly `leftSize`
elements on the left and `rightSize` on the right — which pins `u`'s
position within its own subtree's insertion order to at most two
candidate values (one per choice of "which side was the old heap").
Solving the resulting parity equations for both orientations gives 0, 1,
or 2 valid positions:

- 0 valid positions → the tree is unreachable → `impossible` overall,
  independent of the rest of the tree.
- When two positions exist, they are always `1` and `2` — so choosing
  lex-min vs lex-max just means placing `u` first or second in its local
  sequence; no need to build and compare both candidate sequences.

Because children always carry a larger value than their parent (heap
property), the index order `n, n-1, ..., 1` is already a valid postorder:
every node's children are resolved before the node itself, with no
explicit recursion or traversal needed. For each node `u`, its final
per-subtree insertion sequence is built by merging its children's
sequences: elements before `u`'s position come entirely from one child
(the "old heap" side), elements after alternate between the two
children starting with the other side. The merge only needs to touch the
*shorter* of the two remaining pieces and splice it into an untouched
suffix of the longer one — the untouched prefix is never revisited.

If no valid permutation exists for any node encountered along the way,
report `impossible`; otherwise the sequence built at the root (node `1`)
is the desired lex-min or lex-max permutation.

One additional check has to happen before any of this: the input is
only guaranteed to be *a* valid binary tree shape, not a heap-ordered
one. A child with a value smaller than (or equal to) its parent can
never arise from real insertions, so this must be rejected as
`impossible` up front — before computing subtree sizes, since the
size computation relies on children being processed before parents.

## Complexity

- **Time:** `O(n log n)`. Each node does `O(1)` work to determine its
  candidate position(s). The merge step only touches the shorter of the
  two child sequences at each node (splicing it into an untouched
  suffix of the longer one); by the standard small-to-large argument,
  any single element can be on the "touched" side of a merge at most
  `O(log n)` times before it's absorbed into something at least twice
  as large, bounding the total merge cost at `O(n log n)`.
- **Memory:** `O(n log n)`. This matches the time bound rather than
  being a tighter `O(n)`: each merge step retains both children's
  sequences (the "old heap" side is reused in place, but the other
  side is left allocated rather than freed), so the same small-to-large
  argument that bounds the time cost also bounds total memory — an
  element can appear "duplicated" across live sequences `O(log n)`
  times over the run. In practice this stays small (tens of MB even at
  `n = 2×10^5`), well within typical limits, but it's not strict
  linear-in-`n` memory the way a fully in-place merge would be

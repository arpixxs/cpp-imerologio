# A-Skew-ed Reasoning — Notes

## 1. First observations

The given tree is a min-heap.

For every node `u`, its children have larger values than `u`. Since the nodes contain exactly the values `1..n`, node `1` is necessarily the root of the whole tree.

The difficult part is recovering the **insertion order**.

The insertion operation has two cases:

* If the inserted value `x` is smaller than the current root, `x` becomes a new root and the old heap becomes its left child.
* If the current root is smaller than `x`, the two children of the current root are swapped and the insertion continues into the new left subtree.

The second rule means that the two subtrees keep changing roles as more elements are inserted.

---

## 2. Look at one subtree

Suppose we are considering a subtree rooted at `u`.

Let its left and right subtrees have sizes:

```text
L = size(left subtree)
R = size(right subtree)
```

We want to know where `u` could have appeared in the insertion sequence for this subtree.

There are two possibilities for the elements that appeared **before `u`**.

### Possibility A

All elements before `u` belonged to the left subtree.

When `u` was inserted, the previous heap became its left child.

After that, every larger element that travels through `u` causes its children to swap before continuing downwards.

Therefore the remaining elements alternate between the right and left subtree.

So the final sequence has the structure

```text
[left prefix], u, right element, left element, right element, left element, ...
```

The exact number of elements in each part is determined entirely by `L` and `R`.

### Possibility B

All elements before `u` belonged to the right subtree.

The same argument applies, but the roles of the two subtrees are reversed.

Therefore, from only `L` and `R`, we can determine the possible positions of `u`.

There can be:

```text
0, 1, or 2
```

valid positions.

If there are no valid positions, this subtree — and therefore the whole tree — is impossible.

---

## 3. Why there are at most two positions

Once the position of `u` is fixed, the number of elements before `u` is fixed.

Everything before `u` must belong completely to one of the two child subtrees.

Everything after `u` alternates between the two subtrees.

So the sizes `L` and `R` give a fixed equation for the number of elements before `u`.

Considering the two possible choices for which subtree contained the prefix gives at most two solutions.

This is much better than trying possible insertion positions one by one.

---

## 4. Important observation about the two-position case

The official solution has an especially useful observation:

> If there are two possible positions for a node, they are exactly the first two positions of its sequence.

That means the two possibilities are simply:

```text
position 1
position 2
```

Therefore:

* for the lexicographically smallest answer, choose position `1`;
* for the lexicographically largest answer, choose position `2`.

This avoids having to compare two complicated candidate sequences.

---

## 5. What happens after the root is inserted?

Suppose the sequence for a subtree is being constructed and `u` occurs at some position.

Everything before `u` belongs entirely to one child subtree.

After `u`, the remaining elements alternate between the two child subtrees.

For example, one orientation can look like:

```text
A-prefix, u, B1, A1, B2, A2, B3, A3, ...
```

The other orientation is:

```text
B-prefix, u, A1, B1, A2, B2, A3, B3, ...
```

Which orientation occurs depends on which subtree contained the prefix and on the parity of the number of elements after `u`.

This is the key structural property of the problem.

---

## 6. Recursive construction

For every node, recursively construct the valid insertion sequence for its left and right subtrees.

Then combine those sequences according to the position of the current node.

For each subtree we need two versions:

```text
minimum sequence
maximum sequence
```

When constructing the minimum answer, choose the lexicographically smaller valid possibility.

When constructing the maximum answer, choose the lexicographically larger valid possibility.

Because the only time two positions are possible is when they are the first two positions, the choice is straightforward:

```text
minimum → first position
maximum → second position
```

---

## 7. Interleaving the two child sequences

After deciding where `u` occurs, the remaining elements from the two child sequences have to be interleaved.

The important implementation observation is that we do **not** need to copy both complete sequences every time.

Suppose one child sequence is longer than the other.

The shorter sequence is inserted into an equally sized suffix of the longer sequence.

Conceptually:

```text
longer prefix | longer suffix
              ↑
              shorter sequence is interleaved here
```

For example, if we have

```text
A = a1 a2 a3 a4 a5
B = b1 b2
```

we only need to merge `B` with the last two elements of `A`:

```text
a1 a2 | a3 a4 a5
       b1 b2
```

and obtain an alternating sequence such as

```text
a1 a2 b1 a3 b2 a4 a5
```

depending on the required orientation.

This is important for the time complexity.

---

## 8. Why the solution is `O(n log n)`

At every merge, the amount of new work is proportional to the size of the **smaller** child sequence.

An individual element can belong to the smaller side only logarithmically many times.

Why?

Every time an element is in the smaller side, the size of the sequence it belongs to at least doubles when it is merged into the larger side.

Since there are only `n` elements, this can happen at most:

```text
O(log n)
```

times for each element.

Therefore the total time is:

```text
O(n log n)
```

and the memory usage is:

```text
O(n)
```

---

## 9. Detecting an impossible tree

During the recursive construction, if a node has no valid position consistent with the sizes of its two subtrees, then no insertion sequence can produce that subtree.

Therefore the whole answer is:

```text
impossible
```

as soon as such a node is found.

This also explains why a tree can satisfy the ordinary min-heap property and still be impossible: the skew-heap insertion rule imposes additional restrictions on the possible insertion orders.

---

## 10. Final algorithm

The overall approach is:

1. Compute the size of every subtree.
2. Recursively process the tree.
3. For each node, determine its possible positions from the sizes of its left and right subtrees.
4. If there are no valid positions, return `impossible`.
5. Recursively obtain the minimum and maximum sequences for both children.
6. Interleave the child sequences according to the insertion parity.
7. For the minimum answer, use the earliest possible position.
8. For the maximum answer, use the latest possible position.
9. Print both resulting permutations.

The crucial idea is:

> **After a node becomes the root, later insertions alternate between its two subtrees because the children are swapped before every recursive insertion.**

That alternating structure is what makes it possible to reconstruct the insertion order efficiently.

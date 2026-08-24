# A-Skew-ed Reasoning — my notes

Started by just staring at the tree for a while. Since it's a min-heap on
values `1..n`, node `1` has to be the root — nothing else can be, since a
heap parent is always smaller than its children. That part's free.

The actual problem is the insertion rule messing with which subtree is
"left" and which is "right" over time:

- insert `x`: if root `y < x`, **swap the root's two children**, then
  recurse the insert into the (new) left child.
- if `y >= x`, `x` becomes the new root and the old heap hangs off its left.

That swap-then-recurse is the whole difficulty. It means a subtree isn't
stably "the left subtree" across the whole insertion history — it flips
back and forth depending on what gets inserted after it.

## Poking at small cases by hand

I worked through inserting `1,2,3,4` step by step on paper before trying
to generalize anything. What jumped out: once some node `u` becomes the
root of its little subtree (because it got inserted while sitting on top
of whatever heap existed before it), everything inserted *after* that
point just alternates between `u`'s two children. Left, right, left,
right... because every insertion below `u` swaps children first.

So if I fix "how many elements came before `u`," everything after is
forced — it has to alternate, and I know exactly how many go to each
side from the subtree sizes. That's the whole trick, really: the sizes
`leftSize` and `rightSize` pin down where `u` *could* have sat in the
sequence, up to at most two candidate positions (whether the stuff before
`u` was donated by the left side or the right side).

Wrote it out as an equation rather than searching: if `k` elements came
before `u`, and the rest alternate starting with side A or side B, the
final counts on each side have to match `leftSize`/`rightSize` exactly.
Solving that for both orientations gives 0, 1, or 2 valid values of `k`
per node. Zero valid positions = the whole tree is impossible, full stop
— doesn't matter what the rest of the tree looks like.

The nice bonus (found this only after grinding through a few more
examples): when there ARE two candidate positions, they're always
positions 1 and 2. So I never have to build both candidate sequences and
compare — min just means "put `u` first," max means "put `u` second."
Saved a lot of pain.

## Building it back up

Once I know where `u` goes in its own subtree's sequence, I still need
the actual sequence, and that means recursively knowing the sequences for
the left and right children first — this is basically a postorder thing.
Handy fact I only noticed once I looked at the numbering again: children
always have a bigger value than their parent (heap property), so I can
just walk `u = n, n-1, ..., 1` and every child is already done by the
time I get to its parent. No need for an explicit recursive call stack,
no explicit tree traversal — just a flat loop. Also sidesteps any
recursion-depth worries on a heavily skewed tree.

The merge step: everything before `u` came entirely from one child
(whichever one), everything after alternates B, A, B, A,... To build the
combined list I don't need to touch every element of the longer child
sequence — the short sequence only needs to be spliced into an
equal-length tail of the long one, the untouched prefix stays where it
is. This is the part that keeps it from being `O(n^2)` in the worst case
(fully skewed trees), since each element only gets "touched" again when
it's on the smaller side of a merge, and that can only happen `O(log n)`
times before it's absorbed into something at least twice as big.
Net result: `O(n log n)` time, `O(n)` memory.

## Gotcha I want to flag for future-me

The tree shape given in the input is only guaranteed to be *a* valid
binary tree — nothing in the problem statement says it's already
heap-ordered. It's tempting to assume every child label is bigger than
its parent's (which is true for any tree that actually *could* have come
from real insertions), but a judge could absolutely hand you a tree that
violates that, and the correct answer there is just `impossible` — no
different, structurally, from any other unreachable shape. Worth checking
for explicitly before doing anything else with the sizes, since the rest
of the algorithm quietly assumes it and won't fail loudly if you skip it.

## Complexity

- Time: `O(n log n)` — each node does O(1) work for its own position math,
  and the merge cost across the whole algorithm is bounded by the
  small-to-large argument above.
- Memory: `O(n)` — every value lives in exactly one sequence at a time.
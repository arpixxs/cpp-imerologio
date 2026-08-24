
#include <bits/stdc++.h>
using namespace std;

vector<int> 

buildAnswer(int n,
                        const vector<int>& L,
                        const vector<int>& R,
                        const vector<int>& sz,
                        bool wantMin) {
    vector<vector<int>> seq(n + 1);

    // Every child has a larger label than its parent.
    // So n -> 1 is already a postorder traversal.
    for (int u = n; u >= 1; --u) {
        int l = L[u];
        int r = R[u];

        int leftSize = l ? sz[l] : 0;
        int rightSize = r ? sz[r] : 0;

  /*
            There are at most two possible positions

            Case 1:
            An even number of elements come after u.
            The heap that existed before u eventually becomes
            the left subtree.

            Case 2:
            An odd number of elements come after u.
            The old heap eventually becomes the right subtree.
  */

        bool evenCase = (leftSize >= rightSize);
        int evenPos = leftSize - rightSize + 1;

        bool oddCase = (leftSize >= 1 &&
                        rightSize >= leftSize - 1);
        int oddPos = rightSize - leftSize + 2;

        if (!evenCase && !oddCase)
            return {}; // no permutation can produce this tree

        int pos;

        if (wantMin) {
            pos = INT_MAX;

            if (evenCase)
                pos = min(pos, evenPos);

            if (oddCase)
                pos = min(pos, oddPos);
        }
        else {
            pos = -1;

            if (evenCase)
                pos = max(pos, evenPos);

            if (oddCase)
                pos = max(pos, oddPos);
        }

        int after = sz[u] - pos;

 /*
            If u is the first element, there is no old heap.

            After u is inserted, every new insertion swaps the
            two children first. Therefore the subtree receiving
            positions 1,3,5,... of the remaining sequence depends
            on the parity of the number of remaining elements.
 */
        if (pos == 1) {
            int A, B;

            if (after & 1) {
                // Left subtree gets positions 1,3,5,...
                A = l;
                B = r;
            }
            else {
                // Right subtree gets positions 1,3,5,...
                A = r;
                B = l;
            }

            vector<int>& a = seq[A];
            vector<int>& b = seq[B];

            vector<int> cur;
            cur.reserve(sz[u]);

            cur.push_back(u);

            size_t m = max(a.size(), b.size());

            for (size_t i = 0; i < m; ++i) {
                if (i < a.size())
                    cur.push_back(a[i]);

                if (i < b.size())
                    cur.push_back(b[i]);
            }

            seq[u] = move(cur);
        }
        else {
              /*
                Everything before u belongs completely to one
                subtree. Call that subtree A.

                After u:
                    B gets positions 1,3,5,...
                    A's remaining elements get positions 2,4,6,...

                So we only need to interleave B with the suffix
                of A.
  */

            int A, B;

            if ((after & 1) == 0) {
                // Old heap becomes the left subtree.
                A = l;
                B = r;
            }
            else {
                // Old heap becomes the right subtree.
                A = r;
                B = l;
            }

            vector<int>& a = seq[A];
            vector<int>& b = seq[B];

            int prefix = pos - 1;

            // First part of A was inserted before u.
            vector<int> tail(a.begin() + prefix, a.end());

            a.resize(prefix);
            a.push_back(u);

            // Then B and the remaining part of A alternate.
            size_t m = max(tail.size(), b.size());

            for (size_t i = 0; i < m; ++i) {
                if (i < b.size())
                    a.push_back(b[i]);

                if (i < tail.size())
                    a.push_back(tail[i]);
            }

            seq[u] = move(a);
        }
    }

    return move(seq[1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> L(n + 1);
    vector<int> R(n + 1);
    vector<int> sz(n + 1);

    for (int i = 1; i <= n; ++i)
        cin >> L[i] >> R[i];

    /* A skew heap must satisfy the min-heap property: every child's value
     is strictly greater than its parent's. The problem only guarantees
     that the input is *some* valid binary tree shape, not that it's
     heap-ordered — so a child with a smaller (or equal) label than its
     parent is a legitimate "impossible" case, not something we can
     assume away. Without this check, the size computation below reads
    sz[] entries that haven't been filled in yet (since it walks n..1
     assuming children always have larger indices), producing garbage
    */ or crashing.
    for (int u = 1; u <= n; ++u) {
        if ((L[u] && L[u] <= u) || (R[u] && R[u] <= u)) {
            cout << "impossible\n";
            return 0;
        }
    }

    // Compute subtree sizes.
    for (int u = n; u >= 1; --u) {
        sz[u] = 1;

        if (L[u])
            sz[u] += sz[L[u]];

        if (R[u])
            sz[u] += sz[R[u]];
    }

    // Lexicographically smallest permutation.
    vector<int> mn = buildAnswer(n, L, R, sz, true);

    if (mn.empty()) {
        cout << "impossible\n";
        return 0;
    }

    // Lexicographically largest permutation.
    vector<int> mx = buildAnswer(n, L, R, sz, false);

    for (int i = 0; i < n; ++i) {
        if (i)
            cout << ' ';

        cout << mn[i];
    }

    cout << '\n';

    for (int i = 0; i < n; ++i) {
        if (i)
            cout << ' ';

        cout << mx[i];
    }

    cout << '\n';

    return 0;
}

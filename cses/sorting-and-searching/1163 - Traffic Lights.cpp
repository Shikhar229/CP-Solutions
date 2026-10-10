#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int x, n;
    cin >> x >> n;

    set<int> positions;
    multiset<int> lengths;

    // Initial state: street goes from 0 to x
    positions.insert(0);
    positions.insert(x);
    lengths.insert(x);

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;

        // Find the right boundary (first element greater than p)
        auto r_it = positions.upper_bound(p);
        int right = *r_it;
        
        // Find the left boundary (the element right before r_it)
        int left = *prev(r_it);

        // Remove the old segment length
        lengths.erase(lengths.find(right - left));

        // Insert the two new segment lengths
        lengths.insert(p - left);
        lengths.insert(right - p);

        // Insert the new light position
        positions.insert(p);

        // The maximum length is the last element in the multiset
        cout << *lengths.rbegin() << (i == n - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}
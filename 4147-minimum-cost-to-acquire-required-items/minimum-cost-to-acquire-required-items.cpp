using ll = long long;
class Solution {
public:
    long long minimumCost(int c1, int c2, int c3, int n1, int n2) {
    long long ln1 = n1, ln2 = n2; // Promote to long long immediately

    long long t1 = ln1 * c1 + ln2 * c2;
    long long t2 = ln2 * c3 + ((ln1 > ln2) ? (ln1 - ln2) * c1 : 0);
    long long t3 = ln1 * c3 + ((ln2 > ln1) ? (ln2 - ln1) * c2 : 0);
    long long t4 = max(ln1, ln2) * c3;

    return min({t1, t2, t3, t4});
}


};
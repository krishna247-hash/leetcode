class Solution {
public:
    int fib(int n) {
        
    double phi = (1 + sqrt(5)) / 2;
    double psi = (1 - sqrt(5)) / 2;

    int f = (pow(phi, n) - pow(psi, n)) / sqrt(5);
        return f;
    }
};
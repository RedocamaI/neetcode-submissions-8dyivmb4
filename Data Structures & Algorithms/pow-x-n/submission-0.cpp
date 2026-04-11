class Solution {
public:
    double getPow(double x, int n) {
        if(n == 0)  return 1;
        if(n == 1)  return x;
        if(n%2)
            return getPow(x, n/2) * getPow(x, n/2 + 1);

        return getPow(x, n/2) * getPow(x, n/2); 
    }

    double myPow(double x, int n) {
        if(n < 0)   return 1/myPow(x, -1*n);
        if(n%2)
            return x * myPow(x, n-1);
        
        double ans = getPow(x, n);
        return ans;
    }
};

class Solution {
public:
    int flag=-1;
    void check(double n)
    {
        if(n==1.0)
        {
            flag=0;
            return;
        }
        else if(n<3)
            return;
        check(n/3);
    }
    bool isPowerOfThree(int n) {
        check(n);
        if(flag==0)
            return true;
        return false;
    }
};
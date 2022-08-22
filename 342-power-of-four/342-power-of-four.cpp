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
        else if(n<4)
        { return;}
        check(n/4);
    }
    bool isPowerOfFour(int n) {
       check(n);
        if(flag==0)
           return true;
        return false;
        
    }
};
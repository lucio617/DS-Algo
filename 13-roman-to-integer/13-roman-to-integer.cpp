class Solution {
public:
    int roman(char ch){
        switch(ch){
            case 'I':
            return 1;
            break;
            
             case 'V':
            return 5;
            break;
            
             case 'X':
            return 10;
            break;
                
             case 'L':
            return 50;
            break;
                
             case 'C':
            return 100;
            break;
                
             case 'D':
            return 500;
            break;
            
             case 'M':
            return 1000;
            break;
                
            default:
                return -1;
                break;
        }
    }
    int romanToInt(string s) {
        int ans=0;
        ans=roman(s[s.size()-1]);
        for(int i=s.size()-1;i>0;i--){
            if(roman(s[i-1])>=roman(s[i])){
                ans+=roman(s[i-1]);
            }
            if(roman(s[i-1])<roman(s[i])){
                ans=ans-roman(s[i-1]);
            }
        }
        return ans;
        
    }
};
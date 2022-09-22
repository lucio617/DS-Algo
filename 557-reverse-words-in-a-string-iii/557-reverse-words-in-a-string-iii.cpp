class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string res;
        while(ss>>word)
        { reverse(word.begin(),word.end());
         res=res+word;
         res=res+" ";
        }
        res.pop_back();
        return res;
        
    }
};
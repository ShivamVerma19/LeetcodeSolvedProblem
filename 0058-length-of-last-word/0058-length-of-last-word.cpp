class Solution {
public:
    int lengthOfLastWord(string s) {

        int size=s.size()-1;
        int x=0;

        while(size>=0)
        {
            if(isalpha(s[size]))
            {
                x++;
                size--;
            }
            else
            {
                if(x != 0)
                break;
                else
                size--;
            }
        }
        return x;
        
    }
};
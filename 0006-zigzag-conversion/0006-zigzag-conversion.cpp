class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        
        string st;
        int len = s.size();
        int i = 0, j, k;

        while(i < numRows && st.size() != len){
            j = i;
            int remFromBelow = numRows - (i+1);
            int remFromUP = i;
            k = 1;
            while(j < len && st.size() != len){

                st.push_back(s[j]);

                if(i == 0) j += remFromBelow * 2;

                else if (i == numRows - 1) j += remFromUP * 2;

                else if((k & 1)) j += remFromBelow * 2;
                
                else if(k % 2 == 0) j += remFromUP * 2;
                k++;
            }
            i++;
        }
        return st;
    }
};
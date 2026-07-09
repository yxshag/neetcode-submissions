class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //reverse the arr
        reverse(digits.begin(),digits.end());
        //keep adding 1 to the digits as long as there is a carry
        int carry=1;
        for(int i=0;i<digits.size();i++){
            int sum=(digits[i]+carry);
            carry=sum/10;
            digits[i]=sum%10;
        }
        //at the end if the carry is still one, add a 1
        if(carry==1){digits.push_back(1);}
        //bring back the list to original form
        reverse(digits.begin(),digits.end());
        return digits;
    }
};

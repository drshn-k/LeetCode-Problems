class Solution {
public:
    string DecimalToBinary(int num)
{
    string str;
      while(num){
      if(num & 1) // 1
        str+='1';
      else // 0
        str+='0';
      num>>=1; // Right Shift by 1 
    }   
      return str;
}
 

    int minOperations(int n) {
        int count = 0, ans = 0;
        for(int i = 0; i <= log2(n); ++i){
            if(n & (1 << i )) {  count++; } //when bit is 1
            else if(count) {                //when bit is 0 but count is > 0
                if(count == 1) { ans += 1; count = 0; }              //when we have only 1 count, no need to add any 1 or grouping
                else if(count && n & (1 << (i+1)) ) { ans += 1; count = 1; }   //if we have 1 just next to current zero then simply ans++, to count addition of 1 to the existing group of 1 to single 1 
                else { ans += 2; count = 0;  } // when combination of 1s found with two zeros in cont. found then simply convert this 1's to zero with 2 more operations
            }
        }
        ans += (count < 2)?count:2;
        return (ans);
    }
};
class Solution {
public:
   double myPow(double x, int n) {
     if(n==0) return 1;
     else if(n%2==0){
         double y=pow(x,n/2);
         return y*y;
     }   
     else{
         return x*pow(x,n-1);
     }
    }
};
//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
       long long left=0,right=n-1,left_sum = 0,right_sum =0;
        while(left < right)
        {
            if(left_sum==0 and right_sum == 0)
            {
                left_sum += arr[left];
                right_sum += arr[right];
                left++,right--;
            }
            else if(left_sum < right_sum)
                left_sum += arr[left++];
            
            else
                right_sum += arr[right--];
        }
        return left_sum == right_sum ? left+1 : -1;
        // Your code here
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
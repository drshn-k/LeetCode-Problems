class Solution {
public:
    int romanToInt(string s) {
        int a = 1;
        char I = (char)a;
        int b = 5;
        char V = (char)b;
        int c = 10;
        char X = (char)c;
        int d = 50;
        char L = (char)d;
        int e = 100;
        char C = (char)e;
        int f = 500;
        char D = (char)f;
        int g = 1000;
        char M = (char)g;
        
        cin >> s;
            int value = s[s.size()-1];
        
        for(int i = s.size()-2 ; i > 0 ; i--){
          if (s[i] < value)
          {
            value = value - s[i];

          }
            else value = value + s[i];
        } 

        if (s[0] < s[1])
        {
            value = value - s[0];
        }

        return value;

    }
};
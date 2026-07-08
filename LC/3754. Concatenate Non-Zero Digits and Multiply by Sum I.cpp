class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)    return 0;
        string str = "";
        long long sum = 0;
        while(n>0){
            int c = n%10;
            n/=10;
            sum+=c; 
            if(c!=0)    str+=(c + '0');
        }
        reverse(str.begin(), str.end());
        int num = stoi(str);
        return num*sum;
    }
};
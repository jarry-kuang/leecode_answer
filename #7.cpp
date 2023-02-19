#7.cpp

class Solution {
public:
    int reverse(int x) {
    	int flag = x<0 ? 1:0;//if x<0, then 1, else 0
    	int ans = 0;
    	if(!flag) x = -x;
    	while(x!=0){
    		if(ans< INT_MIN/10 || ans> INT_MAX/10) return 0;
    		int digit = x%10;
    		x/=10;
    		ans = ans*10+digit;
    	}
    	if(!flag) return -ans;
    	return ans;
    }
};
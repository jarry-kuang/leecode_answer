#5.cpp
class Solution {
public:
	int expand(const string&s, int left, int right){  //expand around center
		while(left >= 0 && right < s.size() && s[left] == s[right]){
			--left;
			++right;
		}
		return (right-left-2)/2;
	}

    string longestPalindrome(string s) {
        int start = 0, end = -1;
        string t = "#"; //ensure start on '#'
        for(char c:s){ //end '#'
        	t += c;
        	t += '#';
        }
        s = t;

        std::vector<int> arm_len; //save len on each char
        int right = -1,j = -1;
        for(int i=0; i< s.size(); i++){
        	int cur_arm_len;
        	if(right >= i){
        		int i_sym = j * 2 - i;
        		int min_arm_len  = min(arm_len[i_sym],right-i);
        		cur_arm_len = expand(s,i - min_arm_len,i + min_arm_len);
        	}else{
        		cur_arm_len = expand(s,i,i);
        	}
        	arm_len.push_back(cur_arm_len);

        	if(i+cur_arm_len > right){ //renew j and right
        		j = i;
        		right = i+cur_arm_len;
        	}

        	if(cur_arm_len*2+1 > end-start){ //if new search palindromic larger then old, renew
        		start = i- cur_arm_len;
        		end = i+ cur_arm_len;
        	}
        }

        string ans;
        for(int i= start;i<=end; i++){
        	if(s[i]!='#'){
        		ans+=s[i];
        	}
        }
        return ans;
    }
};
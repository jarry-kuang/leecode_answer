#8.cpp
class Automation{
	string state = "start";
	unordered_map<string,std::vector<string>> hashtable = {
		{"start",{"start","signed","in_number","end"}},
		{"signed",{"end","end","in_number","end"}},
		{"in_number",{"end","end","in_number","end"}},
		{"end",{"end","end","end","end"}},
	};

	int get_col(char c){
		if(isspace(c)) return 0;
		if(c=='+' || c=='-') return 1;
		if(isdigit(c)) return 2;
		return 3;
	}

public:
	int sign = 1;
	long long ans = 0;

	void get(char c){
		state = hashtable[state][get_col(c)];
		if(state == "in_number"){
			ans = ans *10 + c - '0';
			ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if(state == "signed")
        	sign = c == '+' ? 1:-1;
	}
};



class Solution {
public:
    int myAtoi(string s) {
    	Automation automa;
    	for(char c:s) automa.get(c);
    	return automa.sign * automa.ans;
    }
};
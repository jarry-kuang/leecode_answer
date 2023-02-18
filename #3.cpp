#3.cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	unordered_set<char> hashset;
    	int i = s.size();
    	int tail = -1; //set tail as defult
    	int nose = -1; //set nose as defult
    	int ans = 0;
    	for(nose=0; nose < i; nose++){ //move nose on first
    		if(nose!=0){
    			hashset.erase(s[nose-1]);
    		}
    		while(tail+1 < i && !hashset.count(s[tail + 1])){ 
    		// while tail is not at the string end and char in hashaset has not same
    			hashset.insert(s[tail+1]); //add char into hashset
    			tail++; //move to next locate
    		}
    		ans = max(ans, tail-nose+1);
    	}
    	return ans;
    }
};
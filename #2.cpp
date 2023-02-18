#2.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode* nose = nullptr; ListNode* tail = nullptr;
    	int carry = 0;
    	while(l1 || l2){ //loop at l1 or l2 both valued
    		int n1 = l1 ? l1->val: 0; // if l1 have val then n1 equal l1, otherwise n1=0
    		int n2 = l2 ? l2->val: 0; // if l2 have val then n1 equal l2, otherwise n2=0
    		int sum = n1+n2+carry;
    		if(!nose){ //if nose is null
    			nose = tail = new ListNode(sum % 10); //address nose and tail
    		} else{
    			tail->next = new ListNode(sum % 10); //address new tail
    			tail = tail->next; //move tail on new tail
    		}
    		carry = sum / 10;
    		if(l1){
    			l1 = l1->next; //move to next int
    		}
    		if(l2){
    			l2 = l2->next;//move to next int
    		}
    	}
    	if(carry > 0){
    		tail->next = new ListNode(carry); //if carry>0 write extra
    	}
    	return nose;
    }
};
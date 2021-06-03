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
        struct ListNode *head = NULL;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
        
            struct ListNode* temp = new ListNode;
            temp->val = (carry + l1->val + l2->val)%10;
            temp->next = NULL;
            carry = (carry + l1->val + l2->val)/10;
            
            l1 = l1->next;
            l2 = l2->next;
            
            
            if(head==NULL){
                head = temp;
            }
            else{
                struct ListNode *temp2 = head;
                while(temp2->next!=NULL){
                    temp2 = temp2->next;
                }
                temp2 -> next = temp;
            }
            
        }
        
        while(l1!=NULL){
            struct ListNode* temp = new ListNode;
            temp->val = (carry + l1->val)%10;
            temp->next = NULL;
            
            carry = (carry + l1->val)/10;
            
            l1 = l1->next;
            
            struct ListNode *temp2 = head;
            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }
            temp2 -> next = temp;
            
        }
        while(l2!=NULL){
            struct ListNode* temp = new ListNode;
            temp->val = (carry + l2->val)%10;
            temp->next = NULL;
            
            carry = (carry + l2->val)/10;
            
            l2 = l2->next;
            
            struct ListNode *temp2 = head;
            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }
            temp2 -> next = temp;
        }
        
        if(carry){
            struct ListNode* temp = new ListNode;
            temp->val = carry;
            temp->next = NULL;
            
            struct ListNode *temp2 = head;
            while(temp2->next!=NULL){
                temp2 = temp2->next;
            }
            temp2 -> next = temp;
        }
        
        return head;
    }
};


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

/* In Approach - 2, we will NOT be using any extra Recursive Stack Space
To save space, we will use be using iterative approach to Reverse Nodes in Groups of K
Instead of using Start, here we will be using beforeStart which points to the Node before Start Pointer
We also need to store the End's Next in temp variable
After reversing, we just have to make:
a) beforeStart -> next = End
b) Start -> next = temp
Move beforeStart to Start & end to temp for next set of reversals
*/

class Solution {
private :

void reverse(ListNode *s , ListNode *e)
{
    ListNode *p = NULL ;
    ListNode *c = s ;
    ListNode *n = s -> next ;
    while(p != e)
    {
        c -> next = p ;
        p = c ;
        c = n ;
        if(n != NULL)
            n = n -> next ;
    }

}

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
    if(head == NULL || head -> next == NULL || k == 1)
        return head ;
    ListNode *dummy = new ListNode(-1) ;
    dummy -> next = head ;

    ListNode *beforeStart = dummy ;
    ListNode *e = head ;
    int i = 0 ;

    while(e != NULL)
    {
        i++ ;

        if(i % k == 0)
        {
            ListNode *s = beforeStart -> next ;
            ListNode *temp = e -> next ;
            reverse(s , e) ;
            beforeStart -> next = e ;
            s -> next = temp ;
            beforeStart = s ;
            e = temp ;

        }
        else
            e = e -> next ;
    }

   

    return dummy -> next ;

}
};


//
// Created by admin on 21/11/2021.
//

//METHOD 1 (Using Recursion)
//Use two pointers left and right. Move right and left using recursion and check for following in each recursive call.
//1) Sub-list is a palindrome.
//2) Value at current left and right are matching.

bool isPalindrome(struct node* head)
{
    isPalindromeUtil(&head, head);
}
bool isPalindromeUtil(struct node** left, struct node* right)
{
    if (right == NULL)
        return true;
    bool isp = isPalindromeUtil(left, right->next);
    if (!isp)
        return false;
    bool isp1 = (right->data == (*left)->data);
    *left = (*left)->next;

    return isp1;
}
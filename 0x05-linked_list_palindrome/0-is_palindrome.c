#include "lists.h"
/**
 * compare - Compare the numbers of two linked lists
 * @head1: pointer to the head of the list
 * @head2: pointer to the head of the second half of the list
 * @flag: middle pointer to stop the loop
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
 */
int compare(listint_t *head1, listint_t *head2, listint_t *flag)
{
	listint_t *temp1 = head1, *temp2 = head2;

	while (temp1 && temp2)
	{
		if (temp1->n == temp2->n)
			temp1 = temp1->next, temp2 = temp2->next;
		else
			return (0);
	}
	return (temp1 == flag ? 1 : 0);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: pointer to the head of the list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 * An empty list is considered a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow = *head, *fast = *head, *second_half = NULL;
	listint_t *flag = NULL, *prev = NULL, *next = NULL;

	if (head == NULL)
		return (0);
	if (!(*head) || !(*head)->next)
		return (1);

	while (fast && fast->next)
	{
		slow = slow->next; /* First of the second half */
		fast = fast->next->next;
	}
	/* If there are odd elements in the list: fast is not null, slow is the */
	/* middle node (flag) and the first of the second half will be slow->next */
	flag = slow;

	if (fast)
		slow = slow->next;
	second_half = slow;

	while (second_half)
	{	/* Reverse the second half: */
		next = second_half->next;
		second_half->next = prev;
		prev = second_half;
		second_half = next;
	}
	second_half = prev;
	return (compare(*head, second_half, flag));
}

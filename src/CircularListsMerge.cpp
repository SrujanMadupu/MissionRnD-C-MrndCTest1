/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>
int circularcount(struct node *q);
int count(struct node *q);
int merge_circularlists(struct node **head1, struct node **head2);
struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	if (*head1 != NULL&&*head2 != NULL){
		int l1 = count(*head1);
		int l2 = count(*head2);
		struct node *merge;
			struct node *tempA, *tempB, *rA, *rB;
			tempA = *head1;
			tempB = *head2;
			while (tempA != NULL&&tempB != NULL){
				if (tempA->data <= tempB->data){
					if (tempA->next != NULL){
						if (tempB->data < tempA->next->data){
							rA = tempA->next;
							tempA->next = tempB;
							tempA = rA;
						}
						else{
							tempA = tempA->next;
						}
					}
					else{
						tempA->next = tempB;
						while (tempB->next != *head2){
							tempB = tempB->next;
						}
						tempB->next = *head1;
						merge = *head1;
					}
				}
				else{
					if (tempB->next != NULL){
						if (tempA->data <= tempB->next->data){
							rB = tempB->next;
							tempB->next = tempA;
							tempB = rB;
						}
						else{
							tempB = tempB->next;
						}
					}
					else{
						tempB->next = tempA;
						while (tempA->next != *head1){
							tempA = tempA->next;
						}
						tempA->next = *head2;
						merge = *head2;
					}
				}
			}
			return l1+l2;
	}
	else{
		return -1;
	}
}
int count(struct node *q){
	struct node *temp;
	temp = q;
	int c = 0;
	while (temp->next != NULL){
		c = c + 1;
		temp = temp->next;
	}
	return c;
}
int circularcount(struct node *q){
	struct node *temp;
	temp = q;
	int c = 0;
	while (temp->next != q){
		c = c + 1;
		temp = temp->next;
	}
	return c;
}
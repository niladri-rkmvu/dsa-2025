/*------------------------------------------- 
		Linked List
------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int length = 0;

struct Node
{
	int data;
	struct Node *next;
}*head=NULL, *tail=NULL;

struct Node * create_node(int val)
{
	struct Node *temp;
	temp = (struct Node *)malloc(sizeof(struct Node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void delete_node(struct Node *p)
{
	free(p);
}

void create_linked_list(int A[],int n)
{
	struct Node *t;

	head=create_node(A[0]);
	length++;
	tail=head;

	for(int i=1; i<n; i++)
	{
		t = create_node(A[i]);
		tail->next = t;
		tail = t;
		length++;
	}
}

void display()
{
	struct Node *p = head;
	int i = 1;
	while(p != NULL)
	{
		printf("Node : %d\n", i);
		printf("Data = %d\n", p->data);
		printf("Next = %p\n", p->next);
		printf("-------------------\n");
		p = p->next;
		i++;
	}
	printf("length = %d\n",length);
	printf("head = %d\n",head->data);
	printf("tail = %d\n",tail->data);
	printf("-------------------\n");
}

void display_H(char msg[])
{
	printf("%s\n",msg);
	struct Node *p = head;
	int i = 1;
	while(p != NULL)
	{
		printf("%d->", p->data);
		p = p->next;
		i++;
	}
	printf("NULL\n");
	printf("\n");
	printf("length = %d\n",length);
	printf("head = %d\n",head->data);
	printf("tail = %d\n",tail->data);
	printf("-------------------\n");
}

void RDisplay(struct Node *p)
{
	if(p!=NULL)
	{
		printf("%d\n",p->data);
		RDisplay(p->next);
	}
}

void rev_display(struct Node *p)
{
	if(p!=NULL)
	{
		rev_display(p->next);
		printf("%d\n",p->data);
	}
}

int count(struct Node *p)
{
	int c = 0;
	while(p != NULL)
	{
		c++;
		p=p->next;
	}
	return c;
}

int Rcount(struct Node *p)
{
	if (p==0){
		return 0;
	}
	else{
		return Rcount(p->next)+1;
	}
}

int sum(struct Node *p)
{
	int sum = 0;
	while(p != NULL)
	{
		sum = sum + p->data;
		p = p->next;
	}
	return sum;
}

int Rsum(struct Node *p)
{
	if(p==NULL)
		return 0;
	else
		return Rsum(p->next) + p->data;
}

int max(struct Node *p)
{
	int max_val = INT_MIN;
	while(p != NULL){
		if (p->data > max_val)
			max_val = p->data;
		p = p->next;
	}
	return max_val;
}

int Rmax(struct Node *p)
{
	int x = INT_MIN;
	if (p==0)
		return INT_MIN;
	else{
		x = Rmax(p->next);
		if (p->data > x)
			return p->data;
		else
			return x;
	}
}

struct Node * LSearch(struct Node *p, int key)
{
	while(p!=NULL)
	{
		if (p->data == key)
			return p;
		p = p->next;
	}
	return NULL;
}

struct Node * Rsearch(struct Node *p, int key)
{
	if (p==NULL)
		return NULL;
	if (p->data == key)
		return p;
	return Rsearch(p->next,key);
}

struct Node * LSearch_MVH(struct Node *p, int key)
{
	struct Node *q = NULL;
	while(p!=NULL)
	{
		if(p->data!=key)
		{
			q = p;
			p = p->next;
		}
		else
		{
			if(p!=head)
			{
				q->next = p->next;
				p->next = head;
				head = p;
			}
			return p;
		}
	}
	return NULL;
}

// append and prepend logic is getting covered in insert
// separate functions can still be created

int insert(int index, int val)
{
	if(index<0 || index>length)
		return 0;

	struct Node *new_node = create_node(val);

	if (index==0)
	{
		new_node->next = head;
		head=new_node;
	}
	else
	{
		struct Node *p=head;
		
		for(int i=0; i<index-1; i++)
			p=p->next;

		new_node->next = p->next;
		p->next = new_node;

		if(index == length)
			tail = new_node;
	}
	length++;
	return new_node->data;
}

struct Node *pop()
{
	if (length == 0)
		return NULL;

	struct Node *temp = head;
	struct Node *pre = head;

	while(temp->next != NULL)
	{
		pre = temp;
		temp = temp->next;
	}
	pre->next = NULL;
	tail = pre;
	length--;
	if(length==0)
	{
		head=NULL;
		tail=NULL;
	}
	return temp;
}

struct Node *pop_first()
{
	if (length == 0)
		return NULL;

	struct Node *temp = head;
	head = head->next;
	length--;
	if(length==0)
	{
		head=NULL;
		tail=NULL;
	}
	temp->next=NULL;
	return temp;
}

struct Node *get(int index)
{
	if(index<1 || index>length)
		return NULL;

	struct Node *temp = head;

	for(int i=1; i<index; i++)
		temp = temp->next;

	return temp;
}

int set_value(int index,int val)
{
	if(index<1 || index>length)
		return 0;

	struct Node *temp = head;

	for(int i=1; i<index; i++)
		temp = temp->next;

	temp->data = val;

	return val;
}

struct Node *remove_node(int index)
{
	if(index<1 || index>length)
		return NULL;

	if(index==1)
		return pop_first();

	if(index==length)
		return pop();

	struct Node *pre = get(index-1);
	struct Node *temp = pre->next;

	pre->next = temp->next;
	temp->next = NULL;

	length--;

	if(length==0)
	{
		head=NULL;
		tail=NULL;
	}
	return temp;
}

int reverse_elements()
{
	int size = count(head);
	int A[size];

	struct Node *p = head;
	int i = 0;

	while (p != NULL)
	{
		A[i] = p->data;
		p = p->next;
		i++;
	}

	p = head;
	i--;

	while (p != NULL)
	{
		p->data = A[i];
		p = p->next;
		i--;
	}
	return 1;
}

int reverse()
{
	if(length<=1)
		return 0;

	struct Node *before = NULL;
	struct Node *after = NULL;
	struct Node *temp = head;

	head = tail;
	tail = temp;

	// for(int i=1; i<=length; i++)
	// {
	// 	after = temp->next;
	// 	temp->next = before; // pointer is getting reversed
	// 	before = temp;
	// 	temp = after;
	// }

	while(temp!=NULL)
	{
		after = temp->next;
		temp->next = before; // pointer is getting reversed
		before = temp;
		temp = after;
	}
	return 1;
}

void make_empty()
{
    struct Node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
    length = 0;
}

int sorted()
{
	struct Node *p = head;
	int node_val = p->data;

	if (length == 0 || length == 1)
		return -1;

	while (p != NULL)
	{
		if (node_val > p->data)
			return 0;
		else
			node_val = p->data;
		p = p->next;
	}
	return 1;
}

int insert_node_sorted_ll(int val)
{
	struct Node *p = head;
	struct Node *q = NULL;
	int result = 0;

	if(sorted()==0)
	{
		printf("The LL is not sorted\n");
		return 0;
	}
	else if (sorted()==-1)
		printf("The LL has 1 element or 0 elements. Hence no need to sort\n");
	else
		printf("LL is sorted. Hence proceeding\n");


	// check if the val is lower than 1st node
	if (val < p->data)
		result = insert(0,val);
	else
	{
		while(p && p->data<val)
		{
			q = p;
			p = p->next;
			printf("-----------\n");
			printf("q = %d\n",q->data);
			
			if (p) 
			    printf("p = %d\n", p->data);
            else 
                printf("p = NULL\n");
		}
		struct Node *t = create_node(val);
		if (q->next == NULL)
			tail = t;
		t->next = q->next;
		q->next = t;
		length++;
	}
	printf("-----------\n");
	return 1;
}

void remove_duplicate_node_sorted_ll()
{
	struct Node *p = head;
	struct Node *q = head->next;

	while (q != NULL)
	{
		if(p->data != q->data)
		{
			p = q;
			q = q->next;
		}
		else
		{
			p->next = q->next;
			delete_node(q);
			length--;
			q = p->next;
		}
	}
	if (p->next == NULL)
		tail = p;
}

struct Node *isloop()
{
	struct Node *f = head;
	struct Node *s = head;

	while(f && s && f->next)
	{
		s = s->next;
		f = f->next->next;
		if(s==f)
			return s;
	}
	return NULL;
}

struct Node *detect_first_node_in_cycle(struct Node *p)
{
	if (p == NULL)
		return NULL;

	struct Node *s = head;
	while(p != s)
	{
		p = p->next;
		s = s->next;
		if(p==s)
			return p;
	}
	return NULL;
}

struct Node *entry_point_circular_ll()
{
	struct Node *meeting_point = isloop();
	struct Node *entry;
	
	if(meeting_point)
	{
		printf("Loop detected! Meeting Point: %d\n", meeting_point->data);
		entry = detect_first_node_in_cycle(meeting_point);

		if (entry)
		{
            printf("Cycle starts at node with data: %d\n", entry->data);
            return entry;
		}
		else
		{
			printf("Unable to find the entry point\n");
			return NULL;
		}
	}
	else
	{
		printf("No loop detected.\n");
		return NULL;
	}
}

void display_circular_LL(struct Node *entry)
{
    int flag = 0;
	struct Node *p = head;
	while(p != entry || flag == 0)
	{
	    if (p == entry)
	        flag = 1;
	        
	    printf("%d->",p->data);
		p = p->next;
	}
	printf("[%d]\n",entry->data);
	printf("head = %d\n",head->data);
	printf("tail = %d\n",tail->data);
	printf("length = %d\n",length);
	printf("------------------\n");
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {10, 20, 20, 30, 30, 40};

	// ---------------------------
    // Test 1: Create and Display
    // ---------------------------
    create_linked_list(A, 5);
    display_H("Initial List:");

    // ---------------------------
    // Test 2: Count, Sum, Max
    // ---------------------------
    printf("Count = %d\n", count(head));
    printf("RCount = %d\n", Rcount(head));
    printf("Sum = %d\n", sum(head));
    printf("RSum = %d\n", Rsum(head));
    printf("Max = %d\n", max(head));
    printf("RMax = %d\n", Rmax(head));

    // ---------------------------
    // Test 3: Search
    // ---------------------------
    // struct Node *found = LSearch(head, 30);
    // printf("LSearch 30: %p\n", found);
    // found = Rsearch(head, 40);
    // printf("RSearch 40: %p\n", found);
    // found = LSearch_MVH(head, 20);
    // display_H("After MVH Search for 20:");

    // ---------------------------
    // Test 4: Insert
    // ---------------------------
    // insert(0, 5); // prepend
    // insert(3, 25); // middle
    // insert(length, 60); // append
    // display_H("After Insertions:");

	// ---------------------------
    // Test 5: Get and Set
    // ---------------------------
    // struct Node *node = get(3);
    // printf("Get index 3: %d\n", node->data);
    // set_value(3, 99);
    // display_H("After Set index 3 to 99:");

    // ---------------------------
    // Test 6: Pop
    // ---------------------------
    // struct Node *last = pop();
    // printf("Popped last: %d\n", last->data);
    // delete_node(last);
    // struct Node *first = pop_first();
    // printf("Popped first: %d\n", first->data);
    // delete_node(first);
    // display_H("After Pops:");

    // ---------------------------
    // Test 7: Remove Node
    // ---------------------------
    // struct Node *removed = remove_node(2);
    // printf("Removed index 2: %d\n", removed->data);
    // delete_node(removed);
    // display_H("After Remove index 2:");

    // ---------------------------
    // Test 8: Reverse Elements
    // ---------------------------
    // reverse_elements();
    // display_H("After Element Reverse:");

    // ---------------------------
    // Test 9: Reverse Pointers
    // ---------------------------
    // reverse();
    // display_H("After Pointer Reverse:");

	// ---------------------------
    // Test 10: Sorted Check
    // ---------------------------
    // printf("Is Sorted? %d\n", sorted());

    // ---------------------------
    // Test 11: Insert Sorted
    // ---------------------------
    // insert_node_sorted_ll(35);
    // display_H("After Sorted Insert 35:");

	// ---------------------------
    // Test 12: Remove Duplicates
    // ---------------------------
    // make_empty();
    // create_linked_list(B, 6);
    // display_H("Before Removing Duplicates:");
    // remove_duplicate_node_sorted_ll();
    // display_H("After Removing Duplicates:");

    // ---------------------------
    // Test 13: Cycle Detection
    // ---------------------------
    // make_empty();
    // create_linked_list(A, 5);
    // tail->next = head->next; // create cycle
    // struct Node *entry = entry_point_circular_ll();
    // if (entry)
    //     display_circular_LL(entry);

    // // Cleanup
    // tail->next = NULL; // break cycle

    make_empty();
    return 0;
}

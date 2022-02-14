#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node node;
typedef struct queue queue;

struct node
{
	int val;
	node* next;
};

struct queue
{
	node* front;
	node* rear;
};


queue* create()
{
	return calloc(1, sizeof(queue));
	/*queue* q;
	q = malloc(sizeof(queue));
	q->front = NULL;
	q->rear = NULL;
	return q;*/
}

void enqueue(queue* q, int val)
{
	//node* p = malloc(sizeof(queue));
	//p->next=NULL;防止遍历到队列尾部野指针问题
	node* p = calloc(1, sizeof(queue));
	if (!p)
	{
		printf("Error:enqueue malloc fault!");
		return;
	}
	p->val = val;
	//p->next = NULL;
	if (!q->front)
	{
		q->front = p;
		q->rear = p;
	}
	else
	{
		q->rear->next = p;
		q->rear = p;
	}
}

void dequeue(queue* q)
{
	node* p = q->front;
	q->front = p->next;
	free(p);
}

int size(queue* q)
{
	if (!q->front)
		return 0;
	node* p = q->front;
	int count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return count;
}

bool isEmpty(queue* q)
{
	return q->front == NULL;
}

void destroy(queue* q)
{
	node* p = q->front;
	while (p)
	{
		node* tmp = p;
		p = p->next;
		free(tmp);
	}
	free(q);
}

int front_val(queue* q)
{
	return q->front->val;
}


int main()
{
	queue* q = create();
	printf("%d\n", isEmpty(q));
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	dequeue(q);
	dequeue(q);
	dequeue(q);
	printf("%d\n", front_val(q));
	dequeue(q);
	printf("%d\n", size(q));
	destroy(q);
}
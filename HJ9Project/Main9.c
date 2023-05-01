#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int count = 0;
int n;
int front = 0, rear = 0;
int* queue;

void enQueue(int data) {

	if ((rear + 1) % (n + 1) == front) {
		printf("큐가 꽉 찼습니다.\n");
		return;
	}

	rear = (rear + 1) % (n + 1);
	queue[rear % (n + 1)] = data;

}

int deQueue() {
	int data;

	if (front == rear) {
		printf("큐가 비었습니다.\n");
		return 0;
	}

	data = queue[(front + 1) % (n + 1)];
	front = (front + 1) % (n + 1);
}

void printQueue() {
	int idx = 0;
	idx = (front + 1) % (n + 1);

	do {
		if (front == rear) {
			printf("큐가 비었습니다.\n");
			break;
		}
		else if (idx > rear)
			break;
		printf("%d ", queue[idx++ % (n + 1)]);
	} while (1);

}

int main() {
	printf("Max Queue Size : ");
	scanf("%d", &n);
	queue = (int*)malloc(sizeof(int) * (n + 1));

	while (1) {
		int menu, data;
		printf("\n===== Menu =====\n");
		printf("1. Input data and Enqueue\n2. Dequeue and Print data\n3. print Queue \n4. Exit  \n");
		scanf("%d", &menu);

		switch (menu)
		{
		case 1:
			printf("Input the Data : ");
			scanf("%d", &data);
			enQueue(data);
			break;
		case 2:
			deQueue();
			break;
		case 3:
			printQueue();
			break;
		case 4:
			exit(1);
			break;
		}
	}

}
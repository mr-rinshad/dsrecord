#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

// Delete a node by value
void deleteNode(int value) {
    struct Node *temp = head, *prev = NULL;

    if(temp != NULL && temp->data == value) {
        head = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        printf("Value not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Display the list
void display() {
    struct Node *temp = head;
    if(head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void search(int key){
		  struct node *ptr=head;
		  int pos=0;

		  while(ptr!=NULL){
			  if (ptr->data==key){
				  printf("Data found at position %d \n",pos);
				  return;
			  }

			  ptr=ptr->link;
			  pos++;
		  }
		  printf("Data not found in the linked list");
}
int main() {
    int choice, value;

    while(1) {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Delete\n4. Display\n6.Search\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(value);
                break;

            case 4:
                display();
                break;
            case 5:
                 printf("enter the data to search:");
                 scanf("%d",&key);
                 search(key);
                 break;
            
            case 6:
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

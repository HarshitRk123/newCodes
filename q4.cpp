#include <stdio.h>
#include <stdlib.h>

// Creating a structure for a node of the linked list
struct Node {
    int data;
    struct Node* next;
};

// Creating function for take value inside first linked list
void insert(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    
    new_node->data = new_data;
    new_node->next = NULL;
    
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    
    while (last->next != NULL)
        last = last->next;
    
    last->next = new_node;
}

// Function to display element of the linked list
void display(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Function to find the sum of two linked lists
struct Node* addLists(struct Node* first, struct Node* second) {
    struct Node* result = NULL;
    struct Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first != NULL || second != NULL) {
        sum = carry + (first ? first->data : 0) + (second ? second->data : 0);
        
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = sum;
        temp->next = NULL;

        if (result == NULL)
            result = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    if (carry > 0)
        temp->next = result;

    return result;
}

int main() {                    // Calling the function inside main
    struct Node* first = NULL;
    struct Node* second = NULL;
    struct Node* sum = NULL;

    int n, m, data;

    // Taking Input from user for the first linked list
    printf("Enter the number of elements in the first linked list: ");
    scanf("%d", &n);
    printf("Enter the elements of the first linked list: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        insert(&first, data);
    }

    //Taking  Input from user for the second linked list
    printf("Enter the number of elements in the second linked list: ");
    scanf("%d", &m);
    printf("Enter the elements of the second linked list: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &data);
        insert(&second, data);
    }

    printf("First linked list: ");
    display(first);
    printf("Second linked list: ");
    display(second);

    sum = addLists(first, second);  // Add the both linked list element together

    printf("Sum of the two linked lists: ");
    display(sum);

    return 0;
}

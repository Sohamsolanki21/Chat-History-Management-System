#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE 200

/* Node of the Doubly Linked List */
struct Node {
    char message[MAX_MESSAGE];
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *current = NULL;

void removeNewline(char str[]) {
    str[strcspn(str, "\n")] = '\0';
}

struct Node *createNode(const char *message) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMemory allocation failed!\n");
        return NULL;
    }

    strcpy(newNode->message, message);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addMessage(void) {
    char message[MAX_MESSAGE];
    struct Node *newNode;

    printf("\nEnter message: ");
    fgets(message, MAX_MESSAGE, stdin);
    removeNewline(message);

    if (strlen(message) == 0) {
        printf("Message cannot be empty.\n");
        return;
    }

    newNode = createNode(message);
    if (newNode == NULL)
        return;

    if (head == NULL) {
        head = tail = current = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    printf("Message added successfully.\n");
}

void displayChat(void) {
    struct Node *temp = head;
    int position = 1;

    if (head == NULL) {
        printf("\nChat history is empty.\n");
        return;
    }

    printf("\n========== CHAT HISTORY ==========\n");
    while (temp != NULL) {
        if (temp == current)
            printf("%d. %s  <-- CURRENT\n", position, temp->message);
        else
            printf("%d. %s\n", position, temp->message);

        temp = temp->next;
        position++;
    }
    printf("==================================\n");
}

void searchMessage(void) {
    char searchText[MAX_MESSAGE];
    struct Node *temp = head;
    int position = 1;
    int found = 0;

    if (head == NULL) {
        printf("\nChat history is empty.\n");
        return;
    }

    printf("\nEnter message to search: ");
    fgets(searchText, MAX_MESSAGE, stdin);
    removeNewline(searchText);

    if (strlen(searchText) == 0) {
        printf("Search text cannot be empty.\n");
        return;
    }

    while (temp != NULL) {
        if (strstr(temp->message, searchText) != NULL) {
            printf("\nMessage found at position %d: %s\n", position, temp->message);
            found = 1;
        }
        temp = temp->next;
        position++;
    }

    if (!found)
        printf("\nMessage not found.\n");
}

void deleteMessage(void) {
    int position, i;
    struct Node *temp;

    if (head == NULL) {
        printf("\nChat history is empty.\n");
        return;
    }

    displayChat();
    printf("\nEnter message position to delete: ");

    if (scanf("%d", &position) != 1) {
        printf("Invalid position.\n");
        while (getchar() != '\n')
            ;
        return;
    }
    getchar();

    if (position < 1) {
        printf("Invalid position.\n");
        return;
    }

    temp = head;
    for (i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    if (current == temp) {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }

    printf("\nDeleted message: %s\n", temp->message);
    free(temp);

    if (head == NULL)
        current = NULL;

    printf("Message deleted successfully.\n");
}

void nextMessage(void) {
    if (current == NULL) {
        printf("\nNo messages available.\n");
        return;
    }

    if (current->next == NULL) {
        printf("\nYou are already at the last message.\n");
        printf("Current message: %s\n", current->message);
        return;
    }

    current = current->next;
    printf("\nMoved to next message.\n");
    printf("Current message: %s\n", current->message);
}

void previousMessage(void) {
    if (current == NULL) {
        printf("\nNo messages available.\n");
        return;
    }

    if (current->prev == NULL) {
        printf("\nYou are already at the first message.\n");
        printf("Current message: %s\n", current->message);
        return;
    }

    current = current->prev;
    printf("\nMoved to previous message.\n");
    printf("Current message: %s\n", current->message);
}

void countMessages(void) {
    struct Node *temp = head;
    int count = 0;

    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    printf("\nTotal messages: %d\n", count);
}

void clearChat(void) {
    struct Node *temp = head;
    struct Node *nextNode;

    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    head = NULL;
    tail = NULL;
    current = NULL;
    printf("\nChat history cleared successfully.\n");
}

void showCurrentMessage(void) {
    if (current == NULL) {
        printf("\nNo current message. Chat history is empty.\n");
        return;
    }

    printf("\nCurrent message: %s\n", current->message);
}

void displayMenu(void) {
    printf("\n============================================\n");
    printf("       CHAT HISTORY MANAGEMENT SYSTEM       \n");
    printf("          DOUBLY LINKED LIST IN C           \n");
    printf("============================================\n");
    printf("1. Send Message\n");
    printf("2. Display Chat History\n");
    printf("3. Search Message\n");
    printf("4. Delete Message\n");
    printf("5. Next Message\n");
    printf("6. Previous Message\n");
    printf("7. Count Messages\n");
    printf("8. Show Current Message\n");
    printf("9. Clear Chat\n");
    printf("10. Exit\n");
    printf("============================================\n");
}

int main(void) {
    int choice;

    printf("\n============================================\n");
    printf("     WELCOME TO CHAT HISTORY MANAGER        \n");
    printf("============================================\n");

    while (1) {
        displayMenu();
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("\nInvalid input. Please enter a number.\n");
            while (getchar() != '\n')
                ;
            continue;
        }
        getchar();

        switch (choice) {
            case 1: addMessage(); break;
            case 2: displayChat(); break;
            case 3: searchMessage(); break;
            case 4: deleteMessage(); break;
            case 5: nextMessage(); break;
            case 6: previousMessage(); break;
            case 7: countMessages(); break;
            case 8: showCurrentMessage(); break;
            case 9: clearChat(); break;
            case 10:
                clearChat();
                printf("\nThank you for using Chat History Manager!\n");
                return 0;
            default:
                printf("\nInvalid choice. Please select 1-10.\n");
        }
    }

    return 0;
}

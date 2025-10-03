#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BookNode {
    char title[100];
    float price;
    int pages;
    char language[20];
    int weight_g;
    int year;
    struct BookNode* next;
};

struct BookNode* createNode(const char* title, float price, int pages, const char* language, int weight, int year) {
    struct BookNode* newNode = (struct BookNode*)malloc(sizeof(struct BookNode));

    strcpy(newNode->title, title);
    newNode->price = price;
    newNode->pages = pages;
    strcpy(newNode->language, language);
    newNode->weight_g = weight;
    newNode->year = year;
    newNode->next = NULL;

    return newNode;
}

void appendNode(struct BookNode** headRef, struct BookNode* newNode) {
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    struct BookNode* last = *headRef;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void printList(struct BookNode* node) {
    int count = 1;
    printf("The Harry Potter Book Series\n");
    while (node != NULL) {
        printf("--- Book %d ---\n", count++);
        printf("Title: %s\n", node->title);
        printf("Publication Year: %d\n", node->year);
        printf("Language: %s\n", node->language);
        printf("Page Count: %d\n", node->pages);
        printf("Approximate Weight: %d g\n", node->weight_g);
        printf("Approximate Price: $%.2f\n\n", node->price);
        node = node->next;
    }
}

int main() {
    struct BookNode* head = NULL;

    appendNode(&head, createNode("Harry Potter and the Sorcerer's Stone", 19.99, 309, "English", 420, 1998));
    appendNode(&head, createNode("Harry Potter and the Chamber of Secrets", 19.99, 341, "English", 450, 1999));
    appendNode(&head, createNode("Harry Potter and the Prisoner of Azkaban", 22.99, 435, "English", 510, 1999));
    appendNode(&head, createNode("Harry Potter and the Goblet of Fire", 25.99, 734, "English", 720, 2000));
    appendNode(&head, createNode("Harry Potter and the Order of the Phoenix", 29.99, 870, "English", 850, 2003));
    appendNode(&head, createNode("Harry Potter and the Half-Blood Prince", 29.99, 652, "English", 680, 2005));
    appendNode(&head, createNode("Harry Potter and the Deathly Hallows", 34.99, 759, "English", 730, 2007));

    printList(head);

    return 0;
}
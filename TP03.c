# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "TP03.h"


////////// Singly Linked List ////////

struct linearNode* createLinearNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct linearNode* newnode = (struct linearNode*) malloc(sizeof(struct linearNode));
if(newnode != NULL){
newnode->id = id ;
strncpy(newnode->childName, childName, sizeof(newnode->childName));
strncpy(newnode->parentName, parentName, sizeof(newnode->parentName));
newnode->childBY = childBY;
newnode->parentPhone = parentPhone;
}
return newnode ;
}

void SL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct linearNode* newnode = createLinearNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
if(*head == NULL){
    (*head) = newnode ;
}
else{
    newnode->linearNext = (*head);
    (*head) = newnode ; 
}
}
}

void SL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct linearNode* newnode = createLinearNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
   if(*head == NULL){
    (*head) = newnode ;
}
else{
    struct linearNode* temp = (*head);
    while((temp)->linearNext != NULL){
        (temp) = (temp)->linearNext ;
    }
    (temp)->linearNext = newnode ;
    newnode->linearNext = NULL ;
} 
}
}

void SL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
if(prevNode == NULL){
    // TODO
    printf("Previous node cannot be NULL\n");
}
else{
   newNode->linearNext = prevNode->linearNext;
   prevNode->linearNext = newNode;
}
}

void SL_deleteAtBeginning(struct linearNode **head)
{
    if(*head == NULL){
        //TODO
    printf("List is empty, cannot delete.\n"); 
    }
    else{
        struct linearNode* temp = (*head) ;
        (*head) = (*head)->linearNext ;
        free(temp);
    }
}

void SL_deleteAtEnd(struct linearNode **head)
{
if(*head == NULL){
   // TODO
 printf("List is empty, cannot delete.\n"); 
}   
else {
    struct linearNode *temp = *head;
    struct linearNode *prev = NULL;
    while (temp->linearNext != NULL) {
        prev = temp;
        temp = temp->linearNext;
}
    if (prev != NULL) {
        prev->linearNext = NULL; } 
else { 
    *head = NULL;}
    free(temp);
    }
}

void SL_deleteAfterNode(struct linearNode *head, int targetID)
{
struct linearNode *temp = head;
struct linearNode *prev = NULL;
if(head == NULL){
// TODO
printf("List is empty, cannot delete.\n");  
} 
while (temp != NULL) {
   if (temp->id == targetID) {
    if (temp->linearNext != NULL) {
    struct linearNode *node = temp->linearNext;
    temp->linearNext = node->linearNext;
    free(node);} 
        else {
        printf("Node with ID %d is the end.\n", targetID);
 }
 }
    prev = temp ;
    temp = temp->linearNext ;
} // TODO
 printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
}

void printSinglyLinearList(struct linearNode* head)
{
    struct linearNode *current = head;
    if(head == NULL){
    // TODO
    printf("List is empty.\n"); }
    else{
    while(current != NULL){
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->linearNext ;
    }
    }
}

struct linearNode *searchSinglyNode(struct linearNode *head, int id)
{
    if(head == NULL){
     // TODO
    printf("List is empty.\n");
    return NULL ;
    }
    struct linearNode *current = head;
    while(current != NULL){
        if(current->id == id){
            return current ;
        }
        current = current->linearNext ;
    }  
printf("Node with ID %d not found in the list.\n", id);
return NULL ;
}

////////// Circular Singly Linked List ////////

void CSL_insertBeginning(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) {
struct linearNode* newnode = createLinearNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
if(*head == NULL){
    (*head) = newnode ;
    newnode->linearNext = newnode ;
}
else{
    newnode->linearNext = (*head);
    (*head) = newnode ;
    struct linearNode* lastnode = *head;
        while (lastnode->linearNext != *head) {
        lastnode = lastnode->linearNext;
        }
        lastnode->linearNext = newnode;
}
}
}

void CSL_insertAtEnd(struct linearNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct linearNode* newnode = createLinearNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
   if(*head == NULL){
    (*head) = newnode ;
    newnode->linearNext = newnode ;
}
else{
    struct linearNode* temp = (*head);
    while(temp->linearNext != *head){
        (temp) = (temp)->linearNext ;
    }
    (temp)->linearNext = newnode ;
    newnode->linearNext = *head ;
} 
}
}

void CSL_insertAfterNode(struct linearNode *prevNode, struct linearNode *newNode)
{
    if(prevNode == NULL){
    // TODO
    printf("Previous node cannot be NULL\n");
}
else{
   newNode->linearNext = prevNode->linearNext;
   prevNode->linearNext = newNode;
}

}

void CSL_deleteAtBeginning(struct linearNode **head)
{
    if(*head == NULL){
        //TODO
    printf("List is empty, cannot delete.\n"); 
    }
    if ((*head)->linearNext == (*head)) {
        free(*head);
        (*head) = NULL;
    }
    else {
        struct linearNode* lastNode = *head;
        while (lastNode->linearNext != *head) {
            lastNode = lastNode->linearNext;
        }
        lastNode->linearNext = (*head)->linearNext;
        struct linearNode* temp = *head;
        *head = (*head)->linearNext;
        free(temp);
    }

}

void CSL_deleteAtEnd(struct linearNode **head)
{
    if(*head == NULL){
   // TODO
 printf("List is empty, cannot delete.\n"); 
}  
if ((*head)->linearNext == *head) {
    free(*head);
    *head = NULL;
} 
else {
struct linearNode* temp = *head;
        while (temp->linearNext->linearNext != *head) {
            temp= temp->linearNext;
        }
        free(temp->linearNext);
        temp->linearNext = *head;
}
}

void CSL_deleteAfterNode(struct linearNode* head, int targetID) 
{
if(head == NULL){
// TODO
printf("List is empty, cannot delete.\n");  
} 
struct linearNode* goal = head;
while (goal->id != targetID && goal->linearNext != head) {
    goal = goal->linearNext;
}
if (goal->id != targetID) {
    printf("Node with ID %d not found in the list,cannot delete.\n", targetID);
}
if (goal->linearNext == head) {
    printf("Node with ID %d is the end.\n", targetID);
}
struct linearNode* delete = goal->linearNext;
goal->linearNext = delete->linearNext;
free(delete);
}

struct linearNode *searchCircularSinglyNode(struct linearNode *head, int id)
{
    if(head == NULL){
     // TODO
    printf("List is empty.\n");
    return NULL ;
    }
    struct linearNode *current = head;
    do{
        if(current->id == id){
            return current ;
        }
        current = current->linearNext ;
    }  while( current != head);
    printf("Node with ID %d not found in the list.\n", id);
return NULL ;
}

void printSinglyCircularList(struct linearNode* head)
{
    struct linearNode *current = head;
    if(head == NULL){
    // TODO
    printf("List is empty.\n"); }
    else{
    do {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n",
               current->id, current->childName, current->parentName, current->childBY, current->parentPhone);

        current = current->linearNext;
    } while (current != head);
    }
}


////////// Doubly Linked List ////////

// Function to create a node for the circular doubly linked list
struct doublyNode *createDoublyNode(int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct doublyNode* newnode = (struct doublyNode*) malloc(sizeof(struct doublyNode));
if(newnode != NULL){
newnode->id = id ;
strncpy(newnode->childName, childName, sizeof(newnode->childName));
strncpy(newnode->parentName, parentName, sizeof(newnode->parentName));
newnode->childBY = childBY;
newnode->parentPhone = parentPhone;
}
return newnode ;
}

void DL_insertBeginning(struct doublyNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct doublyNode* newnode = createDoublyNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
if(*head == NULL){
    (*head) = newnode ;
    newnode->doublyNext = NULL;
    newnode->doublyPrev = NULL;
}
else{
   newnode->doublyPrev = NULL;
   newnode->doublyNext = *head ;
   (*head)->doublyPrev = newnode;
   *head = newnode ;
}
}
}

void DL_insertAtEnd(struct doublyNode **head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct doublyNode* newnode = createDoublyNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
if(*head == NULL){
    (*head) = newnode ;
    newnode->doublyNext = NULL;
    newnode->doublyPrev = NULL;
}
else {
struct doublyNode* temp = (*head);
    while((temp)->doublyNext != NULL){
        (temp) = (temp)->doublyNext ;
    }
    (temp)->doublyNext = newnode ;
    newnode->doublyPrev = temp ;
    newnode->doublyNext = NULL ;    
}
}
}

void DL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
    if(prevNode == NULL){
    // TODO
    printf("Previous node cannot be NULL\n");
}
else{
   newNode->doublyNext = prevNode->doublyNext;
   prevNode->doublyNext = newNode;
   newNode->doublyPrev = prevNode ;
   if(newNode->doublyNext != NULL){
    newNode->doublyNext->doublyPrev = newNode ;
   }
}
}

void DL_deleteAtBeginning(struct doublyNode **head) 
{
    if(*head == NULL){
        //TODO
    printf("List is empty, cannot delete.\n"); 
    }
    else{
        struct doublyNode* temp = (*head) ;
        (*head) = (*head)->doublyNext ;
        if(head != NULL){
            (*head)->doublyPrev = NULL ;
        }
        free(temp);
    }
}


void DL_deleteAtEnd(struct doublyNode** head) 
{
    if(*head == NULL){
   // TODO
 printf("List is empty, cannot delete.\n"); 
}   
else {
    struct doublyNode *temp = *head;
    struct doublyNode *prev = NULL;
    while (temp->doublyNext != NULL) {
        prev = temp;
        temp = temp->doublyNext;
}
    if (prev != NULL) {
        prev->doublyNext = NULL; } 
else { 
    *head = NULL;}
    free(temp);
    }
    
}

void DL_deleteAfterNode(struct doublyNode *head, int targetID)
{
struct doublyNode *temp = head;
struct doublyNode *prev = NULL;
if(head == NULL){
// TODO
printf("List is empty, cannot delete.\n");  
} 
while (temp != NULL) {
   if (temp->id == targetID) {
    if (temp->doublyNext != NULL) {
    struct doublyNode *node = temp->doublyNext;
    temp->doublyNext = node->doublyNext;
    if (node->doublyNext != NULL) {
        node->doublyNext->doublyPrev = temp;}
    free(node);
    return ;} 
        else {
        printf("Node with ID %d is the end.\n", targetID);
        return ;
 }
 }
    prev = temp ;
    temp = temp->doublyNext ;
} // TODO
 printf("Node with ID %d not found in the list, cannot delete.\n", targetID);
}

void printDoublyLinearList(struct doublyNode *head) 
{
    struct doublyNode *current = head;
    if(head == NULL){
    // TODO
    printf("List is empty.\n"); }
    while(current != NULL){
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n", current->id, current->childName, current->parentName, current->childBY, current->parentPhone);
        current = current->doublyNext ;
    }
}

struct doublyNode* searchDoublyNode(struct doublyNode* head, int id) 
{
    if(head == NULL){
     // TODO
    printf("List is empty.\n");
    return NULL ;
    }
    struct doublyNode *current = head;
    while(current != NULL){
        if(current->id == id){
            return current ;
        }
        current = current->doublyNext ;
    }  
printf("Node with ID %d not found in the list.\n", id);
return NULL ;
}

/////// Circular Doubly Linked List /////////////

void CDL_insertBeginning(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone)
{
struct doublyNode* newnode = createDoublyNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
if(*head == NULL){
    (*head) = newnode ;
    newnode->doublyNext = newnode ;
    newnode->doublyPrev = newnode ;
}
else{
    newnode->doublyNext = (*head);
    (*head) = newnode ;
    struct doublyNode* lastnode = *head;
        while (lastnode->doublyNext != *head) {
        lastnode = lastnode->doublyNext;
        }
        lastnode->doublyNext = newnode;
        newnode->doublyPrev = lastnode ;
}
}
}

void CDL_insertAtEnd(struct doublyNode** head, int id, char childName[], char parentName[], int childBY, int parentPhone) 
{
struct doublyNode* newnode = createDoublyNode(id,childName,parentName,childBY,parentPhone);
if(newnode != NULL){
   if(*head == NULL){
    (*head) = newnode ;
    newnode->doublyNext = newnode ;
    newnode->doublyPrev = newnode ;
}
else{
    struct doublyNode* temp = (*head);
    while(temp->doublyNext != *head){
        (temp) = (temp)->doublyNext ;
    }
    newnode->doublyNext = *head; 
    newnode->doublyPrev = temp;
    temp->doublyNext = newnode;
    (*head)->doublyPrev = newnode;
} 
}
}

void CDL_insertAfterNode(struct doublyNode* prevNode, struct doublyNode* newNode) 
{
if(prevNode == NULL){
    // TODO
    printf("Previous node cannot be NULL\n");
}
else{
newNode->doublyNext = prevNode->doublyNext;
        newNode->doublyPrev = prevNode;
        prevNode->doublyNext->doublyPrev = newNode;
        prevNode->doublyNext = newNode;
}
}

void CDL_deleteAtBeginning(struct doublyNode** head) 
{
    if(*head == NULL){
        //TODO
    printf("List is empty, cannot delete.\n"); 
    }
    if ((*head)->doublyNext == (*head)) {
        free(*head);
        (*head) = NULL;
    }
    else {
        struct doublyNode* lastNode = *head;
        while (lastNode->doublyNext != *head) {
            lastNode = lastNode->doublyNext;
        }
        lastNode->doublyNext = (*head)->doublyNext;
        (*head)->doublyNext->doublyPrev = lastNode ;
        struct doublyNode* temp = *head;
        *head = (*head)->doublyNext;
        free(temp);
    }
}

void CDL_deleteAtEnd(struct doublyNode** head) 
{
    if(*head == NULL){
   // TODO
 printf("List is empty, cannot delete.\n"); 
}  
if ((*head)->doublyNext == *head) {
    free(*head);
    *head = NULL;
} 
else {
struct doublyNode* temp = *head;
        while (temp->doublyNext->doublyNext != *head) {
            temp= temp->doublyNext;
        }
        free(temp->doublyNext);
        temp->doublyNext = *head;
        (*head)->doublyPrev = temp ;
}
}

void CDL_deleteAfterNode(struct doublyNode* head, int targetID) 
{
if(head == NULL){
// TODO
printf("List is empty, cannot delete.\n");  
} 
struct doublyNode* goal = head;
while (goal->id != targetID && goal->doublyNext != head) {
    goal = goal->doublyNext;
}
if (goal->id != targetID) {
    printf("Node with ID %d not found in the list,cannot delete.\n", targetID);
}
if (goal->doublyNext == head) {
    printf("Node with ID %d is the end.\n", targetID);
}
struct doublyNode* delete = goal->doublyNext;
goal->doublyNext= delete->doublyNext;
delete->doublyNext->doublyPrev = goal ;
free(delete);
}


void printDoublyCircularList(struct doublyNode* head)
{
    struct doublyNode *current = head;
    if(head == NULL){
    // TODO
    printf("List is empty.\n"); }
    do {
        printf("ID: %d, Child Name: %s, Parent Name: %s, Child Birth Year: %d, Parent Phone: %d\n",
               current->id, current->childName, current->parentName, current->childBY, current->parentPhone);

        current = current->doublyNext;
    } while (current != head);
}

struct doublyNode* searchCircularDoublyNode(struct doublyNode* head, int id) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
}
    struct doublyNode* current = head;
    while(1){
    if(current->id == id) {
    return current; 
    }
    current = current->doublyNext;
    if(current == head) {
    break;
    }
}
    printf("Node with ID %d not found in the list.\n", id);
    return NULL;
}
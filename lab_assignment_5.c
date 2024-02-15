#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  char letter;
  struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head) {
  // Initializes the counter and the traversal node
  int n = 0;
  node *t = head;

  // Loops through the entire linked list, adding 1 to n for each node
  while (t != NULL) {
    t = t->next;
    n++;
  }

  // Returns the number of nodes
  return n;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString(node *head) {
  // Initializes the traversal node and the char array
  node *t = head;
  char *toString = (char *)malloc((length(head) + 1) * sizeof(char));

  // Checks if malloc succesfully allocated memory
  if (toString == NULL) {
    printf("Failed to allocate memory using malloc!\n");
    return NULL;
  }

  // Makes the counter
  int i = 0;
  
  // Loops through the linked list, adding each letter to toString
  for (i = 0; i < length(head); i++) {
    toString[i] = t->letter;
    t = t->next;
  }
  // Adds the null terminator to the string
  toString[i] = '\0';
  
  // Returns the toString
  return toString;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {
  // Creates the new node and a traversal node
  node *t = *pHead;
  node *newNode = (node *)malloc(sizeof(node));
  newNode->letter = c;
  newNode->next = NULL;

  // Checks if malloc succesfully allocated memory
  if (newNode == NULL) {
    printf("Failed to allocate memory ");
    return;
  }

  // If list empty, set the head to temp
  if (*pHead == NULL) {
    *pHead = newNode;
    return;
  }
  
  // Navagates to the end of the linked list
  while (t->next != NULL) {
    t = t->next;
  }

  // Inserts temp to the end of the list
  t->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
  node *tmp = *pHead;
  while (tmp != NULL) {
    *pHead = tmp->next;
    free(tmp);
    tmp = *pHead;
  }
  *pHead = NULL;
}

int main(void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;
  FILE *inFile = fopen("input.txt", "r");
  fscanf(inFile, " %d\n", &numInputs);
  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }
    str = toCString(head);
    printf("String is : %s\n", str);
    free(str);
    deleteList(&head);
    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }
  fclose(inFile);
}

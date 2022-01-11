// A106 Siddhesh Ballal
// A108 Prajwal Bankar
// A171 Yash Tembhurnikar

// Singly Linked List Integer Implementation

#include <stdio.h>
#include <stdlib.h>

struct node

{
  int data;
  struct node* next;
};

void create(struct node *head)
{
  printf("\nEnter data at start:\t");
  scanf("%d", &head ->data);
  head -> next = NULL;
}

struct node* insert_start(struct node *head)
{
  struct node *temp;
  int input;
  temp = (struct node*) malloc (sizeof(struct node)); 
  printf("\nEnter data to be stored at start:\t");
  scanf("%d",&input);
  temp -> data = input;
  temp -> next = head;
  head = temp; 
  return head;
}

void insert_end(struct node *head)
{
  struct node *p;
  int m;
   
  p = (struct node*) malloc (sizeof(struct node));
  p = head;

  printf("\nHow many data entries do you want at the end?:\t");
  scanf("%d", &m);

  for(int i=0; i<m; i++)
  {
    struct node *temp;
    int input;
    temp = (struct node*) malloc (sizeof(struct node)); 
   
    printf("\nEnter data to be stored at end:\t");
    scanf("%d", &input);
    temp -> data = input;
    temp -> next = NULL;
    
    while(p->next != NULL)
    {
      p = p -> next;
    }

    p -> next = temp;
    p = temp;
  }
}

void insert_mid(struct node *head)
{
  struct node *temp, *p, *q;
  int bef, input;
  temp = (struct node*) malloc (sizeof(struct node)); 
  p = (struct node*) malloc (sizeof(struct node)); 
  q = (struct node*) malloc (sizeof(struct node)); 
  p = head;
  q = head -> next;

  printf("\nBefore what data do you want to add new data?:\t");
  scanf("%d", &bef);

  while(q->data != bef)
  {
    p = p -> next;
    q = q -> next;
  }

  printf("\nEnter data to be added at this position:\t");
  scanf("%d", &input);
  temp -> data = input;
  p -> next = temp;
  temp -> next = q;
}

struct node* delete_start(struct node* head)
{
  struct node* p;
  // p = head -> next;
  // free(head);
  // head = p;
  p=head;
  head=head->next;
  free(p);
  return head;
}

void delete_end(struct node* head)
{
  struct node* p, *q;
  p = head;
  q = head -> next;

  while(q->next != NULL)
  {
    p = p -> next;
    q = q -> next;
  }

  p -> next = NULL;
  free(q);
}

void delete_mid(struct node* head)
{
  struct node *p, *q;
  p=head;
  q=head->next;
  int ch;
  printf("\nEnter data to be deleted:\t");
  scanf("%d", &ch);

  while(q->data != ch)
  {
    p = p-> next;
    q = q-> next;
  }

  p -> next = q -> next;
  free(q);
}

struct node* reverse(struct node * head)
{
  struct node* p, *q, *temp;
  p = head;
  q = head -> next;
  temp = head -> next;

  while(temp != NULL)
  {
    temp = temp->next;
    q->next = p;
    p = q;
    q = temp;
  }
  head -> next = NULL;
  head = p;

  return head;
}

void display(struct node *head)
{
  struct node* p;
  p = head;
  while ( p != NULL)
  {
    printf("%d\t", p->data);
    p = p-> next;
  }
}

int main() 
{
  int menucheck=1, menucontrol;
  struct node *head;
  head= (struct node*) malloc (sizeof(struct node)); 
  create(head);

  while (menucheck == 1)
  {
    printf("\nEnter:\n1 to insert at start\n2 to insert at end\n3 to insert at middle\n4 to delete start\n5 to to delete end\n6 to delete at middle\n7 to reverse\n8 to Exit: \n");
    scanf("%d", &menucontrol);

    switch(menucontrol)
    {
      case(1):
      head = insert_start(head);
      printf("\n");
      display(head);
      break;

      case(2):
      insert_end(head);
      printf("\n");
      display(head);
      break;

      case(3):
      insert_mid(head);
      printf("\n");
      display(head);
      break;

      case(4):
      head = delete_start(head);
      printf("\n");
      display(head);
      break;

      case(5):
      delete_end(head);
      printf("\n");
      display(head);
      break;

      case(6):
      delete_mid(head);
      printf("\n");
      display(head);
      break;

      case(7):
      head = reverse(head);
      printf("\n");
      display(head);
      break;

      case(8):
      menucheck = 0;
      printf("\nProgram Exited successfully.");
      break;

      default:
      printf("\nPlease enter valid input.");
      break;
    }
  }
  return 0;
}
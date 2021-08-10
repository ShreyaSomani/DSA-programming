#include <bits/stdc++.h>
using namespace std;
struct node {
   int data;
   struct node *next;
};

struct node* head = NULL;
int a[1000];
int t=0;
bool o1=0;

void print() {
	for(int i=0;i<1000;++i)
   {
   	if(a[i]>0)
   	++t;
   }
   cout<<t<<endl;
   if(t==0)
   {
   struct node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }}
   else{
   for(int i=0;i<1000;++i)
   {
   	if(a[i]>0)
   	{
   	cout<<i<<" ";
	}
   }
   cout<<endl;
    for(int i=0;i<1000;++i)
   {
   	if(a[i]>0)
   	{
   	cout<<a[i]+1<<" ";
	}
   }
}
}
void insertatend(int new_data) {
   struct node* new_node = (struct node*) malloc(sizeof(struct node));
   new_node->data = new_data;
   new_node->next=NULL;
   struct node *temp=head;
   if(head==NULL)
   {head=new_node;
    return;}
   while(temp->next!=NULL)
   {
       temp=temp->next;
   }
   temp->next = new_node;
   return;
}

void link(int x,int p)
{
    node *iter = new node;
    iter = head;
    int i = 0;
    while (iter != NULL and iter->data != x) {
        iter = iter->next;
        i++;
    }
    a[iter->next->data]--;
    node *iter_new = new node;
    iter_new = iter;
    for (int j = 0; j < p; ++j)
    {
        if (iter_new->next == NULL) {
            iter_new ->next =  head;
            o1 = 1;
        }
        iter_new = iter_new->next;
    }
    iter->next = iter_new;
    a[iter_new->data]++;
}

void insertafter(int y,int x)
{
    struct node *temp=head;
    if(head==NULL) return;
    while(temp!=NULL&&temp->data!=y)
    {
        temp=temp->next;
    }
    if(temp!=NULL&&temp->data==y)
    {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = x;
        struct node *store=temp->next;
        temp->next=new_node;
        new_node->next=store;
        return;
    }
    temp=head;
    struct node *prev=head;
    while(temp!=NULL&&temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->data==x)
    {
        struct node* new_node = (struct node*) malloc(sizeof(struct node));
        new_node->data = y;
        if(temp==prev)
        {
            new_node->next=head;
            head=new_node;
            return;
        }
        prev->next=new_node;
        new_node->next=temp;
    }
    return;
}

void insertbetween(int Z,int Y,int X)
{
    struct node *z=head;
    while(z!=NULL&&z->data!=Z)
    {
        z=z->next;
    }
    if(z==NULL) return;
    int count=0;
    struct node* y=z;
    while(y!=NULL&&y->data!=Y)
    {
        count++;
        y=y->next;
    }
    int mid=count/2;
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = X;
    for(int i=0;i<mid;i++)
    {
        z=z->next;
    }
    struct node *store=z->next;
    z->next=new_node;
    new_node->next=store;
     return;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        char c;
        cin>>c;
        if(c=='I')
        {
            int i;
            cin>>i;
            if(i==0)
            {
                int x;
                cin>>x;
                insertatend(x);
            }
            else if(i==1)
            {
                int x,y;
                cin>>y>>x;
                insertafter(y,x);
            }
            else
            {
                int x,y,z;
                cin>>z>>y>>x;
                insertbetween(z,y,x);
            }
        }
        else
        {
            int x,p;
            cin>>x>>p;
            if(p>0)
            link(x,p);
        }
    }
    if(o1) cout<<"1\n";
    else cout<<"0\n";
    print();
}

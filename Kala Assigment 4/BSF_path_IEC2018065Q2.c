
    #include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct List_Node
{
    int vertexNo;
    struct List_Node *next;
};

struct node{

   int info ;
   struct node *next;
   };
struct Graph
{
int V;
int E;
struct List_Node* Adj;
};

struct Graph* Create_adjacent_list()
{
 int i=0,x,y;
 struct List_Node *temp,*t;
 struct Graph * G= (struct Graph *)malloc(sizeof( struct Graph));
// printf("Enter the number of vertices  and edges\n");
 scanf("%d %d",&G->V,&G->E);

  G->Adj=(struct List_Node*)malloc((G->V)*sizeof(struct List_Node ));
 for(i=0;i<G->V;i++)
    {G->Adj[i].vertexNo=i;
     G->Adj[i].next=NULL;
    }
 for(i=0;i<G->E;i++)
 {
    // printf("Enter the  edge ");
     scanf("%d %d",&x,&y);
     temp=(struct List_Node*)malloc(sizeof(struct List_Node));

     temp->vertexNo=y;
     temp->next=NULL;


     if(G->Adj[x].next==NULL)
         G->Adj[x].next=temp;
    else{
            t=G->Adj+x;
         while(t->next!=NULL)
             t=t->next;
         t->next=temp;
        }
     //temp->next=G->Adj[x].next;

     // G->Adj[x].next=temp;

 }


 return (G);
}


void  pop(struct node**s)
{
    int item;
    struct node *r;
    if((*s)==NULL)
        printf("stack underflow \n");
    else
            { item=(*s)->info;
              r=*s;
              *s=r->next;

              free(r);
              //return (item);
             printf("%d ",item);
            }

}

int   top(struct node **s)
    {   if(*s==NULL)
         //printf("stack underflow\n");
         return 0;
        else {
                   // printf("%d\n",(*s)->info);
                   return 1;
             }

    }

struct node * create_stack_node()
{struct node*n;
 n=(struct node*)malloc(sizeof(struct node));
 return (n);
}
void  push(struct node **s,int item)

{
    struct node *n;
    n=create_stack_node();
    //printf(" pussed\n");


            if(n!=NULL)
              {
                  n->info=item;

                  n->next=(*s);
                  *s=n;
              }

}

 struct List_Node *create_node(int x)
{       struct List_Node  *temp=(struct List_Node*)malloc(sizeof(struct List_Node));
        temp->vertexNo=x;
        temp->next=NULL;
        return (temp);


}

void BFS(struct Graph *G)
{     int j=0,i=0;
         int *path=(int *)malloc(sizeof(int) *(G->V));
             //dis[0]=0;
         int *arr=(int *)malloc(sizeof(int) *(G->V));
             //int dis[100],arr[100];
          for(j=0;j<G->V;j++)
             {arr[j]=0;
              path[j]=-1;
              }


        struct List_Node *Front=NULL,*Rear=NULL,*temp,*r,*u;

        temp=G->Adj;

        {Rear=create_node(temp->vertexNo);
         Front=Rear;
         Rear=NULL;
        }
         arr[0]=1;



        while((Front!=NULL))
        {

              r=Front;
              temp=G->Adj+Front->vertexNo;
              u=temp;
              temp=temp->next;
            if(Front==Rear)    Front=Rear=NULL;

            else   Front=Front->next;



             free(r);
              while(temp!=NULL)
              {
                if(arr[temp->vertexNo]==0)
                    {    arr[temp->vertexNo]=1;
                         if(Rear==NULL)
                         {Rear=create_node(temp->vertexNo);
                            Front=Rear;
                         }
                         else
                        {
                          Rear->next=create_node(temp->vertexNo);
                          Rear=Rear->next;


                        }



                         path[temp->vertexNo]=u->vertexNo;
                    }

                 temp=temp->next;
              }



           }

          // printf("\n0\n");
         /* for(i=0;i<G->V;i++)
             printf("%d ",path[i]);*/

            struct node *stack=NULL;int a=0;
            printf("0\n");
            for(i=1;i<G->V;i++)
              {

               if(path[i]==-1)
                printf("NIL\n");
               else
                {

                 j=i;
                  while(j!=0)
                       {
                           a=path[j];
                           push(&stack,a);
                           j=a;
                       }
                 while(top(&stack))
                 {
                    pop(&stack);
                    //printf("%d ",a);

                 }
                 printf("%d\n",i);
              }

                printf("\n");;
              }
              //printf("\n");


    }

int main()
{  int i,T;
   scanf("%d",&T);
   while(T--)
   {


    struct Graph *G=Create_adjacent_list();
    struct List_Node *t;
    /*for(i=0;i<G->V;i++)
    {
        t=G->Adj+i;
        //printf("Vertex %d  ",i);

        /*while(t!=NULL)
        {
            //printf("%d ",t->vertexNo);
            t=t->next;
            //printf("t =%d\n",t);
        }*/
        printf("\n");



    //}

     BFS(G);
   }

     return 0;
}



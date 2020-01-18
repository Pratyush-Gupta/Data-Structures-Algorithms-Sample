
#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
struct List_Node
{
    int vertexNo;
    struct List_Node *next;
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
  scanf("%d %d",&G->V,&G->E);

  G->Adj=(struct List_Node*)malloc((G->V)*sizeof(struct List_Node ));
 for(i=0;i<G->V;i++)
    {G->Adj[i].vertexNo=i;
     G->Adj[i].next=NULL;
    }
 for(i=0;i<G->E;i++)
 {

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

 }


 return (G);
}
 struct List_Node *create_node(int x)
{       struct List_Node  *temp=(struct List_Node*)malloc(sizeof(struct List_Node));
        temp->vertexNo=x;
        temp->next=NULL;
        return (temp);


}

void BFS(struct Graph *G)
{     int j=0,i=0;
         int *dis=(int *)malloc(sizeof(int) *(G->V));

         int *arr=(int *)malloc(sizeof(int) *(G->V));

          for(j=0;j<G->V;j++)
             {arr[j]=0;
              dis[j]=0;
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


                         dis[temp->vertexNo]=dis[u->vertexNo]+1;

                    }


                 temp=temp->next;
              }



           }

           printf("\n0\n");

           for(i=1;i<G->V;i++)
              {if(dis[i]==0)
                printf("-1\n");
               else
               printf("%d\n",dis[i]);
              }
              printf("\n");


    }

int main()
{  int i,T;
   scanf("%d",&T);
   while(T--)
   {


    struct Graph *G=Create_adjacent_list();
    struct List_Node *t;


     BFS(G);
   }

     return 0;
}




#include<stdio.h>
#include<stdlib.h>
#define INFI 99999999
struct List_Node
{
    int vertexNo;
    int w ;
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
 int i=0,x,y,weight=0;
 struct List_Node *temp,*t;
 struct Graph * G= (struct Graph *)malloc(sizeof( struct Graph));
// printf("Enter the number vertices and edges\n");
  scanf("%d %d",&G->V,&G->E);

  G->Adj=(struct List_Node*)malloc((G->V)*sizeof(struct List_Node ));
 for(i=0;i<G->V;i++)
    {G->Adj[i].vertexNo=i;
     G->Adj[i].next=NULL;
    }
 for(i=0;i<G->E;i++)
 {
    //printf("Enter the edges and weight\n");
     scanf("%d %d %d",&x,&y,&weight);

     temp=(struct List_Node*)malloc(sizeof(struct List_Node));

     temp->vertexNo=y;
     temp->w=weight;
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

    struct node
    { int vertex,d,parent,set;
       struct node *next;

    };
    struct node *create_DJ_node()
    {
        struct node *n=(struct node *) malloc(sizeof(struct node));
        n->next=NULL;
        return (n);
    }
    struct node * extract_min(struct node *Front)
    { struct node *t,*p=NULL;
      int a=999999;
      t=Front;
      while(t!=NULL)
      {   if((t->d<a)&&(t->set!=-1))
            {p=t;
            a=t->d;}
          t=t->next;

      }
      return (p);

    }
    struct node * special_search(struct node *Front,int v)
    { struct node *t,*p=NULL;

      t=Front;
      while(t!=NULL)
      {   if(t->vertex==v)
             {p=t;
             return p;}
            t=t->next;

      }
      return (p);

    }

    int  present_parent(struct node *Front,int v)
    { struct node *t,*p;

      p=Front;
      t=p;
      while(t!=NULL)
      {   if(t->vertex==v)
             {return  (t->parent);
              break;

             }
          t=t->next;

      }
    //  printf("hi\n");
      return 0;


    }
    int  present(struct node *Front,int v)
    { struct node *t,*p;

      p=Front;
      t=p;
      while(t!=NULL)
      {   if(t->vertex==v&&(t->set!=-1))
             {return 1;
             break;}
          t=t->next;

      }
    //  printf("hi\n");
      return 0;


    }


    int  search(struct node *Front,int v)
    { struct node *t,*p;

      t=Front;

      while(t!=NULL)
      {   if(t->vertex==v)
             {


             return (t->d);
             }

          t=t->next;

      }


    }
void  fit(struct node *Front,int v,int value,int u)
    { struct node *t,*p;

      t=Front;

      while(t!=NULL)
      {   if(t->vertex==v)
             {


              t->d=value;
              t->parent=u;
              //printf("t =%d ",t->parent);
              return ;
              break;


             }

          t=t->next;

      }


    }
    struct stack_node{

   int info ;
   struct stack_node *next;
   };
void  pop(struct stack_node**s)
{
    int item;
    struct stack_node *r;
    if((*s)==NULL)
        printf("\n");
    else
            { item=(*s)->info;
              r=*s;
              *s=r->next;

              free(r);
              //return (item);

              printf("%d ",item);
            }

}

int   top(struct stack_node **s)
    {   if(*s==NULL)

         return 0;
        else {

                   return 1;
             }

    }

struct stack_node * create_stack_node()
{struct stack_node*n;
 n=(struct stack_node*)malloc(sizeof(struct stack_node));
 return (n);
}
void  push(struct stack_node **s,int item)

{
    struct stack_node *n;
    n=create_stack_node();



            if(n!=NULL)
              {
                  n->info=item;

                  n->next=(*s);
                  *s=n;
              }

}


   void  dijkstras(struct Graph *G,int s)
    {  int i=0,j=0,u,v,w,y=0;
       struct List_Node *p=NULL;
       struct node *Front=NULL,*Rear=NULL,*n,*F=NULL;
        for(i=0;i<G->V;i++)
        {if(Front==NULL)
           {Front=create_DJ_node();
            Rear=Front;
           }
         else
            {  Rear->next=create_DJ_node();
               Rear=Rear->next;

            }
           Rear->vertex=i;
           Rear->d=INFI;
           Rear->parent=-001;
           Rear->set=0;
        }
        Front->d=0;
        F=Front;

        while(Front!=NULL)
        { n=extract_min(Front);
          //printf("Here\n");
          if(n==NULL) break;
           u=n->vertex;
          n->set=-1;
          p=G->Adj+u;
          p=p->next;
          while(p!=NULL)
          { v=p->vertexNo;
           //printf(" u=%d v=%d w=%d",u,v,p->w);
            y=present(Front,v);
             if(y==1)
             {   if(search(Front,v)==search(Front,u)+p->w)
                    {if(u<present_parent(Front,v))
                     fit(Front,v,search(Front,u)+p->w,u);
                    }


                 else if(search(Front,v)>search(Front,u)+p->w)
                   fit(Front,v,search(Front,u)+p->w,u);

                // printf("change\n");
             }
             p=p->next;
             if(p==NULL)
                 break;

           }
           //printf("Hello\n");

        }
        struct stack_node *stack=NULL;int a=0;
        F=Front;

       while(F!=NULL)
       {   if(F==Front)
             printf("0\n");

           else if(F->parent==-001&&F!=Front)
              printf("NIL\n");
            else

              {   n=F;
                 while(n->vertex!=0)
                {
                           a=n->parent;
                           //if(n!=Front)
                           push(&stack,a);

                   //printf("%d ",Front->parent);
                   n=special_search(Front,a);
                }
                while(top(&stack))
                     {
                        pop(&stack);
                     }
                 printf("%d\n",F->vertex);

              }
           F=F->next;
       }
     // printf("\n");



    }
int main()
{  int i,T;
   scanf("%d",&T);
   while(T--)
   {


    struct Graph *G=Create_adjacent_list();
    struct List_Node *t;
    //printf("Hi\n");
    /*for(i=0;i<G->V;i++)
    {   t=G->Adj+i;
        while(t!=NULL)
            {printf("%d ",t->vertexNo);
             t=t->next;
             }
             printf("\n");
    }*/
    dijkstras(G,0);


    // BFS(G);
   }

     return 0;
}





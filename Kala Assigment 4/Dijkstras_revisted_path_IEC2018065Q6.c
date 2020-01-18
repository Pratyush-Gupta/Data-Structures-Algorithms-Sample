
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFI 99999999
struct List_Node
{   char name[100];
    int  vertexNo;
    int w ;
    struct List_Node *next;
};
struct Graph
{
int V;
int E;
struct List_Node* Adj;
};
int send_address(struct Graph *G,char nam[])
    { struct List_Node *t;
      char x[1000];
      int p=0,i=0;
       for(i=0;i<G->V;i++)
       {


          t=G->Adj+i;
          strcpy(x,t->name);

            if(strcmp(x,&nam[0])==0)
               { p=t->vertexNo;
                 return (p);
               }



       }
      return 0;

    }
struct Graph* Create_adjacent_list()
{
 int i=0,weight=0,p=0;
 char x[100],y[100];
 struct List_Node *temp,*t;
 struct Graph * G= (struct Graph *)malloc(sizeof( struct Graph));

  scanf("%d %d",&G->V,&G->E);

  G->Adj=(struct List_Node*)malloc((G->V)*sizeof(struct List_Node ));
 for(i=0;i<G->V;i++)
    {scanf("%s",&G->Adj[i].name);
     G->Adj[i].vertexNo=i;
     G->Adj[i].next=NULL ;
    }
 for(i=0;i<G->E;i++)
 {
     scanf("%s %s %d",&x,&y,&weight);

     temp=(struct List_Node*)malloc(sizeof(struct List_Node));

     strcpy(temp->name,y);
     temp->vertexNo=send_address(G,y);
     temp->w=weight;
     temp->next=NULL;

     p=send_address(G,x);
    if(G->Adj[p].next==NULL)
         G->Adj[p].next=temp;
    else{
            t=G->Adj+p;
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
       char name[100];
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
void  pop(struct stack_node**s,struct Graph *G)
{
    int item,i=0;
    struct stack_node *r;struct List_Node *t=NULL;
    if((*s)==NULL)
        printf("stack underflow \n");
    else
            { item=(*s)->info;
              r=*s;
              *s=r->next;

              free(r);
              //return (item);
             for(i=0;i<G->V;i++)
              {t=G->Adj+i;
                if(item==t->vertexNo)
                    printf("%s ",t->name);

              }

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





   void  dijkstras(struct Graph *G,int a,int b)
    {  int i=0,set[100],j=0,u,v,w,y=0;
       struct List_Node *p=NULL,*r=NULL,*m,*f;
       struct node *Front=NULL,*Rear=NULL,*n,*t=NULL,*g=NULL;
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
           strcpy(Rear->name,G->Adj[i].name);
           Rear->d=INFI;
           Rear->parent=-1;
           Rear->set=0;
        }

        t=Front;
        while(1)
        {
            if(t->vertex==a)
            {
                t->d=0;
                break;
            }
            t=t->next;
        }

        while(Front!=NULL)
        { n=extract_min(Front);

          if(n==NULL) break;
           u=n->vertex;
          n->set=-1;

          p=G->Adj+u;
          p=p->next;
          while(p!=NULL)
          { v=p->vertexNo;

            y=present(Front,v);
             if(y==1)
             {

                 if(search(Front,v)==search(Front,u)+p->w)
                    {


                        int z=present_parent(Front,v);

                        if(strcmp(G->Adj[z].name,n->name)>0)
                           fit(Front,v,search(Front,u)+p->w,u);

                    }


                 else if(search(Front,v)>search(Front,u)+p->w)
                   fit(Front,v,search(Front,u)+p->w,u);

             }

             p=p->next;
             if(p==NULL)
                 break;

           }

        }
        t=Front;
        char c[100];
        struct stack_node *stack=NULL;

       t=Front;
       int e=0;

       while(t!=NULL)
       {


           if(t->vertex==b)
           {


            if(t->vertex==a)
             printf("%s\n",t->name);

            else if(t->parent==-1&&t->vertex!=a)
              printf("NIL\n");
            else

              {   n=t;
                 while(n->vertex!=a)
                {
                           e=n->parent;
                           push(&stack,e);

                   //printf("%d ",Front->parent);
                   n=special_search(Front,e);
                }
                while(top(&stack))
                     {
                        pop(&stack,G);
                     }
                 printf("%s\n",t->name);

              }
           }
           t=t->next;
       }





  }
int main()
{  int i,T,Q=0,a,b;
char u[100],v[100];
   scanf("%d",&T);
   while(T--)
   {


    struct Graph *G=Create_adjacent_list();
    struct List_Node *t;

    scanf("%d",&Q);
    for(i=0;i<Q;i++)
    {

     scanf("%s %s",u,v);
     a=send_address(G,u);
     b=send_address(G,v);

     dijkstras(G,a,b);
     printf("\n");



   }
   }

     return 0;
}




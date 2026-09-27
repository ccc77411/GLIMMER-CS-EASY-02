#include <stdio.h>
#include <stdlib.h>



typedef struct Node {
    int date;
    struct Node *next;      //先定义一个链表的结点
} Node;

  


Node *t;
t->date=0;        //定义头节点
t->next=NULL;
Node *head=t;




    

Node *a(int x) {
    Node *p1 = (Node *)malloc(sizeof(Node));   //这里定义了一个创造新节点的函数
    if (p1 == NULL) {
        printf("内存分配错误\n");         //这里讨论了内存分配错误的情况
        exit(1);                                
    }
    p1->date = x;        //赋值要存的数据
    p1->next =NULL;       
    return p1;         //返回这一新节点
}






void b(Node **head, int n) {     //头插法
   
    Node *A = a(n);
    A->next = *head;       //让A指向头节点0
    *head = A;             //再让头指针指向A
}







void c(Node *head, int n) {      //尾插法
    Node *p = a(n);
    Node *h = head;           //定义一个新的指针将其赋值为头指针
    
    while (h->next != NULL) {
        h = h->next;            //这里让新定义的指针通过循环结构去找到链表的尾节点
    }
    h->next = p;         //将创造出的新节点接在原尾节点后，形成新的尾节点

}







void dy(Node *p) {         //这里定义了一个遍历链表的函数
    while (p != NULL) {
        printf("%d \n", p->date);   //通过循环结构遍历链表
        p = p->next;
    }
}







int find(Node *p,int x){      //这里定义了一个查找元素的函数
  int i=0;
  
  while (p!=NULL && p->date != x)
  {
    p=p->next;                     //这里也是通过循环结构一直沿着链表向后找到要找的元素
    i++;
  }  
    if (p==NULL)
    {                             //这一条件结构是为了讨论要找的数不在链表中时，即链表一直走到尾节点也没找到元素时，返回0即false
        return 0;
    }
  
  else{
  printf("这一节点距头节点的距离为%d。\n",i);   //输出这个节点距头节点的距离
  return 1;                        //返回1即true
  }
}






void change(Node*p,int x,int y){     //这里定义了一个更改date值的1函数
  
  while (p!=NULL && p->date != x)   //由find函数改编，就是找到要改的数然后改变这一节点的date值
  {
    p=p->next;
  }  
    if (p==NULL)
    {
        return 0;
    }
  
  else{
    p->date=y;
    return 1;
}
}







 int det(Node *head,int n){      //这里定义了一个删除节点的函数
    Node*a1=NULL;
    Node*a2=head;            //先定义两个指针
    int i=1;
    if (n==1)                 //讨论要删的节点为头节点时
    {
      Node*t=head->next;        
      if (t==NULL)       //讨论当链表只有一个节点时的情况
      {
        return 0;
      }
      
      head->date=t->date;   //这里操作的实质是把第二个节点的值赋值给头节点然后再删去原头节点
      head->next=t->next;
      free(t);
      return 1;  
    }
    else if (n<1)
    {
        return 0;        //这里是为了防止输入小于一的数
    }
    
    while(i!=n){
        if (a2->next==NULL)
        {
            return 0;        //先找到要删的节点
        }
        
        a1=a2;
        a2=a2->next;
        i++;
    }
        a1->next=a2->next;      //让前一个指针指向要删除节点的下一个节点
        free(a2);               //删除节点
        return 1 ;
        
    }   







void re(Node **head)       //这里定义了一个将链表倒置的函数
{
   Node*a1=NULL;
   Node*t=a1;
   Node*a2=*head;          //这里是定义了三个指针
   while (a2->next!=NULL)   
   {
    a1=a2;
    a2=a2->next;               //让这三个指针在循环结构中不断向后走且每走一步都改变原节点的指向
    a1->next=t;
    t=a1;
   }
   a2->next=a1;         //这是为了改变最后一个节点的指向
   *head=a2;             //让头指针指向新链表的第一个节点
}


















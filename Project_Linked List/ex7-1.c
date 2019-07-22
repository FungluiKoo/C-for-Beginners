#ifdef EX7_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "assignment.h"
    int ex7() {
        node_t *a=Initialize('1'); 
        node_t *b=NULL; PrintList(a);
        InsertFirstList(&a, 'V');
        InsertFirstList(&a, 'M');
        PrintList(a); 
        InsertLastList(&a, 'C'); 
        PrintList(a);
        SplitList(&a, &b, 2); 
        PrintList(a); 
        PrintList(b);
        DeleteFirstList(&a); 
        PrintList(a); 
        InsertLastList(&a, 'G');
        DeleteLastList(&b); 
        PrintList(b); 
        InsertLastList(&b,'0');
        PrintList(b); 
        InsertLastList(&b, '1'); 
        PrintList(b);
        MergeList(&a,&b); 
        PrintList(a);
        char target='G';
        printf("Count '%c': %d\n",target, SearchList(&a,target));
        target='1';
        printf("Count '%c': %d\n",target, SearchList(&a,target));
        FreeList(&a);
        return 0;
        }

    node_t *Initialize(char ch) {
        node_t *head;
        head=(node_t*)calloc(1,sizeof(node_t));
        if(head==NULL){ 
            fprintf(stderr,"Failed to assign memory!\n"); 
            exit(-1); 
        }
        head->next=NULL; 
        head->ch=ch;
        return head;
        }
    void PrintList(node_t *head) {
        node_t *temp=head;
        printf("***Print Linked List***\n");
        while(temp!=NULL) { 
            printf("%c ",temp->ch); 
            temp=temp->next; 
        }
        printf("\n****Print Finished****\n\n");
        free(temp);
        }
        
    void FreeList(node_t **head) {
        node_t *tmp=NULL; 
        node_t *pHead=*head;
        while(pHead->next!=NULL) { 
            tmp=pHead; 
            pHead=pHead->next; 
            free(tmp); }
        free(pHead);
        }

    bool IsEmptyList(node_t *head){                 //通过抓住链表的头节点来判断是否空
            if (NULL == head->next) {return true;}  //如果链表头节点的指针指向NULL，说明是空链表
            else{return false;}                     //如果指向了下一个，就不是空的
    }

    void InsertFirstList(node_t **head,char insert_char){
        node_t *new_node=malloc(sizeof(node_t));
        new_node->ch=insert_char;
        new_node->next=*head;
        *head=new_node;
        free(new_node);
    }

    void InsertLastList(node_t **head,char insert_char){
        node_t *pHead=*head;
        node_t *temp=*head;
        node_t *new_node=malloc(sizeof(node_t));
        while(pHead->next!=NULL) { pHead=pHead->next; }
        pHead->next=new_node;
        new_node->ch=insert_char;
        new_node->next=NULL;
        *head=temp;
        free(pHead);
        free(temp);
        free(new_node);
    }

    void SplitList(node_t **head, node_t **tail, int pos){
        node_t* temp=*head;
        for (int i=0;i<pos-1;i++){
            temp = temp->next;
        }
        *tail=temp->next;
        temp->next=NULL;
        free(temp);
    }
    
    void DeleteFirstList(node_t **head){    //删除以head打头的链表的第一个节点
        node_t* first=*head;                //常规的，我们先给第一个节点来个临时节点standby
        if (first==NULL){return;}           //如果没得删就算了
        *head=first->next;                  //获取下一个节点
        free(first);                        //释放空间
    }

    void DeleteLastList(node_t **head){     //删除以head打头的链表的最后一个节点
        int i;
        node_t *pTemp;                      //定义一个临时节点
        node_t *pPre;                       //同上
        pTemp=*head;                        //指向了头节点
        pPre=pTemp;                         //又是头节点
        for(i=1;i<SizeList(*head);i++){     //遍历
            pPre=pTemp;                     //让pPre“追上来”
            pTemp=pTemp->next;              //让pTemp领先一步
        }                                   //最后循环结束的时候，pTemp就是最后一个节点，pPre就是他的前驱结点（倒数第二个节点）
        pPre->next=pTemp->next;             //倒数第二个节点的指针指向最后一个节点指向的NULL，于是最后一个节点就被架空了
        free(pTemp);                        //释放空间
        free(pPre);
    }

    int SizeList(node_t *head){
        node_t* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        return count;
        free(temp);
    }

    void MergeList(node_t **head1, node_t **head2){
        node_t * current;
        if(*head1 == NULL) {
            *head1 = *head2;
        }
        else {
            current = *head1;
            while(current->next != NULL)
                current = current->next;
    
            current->next = *head2;
        }
        *head2 = NULL
        free(current);
    }

    int SearchList(node_t **head, char target){
        node_t *temp= *head;
        int count=0;
        while(temp!=NULL){
            if(temp->ch==target){count++;}
            temp=temp->next;
        }
        return count;
        free(temp);
    }

    #endif //EX7_H
/*
    Muchamad Iqbal Fauzi
    672018382
*/

#include "stdio.h"
#include "stdlib.h"

int main(){

    // struktur data
    struct tnode{
        int x;
        struct tnode *next;
    };

    // inisialisasi object
    struct tnode *head=NULL, *curr=NULL, *node=NULL;

    // eksekusi atau get data
    for(int i=0; i<5; i++){
        node = (struct tnode*) malloc(sizeof (struct tnode));
        
        //input data
        printf("input-%i : ", i+1);
        scanf("%i", &node -> x);

        //reposition
        if(head == NULL){
            head = node;
            curr = node;
        }else{
            curr -> next = node;
            curr = node;
        }
    }
    //reset posotion
    curr -> next = NULL;
    curr = head;

    //tampil data
    int i=1;
    while(curr != NULL){
        printf("data-%i: %i\n",i++ ,curr -> x);
        curr = curr -> next;
    }

    return 0;
}
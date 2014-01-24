/*基础题。链表操作。每个牌堆之间用双链表链接，同一堆的牌直接用单链表链接.链表的头和尾各有一个哨兵，
为了方便查找左边的第三个牌堆，将表头哨兵的pre设为他自己，因此才需要表尾的哨兵*/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
using namespace std;
struct Card {
    char suit[2];      //花色和数字
    int num;           //它下面牌堆，包括自己的牌数
    Card *pre, *next, *child;   //指向前一个牌堆，后一个牌堆，自己牌堆下面的牌
};
Card data[55];
void Move(Card *p1, Card *p2)
{
    Card *child;
    child = p2->child;
    //delete p2
    if(child == NULL) {
        p2->pre->next = p2->next;
        p2->next->pre = p2->pre;
    }
    else {
        p2->pre->next = child;
		p2->next->pre = child;
        child->pre = p2->pre;
        child->next = p2->next;
    }
    //put p2 on top of p1
    p2->child = p1;
    p2->num = p1->num+1;
    //insett p2
    p2->pre = p1->pre;
    p2->next = p1->next;
    p2->pre->next = p2;
	p2->next->pre = p2;
    return ;
}
int main()
{
    int i, n;
    Card *current, *pre;
    data[0].suit[0] = data[0].suit[1] = '\0';
    data[0].pre = &data[0];
	data[53].next = NULL;
    while(1) {
        scanf("%s",data[1].suit);
        if(data[1].suit[0] == '#')
            break;
        for(i=2; i<=52;i++)
            scanf("%s",data[i].suit);
        for(i=0;i<53;i++)
            data[i].next = &data[i+1];
        for(i=1;i<54;i++) {
            data[i].pre = &data[i-1];
            data[i].num = 1;
            data[i].child = NULL;
        }
        current = &data[1];
        while(current != &data[53]) {
            pre = current->pre->pre->pre;
            if(pre->suit[0] == current->suit[0] || pre->suit[1] == current->suit[1])
                Move(pre, current);
            else {
                pre = current->pre;
                if(pre->suit[0] == current->suit[0] || pre->suit[1] == current->suit[1])
                    Move(pre, current);
                else
                    current = current->next;
            }
        }
        current = data[0].next;
        n = 0;
        while(current != &data[53]) {
            n++;
            current = current->next;
        }
        current = data[0].next;
		if(n == 1)
			printf("%d pile remaining:",n);
		else
			printf("%d piles remaining:",n);
        while(current != &data[53]) {
            printf(" %d", current->num);
			current = current->next;
        }
        printf("\n");
    }
    return 0;
}

/*
 * PrettyPrint.c
 *
 *  Created on: Nov 26, 2019
 *      Author: Omar Yunus
 */
#include <stdio.h>
#include <stdlib.h>
struct ACCOUNT {
int accountNumber;
float balance;
struct ACCOUNT *next;
};
struct ACCOUNT *head = NULL;

void findUpdate(int account, float amount){
	struct ACCOUNT *temp;
	temp=head;
	struct ACCOUNT *newnode;
	int accountexist=0;
	if(head==NULL){
		head=(struct ACCOUNT*)malloc(sizeof(struct ACCOUNT));
		head->accountNumber=account;
		head->balance=amount;
		head->next=NULL;
	}
	else{
		temp=head;
		while(temp!=NULL){//how to stop infinite loop
			if(temp->accountNumber==account){
				//update balance since account found
				temp->balance=(temp->balance)+amount;
				accountexist=1;//ie true
				break;
			}
			if(temp->next!=NULL){
				temp=temp->next;
			}
			else{
				break;
			}
			//to go ahead. when we exit loop temp goes last node BUT we havent checked temp itself
		}


		if(accountexist==0){
			newnode=(struct ACCOUNT*)malloc(sizeof(struct ACCOUNT));//created new node
			newnode->accountNumber=account;
			newnode->balance=amount;
			temp->next=newnode;
			newnode->next=NULL;
		}
		//if account does not exist

	}

}

void prettyPrint(){//linked list pretty printer
	struct ACCOUNT *ptemp;
		ptemp=head;
		while(ptemp!=NULL){
		 printf("ACCOUNT ID: %5d BALANCE: $ %6.2f \n", ptemp->accountNumber,ptemp->balance);
				 ptemp=ptemp->next;
		}
}


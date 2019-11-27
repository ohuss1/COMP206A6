/*
 * SSV.c
 *
 *  Created on: Nov 26, 2019
 *      Author: Omar Yunus
 */
#include <stdio.h>
#include <stdlib.h>

void parse(char record[],int *acct,float *amnt){
	int j=0,i=0,k=0;
							//ACCOUNT
					int characters1=0;
					int account;
					int fakeaccount;
					//int accountk;
					float amount;
					int counter=0;
					char field1 [300];
					char field2 [300];
					int flagaccount=0;
					int flagamount=0;//0 false

						//account

						for(k=0;k<300 && record[k]!=' ' && record[k]!='\n' && record[k]!=EOF && isdigit(record[k]);k++,i++){
							flagaccount=1;

							field1[i]=record[i];
							counter++;

							characters1=i;
						}
						field1[counter+1]='\0';
						account=atoi(field1);

						*acct=account;
						//fakeaccount=*acct;

							//NOW TRANSACTION
						k=0;
							for(int i=counter+1;i<300 && record[i]!=' ' && record[i]!='\n' && record[i]!=EOF && (isdigit(record[i])||record[i]=='.'||record[i]=='-');k++,i++){

								field2[k]=record[i];
												}//name
							field2[k+1]='\0';
													amount=strtof(field2,NULL);
													*amnt=amount;
													//amount=
							counter=0;
							k=0;
												characters1=25-characters1;

												//memset(acct, 0, sizeof acct);
												//memset(amnt, 0.0, sizeof amnt);
												memset(field1, '\0', sizeof field1);
												memset(field2, '\0', sizeof field2);

}

/*
 ============================================================================
 Name        : main.c
 Author      : Omar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ssv.h"
#include "linked.h"
int main(int argc, char* argv[]) {
	FILE *s=fopen("students.ssv", "r");//, *d=fopen("copy.txt", "wt");
			if(s==NULL){
				  perror("Error while opening the file.\n");
				  exit(1);
			}
			char field1[300];
			char field2[300];
			char field3[400];

			//PrintFile(s);
			//PrintFile in main

			char buffer[500];
				char field11[300];
				char field22[300];
				char field33[400];
				char c;
				int record=1;
				//double fieldTT;
				float amount;
				int account;
				//double amount;
				char emptyspace;


				char * Transaction = "Transaction";
				while ( !feof(s)){
					printf("\n %c \n",c);

						if (fgets(buffer,499,s) !=NULL && (c!='\n') && (buffer[0]!='\n'))
						{


							int i=0;

							int *acct;
							acct = (int*) malloc(2*sizeof(int));

							float *amnt;
							amnt = (float*) malloc(2*sizeof(float));



							parse(buffer,acct,amnt);
							amount=*amnt;
							account=*acct;
							findUpdate(account,amount);

							//printf("Account no %d: Transaction %.2f", *acct,*amnt);
							i+=2;
							memset(acct, 0, sizeof acct);
							memset(amnt, 0.0, sizeof amnt);
							memset(buffer, '\0', sizeof buffer);
								account=-1;
							//}
						}
				}

			//Printfileinamin


			fclose(s); //fclose(d);
			prettyPrint();

					return(0);

}

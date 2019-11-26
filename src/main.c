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


void PrintFile(FILE *source){
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
	while ( !feof(source)){
		printf("\n %c \n",c);

			if (fgets(buffer,499,source) !=NULL && (c!='\n') && (buffer[0]!='\n'))
			{

				/*int j=0,i=0,k=0;
				int characters1=0;



					for(k=0;k<300 && buffer[i]!=' ' && buffer[i]!='\n' && buffer[i]!=EOF;k++,i++){
						field11[k]=buffer[i];
						characters1=i;
					}//id
						characters1=15-characters1;
						account=atoi(field11);


					//printf("Record%d: Account=%s %*s ", record,field11,characters1,"");
						printf("Record%d: Account=%d %*s ", record,account,characters1,"");
					i++;
					//for(k=0;k<300 && buffer[i]!=',';k++,i++)field2[k]=buffer[i];
					for(k=0;k<300 && buffer[i]!=' ' && buffer[i]!='\n' && buffer[i]!=EOF;k++,i++){
						field22[k]=buffer[i];
						characters1=i;
					}//name
					characters1=25-characters1;
					printf(" %s=%s ", Transaction,field22);
					i++;
					//for(k=0;k<400 && ((buffer[i]!='\0'));k++,i++)field3[k]=buffer[i];

					record++;
					memset(field11, '\0', sizeof field11);
					memset(field22, '\0', sizeof field22);*/
				//char fake[];
				int i=0;
				//sscanf(buffer,"%d,%f",&account,&amount);
				//sscanf(buffer,"%lf",&amount);
				//account=atoi(buffer[i]);
				int *acct;
				acct = (int*) malloc(2*sizeof(int));

				float *amnt;
				amnt = (float*) malloc(2*sizeof(float));

				//printf("%c",buffer[i]);

				parse(buffer,acct,amnt);
				amount=*amnt;
				account=*acct;
				printf("Account no %d: Transaction %.2f", *acct,*amnt);
				i+=2;
				memset(acct, 0, sizeof acct);
				memset(amnt, 0.0, sizeof amnt);
				memset(buffer, '\0', sizeof buffer);




					account=-1;//indicates wrong account number
					//memset(field33, '\0', sizeof field33);
				//}
			}//displays all records in database
	}
}

int main(int argc, char* argv[]) {
	FILE *s=fopen("babloo.ssv", "r");//, *d=fopen("copy.txt", "wt");
			if(s==NULL){
				  perror("Error while opening the file.\n");
				  exit(1);
			}
			char field1[300];
			char field2[300];
			char field3[400];

			PrintFile(s);
			fclose(s); //fclose(d);
					return(0);
}

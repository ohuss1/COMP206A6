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

void PrintFile(FILE *source){
	char buffer[500];
	char field11[300];
	char field22[300];
	char field33[400];
	char c;
	int record=1;
	double fieldTT;
	int account;

	char * name = "Transaction";
	while ( !feof(source)){
		printf("\n %c \n",c);

			if (fgets(buffer,499,source) != NULL && (c!='\n'))
			{

				int j=0,i=0,k=0;
				int characters1=0;


					for(k=0;k<300 && buffer[i]!=' ' && buffer[i]!='\n' && buffer[i]!=EOF;k++,i++){
						field11[k]=buffer[i];
						characters1=i;
					}//id
						characters1=15-characters1;


					printf("Record%d: Account=%s %*s ", record,field11,characters1,"");
					i++;
					//for(k=0;k<300 && buffer[i]!=',';k++,i++)field2[k]=buffer[i];
					for(k=0;k<300 && buffer[i]!=' ' && buffer[i]!='\n' && buffer[i]!=EOF;k++,i++){
						field22[k]=buffer[i];
						characters1=i;
					}//name
					characters1=25-characters1;
					printf(" %s=%s ", name,field22);
					i++;
					//for(k=0;k<400 && ((buffer[i]!='\0'));k++,i++)field3[k]=buffer[i];

					record++;
					memset(field11, '\0', sizeof field11);
					memset(field22, '\0', sizeof field22);
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

#include<stdio.h>
#define size 100
//the ciphering function
void caesar(char *sptr,int key){
	char cipher[size];
	//loop to cipher each element
	for(int i=0;(*(sptr+i))!='\0';i++){
		//In case of (space)
		if((*(sptr+i))==32)
					cipher[i]=(*(sptr+i));
		//In case the sum of the key and the key doesn't exceed the range of alphabets
		else if((((*(sptr+i))+key<=122)&&(*(sptr+i)>=97))||(((*(sptr+i))+key<=90)&&(*(sptr+i)>=65)))
			cipher[i]=(*(sptr+i))+key;
		//In case the sum of the key and the key exceeds the range of alphabets
		else if((((*(sptr+i))+key>=122)&&(*(sptr+i)<=122))||(((*(sptr+i))+key>=90)&&(*(sptr+i)<=90)))
			cipher[i]=(*(sptr+i))-(26-key);
		//In case there is a non alphabetic character
		else{
			puts("ERROR!! You have entered a non alphabetic character \n");
			//End the function
			return;
		}
	}
	//printing the plain text and the cipher text
	printf("The plain text is: %s \n",sptr);
	printf("The cipher text is: %s \n",cipher);
}
int main(){
	//Lines 30,31 are functions to deal with eclipse problems with scanning and printing functions
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	char plain[size],*sptr=plain;
	int key;
	//Get the original text and the key
	puts("Enter the plain text: \n");
	gets(sptr);
	puts("Enter the key: \n");
	scanf("%d",&key);
	//call the ciphering function
	caesar(sptr,key);
	//End of the program
	return 0;
}

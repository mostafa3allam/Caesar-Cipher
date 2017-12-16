#include<stdio.h>
#define size 100
void decrypt(char *cptr,int key){
	char plain[size];
	int x=0;
	//loop to cipher each element
	for(int i=0;(*(cptr+i))!='\0';i++){
		//In case of (space)
		if((*(cptr+i))==32)
			plain[i]=(*(cptr+i));
		//In case the subtraction of the key and the key doesn't exceed the range of alphabets
		else if((((*(cptr+i))<=122)&&(*(cptr+i)-key>=97))||(((*(cptr+i))<=90)&&(*(cptr+i)-key>=65)))
			plain[i]=(*(cptr+i))-key;
		//In case the subtraction of the key and the key exceeds the range of alphabets
		else if((((*(cptr+i))>=97)&&(*(cptr+i)-key<=97))||(((*(cptr+i))>=65)&&(*(cptr+i)-key<=65)))
			plain[i]=(*(cptr+i))+(26-key);
		//In case there is a non alphabetic character
		else{
			puts("ERROR!! You have entered a non alphabetic character \n");
			//End the function
			return;
		}
		x++;
	}
	*(cptr+x)='\0';
	//printing the plain text and the cipher text
	printf("The cipher text is: %s \n",cptr);
	printf("The plain text is: %s \n",plain);
}
//the ciphering function
void caesar(char *sptr,int key){
	char cipher[size];
	int x=0;
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
		x++;
	}
	*(sptr+x)='\0';
	//printing the plain text and the cipher text
	printf("The plain text is: %s \n",sptr);
	printf("The cipher text is: %s \n",cipher);
}
int main(){
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int key;
	char inp;
	puts("Please enter E for encryption and D for decryption: ");
	gets(&inp);
	if(inp==69||inp==101){
		//Get the original text and the text
		char plain[size],*sptr=plain;
		puts("Enter the plain text: \n");
		gets(sptr);
		puts("Enter the key: \n");
		scanf("%d",&key);
		//call the ciphering function
		caesar(sptr,key);
	}
	else if(inp==68||inp==100){
		char cipher[size],*cptr=cipher;
		//Get the encrypted text and the text
		puts("Enter the encrypted text: \n");
		gets(cptr);
		puts("Enter the key: \n");
		scanf("%d",&key);
		//call the decryption function
		decrypt(cptr,key);
	}
	else
		puts("ERROR You have entered a wrong character");
	//End of the program
	return 0;
}

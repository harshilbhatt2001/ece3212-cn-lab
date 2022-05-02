#include<stdio.h>
#include<string.h>

char data[100], pattern[100];
int data_length, pattern_length;
char rem[10];
int i, j, count=0, num;

void xor();
void crc();

void xor()
{	
	for(i=1; i<pattern_length; i++) {
		rem[i] = ((rem[i] == pattern[i]) ? '0' : '1');
	}
}

void crc()
{
	for(num=0; num < pattern_length; num++) {
    rem[num]=data[num];
  }
	do {
		if(rem[0] == '1') {
      xor();
    }
		
    for(i=0;i<pattern_length-1;i++) {
			rem[i] = rem[i+1];
		}
		
    rem[i] = data[num++];
  } while (num <= data_length + pattern_length - 1);	
}

int main()
{
	printf("Enter the data :");
	scanf("%s",data);
	printf("-------------------------------------------------------------------\n");
	data_length = strlen(data);
	printf("Enter the generating Pattern:");
	scanf("%s",pattern);
	printf("-------------------------------------------------------------------\n");
	pattern_length = strlen(pattern);
	for (i = data_length; i < data_length+pattern_length-1; i++)
	{
		data[i]='0';
	}
	printf("-------------------------------------------------------------------\n");
	
	printf("\nModifying the data\n");
	printf("-------------------------------------------------------------------\n");
	crc();
	printf("\nData Modified\n");
	printf("-------------------------------------------------------------------\n");
	printf("\nModified Data:");
	for (i = data_length,j=0; i < data_length+pattern_length-1; i++,j++)
	{
		data[i]=rem[j];
	}
	printf("%s\n",data);
	printf("-------------------------------------------------------------------\n");
	printf("\nSending the modified data\n");
	printf("\nData Sent\n");
	printf("-------------------------------------------------------------------\n");
	printf("-------------------------------------------------------------------\n");
	printf("\nRecieving the Data\n");
	printf("-------------------------------------------------------------------\n");
	printf("\nChecking for error bits\n");
	crc();
	printf("-------------------------------------------------------------------\n");
	for(i=0;i<strlen(rem);i++)
	{
		if(rem[i]=='0')
		count++;
	}
	if(count==strlen(rem))
	{
		printf("\nData Received Successfully");
	}
	else
	{
		printf("Parity Error");
	}
}

#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MSGSZ	128

struct msgbuf{
	long mtype;
	char mtext[MSGSZ];
};


int main(){

	
	int msqid;	
	key_t key;
	struct msgbuf rcv;
	int length;
	
	key=1234;
	msqid=msgget(key,0666);
	
	if(msgrcv(msqid, &rcv, MSGSZ, 1, 0) <0)
	{
		printf("nie udalo sie odebrac komunikatu");
		return -1;
	}
	
	length=strlen(rcv.mtext);
	int dlugosc=0;
	
	if(((rcv.mtext[0] >= 65) && (rcv.mtext[0] <= 90)) || ((rcv.mtext[0] >= 97) && (rcv.mtext[0] <= 122))){
		dlugosc++;
	for(int i = 1; i<length; i++){
	if((rcv.mtext[i] >= 32) && (rcv.mtext[i] <= 126))  {
		dlugosc++;
		}
		
	if(length==dlugosc)
	{
		printf("poprawny komunikat: %s",rcv.mtext);
	}
	
return 0;	
}
	
	
	
	
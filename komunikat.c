#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSZ 128

struct msgbuf{
long type;
char mtext[MSGSZ];
};

int main()
{
int msqid;
int msgflg = IPC_CREAT | 0666;
key_t key;
size_t length;

key=1234;
struct msgbuf msg;
msg.mtype=1;

scanf("%[^\n]",msg.mtext);
length=strlen(msg.mtext)+1;

msqid=msgget(key,msgflg);

if((msgsnd(msqid,&msg,length,0)== -1 ){
	printf("wysylanie wiadomosci nie powiodlo sie");
	return -1;
}

return 0;
}
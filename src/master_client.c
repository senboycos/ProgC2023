#if defined HAVE_CONFIG_H
#include "config.h"
#endif

#define _XOPEN_SOURCE

#include <stdlib.h>
#include <stdio.h>

#include "myassert.h"

#include "master_client.h"

// fonctions éventuelles internes au fichier

// fonctions éventuelles proposées dans le .h

//creation semaphores
int creatSem(int key,char * chemin){
	key =ftok(chemin,cle);
	int semId = semget(key,1,0641 | IPC_CREAT);
	myassert(semId!=-1,"erreur creation semaphore");
	return semId;
}

//operation sur semaphore
void my_semctl(int semId,int valeur){
	int ret = semclt(semId,0,SETVAL, valeur);
	myassert(ret !=-1,"erreur modif semaphore");
}
void my_semdelete(int semId){
	int ret = semclt(semId,-1, IPC_RMID);
	myassert(ret !=-1,"erreur destruction semaphore");
}
void operationMoins(int semId){
	struc sembuf moins={0,-1,0};
	int ret = semop(semId,&moins,1);
	myassert(ret !=-1,"erreur moins sur semaphore");
}
void operationPlus(int semId){
	struc sembuf plus={0,1,0};
	int ret = semop(semId,&plus,1);
	myassert(ret !=-1,"erreur moins sur semaphore");
}

//creation tubes
void creatTube(const char * chemin){
	int f = mkfifo(chemin, 0666);
	myassert(f == 0,"erreur creation tube");
}
void deleteTube(const char * chemin){
	int f =unlink(chemin);
	myassert(f == 0,"erreur suppression tube");
}
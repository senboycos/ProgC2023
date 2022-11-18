#ifndef CLIENT_CRIBLE
#define CLIENT_CRIBLE

// On peut mettre ici des éléments propres au couple master/client :
//    - des constantes pour rendre plus lisible les comunications
//    - des fonctions communes (création tubes, écriture dans un tube,
//      manipulation de sémaphores, ...)

// ordres possibles pour le master
#define ORDER_NONE                0
#define ORDER_STOP               -1
#define ORDER_COMPUTE_PRIME       1
#define ORDER_HOW_MANY_PRIME      2
#define ORDER_HIGHEST_PRIME       3
#define ORDER_COMPUTE_PRIME_LOCAL 4   // ne concerne pas le master

#define TUBE_CLIENT_MASTER "Tclientmaster"
#define TUBE_MASTER_CLIENT "Tmasterclient"

#define SEM_CLIENT_MASTER "Sclientmaster"
#define SEM_MASTER "Smaster"

#define cle 50


// bref n'hésitez à mettre nombre de fonctions avec des noms explicites
// pour masquer l'implémentation

//creation semaphores
int creatSem(int key,char * chemin);

//operation sur semaphore
void my_semctl(int semId,int valeur);
void my_semdelete(int semId);
void operationMoins(int semId);
void operationPlus(int semId);

//creation tubes
void creatTube(const char * chemin);
void deleteTube(const char * chemin);

#endif

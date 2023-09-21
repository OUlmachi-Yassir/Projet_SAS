#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define max 100

typedef struct
{
    int j, m, a;
} date;

typedef struct
{
    char description[100];
    char titre[20];
    char statut[20];
    int Id;
    date Deadline;
} ToDolist;

static int i = 0; 
int totalTaches=0;
int tachesCompletes = 0; 
int tachesIncompletes = 0; 

void ajouterFc(ToDolist np[])
{
    ToDolist A;
    A.Id=i+1;
    printf("le titre :\n");
    fgets(A.titre, 20, stdin);
    printf("Description: \n");
    fgets(A.description,100, stdin);
    printf("ID :%d\n",A.Id);
    //scanf("", &);
    printf("Deadline :\n");
    scanf("%d/%d/%d", &A.Deadline.j, &A.Deadline.m, &A.Deadline.a);
    getchar();
    printf("statut {complète , en cours , incomplète}: \n");
    fgets(A.statut, 20, stdin);
    
    if (strcmp(A.statut, "complète\n") == 0)
    {
        tachesCompletes++; 
    }
    else if (strcmp(A.statut, "incomplète\n") == 0)
    {
        tachesIncompletes++;
    }
    np[i++] = A;
    totalTaches++;
}
void modifierTache1(ToDolist np[100], int numTasks)
{
    int taskId;
    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &taskId);

    for (int j = 0; j < numTasks; j++)
    {
        if (np[j].Id == taskId)
        {
             printf("Nouvelle description :\n");
            fgets(np[j].description, sizeof(np[j].description), stdin);
           
            return;
        }
    }

    printf("Aucune tache avec l'ID %d n'a ete trouvee.\n", taskId);
}
void modifierTache2(ToDolist np[100], int numTasks)
{
    int taskId;
    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &taskId);

    for (int j = 0; j < numTasks; j++)
    {
        if (np[j].Id == taskId)
        {
           
            printf("Nouvelle description :\n");
            fgets(np[j].description, sizeof(np[j].description), stdin);
            
            return;
        }
    }

    printf("Aucune tâche avec l'ID %d n'a ete trouvee.\n", taskId);
}
void modifierTache3(ToDolist np[100], int numTasks)
{
    int taskId;
    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &taskId);

    for (int j = 0; j < numTasks; j++)
    {
        if (np[j].Id == taskId)
        {
             printf("Nouveau statut :\n");
             getchar(); 
            fgets(np[j].statut, sizeof(np[j].statut), stdin);
            printf("Tache modifiee avec succes.\n");
            return;
        }
    }

    printf("Aucune tache avec l'ID %d n'a ete trouvee.\n", taskId);
}
void TrisAlphabe(ToDolist np[100], int taille) {
    ToDolist cle;

    for (int i = 1; i < taille; i++) {
        cle = np[i];
        int j = i - 1;

        while (j >= 0 && strcmp(np[j].titre, cle.titre) > 0) {
            np[j + 1] = np[j];
            j = j - 1;
        }

        np[j + 1] = cle;
    }
}
void triDeadline(ToDolist np[100], int numTasks){
ToDolist temp;

    for (int i = 0; i < numTasks - 1; i++)
    {
     for (int j = 0; j < numTasks - i - 1; j++)
     {
        if (np[j].Deadline.a > np[j + 1].Deadline.a ||
           (np[j].Deadline.a == np[j + 1].Deadline.a && np[j].Deadline.m > np[j + 1].Deadline.m) ||
           (np[j].Deadline.a == np[j + 1].Deadline.a && np[j].Deadline.m == np[j + 1].Deadline.m && np[j].Deadline.j > np[j + 1].Deadline.j))
            {
                temp = np[j];
                np[j] = np[j + 1];
                np[j + 1] = temp;
            }
        }
    }


}

void rechercheId(ToDolist np[100], int numTasks)
{
    int taskId;
    printf("Entrez l'ID de la tache a rechercher : ");
    scanf("%d", &taskId);

    for (int j = 0; j < numTasks; j++)
    {
        if (np[j].Id == taskId)
        {
            printf("%d---%s %s /ID:%d />>  %d/%d/%d  <</>>%s \n",j+1,np[j].titre,np[j].description,np[j].Id,np[j].Deadline.j,np[j].Deadline.m,np[j].Deadline.a,np[j].statut);
            }
    }
}

void rechercheAlphabet(ToDolist np[100], int numTasks)
{
    char cle[20];
    
    printf("Entrez le titre de la tache a rechercher : ");
    getchar();
    fgets(cle,20, stdin);
    for (int j = 0; j < numTasks; j++){
    if(strcmp(np[j].titre,cle)==0){
    printf("%d---%s %s /ID:%d />>  %d/%d/%d  <</>>%s \n",j+1,np[j].titre,np[j].description,np[j].Id,np[j].Deadline.j,np[j].Deadline.m,np[j].Deadline.a,np[j].statut);
    }
    }
}

void supprimer(ToDolist np[100], int numTasks)
{
    int taskId;
    int k;
    printf("Entrez l'ID de la tache a modifier : ");
    scanf("%d", &taskId);

    for (int i = 0; i < numTasks; i++)
    {
        if (np[i].Id == taskId)
        {
         k=i;
			
		for(int j=k;j<numTasks;j++){
			np[j]=np[j+1];
				numTasks=numTasks-1;
         }
        }
    }
}

int main()
{
    ToDolist np[100];
    int nbTs;
    int n;

    printf("*********\\INSCRIPTION//*********\n");
    char a[25], b[25];
    strcpy(b, "User");

    start:
    printf("code d'acces : ");
    scanf("%s", a);
    if (strcmp(a, b) == 0)
    {
        printf("****BIENVENUE****\n");
    }
    else
    {
        printf("****L'ACCES EST REFUSE****\n");
        goto start;
    }

    printf(" ************************************************* ");
    sleep(5);
    system("cls");
    printf("*****************MENUS*****************\n\n");
    printf("1-Ajouter une nouvelle tache \n");
    printf("2-Ajouter plusieurs nouvelles taches\n");
    printf("3-Afficher la liste de toutes les taches \n");
    printf("4-Modifier une tache\n");
    printf("5-Supprimer une tache par identifiant \n");
    printf("6-Rechercher les Taches\n");
    printf("7-Statistiques \n");
    printf("8-Quitter\n\n");

    st:
    printf("**>>>choisir : \n");
    scanf("%d", &n);
    getchar();

    switch (n)
    {
    case 1:
        do
        {
            printf(" donner le nombre de taches que tu veux faire : ");
            scanf("%d", &nbTs);
    getchar();
            printf("\n");
            if (nbTs > 50 || nbTs < 1)
                printf("le nombre des taches doit etre compris entre 1 et %d\n", max);
        } while (nbTs > 50 || nbTs < 1);
        for (int j = 0; j < nbTs; j++)
        {
            ajouterFc(np);
        }
        goto st;
    case 2:
    printf("Ajouter plusieurs taches\n");
    printf("Combien de taches voulez-vous ajouter : ");
    scanf("%d", &nbTs);
    getchar();

    for (int j = 0; j < nbTs; j++)
    {
        if (i < max)
        {
            ajouterFc(np);
        }
        else
        {
            printf("Le tableau est plein, impossible d'ajouter plus de taches.\n");
            break;
        }
    }
    goto st;
    case 3:
    printf("**************<Affichage des tache>***********\n ");
    for(int j=0;j<nbTs;j++){
    printf("%d---%s %s /ID:%d />>  %d/%d/%d  <</>>%s \n",j+1,np[j].titre,np[j].description,np[j].Id,np[j].Deadline.j,np[j].Deadline.m,np[j].Deadline.a,np[j].statut);
    }
    int A;
    cc :
    printf("tu veux trier votre tableux (chois 1/0): \n");
    scanf("%d",&A);
    if(A==0){
        printf("okay\n");
        sleep(2);
        goto st;
    }
    else if(A==1){
        int s;
        
        printf("1->Trier les taches par ordre alphabetique.\n");
        printf("2->Trier les taches par deadline.\n");
        printf("Choise de Tirage (1/2): \n");
        scanf("%d",&s);
        switch (s)
        {
        case 1:
            TrisAlphabe(np,i);
            printf("Taches tries par ordre alphabetique.\n");
            sleep(2);
            goto cc;
        case 2:
            triDeadline(np,i);
            printf("Taches tries par ordre alphabetique.\n");
            sleep(2);
            goto cc;
        
        default: printf(" choix invalide.\n");
            goto cc;
        }
          
     }

    goto st;
    case 4://modifier
    int x;
    xx:
    printf("choix de modification d'une tache :");
    scanf("%d",&x);
    switch (x)
    {
    case 1:
        modifierTache1(np,i);
        goto xx;
    case 2:
        modifierTache2(np,i);
        goto xx;
    case 3:
        modifierTache3(np,i);
        goto xx;
    
    default:
        break;
    }

    goto st;
    case 5://supprime
supprimer(np,i);
    goto st;
    case 6://Alphabe
    int m;
    RT:
    printf("Rechercher une tache par son Identifiant.\n");
    printf("Rechercher une tache par son Titre.\n");
    printf("Rechercher les Taches 1/2:");
    scanf("%d",&m);
    if(m=1){
        rechercheId(np,i);
    }
    else if(m=2){
    rechercheAlphabet(np,i);
    }
    else{
        goto RT;
    }

    goto st;
    case 7://statestiques
    int r;
    stt :
      printf("1\\ --Afficher le nombre total des taches.\n");
      printf("2\\--Afficher le nombre de taches completes et incompletes.\n");
      printf("3\\ --Afficher le nombre de jours restants jusqu'au delai de chaque tache.\n");
      printf("\n");
      printf(">>>quelle genre de statique tu veux faire : \n");
      scanf("%d",&r);
      switch (r)
      {
       case 1:
        printf("Nombre total de taches : %d\n", totalTaches);
        goto stt;
       case 2:
        printf("Nombre de taches completes : %d\n", tachesCompletes);
        printf("Nombre de taches incompletes : %d\n", tachesIncompletes);
        goto stt;
       case 3:
        
        goto stt;
      
      default:
        break;
      }

    goto st;
    case 8:
    system("cls");
    printf("***********************GOOOOODBYE**********************");
    sleep(5);
    break;
    }
    
    return 0;
}

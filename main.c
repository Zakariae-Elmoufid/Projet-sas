#include <stdio.h>
#include <string.h>

#define maxEtudiant 300

struct DateNaissance{
    int jour;
    int mois;
    int annee;
};
struct Etudiants{
  int Numero ;
  char Nom[30];
  char Prenom[30];
  struct DateNaissance date ;
  char Departement[30];
  float NoteGeneral;
};

struct Etudiants etudiant[maxEtudiant];

int count = 0;
int repeat = 0;

void Ajouter(){
        encore:
    printf("Entrez le numero d'etudiant : ");
    scanf("%d",&etudiant[count].Numero);
    printf("Entrez le nom d'etudiant: ");
    scanf("%s",etudiant[count].Nom);
    printf("Entrez le prenom d'etudiant : ");
    scanf("%s",etudiant[count].Prenom);
    printf("Entrez la date de naissance.\n");
    printf("jour : ");
    scanf("%d",&etudiant[count].date.jour);
    printf("mois : ");
    scanf("%d",&etudiant[count].date.mois);
    printf("annee : ");
    scanf("%d",&etudiant[count].date.annee);
    printf("Entrez departement d'etudiant :");
    scanf("%s",etudiant[count].Departement);
    printf("Entrez la note general d'etudiant : ");
    scanf("%f",&etudiant[count].NoteGeneral);


    count++;

     printf("vous voulez ajouter un autre contact? \n");
     printf("si oui tapez 1 sinon tapez 0 : ");
     scanf("%d",&repeat);

     if(repeat!=0)
        goto encore ;

}

void Afficher(){
    int i ;
for (i=0;i<count;i++) {
        printf("Numero: %d\n", etudiant[i].Numero);
        printf("Nom: %s\n", etudiant[i].Nom);
        printf("Prenom: %s\n", etudiant[i].Prenom);
        printf("Date de Naissance: %d/%d/%d\n",etudiant[i].date.jour,etudiant[i].date.jour,etudiant[i].date.jour);
        printf("Departement: %s\n", etudiant[i].Departement);
        printf("Note Generale: %.2f\n", etudiant[i].NoteGeneral);
        printf("----------------------------\n");
    }
}

void Modifier(){
    int numeroUnique, i;
    int numero ;
    char nom[30] ;
    char prenom[30] ;
    int j , m , a ;
    char departement[30] ;
    float note ;


    printf("Entrez le nomber d'etudiant s'il vous plait : ");
    scanf("%d",&numeroUnique);
    for(i=0;i<count;i++){
        if(numeroUnique==etudiant[i].Numero){
    printf("Entrez la nouvelle d'information.\n");
    printf(" nom d'etudiant: ");
    scanf("%s",nom);
    strcpy(etudiant[i].Nom,nom);
    printf(" prenom d'etudiant : ");
    scanf("%s",prenom);
    strcpy(etudiant[i].Prenom,prenom);
    printf(" la date de naissance.\n");
    printf("jour : ");
    scanf("%d",&j);
    etudiant[i].date.jour=j;
    printf("mois : ");
    scanf("%d",&m);
    etudiant[i].date.mois=m;
    printf("annee : ");
    scanf("%d",&a);
    etudiant[i].date.annee=a;
    printf(" departement d'etudiant :");
    scanf("%s",departement);
    strcpy(etudiant[i].Departement,departement);
    printf(" la note general d'etudiant : ");
    scanf("%f",&note);
    etudiant[i].NoteGeneral = note;
    return;
    printf(" modification avec succes.\n");
        }
    }
    printf("Cette etudiant n'existe pas");
}

void Supprimer(){
   int numeroUnique , i , j ;
    printf("Entrez le nomber d'etudiant s'il vous plait : ");
    scanf("%d",&numeroUnique);

    for(i=0;i<count;i++){
        if(numeroUnique==etudiant[i].Numero){
            for(j=i;j<count-1;j++){
                strcpy(etudiant[j].Nom,etudiant[j+1].Nom);
                strcpy(etudiant[j].Prenom,etudiant[j+1].Prenom);
                etudiant[j].date.jour = etudiant[j+1].date.jour;
                etudiant[j].date.mois = etudiant[j+1].date.mois;
                etudiant[j].date.annee = etudiant[j+1].date.annee;
                strcpy(etudiant[j].Departement,etudiant[j+1].Departement);
            }
            count--;
            printf("supprimer avec succes.\n");
            return;
        }
    }
    printf("ne trouve pas cette numero");
}

void CalculerDepartement(){

  char departement[30];
  float sommeD = 0;
  float sommeU = 0 ;
  int countEtudiant = 0 ;
  int i;

  printf("saisir departement que vous vollez savoir la note generle :");
  scanf("%s",departement);

  for(i=0;i<count;i++){
    if(strcasecmp(etudiant[i].Departement,departement)==0){
        sommeD = sommeD + etudiant[i].NoteGeneral;
        countEtudiant++;
    }
  }

  printf("la note general depatement %s est %.2f",departement,sommeD / countEtudiant);

  for(i=0;i<count;i++){
    sommeU = sommeU + etudiant[i].NoteGeneral;
  }
  printf("la note general dans university est %2.f",sommeU/count);
}

//Statistique
void Statistiques(){

    printf("le nomber total d'etudians inscrits est %d .\n",count);
//le nombre d'étudiants dans chaque département.
     int i ,j ;
   char T[maxEtudiant][30];
   int copmare ;
    int countE = 0 ;



   for(i=0;i<count;i++){
     copmare=1;
     for( j=0;j<countE;j++){
           if(strcasecmp(etudiant[i].Departement,T[j])==0) {
           copmare = 0;
           break;
           }
   }
     if(copmare){
        strcpy(T[countE],etudiant[i].Departement);
        countE++;
     }
    }


      for(i=0;i<countE;i++){
     int countD = 0;
        for(j=0;j<count;j++){
            if(strcasecmp(T[i],etudiant[j].Departement)==0){
                countD++;
            }
        }
        printf("--%s : %d\n",T[i],countD);
      }
//les étudiants ayant une moyenne générale supérieure à un certain seuil.

        printf("les etudiants ayant une moyenne generale superieure a un certain seuil :\n");
   for(i=0;i<count;i++){
    if(etudiant[i].NoteGeneral>=10){
        printf("----%s %s : %.2f .\n",etudiant[i].Nom,etudiant[i].Prenom,etudiant[i].NoteGeneral);
    }
   }
//les 3 étudiants ayant les meilleures notes.
 int swap ;
for(i=0;i<count-1;i++){
    for(j=0;j<count-i-1;j++){
            if(etudiant[i].NoteGeneral<etudiant[j+1].NoteGeneral){
        swap = etudiant[j].NoteGeneral;
        etudiant[j].NoteGeneral = etudiant[j+1].NoteGeneral;
        etudiant[j+1].NoteGeneral = swap ;
    }
    }
}

for(i=0;i<3;i++){
    printf("-- la note %d: %.2f \n",i+1,etudiant[i].NoteGeneral);
        printf("Numero: %d\n", etudiant[i].Numero);
        printf("Nom: %s\n", etudiant[i].Nom);
        printf("Prenom: %s\n", etudiant[i].Prenom);
        printf("Date de Naissance: %d/%d/%d\n",etudiant[i].date.jour,etudiant[i].date.jour,etudiant[i].date.jour);
        printf("Departement: %s\n", etudiant[i].Departement);
}



}









int main() {

   int choix ;
    choix = 0 ;
    int i ;

    do{
     printf("\nMenu de gestion des Etudiants dans une universite :\n");
         printf("1. Ajouter un etudiant\n");
         printf("2. Modifier un etudiant\n");
         printf("3. Supprimer un etudiant\n");
         printf("4. Afficher \n");
         printf("5. moyenne generale\n");
         printf("6. statistiques\n");
         printf("7. Rechercher\n");
         printf("Entrez votre choix : ");
         scanf("%d", &choix);


//    // Exécution des fonctions selon le choix
    switch(choix){
    case 1 :
    Ajouter();
        break;
    case 2:
       Modifier();
        break;
    case 3:
        Supprimer();
       break;
    case 4:
        Afficher();
        break;
    case 5:
        CalculerDepartement();
        break;
    case 6 :
        Statistiques();
        break;



    default :
     printf("il n'y a pas cette le nomber sur menu");
      break;
    }

     printf(" est ce que vous-affichez le menu \n");
     printf("si vollez-vous afficher le menu ,ecrivez 1 si non 0 :");
     scanf("%d",&repeat);


 }while(repeat != 0);


return 0;
}

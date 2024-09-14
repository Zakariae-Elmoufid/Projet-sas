#include <stdio.h>
#include <string.h>
#include "header.h"

#define maxEtudiant 300


int main() {

   int choix ;
    choix = 0 ;
    int i ;

    do{
         printf("\nMenu de gestion des Etudiants dans une universite :\n");
         printf("       1. Ajouter un etudiant\n");
         printf("       2. Modifier un etudiant\n");
         printf("       3. Supprimer un etudiant\n");
         printf("       4. Afficher \n");
         printf("       5. moyenne generale\n");
         printf("       6. statistiques\n");
         printf("       7. Rechercher\n");
         printf("       8. List d'etudiants\n");
         printf("       9. Afficher le nom  de A a Z OU de Z a A \n");
         printf("\n");
         printf("--Entrez votre choix : ");
         scanf("%d", &choix);



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
        printf("\n");
        printf("le nomber total d'etudians inscrits est %d .\n",count);
        EtudiantDepartement();
        MoyenneSeuil();
        MeilleuresNotes();
        EtudiantReussiDepartement();
        break;
    case 7 :
        Rechercher();
        break;
    case 8 :
        ListDepartement();
        break;
    case 9 :
        TrierAlphabetiqueAZ();
        TrierAlphabetiqueZA();
        break;

    default :
     printf("il n'y a pas cette le nomber sur menu");
      break;
    }

     printf("***est ce que vous-affichez le menu*** \n");
     printf("***si vollez-vous afficher le menu ,ecrivez 1 si non 0 :  ");
     scanf("%d",&repeat);


 }while(repeat != 0);


return 0;
}

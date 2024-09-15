#include <stdio.h>
#include <string.h>
#include "header.h"

#define maxEtudiant 300

struct Etudiants etudiant[maxEtudiant];

int count = 0;
int repeat = 0;

// Cette fonction permet d'ajouter des �tudiants au tableau.
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

     printf("vous voulez ajouter un autre etudiant? \n");
     printf("si oui tapez 1 sinon tapez 0 : ");
     scanf("%d",&repeat);

     if(repeat!=0)
        goto encore ;

}
// Fonction pour afficher les informations des �tudiants
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
// Fonction pour modifier les informations d'un �tudiant sp�cifique
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
    printf("entrez le numero unique : ");
    scanf("%d",&numeroUnique);
    etudiant[i].Numero=numeroUnique;
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
// Fonction pour supprimer un �tudiant du tableau
void Supprimer(){
   int numeroUnique , i , j ;
    printf("Entrez le nomber d'etudiant s'il vous plait : ");
    scanf("%d",&numeroUnique);

    for(i=0;i<count;i++){
        if(numeroUnique==etudiant[i].Numero){
            for(j=i;j<count-1;j++){
                etudiant[j].Numero = etudiant[j+1].Numero;
                strcpy(etudiant[j].Nom,etudiant[j+1].Nom);
                strcpy(etudiant[j].Prenom,etudiant[j+1].Prenom);
                etudiant[j].date.jour = etudiant[j+1].date.jour;
                etudiant[j].date.mois = etudiant[j+1].date.mois;
                etudiant[j].date.annee = etudiant[j+1].date.annee;
                strcpy(etudiant[j].Departement,etudiant[j+1].Departement);
                etudiant[j].NoteGeneral = etudiant[j+1].NoteGeneral;
            }
            count--;
            printf("supprimer avec succes.\n");
            return;
        }
    }
    printf("ne trouve pas cette numero");
}
// Fonction pour calculer la moyenne par d�partement et dans l'universit�
void CalculerDepartement(){

   char Tdepartement[50][30];
 int i,j;
 int countD = 0;

 int compare = 0 ;

 for(i=0;i<count;i++){
        compare = 1 ;
       for(j=0;j<countD;j++){
    if(strcmp(etudiant[i].Departement,Tdepartement[j]) == 0 ){
        compare = 0;
       break;
        }
    }
   if(compare){
    strcpy(Tdepartement[countD],etudiant[i].Departement);
    countD++;
   }
 }

  for(i=0;i<countD;i++){
     float somme = 0 ;
     float moyenne ;
     int countE = 0;
        for(j=0;j<count;j++){
          if(strcmp(etudiant[j].Departement,Tdepartement[i])==0){
             somme = somme + etudiant[j].NoteGeneral;
             countE++;
          }
        }
            moyenne = somme / countE ;
            printf("La note generale de ce departement - %s est %.2f.\n", Tdepartement[i],moyenne);
  }

}

//Statistique

//le nombre d'�tudiants dans chaque d�partement.
void EtudiantDepartement(){
     int i ,j ;
   char TDepartement[maxEtudiant][30]; //un tableau pour stocker les noms des d�partements trouv�s.
   int copmare ;
    int countD = 0 ;



   for(i=0;i<count;i++){
     copmare=1;
     for( j=0;j<countD;j++){
           if(strcasecmp(etudiant[i].Departement,TDepartement[j])==0) {
           copmare = 0;
           break;
           }
   }
     if(copmare){
        strcpy(TDepartement[countD],etudiant[i].Departement);
        countD++;
     }
    }

      for(i=0;i<countD;i++){
     int countE = 0;
        for(j=0;j<count;j++){
            if(strcasecmp(TDepartement[i],etudiant[j].Departement)==0){
                countE++;
            }
        }
        printf("\n");
        printf("le nombre d'etudiants dans %s est %d\n",TDepartement[i],countE);
      }
}

//les �tudiants ayant une moyenne g�n�rale sup�rieure � un certain seuil.
void  MoyenneSeuil(){
    int i ;
        printf("\n");
        printf("les etudiants ayant une moyenne generale superieure a un certain seuil :\n");
   for(i=0;i<count;i++){
       if(etudiant[i].NoteGeneral >= 10 ){
        printf("----%s ",etudiant[i].Nom);
        printf(" %s :",etudiant[i].Prenom);
        printf(" %.2f\n",etudiant[i].NoteGeneral);
      }
   }
}
//les 3 �tudiants ayant les meilleures notes
void MeilleuresNotes(){

 int swap ,i ,j;
 float TMeilleures[30];

 for (i =0;i<count;i++) {
        TMeilleures[i] = etudiant[i].NoteGeneral;
    }

for(i=0;i<count-1;i++){
    for(j=0;j<count-i-1;j++){
            if(TMeilleures[j]<TMeilleures[j+1]){
        swap = TMeilleures[j];
        TMeilleures[j] = TMeilleures[j+1];
        TMeilleures[j+1] = swap ;
             }
     }
  }

  for(i=0;i<3&&i<count;i++)
    { 
        int compare = 0 ;
        int index = 0 ;

        for(j=0;j<count;j++){
            if (TMeilleures[i] == etudiant[j].NoteGeneral)
            {
                compare = 1 ;
                index = j ;
                break;
            }
        }

      if(compare){
        printf("\n");
        printf("------la note %d: %.2f \n",i+1,etudiant[index].NoteGeneral);
        printf("-Numero: %d\n", etudiant[index].Numero);
        printf("-Nom: %s\n", etudiant[index].Nom);
        printf("-Prenom: %s\n", etudiant[index].Prenom);
        printf("-Date de Naissance: %d/%d/%d\n",etudiant[index].date.jour,etudiant[index].date.jour,etudiant[index].date.jour);
        printf("-Departement: %s\n", etudiant[index].Departement);
     }


}
}
//nombre d'�tudiants ayant r�ussi dans chaque d�partement
void EtudiantReussiDepartement(){
       int i ,j ;
   char TDepartement[maxEtudiant][30]; //un tableau pour stocker les noms des d�partements trouv�s.
   int copmare ;
    int countD = 0 ;

   for(i=0;i<count;i++){
     copmare=1;
     for( j=0;j<countD;j++){
           if(strcasecmp(etudiant[i].Departement,TDepartement[j])==0) {
           copmare = 0;
           break;
           }
   }
     if(copmare){
        strcpy(TDepartement[countD],etudiant[i].Departement);
        countD++;
     }
    }

  for(i=0;i<countD;i++){
     int countE = 0;

        for(j=0;j<count;j++){
            if(etudiant[j].NoteGeneral>=10 && strcasecmp(etudiant[j].Departement,TDepartement[i])==0){
                countE++;
            }
        }
        printf("\n");
        printf("le nombre d'etudiants ayant reussi dans  departement %s est %d\n",TDepartement[i],countE);
      }

}

//Rechercher
void Rechercher(){

    int i ;
    char nomRecherche[30];

   printf("***saisir le nom que vous voulez Rechercher");
   scanf("%s",nomRecherche);

   i=0;
   while(i<count){
    if(strcasecmp(etudiant[i].Nom,nomRecherche)==0){
      printf("\n");
      printf("------le numero unique est %d .\n",etudiant[i].Numero);
      printf("------le nom de  est %s.\n",etudiant[i].Nom);
      printf("------le prenome est %s \n",etudiant[i].Prenom);
      printf("------Date de Naissance: %d/%d/%d\n",etudiant[i].date.jour,etudiant[i].date.jour,etudiant[i].date.jour);
      printf("------Departement: %s\n", etudiant[i].Departement);
      printf("------la note general : %.2f ",etudiant[i].NoteGeneral);

    }
    i++;
   }

}

//la liste des �tudiants inscrits dans un d�partement sp�cifique
void ListDepartement(){
    int i ;
       char departementRechercher[30] ;
    printf("saisir le departement que vous voulez Rechercher : ");
    scanf("%s",departementRechercher);
    printf("-----les etudiants de departement %s :\n", departementRechercher);
    for(i=0;i<count;i++){
        if(strcasecmp(etudiant[i].Departement , departementRechercher )==0){
            printf("\n");
            printf("----%s %s %d \n",etudiant[i].Nom,etudiant[i].Prenom,etudiant[i].Numero);
        }
    }

}

void TrierAlphabetiqueAZ() {
    int i, j;

    char swap[30];
    // Tri � bulles pour trier les noms dans l'ordre croissant (A � Z)
    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcasecmp(etudiant[j].Nom, etudiant[j+1].Nom) > 0) {
                // Si l'�tudiant[j] est plus grand que l'�tudiant[j+1], on �change leurs places
              strcpy(swap,etudiant[j].Nom);
                strcpy( etudiant[j].Nom, etudiant[j + 1].Nom);
                strcpy( etudiant[j + 1].Nom, swap);


            }
        }
    }


    // Affichage des etudiants tri�s
    printf("\nListe des etudiants triee de A a Z:\n");
    for(i=0;i<count;i++) {
        printf("Nom: %s, Prenom: %s\n", etudiant[i].Nom,etudiant[i].Prenom);
    }
}


void TrierAlphabetiqueZA() {
    int i, j;

    char swap[30];

    for (i = 0; i < count - 1; i++) {
        for (j = 0; j < count - i - 1; j++) {
            if (strcasecmp(etudiant[j].Nom, etudiant[j+1].Nom) < 0) {

              strcpy(swap,etudiant[j].Nom);
                strcpy( etudiant[j].Nom, etudiant[j + 1].Nom);
                strcpy( etudiant[j + 1].Nom, swap);

            }
        }
    }




    printf("\n");
    printf("\nListe des etudiants triee de Z a A:\n");
    for(i=0;i<count;i++) {
        printf("Nom: %s, Prenom: %s\n", etudiant[i].Nom,etudiant[i].Prenom);
    }
}
//Tri des étudiants par moyenne générale, du plus élevé au plus faible ou inversement
void TriEtudiantsMoyennePlusFaible(){
    int i , j ;
    float TNote[maxEtudiant];
    float swap;

      for (i =0;i<count;i++) {
        TNote[i] = etudiant[i].NoteGeneral;
    }
    
    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
            if(TNote[j] < TNote[j+1]){
                swap=TNote[j];
                TNote[j]=TNote[j+1];
                TNote[j+1]=swap;
            }      
        }
     }
     printf("\n");
      printf("la moyenne generale des etudiants , du plus eleve au plus faible \n");
     for(i=0;i<count;i++){
        int nmb = 0;
        int index = 0;
        for(j=0;j<count;j++){
            if(TNote[i]==etudiant[j].NoteGeneral){
                nmb = 1 ;
                index = j ; 
                break;
            }
        }
        if(nmb){
           
        printf("- | %d ", etudiant[index].Numero);
        printf(" %s", etudiant[index].Nom);
        printf(": %s", etudiant[index].Prenom);
        printf("  %.2f \n",etudiant[index].NoteGeneral);
        
        }

       }
 }
     
  


void TriEtudiantsMoyenneFaiblePlus(){
   int i , j ;
    float TNote[maxEtudiant];
    float swap;

      for (i =0;i<count;i++) {
        TNote[i] = etudiant[i].NoteGeneral;
    }
    
    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
            if(TNote[j] > TNote[j+1]){
                swap=TNote[j];
                TNote[j]=TNote[j+1];
                TNote[j+1]=swap;
            }      
        }
     }
     printf("\n");
     printf("la moyenne generale des etdiants, du plus faible au plus eleve \n");
     for(i=0;i<count;i++){
        int nmb = 0;
        int index = 0;
        for(j=0;j<count;j++){
            if(TNote[i]==etudiant[j].NoteGeneral){
                nmb = 1 ;
                index = j ; 
                break;
            }
        }
        if(nmb){
        printf("- | %d ", etudiant[index].Numero);
        printf(" %s", etudiant[index].Nom);
        printf(": %s", etudiant[index].Prenom);
        printf("%.2f \n",etudiant[index].NoteGeneral);
        
        }

       }

}

// Tri des étudiants selon leur statut de réussite .

void TriEtudiantSelonResussite(){
    int i,j;
    float swap ;

    for(i=0;i<count-1;i++){
        for(j=0;j<count-i-1;j++){
           if(etudiant[j].NoteGeneral < etudiant[j+1].NoteGeneral){
            swap = etudiant[j].NoteGeneral;
            etudiant[j].NoteGeneral= etudiant[j+1].NoteGeneral;
            etudiant[j+1].NoteGeneral = swap;
           }
        }
    }
    printf("Classement des etudiants selon leur statut de russite.\n");
    for(i=0;i<count;i++){
        if(etudiant[i].NoteGeneral>=10){
           printf("- %d | ",etudiant[i].Numero);
           printf(" %s %s : ",etudiant[i].Nom,etudiant[i].Prenom);
           printf(" %.2f .\n",etudiant[i].NoteGeneral);
        }
    }


}

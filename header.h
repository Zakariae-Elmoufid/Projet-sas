#ifndef header_h
#define header_h

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
int count ;
int repeat ;

void Ajouter();
void Modifier();
void Supprimer();
void Afficher();
void CalculerDepartement();
void EtudiantDepartement();
void MoyenneSeuil();
void MeilleuresNotes();
void EtudiantReussiDepartement();
void Rechercher();
void ListDepartement();
void TrierAlphabetiqueAZ();
void TrierAlphabetiqueZA();


#endif

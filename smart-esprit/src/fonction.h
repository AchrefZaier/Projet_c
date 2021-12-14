#include <gtk/gtk.h>
typedef struct
{
int jour;
int mois;
int annee;
}Dateee;

typedef struct

{
char chambre[30];
char identifiant[30];
char etage[30];
char sexe[30];
char nom[30];
Dateee datenada;
}etudiant;

void ajoutnada(etudiant c);
void recherchenada(GtkWidget* treeview11);
void suppressionnada(char id[30], etudiant c);
void affichagenada(GtkWidget* treeview11);
void modificationnada(char id[30],etudiant c);
void affichagestatnada(GtkWidget* treeview12);

typedef struct 
{
char jour[20];    
char heure[20];  
char etage[20];
char valeur[20];
}debit;



#include <gtk/gtk.h>

#define FONCTIONZA_H_INCLUDED
typedef struct
{
int jour;
int mois;
int annee;
}Datee;

typedef struct

{
char type[30];
char identifiant[30];
char marque[30];
char quantite[30];
Datee date;
}STOCK;

void ajout(STOCK c);
void recherche(GtkWidget* treeview11);
void suppression(char id[30], STOCK c);
void affichage(GtkWidget* treeview11);
void modification(char id[30],STOCK c);
void affichagestat(GtkWidget* treeview12);
int verifid(char id[30]);
int veriff(char x[]);

typedef struct
{
char First_Name[50];
char Last_Name[50];
char Username[50];
char Password[50];
int Role;
}user ;

/*partie1*/
void add_user(user u);
int find_user(char username[]);
void delete_user(char username[]);
void update_user(user u,char username[]);
void display_user_info(GtkWidget *liste);
int verif(char log[], char Pw[]);
/*partie 2*/
int student_number(int specialite);
void empty(GtkWidget *liste);
 // FONCTION_H_INCLUDED 




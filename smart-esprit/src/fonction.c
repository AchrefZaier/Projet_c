#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "fonction.h"
enum{CHAMBRE2,IDENTIFIANT2,ETAGE2,DATE2,NOM2,SEXE2,COLUMNS2};


void affichagenada(GtkWidget* treeview11)

{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
etudiant c;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview11);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("NOM", renderer, "text",NOM2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("CHAMBRE", renderer, "text",CHAMBRE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("IDENTIFIANT", renderer, "text",IDENTIFIANT2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("ETAGE", renderer, "text",ETAGE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("SEXE", renderer, "text",SEXE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date", renderer, "text",DATE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("etudiant.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("etudiant.bin","ab+");
while(fread(&c,sizeof(etudiant),1,f))
{sprintf(Date,"%d/%d/%d",c.datenada.jour,c.datenada.mois,c.datenada.annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,NOM2,c.nom,IDENTIFIANT2,c.identifiant,SEXE2,c.sexe,CHAMBRE2,c.chambre,ETAGE2,c.etage,DATE2,Date,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview11),GTK_TREE_MODEL (store));
g_object_unref(store);}}




void ajoutnada (etudiant c){
FILE*f=NULL; 
f=fopen("etudiant.bin","ab+");
fwrite(&c,sizeof(etudiant),1,f);  
fclose(f);
 
}


void suppressionnada(char id[30],etudiant c){
FILE*f;
FILE*g;
f=fopen("etudiant.bin","rb+");
g=fopen("tmp.bin","wb+");
if(g!=NULL){
while(fread(&c,sizeof(etudiant),1,f))
{
if (strcmp(c.identifiant,id)!=0){
fwrite(&c,sizeof(etudiant),1,g);

}
}
}fclose(f);
fclose(g);
remove("etudiant.bin");
rename("tmp.bin","etudiant.bin");
}



void modificationnada(char id[30],etudiant c)
{

	suppressionnada(id,c);
	ajoutnada(c);

}

void recherchenada(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;etudiant c;
 FILE *f2;char Date[100]; 
 store=gtk_tree_view_get_model(treeview11);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("CHAMBRE",renderer, "text",CHAMBRE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
 
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("CIN",renderer, "text",IDENTIFIANT2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("ETAGE",renderer, "text",ETAGE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Date",renderer, "text",DATE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("SEXE",renderer, "text",SEXE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("NOM",renderer, "text",NOM2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);}
  
store=gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&c,sizeof(etudiant),1,f2))
     {sprintf(Date,"%d/%d/%d",c.datenada.jour,c.datenada.mois,c.datenada.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,CHAMBRE2,c.chambre,IDENTIFIANT2,c.identifiant,ETAGE2,c.etage,DATE2,Date,NOM2,c.nom,SEXE2,c.sexe -1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview11), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
enum{JOUR,HEURE,ETAGE,VAL,COLUMNSSS};


void affichagestatnada(GtkWidget* liste)
{

GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store; 
  
debit ff;
char jour[20];    
char heure[20];  
char etage[20];
char valeur[20];	


  FILE *f;
	
  store=gtk_tree_view_get_model(liste);

  if (store==NULL)
  {


    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",JOUR,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("heure",renderer,"text",HEURE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("etage",renderer,"text",ETAGE,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


    renderer = gtk_cell_renderer_text_new();
		column = gtk_tree_view_column_new_with_attributes("valeur",renderer,"text",VAL,NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

   store=gtk_list_store_new(COLUMNSSS,G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

 

  f = fopen("debit.txt","r");

    if (f==NULL)
    
      {return;}
    
    else{
      
      while ((fscanf(f," %s\t %s\t %s\t %s \n",&jour,&heure,&etage,&valeur)!=EOF)){
if(atof(valeur)<5){
       gtk_list_store_append(store, &iter);
				gtk_list_store_set(store,&iter,JOUR,jour,HEURE,heure,ETAGE,etage,VAL,valeur, -1);
}

      }
      fclose(f);
	


      gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store));
		  g_object_unref(store);



}
}
}



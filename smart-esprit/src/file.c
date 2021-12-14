#include <stdlib.h>
#include <stdio.h>
#include<string.h>

#include "file.h"
enum{TYPE2,IDENTIFIANT2,MARQUE,DATE2,QUANTITE2,COLUMNS2};
enum{TYPEC,IDENTIFIANTC,MARQUEC,QUANTITEC,COLUMNSC};

void affichage(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
STOCK c;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview11);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANT2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",MARQUE, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Date d'éxpiration", renderer, "text",DATE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Quantité", renderer, "text",QUANTITE2, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview11), column);}

store=gtk_list_store_new(COLUMNS2,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("stock.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("stock.bin","ab+");
while(fread(&c,sizeof(STOCK),1,f))
{sprintf(Date,"%d/%d/%d",c.date.jour,c.date.mois,c.date.annee);
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPE2,c.type,IDENTIFIANT2,c.identifiant,MARQUE,c.marque,DATE2,Date,QUANTITE2,c.quantite,-1);
}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview11),GTK_TREE_MODEL (store));
g_object_unref(store);}}



void ajout (STOCK c){
FILE*f=NULL; 
f=fopen("stock.bin","ab+");
fwrite(&c,sizeof(STOCK),1,f);  
fclose(f);
 
}


void suppression(char id[30],STOCK c){
FILE*f;
FILE*g;
f=fopen("stock.bin","rb+");
g=fopen("tmp.bin","wb+");
if(g!=NULL){
while(fread(&c,sizeof(STOCK),1,f))
{
if (strcmp(c.identifiant,id)!=0){
fwrite(&c,sizeof(STOCK),1,g);

}
}
}fclose(f);
fclose(g);
remove("stock.bin");
rename("tmp.bin","stock.bin");
}



void modification(char id[30],STOCK c)
{

	suppression(id,c);
	ajout(c);

}

void recherche(GtkWidget* treeview11)
{
GtkCellRenderer *renderer;
 GtkTreeViewColumn *column;
 GtkTreeIter iter;
 GtkListStore *store;

store=NULL;STOCK c;
 FILE *f2;char Date[100]; 
 store=gtk_tree_view_get_model(treeview11);
 if (store==NULL)
{

   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Type",renderer, "text",TYPE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
 
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Identifiant",renderer, "text",IDENTIFIANT2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
  
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Marque",renderer, "text",MARQUE,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Date d'éxpiration",renderer, "text",DATE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);
   
   renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Quantité",renderer, "text",QUANTITE2,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview11), column);}
  
store=gtk_list_store_new(COLUMNS2, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
f2=fopen("recherche.bin", "rb");
if(f2==NULL)
{
 return;
}
else 
{ f2=fopen("recherche.bin", "ab+");
    while(fread(&c,sizeof(STOCK),1,f2))
     {sprintf(Date,"%d/%d/%d",c.date.jour,c.date.mois,c.date.annee);
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,TYPE2,c.type,IDENTIFIANT2,c.identifiant,MARQUE,c.marque,DATE2,Date,QUANTITE2,c.quantite, -1);
}
fclose(f2);
gtk_tree_view_set_model (GTK_TREE_VIEW (treeview11), GTK_TREE_MODEL (store));
g_object_unref (store);
}
}
int verifid(char id[30])
{
   STOCK c;
   int res = 1;
   FILE *f;
   f = fopen("stock.bin", "ab+");
   if (f != NULL)
   {
      while (fread(&c,sizeof(STOCK),1,f))
      {
         if (strcmp(id,c.identifiant) == 0)
         {
            res = 0;
         }
         else
         {
            res = 1;
         }
      }
   }
   fclose(f);
   return res;
}
int veriff(char x[])
{
   int i=0;
   if (strcmp(x, "")==0)
   {
      i=0;
   }
   else
   {
      i=1;
   }
   return i;
}



void affichagestat(GtkWidget* treeview12)
{

GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeIter iter;
GtkListStore *store;
STOCK c;char Date[100];
store=NULL;
FILE *f;
store=gtk_tree_view_get_model(treeview12);
if (store==NULL)
{
renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Type", renderer, "text",TYPEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);


renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text",IDENTIFIANTC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer = gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("Marque", renderer, "text",MARQUEC, NULL);
gtk_tree_view_append_column (GTK_TREE_VIEW (treeview12), column);

renderer=gtk_cell_renderer_text_new();
   column= gtk_tree_view_column_new_with_attributes("Quantité",renderer, "text",QUANTITEC,NULL);
   gtk_tree_view_append_column(GTK_TREE_VIEW(treeview12), column);}

store=gtk_list_store_new(COLUMNSC,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
f=fopen("stock.bin","rb");
if(f==NULL)
{return;}
else
{f=fopen("stock.bin","ab+");
while(fread(&c,sizeof(STOCK),1,f))
{
if( ((strcmp(c.type,"produit1")==0)&& (atoi(c.quantite)==0))||((strcmp(c.type,"produit2")==0)&& (atoi(c.quantite)==0)) ||((strcmp(c.type,"produit3")==0)&& (atoi(c.quantite)==0)) )
{
gtk_list_store_append(store,&iter);
gtk_list_store_set(store,&iter,TYPEC,c.type,IDENTIFIANTC,c.identifiant,MARQUEC,c.marque,QUANTITEC,c.quantite,-1);
}}
fclose(f);
gtk_tree_view_set_model(GTK_TREE_VIEW(treeview12),GTK_TREE_MODEL (store));
g_object_unref(store);}}


/********************************************************************************************************************************/

#include "fonctionZA.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <gtk/gtk.h>


enum 
{
	EFirst_Name ,
	ELast_Name ,	
	EUsername ,	
	EPassword ,
	ERole ,
	COLUMNS
};

/****************************add user function*********************/

void add_user(user u)
{
FILE *f=NULL;
f=fopen("utlisateur.txt","a+");
if (f!=NULL)
{
fprintf(f,"%s %s %s %s %d \n",u.First_Name,u.Last_Name,u.Username,u.Password,u.Role);
fclose(f);
}
else
	printf("ERROR");
}


/********************************* find user function*********************/

int find_user(char username[])
{
FILE *f=NULL;
int trouve=0;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;

f=fopen("utlisateur.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
if(strcmp(ch3,username)==0)
{
trouve=1;
break;
}
}
fclose(f);
}
return trouve;
}

/******************delete user function**********************/

void delete_user(char username[])
{
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;
int c=0;
FILE *f=NULL;
FILE *temp=NULL;
f=fopen("utlisateur.txt","r");
if(f!=NULL)
{
temp=fopen("temp.txt","a");
if(temp!=NULL)
{
while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
fprintf(temp,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,ch5);
}
fclose(temp);
}
fclose(f);
}
temp=fopen("temp.txt","r");
if(temp!=NULL)
{
f=fopen("utlisateur.txt","w");
if(f!=NULL)
{
while(fscanf(temp,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
if(strcmp(username,ch3)!=0)
{
c=1;
fprintf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,ch5);
}
}
fclose(f);
}
fclose(temp);
}
remove("temp.txt");
if(c==1)
printf("User : %s Succesfully Deleted",username);
else
printf("User %s Not Found",username);

}

/****************verif function******************/

int verif(char log[], char Pw[])
{
int trouve=0;
FILE* f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;
f=fopen("utlisateur.txt","r");
if (f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
if((strcmp(ch3,log)==0) && (strcmp(ch4,Pw)==0))
{
trouve=1;
break;
}
}
fclose(f);
}
return trouve;
}

/*********************update function*********************/

void update_user(user u,char username[])
{
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;

FILE *f=NULL;
FILE *temp=NULL;
f=fopen("utlisateur.txt","r");
if(f!=NULL)
{
temp=fopen("temp.txt","a");
if(temp!=NULL)
{
while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
if(strcmp(ch3,username)==0)
{
strcpy(ch1,u.First_Name);
strcpy(ch2,u.Last_Name);
strcpy(ch3,u.Username);
strcpy(ch4,u.Password);
ch5=u.Role;
fprintf(temp,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,ch5);
}
else 
{
fprintf(temp,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,ch5);
}
}
fclose(temp);
}
fclose(f);
}
temp=fopen("temp.txt","r");
if(temp!=NULL)
{
f=fopen("utlisateur.txt","w");
if(f!=NULL)
{
while(fscanf(temp,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{

fprintf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,ch5);

}
fclose(f);
}
fclose(temp);
}
remove("temp.txt");
}
/*FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;
int c=0;
f=fopen("utlisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
if(strcmp(ch3,username)==0)
{
c=1;
strcpy(ch1,u.First_Name);
strcpy(ch2,u.Last_Name);
strcpy(ch3,u.Username);
strcpy(ch4,u.Password);
ch5=u.Role;
fprintf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,ch5);
break;
}
else 
c=0;
}
fclose(f);
}
if(c==1)
{
printf("User : %s Successfully updated \n",username);

}
else
printf("User : %s Not Found \n ",username);

}*/

/*********************display Function*****************/
void display_user_info(GtkWidget *liste)
{
GtkCellRenderer *renderer ;
GtkTreeViewColumn *column ;
GtkTreeIter iter ;
GtkListStore *store;

FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;



store=gtk_tree_view_get_model(liste);
if(store==NULL)
{	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("First_Name" , renderer , "text" , EFirst_Name , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Last_Name" , renderer , "text" , ELast_Name , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Username" , renderer , "text" , EUsername , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Password" , renderer , "text" , EPassword , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

	renderer = gtk_cell_renderer_text_new() ;
	column = gtk_tree_view_column_new_with_attributes("Role" , renderer , "text" , ERole , NULL) ;
	gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );
}
store=gtk_list_store_new(COLUMNS ,G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING , G_TYPE_STRING, G_TYPE_INT);

f = fopen("utlisateur.txt" , "r");
if(f==NULL)
{
	return ; 
}
else 
{

f=fopen("utlisateur.txt" , "a+");
	while(fscanf(f,"%s %s %s %s %d \n" , ch1 , ch2 ,ch3 ,ch4,&ch5)!=EOF)
	{	gtk_list_store_append(store, &iter);
		gtk_list_store_set (store , &iter ,EFirst_Name,ch1,ELast_Name,ch2,EUsername,ch3,EPassword,ch4,ERole,ch5,-1);
	}
	fclose(f) ;
gtk_tree_view_set_model(GTK_TREE_VIEW(liste) , GTK_TREE_MODEL (store));
g_object_unref(store);
}

}

/*	
f=fopen("utlisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %s \n",ch1,ch2,ch3,ch4,ch5)!=EOF)
{
if(strcmp(ch3,EUsername)==0)
{
printf(" First Name : %s \n Last Name : %s \n Username : %s \n Password : %s \n Role : %s \n",ch1,ch2,ch3,ch4,ch5);
break;
}
}
fclose(f);
}*/



/************************ student num function***************/

int student_number(int specialite)
{
FILE *f=NULL;
char ch1[20];
char ch2[20];
char ch3[20];
char ch4[20];
int ch5;
int res=0;
f=fopen("utlisateur.txt","r");
if(f!=NULL)
{
while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
{
if(ch5==specialite)
	res=res+1;
}

fclose(f);

}
return res;
}

/****************EMPTY THE TREE VIEW************
void empty(GtkWidget *liste ) 
	GtkCellRenderer *renderer ;
	GtkTreeViewColumn *column ;
	GtkTreeIter iter ;
	GtkListStore *store;
	
	
	FILE *f;
	char First_Name[20];
	char Last_Name[20];
	char Username[30];
	char Password[30];
	int role ;
	
	
	store=gtk_tree_view_get_model(liste);	

	if (store==NULL)
	{
		
		renderer = gtk_cell_renderer_text_new() ;
		column = gtk_tree_view_column_new_with_attributes("First_Name" , renderer , "text" , EFirst_Name , NULL) ;
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

		renderer = gtk_cell_renderer_text_new() ;
		column = gtk_tree_view_column_new_with_attributes("Last_Name" , renderer , "text" , ELast_Name , NULL) ;
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

		renderer = gtk_cell_renderer_text_new() ;
		column = gtk_tree_view_column_new_with_attributes("Username" , renderer , "text" , EUsername , NULL) ;
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

		renderer = gtk_cell_renderer_text_new() ;
		column = gtk_tree_view_column_new_with_attributes("Password" , renderer , "text" , EPassword , NULL) ;
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

		renderer = gtk_cell_renderer_text_new() ;
		column = gtk_tree_view_column_new_with_attributes("Role" , renderer , "text" , ERole , NULL) ;
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste) , column );

	}

	store=gtk_list_store_new(column,G_TYPE_STRING ,G_TYPE_STRING,G_TYPE_STRING ,G_TYPE_STRING , G_TYPE_STRING);
	gtk_list_store_append(store,&iter);
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste),GTK_TREE_MODEL(store)):

}*/







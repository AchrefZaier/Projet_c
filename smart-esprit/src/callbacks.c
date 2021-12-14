#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <string.h>
#include <stdio.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "menu.h"
#include "file.h"
#include "fonction.h"
#include "fonctionZA.h"


int x = 1;
char id[30],idrech[30];
int l=0,j=0,m=1;
GtkWidget *windowgestion;
int a,b;

/* -------------------- NAVIGATION ----------------- */ 

void
on_toafficherFarah_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_liste_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_ToajoutFarah_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_ajout_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_tomodfiFarah_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_modifier_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_toSupprimerFarah_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_supprimer_menu ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}
void
on_supprimer_farah_clicked             (GtkWidget       *objet,
                                        gpointer         user_data)
{
		char id[20],message[200];
		int ident;
		GtkWidget *input,*output; 
		input = lookup_widget(objet,"id_supp_farah");
		strcpy(id,gtk_entry_get_text(GTK_ENTRY(input)));
		ident = atoi(id);
		
		output = lookup_widget(objet,"outputDel");
		sprintf(message,"Votre suppression a été effectué avec succés ! ");
		gtk_label_set_text(GTK_LABEL(output),message);
		
		supprimer(ident);
			
}

void
on_meuilleurMenuFarah_clicked          (GtkWidget       *objet,
                                        gpointer         user_data)
{

		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"accueil");
		window2 = create_meilleur_menu();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);

		
}

/* ------------------------------------------------------------- */ 

void
on_retour_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"ajout_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

void
on_Retour_list_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"liste_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

void
on_retourModif_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"modifier_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}

void
on_retour_supp_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"supprimer_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


 
void
on_ajout_farah_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *aj1, *aj2, *aj3, *a, *b, *c,*d,*month,*y,*output;
	
	char message[200];

	char id[20];
	menu m,p;
	aj1=lookup_widget(objet,"id_farah");
	aj2=lookup_widget(objet,"nomMenuFarah");
	aj3=lookup_widget(objet,"dechetFarah");

	d = lookup_widget(objet,"spinJ");
	month = lookup_widget(objet,"spinM");
	y = lookup_widget(objet,"spinA");

	output = lookup_widget(objet,"outputAdd");


	strcpy(id,gtk_entry_get_text(GTK_ENTRY(aj1)));
	m.id = atoi(id);
	strcpy(m.nom,gtk_entry_get_text(GTK_ENTRY(aj2)));
	m.dechet=atof(gtk_entry_get_text(GTK_ENTRY(aj3)));


	m.d.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(d));
	m.d.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(month));
	m.d.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(y));


	if(x==1){
		strcpy(m.type,"petit_dejeuner");	
	}
	else if(x == 2){
		strcpy(m.type,"dejeuner");
	}
	else{
		strcpy(m.type,"diner");
	}

	sprintf(message,"Votre ajout a été effectué avec succés ! ");
	gtk_label_set_text(GTK_LABEL(output),message);
	ajouter(m);
	
	
}

void
on_radio_p_dej_toggled                 (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
			x=1;
		}
}


void
on_radio_dej_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=2;
	}
}


void
on_radio_d_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton)){
		x=3;
	}
}


void
on_valider_farah_clicked               (GtkWidget       *objet,
                                        gpointer         user_data)
{

	GtkWidget *mod1, *mod2, *mod3, *mod4,*output;
	menu p;
	
	char id[20],message[200];
	FILE *f;
	int a = 0,ident;
	mod1=lookup_widget(objet,"id_mod_farah");
	mod2=lookup_widget(objet,"dechet_mod_farah");
	mod3=lookup_widget(objet,"nom_mod_farah");
	mod4=lookup_widget(objet,"comboboxtype_farah");
	
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
	ident = atoi(id);


	f = fopen("menu.txt","r");
	if(f!=NULL){

	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
		{
			if(p.id == ident){
				a=1;
				break;
		         }
		}
	fclose(f);
	}
	
	
	p.dechet = atof(gtk_entry_get_text(GTK_ENTRY(mod2)));

	strcpy(p.nom,gtk_entry_get_text(GTK_ENTRY(mod3)));
	strcpy(p.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(mod4)));
	
	output = lookup_widget(objet,"outputEdit");
	sprintf(message,"Votre modification a été effectué avec succés !");
	gtk_label_set_text(GTK_LABEL(output),message);
	modifier(p);

}


void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *mod1, *mod2, *mod3,*mod4;
	menu p;
	int a=0;
	char ch[20], id[50],nom[50];
	char dechet[50];
	FILE *f;
	int ident ; 
	mod1=lookup_widget(objet,"id_mod_farah");
	mod2=lookup_widget(objet,"dechet_mod_farah");
	mod3=lookup_widget(objet,"nom_mod_farah");
	mod4=lookup_widget(objet,"comboboxtype_farah");
	strcpy(id,gtk_entry_get_text(GTK_ENTRY(mod1)));
	ident = atoi(id);
	
	f = fopen("menu.txt","r");
	if(f!=NULL){

	while(fscanf(f,"%d %s %s %f %d %d %d\n",&(p.id),p.type,p.nom,&(p.dechet),&(p.d.j),&(p.d.m),&(p.d.a))!=EOF)
		{
			if(p.id == ident){
				a=1;
				break;
		         }
		}
	fclose(f);
	}
	if(a==1){
		
		sprintf(ch,"%f",p.dechet);		
		gtk_entry_set_text(GTK_ENTRY(mod2),ch);
		

		sprintf(nom,"%s",p.nom);
		gtk_entry_set_text(GTK_ENTRY(mod3),nom);

		if(strcmp(p.type,"petit_dejeuner") == 0){
			gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),0);
		}
		else if(strcmp(p.type,"dejeuner") == 0){
			gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),1);
		}
		else{
			gtk_combo_box_set_active(GTK_COMBO_BOX(mod4),2);
		}
		
	}
	
}


void
on_affichage_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1,*treeview;
	
	window1 = lookup_widget(objet,"liste_menu");
	
	treeview = lookup_widget(window1,"treeviewFarah");
		
	afficher(treeview);
}

void
on_retourMeui_farah_clicked            (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *window1,*window2;
		window1 = lookup_widget(objet,"meilleur_menu");
		window2 = create_accueil ();
	  	gtk_widget_show (window2);
		gtk_widget_destroy(window1);
}


void
on_trouverM_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data)
{
		GtkWidget *id_l,*nom_l,*jd,*md,*ad,*ja,*ma,*aa ; 
		date d1,d2;

	
		jd = lookup_widget(objet,"JD");
		md = lookup_widget(objet,"MD");
		ad = lookup_widget(objet,"AD");

		d1.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jd));
		d1.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(md));
		d1.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ad));


		ja = lookup_widget(objet,"JA");
		ma = lookup_widget(objet,"MA");
		aa = lookup_widget(objet,"AA");

		d2.j = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ja));
		d2.m = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(ma));
		d2.a = gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(aa));

		id_l = lookup_widget(objet,"id_menu");
		nom_l = lookup_widget(objet,"nom_Mmenu");

	
		


		char sid[20],snom[20];
		sprintf(sid,"%d",meuilleur_menu(d1,d2).id);
		gtk_label_set_text(GTK_LABEL(id_l),sid);	


		sprintf(snom,"%s",meuilleur_menu(d1,d2).nom);
		gtk_label_set_text(GTK_LABEL(nom_l),snom);
}
/* _________________________________________________________________________________ */




void
on_buttonrechercher_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;
GtkWidget *entryid;
GtkWidget *treeview11;
FILE*f;
FILE*f2;


windowgestion=lookup_widget(button,"windowgestion");
entryid=lookup_widget(button,"entryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entryid)));
f=fopen("stock.bin","rb");

 if(f!=NULL)
 {
  while(fread(&c,sizeof(STOCK),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(c.identifiant,idrech)==0))||((strcmp(c.type,idrech)==0))||((strcmp(c.marque,idrech)==0)))
     { 
     fwrite(&c,sizeof(STOCK),1,f2);
     }
   
     treeview11=lookup_widget(windowgestion,"treeview11");
     recherche(treeview11);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}


void
on_buttonactualiser_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *treeview11;
	windowgestion=lookup_widget(button,"windowgestion");
	treeview11=lookup_widget(windowgestion,"treeview11");
	affichage(treeview11);
}


void
on_buttonsupprimer_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
		STOCK c;
	    GtkWidget *treeview11;
	    windowgestion=lookup_widget(button,"windowgestion");
	    treeview11=lookup_widget(windowgestion,"treeview11");
	    suppression(id,c);
            affichage(treeview11);
}


void
on_buttonajouter_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
}



void
on_buttonboard_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
}

void
on_radiobutton10_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
m=2;}
}


void
on_radiobutton20_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
m=1;}
}




void
on_buttonajout_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	char Type[30];char Marque[30];char x[30];
STOCK c;
GtkWidget *entryajoutidentifiant;
GtkWidget *comboboxajoutmarque;
GtkWidget *entryajoutquantite;
GtkWidget *spinbuttonajoutjour;
GtkWidget *spinbuttonajoutmois;
GtkWidget *spinbuttonajoutannee;
GtkWidget *comboboxajouttype;
GtkWidget *sortiea;
GtkWidget *radiobutton10;
GtkWidget *radiobutton20;

spinbuttonajoutjour=lookup_widget(button, "spinbuttonajoutjour");
spinbuttonajoutmois=lookup_widget(button, "spinbuttonajoutmois");
spinbuttonajoutannee=lookup_widget(button, "spinbuttonajoutannee");
comboboxajouttype=lookup_widget(button, "comboboxajouttype");
radiobutton10=lookup_widget(button, "radiobutton10");
radiobutton20=lookup_widget(button, "radiobutton20");
entryajoutidentifiant=lookup_widget(button,"entryajoutidentifiant");
comboboxajoutmarque=lookup_widget(button,"comboboxajoutmarque");
entryajoutquantite=lookup_widget(button,"entryajoutquantite");
sortiea=lookup_widget(button, "labelajoutreus");

strcpy(x,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
if (veriff(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"ajoutez un identifiant svp!");}
else if (veriff(x)==1){
	if(verifid(x)==0){gtk_label_set_text(GTK_LABEL(sortiea),"identifiant existe déja !");}

else if((verifid(x)==1)&&(l==1)){


strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(entryajoutquantite)));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutannee));
if (m==1)
{strcpy(Marque,"marque2");}
else if (m==2)
{strcpy(Marque,"marque1");}

strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajouttype)));
//strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutmarque)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);
ajout(c);
gtk_label_set_text(GTK_LABEL(sortiea),"ajout effectué avec succés");
}}
}

void
on_checkbuttonEM_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
l=1;}
}


void
on_checkbutton1EM_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
j=1;}
}


void
on_buttonaffichboard_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;

GtkWidget *treeview12;


treeview12=lookup_widget(windowgestion,"treeview12");
affichagestat(treeview12);
}


void
on_buttonmodifier_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
}


void
on_buttonmodif_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
STOCK c;char Type[30];char Marque[30];char x[30];
GtkWidget *comboboxmodiftype;
//GtkWidget *entrymodifidentifiant;
GtkWidget *comboboxmodifmarque;
GtkWidget *spinbuttonmodifjour;
GtkWidget *spinbuttonmodifmois;
GtkWidget *spinbuttonmodifannee;
GtkWidget *entrymodifquantite;
GtkWidget *sortiem;    
	
spinbuttonmodifjour=lookup_widget(button, "spinbuttonmodifjour");
spinbuttonmodifmois=lookup_widget(button, "spinbuttonmodifmois");
spinbuttonmodifannee=lookup_widget(button, "spinbuttonmodifannee");
comboboxmodiftype=lookup_widget(button, "comboboxmodiftype");
//entrymodifidentifiant=lookup_widget(button,"entrymodifidentifiant");
comboboxmodifmarque=lookup_widget(button,"comboboxmodifmarque");
entrymodifquantite=lookup_widget(button,"entrymodifquantite");
sortiem=lookup_widget(button, "labelmodifreus");
if (j==1){
strcpy(c.identifiant,id);
strcpy(c.quantite,gtk_entry_get_text(GTK_ENTRY(entrymodifquantite)));
c.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjour));
c.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmois));
c.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifannee));
strcpy(Type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodiftype)));
strcpy(Marque,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifmarque)));
strcpy(c.type,Type);
strcpy(c.marque,Marque);

modification(id,c);
gtk_label_set_text(GTK_LABEL(sortiem),"Modification effectué avec succés");
}
}


void
on_treeview11nada_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
	gchar* identifiant;
	GtkTreeModel *Model = gtk_tree_view_get_model(treeview);

		if (gtk_tree_model_get_iter(Model, &iter, path)){
				gtk_tree_model_get(GTK_LIST_STORE(Model),&iter,1,&identifiant, -1);
				strcpy(id,identifiant);}
}






void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{char chambre[30];
char etage[30];
char id[9];
char sexe[30];
etudiant c;
GtkWidget *entryajoutidentifiant;
GtkWidget *comboboxajoutmarque;
GtkWidget *entryajoutquantite;
GtkWidget *spinbuttonajoutjour;
GtkWidget *spinbuttonajoutmois;
GtkWidget *spinbuttonajoutannee;
GtkWidget *comboboxajouttype;
GtkWidget *sortiea;

spinbuttonajoutjour=lookup_widget(button, "spinbuttonajoutjour");
spinbuttonajoutmois=lookup_widget(button, "spinbuttonajoutmois");
spinbuttonajoutannee=lookup_widget(button, "spinbuttonajoutannee");
comboboxajouttype=lookup_widget(button, "comboboxajouttype");
entryajoutidentifiant=lookup_widget(button,"entryajoutidentifiant");
comboboxajoutmarque=lookup_widget(button,"comboboxajoutmarque");
entryajoutquantite=lookup_widget(button,"entryajoutquantite");
sortiea=lookup_widget(button, "label322");


if (l==1){
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entryajoutidentifiant)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entryajoutquantite)));
c.datenada.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutjour));
c.datenada.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutmois));
c.datenada.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonajoutannee));

strcpy(chambre,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajouttype)));
strcpy(etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxajoutmarque)));
strcpy(c.chambre,chambre);
strcpy(c.etage,etage);
if(a==2)strcpy(sexe,"homme");
else if (a==1) strcpy(sexe,"femme");
strcpy(c.sexe,sexe);
ajoutnada(c);
gtk_label_set_text(GTK_LABEL(sortiea),"succecfuly created!");
}

}


void
on_radiobuttonah_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
a=2;}
}


void
on_radiobuttonaf_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
a=1;}
}







void
on_button11_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{etudiant c;
char ch[40];
char etage[30];
char Sexe[30];
GtkWidget *comboboxmodiftypee;
GtkWidget *entrymodifidentifiant;
GtkWidget *comboboxmodifmarque;
GtkWidget *spinbuttonmodifjour;
GtkWidget *spinbuttonmodifmois;
GtkWidget *spinbuttonmodifannee;
GtkWidget *entrymodifquantite;
GtkWidget *sortiem;
    
	
spinbuttonmodifjour=lookup_widget(button, "spinbuttonmodifjour");
spinbuttonmodifmois=lookup_widget(button, "spinbuttonmodifmois");
spinbuttonmodifannee=lookup_widget(button, "spinbuttonmodifannee");
comboboxmodiftypee=lookup_widget(button, "chambrebox");
entrymodifidentifiant=lookup_widget(button,"entrymodifidentifiant");
comboboxmodifmarque=lookup_widget(button,"comboboxmodifmarque");
entrymodifquantite=lookup_widget(button,"entrymodifquantite");
sortiem=lookup_widget(button, "labelmodifreus");
if (j==1){
strcpy(c.identifiant,gtk_entry_get_text(GTK_ENTRY(entrymodifidentifiant)));
strcpy(c.nom,gtk_entry_get_text(GTK_ENTRY(entrymodifquantite)));
c.datenada.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifjour));
c.datenada.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifmois));
c.datenada.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbuttonmodifannee));

strcpy(etage,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodifmarque)));

strcpy(c.etage,etage);

strcpy(ch,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxmodiftypee)));

strcpy(c.chambre,ch);

if(b==2)strcpy(Sexe,"homme");
else if (b==1) strcpy(Sexe,"femme");
strcpy(c.sexe,Sexe);

modificationnada(id,c);
gtk_label_set_text(GTK_LABEL(sortiem),"succecfuly updated!");
}

}


void
on_radiobuttonmh_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
b=2;}

}


void
on_radiobuttonmf_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton))){
b=1;}

}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview12;

debit ff;
char jour[20];    
char heure[20];  
char etage[20];
char val[20];
GtkWidget *windowskipoii;
GtkWidget *entrychercherr;
GtkWidget *Treevieww;

treeview12=lookup_widget(windowgestion,"treeview12");
affichagestat(treeview12);

}


void
on_checkbutton1nada_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton)){
j=1;}


}


void
on_buttonmenucp_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_buttonactualisernada_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *treeview11nada;
GtkWindow *agent_de_foyer;
agent_de_foyer=lookup_widget(button,"agent_de_foyer");
treeview11nada=lookup_widget(agent_de_foyer,"treeview11nada");
affichage(treeview11nada);gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(windowgestion,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));

}


void
on_buttonsupprimernada_clicked         (GtkButton       *button,
                                        gpointer         user_data)
{etudiant c;
	    GtkWidget *treeview11nada;
	    GtkWindow *agent_de_foyer;
	    agent_de_foyer=lookup_widget(button,"agent_de_foyer");
	    treeview11nada=lookup_widget(agent_de_foyer,"treeview11nada");
	    suppressionnada(id,c);
            affichage(treeview11nada);

}


void
on_buttonajouternada_clicked           (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWindow *agent_de_foyer;
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
}


void
on_buttonmodifiernada_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{GtkWindow *agent_de_foyer;
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));


}


void
on_buttonboardnada_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{GtkWindow *agent_de_foyer;
gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
                gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
		gtk_notebook_next_page(GTK_NOTEBOOK(lookup_widget(agent_de_foyer,"notebook6")));
}


void
on_buttonrecherchernada_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
etudiant c;
GtkWidget *entryid;
GtkWidget *treeview11nada;
GtkWindow *agent_de_foyer;
FILE*f;
FILE*f2;


agent_de_foyer=lookup_widget(button,"agent_de_foyer");
entryid=lookup_widget(button,"entryid");
strcpy(idrech,gtk_entry_get_text(GTK_ENTRY(entryid)));
f=fopen("etudiant.bin","rb");

 if(f!=NULL)
 {
  while(fread(&c,sizeof(etudiant),1,f))
     {
       f2=fopen("recherche.bin","ab+");
       if  (f2!=NULL)
   {  
     
     if (((strcmp(c.identifiant,idrech)==0))||((strcmp(c.chambre,idrech)==0))||((strcmp(c.etage,idrech)==0)))
     { 
     fwrite(&c,sizeof(etudiant),1,f2);
     }
   
     treeview11nada=lookup_widget(agent_de_foyer,"treeview11nada");
     recherche(treeview11nada);
    
        fclose(f2);
    }

 }
 fclose(f);
}
remove("recherche.bin");
}





void
on_checkbutton2nada_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton)){
l=1;}




}
/************************************************************************************************/
/************************************************************************************************/

void sendmail(char body[])
{
        char cmd[1000];
        FILE *fp = fopen("mail.txt","w+"); // open it for writing.
        fprintf(fp,"%s\n",body);        // write body to it.
        fclose(fp);             // close it.

        sprintf(cmd,"curl smtps://smtp.gmail.com:465 -v --mail-from \"smartesprit86@gmail.com:&azerty123\" --mail-rcpt \"achref.zaier@esprit.tn\" --ssl -u smartesprit86@gmail.com:&azerty123 -T mail.txt -k --anyauth"); // prepare command.
        system(cmd);     // execute it.
}
int specialite=1;

void
on_buttonSignup_clicked                (GtkWidget       *objet,
                                        gpointer         user_data)
{

FILE *f=NULL;
GtkWidget *fname;
GtkWidget *lname;
GtkWidget *uname;
GtkWidget *pw;
GtkWidget *spinbutton4;
GtkWidget *windowLogin;
GtkWidget *output;
char first_name[20];
char last_name[20];
char user_name[20];
char passw[20];
int r;
int trouve;
char ch[20];
fname=lookup_widget(objet,"entryFirstName");
lname=lookup_widget(objet,"entryLastName");
uname=lookup_widget(objet,"entryUsername");
pw=lookup_widget(objet,"entryPassword");

strcpy(first_name,gtk_entry_get_text(GTK_ENTRY(fname)));
strcpy(last_name,gtk_entry_get_text(GTK_ENTRY(lname)));
strcpy(user_name,gtk_entry_get_text(GTK_ENTRY(uname)));
strcpy(passw,gtk_entry_get_text(GTK_ENTRY(pw)));
r=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton4));
trouve= find_user(user_name );
if(trouve==1) 
{
output = lookup_widget(objet, "label72") ;
strcpy(ch,"*used !!");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else
	{
		f=fopen("utlisateur.txt","a");
		if(f!=NULL)
		{
		fprintf(f,"%s %s %s %s %d \n",first_name,last_name,user_name,passw,r);
		fclose(f);
		windowLogin=create_Login();
		gtk_widget_show(windowLogin);
		}
	}



}



void
on_buttonLogin_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *username,*password, *windowAdmin , *output,*Login;
char user[20];
char pasw[20];
char ch[90];
int trouve ;
username = lookup_widget (objet, "entryUsername_Login");
password = lookup_widget (objet, "entryPassword_Login");

strcpy(user, gtk_entry_get_text(GTK_ENTRY(username)));
strcpy(pasw, gtk_entry_get_text(GTK_ENTRY(password)));
trouve=verif(user,pasw);

if (trouve==1)
{
windowAdmin=create_Admin();
Login=lookup_widget(objet,"Login");
gtk_widget_destroy(Login);
gtk_widget_show(windowAdmin);
}
else 
{


output = lookup_widget(objet, "labelAZ1") ;
strcpy(ch,"User not found,create your account");
gtk_label_set_text(GTK_LABEL(output),ch);
}

}
int confirmation;
void
on_checkbuttonyes_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
		confirmation=1;
	}
}


void
on_checkbuttonno_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
	{
		confirmation=0;
	}
}



void
on_Delete_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{	char ch[20];
	char ch1[20];
	char ch2[20];
	user u ;
	GtkWidget *input ,*output1 ,*output2;
	input=lookup_widget(objet,"entryAZ100");     
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input)));
	if(confirmation==1)
	{	
		delete_user(ch);
		output1=lookup_widget(objet,"label3452") ;
		strcpy(ch1,"sucessfully deleted");
		gtk_label_set_text(GTK_LABEL(output1),ch1);
		
	}
	if(confirmation==0)
	{
		output2=lookup_widget(objet,"label3451") ;
		strcpy(ch2,"**please confirm !");
		gtk_label_set_text(GTK_LABEL(output2),ch2);
	}
}

void
on_button_search_clicked                     (GtkButton       *button,
                 	                       gpointer         user_data)
{
	GtkWidget *output ,*output1 ,*output2,*output3,*output4,*output5,*output6,*Window;	
	char ch[20];
	char ch1[20];
	char ch2[20];
	char ch3[20];
	char ch4[20];
	int ch5[20];
	char ch6[20];
	char ch7[20];
	int x ;
	user u ;
	GtkWidget *input ,*comboboxZA;
	FILE *f=NULL;
	f=fopen("utlisateur.txt","r");

	input=lookup_widget(button,"entryAZ11");
	strcpy(ch,gtk_entry_get_text(GTK_ENTRY(input)));
	x=find_user(ch); 
	comboboxZA=lookup_widget(button,"comboboxZA");
	strcpy(ch7,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxZA)));	
		
	if(f!=NULL)
	{
	if(x==1)
	{
		
		while(fscanf(f,"%s %s %s %s %d \n",ch1,ch2,ch3,ch4,&ch5)!=EOF)
		{
		if(strcmp(ch3,ch)==0)
		{
		//Window=create_Window2();
		//gtk_widget_show(Window);		
			if(strcmp("AllIInformation",ch7)==0)
			{
			output1 = lookup_widget(button, "label3462") ;
			output2 = lookup_widget(button, "label3463") ;
			output3 = lookup_widget(button, "label3464") ;
			output4 = lookup_widget(button, "label3466") ;
			output5 = lookup_widget(button, "label3467") ;	
				
			gtk_label_set_text(GTK_LABEL(output1),ch1);
			gtk_label_set_text(GTK_LABEL(output2),ch2);
			gtk_label_set_text(GTK_LABEL(output3),ch3);
			gtk_label_set_text(GTK_LABEL(output4),ch4);
			sprintf(ch6,"%d",*ch5);
			gtk_label_set_text(GTK_LABEL(output5),ch6);
			}
			if(strcmp("ExistorNot",ch7)==0)
			{
				output6= lookup_widget(button, "label3470") ;
				strcpy(ch1,"User found !");
				gtk_label_set_text(GTK_LABEL(output6),ch1);
			}
		}
		}
		
	}
	if(x==0)
	{
		output = lookup_widget(button, "labelAZ57") ;
		strcpy(ch1,"User not found");
		gtk_label_set_text(GTK_LABEL(output),ch1);
	}
	}
	
}

void
on_Update_Update_clicked                     (GtkWidget       *objet,
	                                        gpointer         user_data)
{
	
	user u ;
	char ch[20] ;
	GtkWidget *input1 , *input2 , *input3 ,*input4 , *spinbutton6 ;
	
	
	input1=lookup_widget(objet,"entry13");
	input2=lookup_widget(objet,"entry14");
	input3=lookup_widget(objet,"entry15");
	input4=lookup_widget(objet,"entry16");
	spinbutton6=lookup_widget(objet,"spinbutton6");

	strcpy(u.First_Name , gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.Last_Name , gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.Username , gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(u.Password , gtk_entry_get_text(GTK_ENTRY(input4)));
	u.Role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton6));
	strcpy(ch , u.Username) ;
	update_user(u,ch) ;
}



void
on_add_add_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	char ch[20] ;
	int trouve ;	
	user u ;
	GtkWidget *input1 , *input2 , *input3 ,*input4 , *spinbutton5 ,*output ;
	
	
	input1=lookup_widget(objet,"entryAZ6");
	input2=lookup_widget(objet,"entryAZ8");
	input3=lookup_widget(objet,"entryAZ9");
	input4=lookup_widget(objet,"entryAZ10");
	spinbutton5=lookup_widget(objet,"spinbutton5");
	

	strcpy(u.First_Name , gtk_entry_get_text(GTK_ENTRY(input1)));
	strcpy(u.Last_Name , gtk_entry_get_text(GTK_ENTRY(input2)));
	strcpy(u.Username , gtk_entry_get_text(GTK_ENTRY(input3)));
	strcpy(u.Password , gtk_entry_get_text(GTK_ENTRY(input4)));
	u.Role=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(spinbutton5));
	trouve=find_user(u.Username);
if(trouve==1) 
{
output = lookup_widget(objet, "label86") ;
strcpy(ch,"*used !!");
gtk_label_set_text(GTK_LABEL(output),ch);
}
else
	{
	add_user(u);
	sendmail("you have a new user");	
	}
	


}	


void
on_Display_add_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *Admin;
	GtkWidget *Window1;
	GtkWidget *treeview1 ;
	
	

	Admin=lookup_widget(button,"Admin");
	gtk_widget_destroy(Admin);
	Window1=lookup_widget(button,"Window1") ;
	Window1=create_window1();

	gtk_widget_show(Window1) ;

	treeview1=lookup_widget(Window1 , "treeview1");
	
	display_user_info(treeview1);
	
}



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
	GtkTreeIter iter ;
	GtkCellRenderer *renderer;
	GtkListStore *store;
	gchar* First_Name ;
	gchar* Last_Name ;
	gchar* Username ; 
	gchar* Password ;
	gint* Role ;
	user u; 

	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

	if (gtk_tree_model_get_iter(model, &iter , path))
	{
		gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &First_Name,1,&Last_Name,2,&Username,3,&Password,4,&Role,-1) ;

		strcpy(u.First_Name,First_Name);
		strcpy(u.Last_Name,Last_Name);
		strcpy(u.Username,Username);
		strcpy(u.Password,Password);
		u.Role=Role;
		
		display_user_info(treeview) ;
	}
	
}


void

on_Refrech_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *window1 ,*w1;
	GtkWidget *treeview1 ;

	
	w1=lookup_widget(objet,"window1");
	gtk_widget_hide(window1);	
	window1=create_window1() ;
	
	gtk_widget_show(window1);

	gtk_widget_hide(w1);
	treeview1=lookup_widget(window1,"treeview1");
	
	/*empty(treeview1);*/
	display_user_info(treeview1);
}


void
on_Back_clicked                        (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Admin , *window1 ;
	window1=lookup_widget(objet,"window1");	
	Admin=create_Admin();
	gtk_widget_destroy(window1);	
	gtk_widget_show(Admin);

}

































/*void
on_Add_clicked                         (GtkButton       *Button,
                                        gpointer         user_data)
{

}


void
on_Remove_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Update_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Find_clicked                        (GtkButton       *button,
                                        gpointer         user_data)
{
}


void
on_Check_clicked                       (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_search_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_add_user_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_Display_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}

void
on_Refresh_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}*/


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=2;
}


void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=6;
}


void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=5;
}


void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=4;
}


void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=7;
}


void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		specialite=3;
}


int res=0;
void
on_calcul_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output ;
char ch1[50];
char ch2[20];
int res;
	res=student_number(specialite);
	if(specialite==7)
	{
	res=student_number(1)+student_number(2)+student_number(3)+student_number(4)+student_number(5)+student_number(6);	
	}
	sprintf(ch2,"%d",res);
	output = lookup_widget(button, "label3485") ;
	strcpy(ch1,"vous avez ::: ");
	gtk_label_set_text(GTK_LABEL(output),ch1);
	output = lookup_widget(button, "label3484") ;
	gtk_label_set_text(GTK_LABEL(output),ch2);
	

	
}
int choix;

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		choix=1;
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		choix=2;
}


void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Sign_up , *Login ;
	Login=lookup_widget(objet,"Login");	
	Sign_up=create_Sign_up();
	gtk_widget_destroy(Login);	
	gtk_widget_show(Sign_up);
}


void
on_button6_Logout_clicked              (GtkWidget       *objet,
                                        gpointer         user_data)
{
	GtkWidget *Login , *Admin ;
	Admin=lookup_widget(objet,"Admin");	
	Login=create_Login();
	gtk_widget_destroy(Admin);	
	gtk_widget_show(Login);
}













void
on_treeview12nada_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview12_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_treeview11_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_checkbutton11EM_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


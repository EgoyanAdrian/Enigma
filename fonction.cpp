#include <iostream>
#include <string>
using namespace std;
#include "fonction.hpp"
#include "fcto-pr-char.hpp"

string Al="ABCDEFGHIJKLMNOPQRSTUVWXYZ",I="EKMFLGDQVZNTOWYHXUSPAIBRCJ",II="AJDKSIRUXBLHWTMCQGZNPYFVOE",III="BDFHJLCPRTXVZNYEIWGAKMUSQO";
string IV="ESOVPZJAYQUIRHXLNFTGKDCMWB",V="VZBRGITYUPSDNHLXAWMJQOFECK",ReflB="YRUHQSLDPXNGOKMIEBFZCWVJAT",ReflC="RDOBJNTKVEHMLFCWZAXGYIPSUQ";

Fiche fiche={"AWHXCOJPEKFR",12};

void code(Rotor r,char &l,char sens)//recherche la lettre correspondante a celle donner dans une rotor donner
{
	//variable
	int i;
	bool tr;
	//debut
	i=0;
	tr=false;
	while((tr==false)&&(i<26))
	{
		if(sens=='A')
		{	
			if(Al[i]==l)
			{
				l=r.struc[i];
				tr=true;
			}
			i+=1;
		}
		else
		{
			if(r.struc[i]==l)
			{
				l=Al[i];
				tr=true;
			}
			i+=1;
		}
	}
}

void rotor(Rotor r1, Rotor r2, Rotor r3, char &l,int mode,char sens)//fonction qui fait l'acion des rotor
{
	//Debut
	for(int t=1;t<4;t++)
	{
		if(t==3)
		{
			if (mode==1)//si on est en mode demo
				{
					cout<<endl<<"passage dans le dernier rotor"<<endl;
					cout<<"Lettre à coder: "<<l<<endl;
					cout<<Al<<endl;
					cout<<r1.struc<<endl;
				}
			//appel de la fonction qui fait le travail
			code(r1,l,sens);
			if (mode==1)
			{
				cout<<"Lettre coder: "<<l<<endl;
			}
		}
		else
		{
			if (t==2)
			{
				if (mode==1)
				{
				cout<<endl<<"passage dans le deuxieme rotor"<<endl;
					cout<<"Lettre à coder: "<<l<<endl;
					cout<<Al<<endl;
					cout<<r2.struc<<endl;
				}
				//appel de la fonction qui fait le travail
				code(r2,l,sens);
				if (mode==1)
				{
					cout<<"Lettre coder: "<<l<<endl;
				}
			}
			else
			{
				if (mode==1)
				{
					cout<<endl<<"passage dans le premier rotor"<<endl;
					cout<<"Lettre à coder: "<<l<<endl;
					cout<<Al<<endl;
					cout<<r3.struc<<endl;
				}
				//appel la fonction qui fait le travail
				code(r3,l,sens);
				if (mode==1)
				{
				cout<<"Lettre coder: "<<l<<endl;
				}
			}
		}
	}
	
}

void table_conne(Fiche &fich,char &lettre)
{
	//variable
	int i;
	bool t;
	
	//debut
	t=false;
	i=0;
	while((t==false)&&(i<fich.nb_ele))
	{
		if (fich.contenu[i]==lettre)
		{
			t=true;
			if (i%2==1)
			{
				lettre=fiche.contenu[i-1];
			}
			else
			{
				lettre=fiche.contenu[i+1];
			}
		}
		i+=1;
	}
}

void reflecteur(string refl,char &lettre)
{
	//variable
	int i;
	bool t;
	
	//Debut
	t=false;
	i=0;
	while ((t==false)&&(i<26))
	{
		if (Al[i]==lettre)
		{
			lettre=refl[i];
			t=true;
		}
	i+=1;
	}
}

Rotor rotat(Rotor r)
{
	//Variable
	char prec,stock;
	//Debut
	prec=r.struc[0];
	for(int i=1;i<26;i++)
	{
		stock=r.struc[i];
		r.struc[i]=prec;
		prec=stock;
	}
	r.struc[0]=prec;
	if (r.mv==26)
	{
		r.mv=1;
	}
	else
		r.mv+=1;
	return r;
}

void convert(Rotor &r,int choix)
{
	switch(choix)
	{

		case 1:
			r.struc=I;
			cout<<I<<endl;
			break;
		case 2:
			r.struc=II;
			cout<<II<<endl;
			break;
		case 3:
			r.struc=III;
			cout<<III<<endl;
			break;
		case 4:
			r.struc=IV;
			cout<<IV<<endl;
			break;
		case 5:
			r.struc=V;
			cout<<V<<endl;
			break;
	}
	r.mv=0;
}
void lec_fiche(Fiche a)
{
	for(int i=0;i<a.nb_ele;i++)
	{
		cout<<a.contenu[i];
	}
	cout<<endl;
}

void decouverte()
{
	//variable
	char copie,lettre,ok;
	string ref;
	Rotor rotor1,rotor2,rotor3;
	int rot1,rot2,rot3;
	
	
	//Debut
	cout<<"Vous etez dans le mode decouverte"<<endl;
	//lettre a coder
	cout<<"donner un lettre à coder"<<endl;
	cin>>lettre;
	//choix des rotors
	cout<<"maintenant il faut choisir les rotors"<<endl;
	cout<<"leurs position serons detreminer par l'ordre dans le quelle il seront donner"<<endl;
	cout<<"rotor I(taper 1)"<<endl<<"rotor II(taper 2)"<<endl<<"rotor III(taper3)"<<endl<<"rotor IV(taper4)"<<endl<<"rotor V(taper5)"<<endl;
	cin>>rot1;
	cin>>rot2;
	cin>>rot3;
	convert(rotor1,rot1);
	convert(rotor2,rot2);
	convert(rotor3,rot3);
	//choix du reflcteur
	cout<<endl<< "il faut maintenant choisir le reflecteur"<<endl;
	cout<<"choix automatique RefC"<<endl;
	cout<<"ReflB: "<<ReflB<<endl<<"ou"<<endl<<"ReflC: "<<ReflC<<endl;
	cin>>ref;
	cout<<endl<<endl<<endl<<endl;
	
	//debut du travail
	cout<<"===Table de connection==="<<endl;
	lettre=lettre-32;
	copie=lettre;
	cout<<"voici la fiche utiliser"<<endl;
	lec_fiche(fiche);
	ok=getHiddenChar();																			//gethiddenchar
	table_conne(fiche,lettre);
	cout<<"votre lettre: "<<copie<<" et code pour le moment en "<< lettre <<endl;
	ok=getHiddenChar();																			//gethiddenchar
	cout<<endl<<endl<<endl<<endl;
	cout<<"===passage dans les rotors==="<<endl;
	rotor(rotor1,rotor2,rotor3,lettre,1,'A');//A=aller
	ok=getHiddenChar();																			//gethiddenchar
	cout<<endl<<endl<<endl<<endl;
	cout<<"===passage dans le reflecteur==="<<endl;
	if ((ref=="ReflB")||(ref=="REFLB")||(ref=="reflb")||(ref=="reflB"))	
	{
		cout<<"Lettre à coder: "<<lettre<<endl;
		cout<<Al<<endl;
		cout<<ReflB<<endl;
		reflecteur(ReflB,lettre);
	}	
	else
	{
		cout<<"Lettre à coder: "<<lettre<<endl;
		cout<<Al<<endl;
		cout<<ReflB<<endl;
		reflecteur(ReflC,lettre);
	}
	cout<<"maintenant la lettre donner: "<<copie<<" et code par :"<<lettre<<endl;
	ok=getHiddenChar();																			//gethiddenchar
	cout<<endl<<endl<<endl<<endl;
	cout<<"===passage dans les rotors(retour)==="<<endl;	
	rotor(rotor3,rotor2,rotor1,lettre,1,'R');//R=retour;
	ok=getHiddenChar();																			//gethiddenchar
	cout<<endl<<endl<<endl<<endl;
	cout<<"===Table de connection(retour)==="<<endl;
	table_conne(fiche,lettre);
	cout<<"la lettre "<<copie<<" et finalement code par "<<lettre<<endl;
}

void normal()
{
	//Variable
	string Acode,Code;
	string ref;
	Rotor rotor1,rotor2,rotor3;
	int taille,rot1,rot2,rot3;
	char lettre;
	
	//Debut
	
	Code="";
	cout<<"Vous etez dans le mode normal"<<endl;
	cout<<"donner un le mots à coder"<<endl;
	cin>>Acode;
	//choix rotor
	cout<<"maintenant il faut choisir les rotors"<<endl;
	cout<<"leurs position serons detreminer par l'ordre dans le quelle il seront donner"<<endl;
	cout<<"rotor I(taper 1)"<<endl<<"rotor II(taper 2)"<<endl<<"rotor III(taper3)"<<endl<<"rotor IV(taper4)"<<endl<<"rotor V(taper5)"<<endl;
	cin>>rot1;
	cin>>rot2;
	cin>>rot3;
	convert(rotor1,rot1);
	convert(rotor2,rot2);
	convert(rotor3,rot3);
	//choix reflecteur
	cout<< "il faut maintenant choisir le reflecteur"<<endl;
	cout<<"choix automatique RefC"<<endl;
	cout<<"ReflB: "<<ReflB<<endl<<"ou"<<"ReflC: "<<ReflC<<endl;
	cin>>ref;
	taille=Acode.size();
	for(int i=0;i<taille;i++)
	{
		//passage au majuscule
		lettre=Acode[i]-32;
		//table de connection
		table_conne(fiche,lettre);
		//passage dans les rotors
		rotor(rotor1,rotor2,rotor3,lettre,0,'A');
		//passage dans le reflecteur
		if ((ref=="ReflB")||(ref=="REFB")||(ref=="refb")||(ref=="refB"))	
			reflecteur(ReflB,lettre);
		else
			reflecteur(ReflC,lettre);
		//passage retour par le rotor
		rotor(rotor3,rotor2,rotor1,lettre,0,'R');
		//passage retour par la table de connection
		table_conne(fiche,lettre);
		//verif rotation
		rotor1=rotat(rotor1);
		if(rotor1.mv==26)
			rotor2=rotat(rotor2);
		if(rotor2.mv==26)
			rotor3=rotat(rotor3);
		Code+=lettre;//ajoute les lettres code pour avoir le message codée
	}
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"Le mots codé est :"<<Code<<endl;
}

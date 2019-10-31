#include <iostream>
#include <string>
using namespace std;
#include "fonction.hpp"
#include "fcto-pr-char.hpp"

int main()
{
		//variable
		int mode;
		bool next;
		char cont;
		//debut
		cout<<"Bonjour bienvenu dans le programme de presentation de la machine Enigma"<<endl;
		cout<<"vous allez pouvoir code une phrases de la meme façons que les allemend pendants la segonde guerre mondial"<<endl;
		do
		{
			cout<<"==========Menu=========="<<endl;
			cout<<"Mode decouverte (taper 1)"<<endl;
			cout<<"Mode normal (taper 2)"<<endl;
			cout<<"Arret du programme(taper 3)"<<endl;
			cin>>mode;
			if (mode!=3)
			{	if (mode==1)
					decouverte();
				else if (mode==2)
						normal();
					else
					{
						cout<<"donner incorrecte"<<endl;
						next=true;
					}
				if (next==false)
				{
					cout<<"voulez vous continuer?(O/N)"<<endl;
					cin>>cont;
					if ((cont=='O')||(cont='o'))
						next=true;
					else if ((cont=='N')||(cont='n'))
						next=false;
						else
							{
								cout<<"reponce inccorect retour au menu"<<endl;
								next=true;
							}
				}
			}
			else
				next=false;
		}while(next==true);
	return 0;
}


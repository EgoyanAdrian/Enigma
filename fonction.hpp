#include <string>
struct SRotor{
	string struc;
	int mv;
};

typedef struct SRotor Rotor;

struct SFiche{
	string contenu;
	int nb_ele;
};

typedef struct SFiche Fiche;

void code(Rotor r,char &l);//recherche la lettre correspondante a celle donner dans une rotor donner
void rotor(Rotor r1, Rotor r2, Rotor r3, char &l,int mode);//fonction qui fait l'acion des rotor
void table_conne(Fiche &fich,char &lettre);
void reflecteur(string refl, char &lettre);
Rotor rotat(Rotor r);
void convert(Rotor &r,int choix);
void lec_fiche(Fiche a);
void decouverte();
void normal();
char getHiddenChar();

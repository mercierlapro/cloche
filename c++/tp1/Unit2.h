//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H

class pile_entier
{
	private:
	int *pile,taille,hauteur;
	public:
	pile_entier(int t);
	~pile_entier();
	void empile(int val);
	int depile();
	int pleine();
	int vide();
	int *getpile();
	int gethauteur();
	int gettaille();

};
//---------------------------------------------------------------------------
#endif

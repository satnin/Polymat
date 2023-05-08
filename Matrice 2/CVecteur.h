#pragma once
#include <iomanip>
#include <random>
#include <iostream>
using namespace std;
class CVecteur
{
protected:
	int m_dimension;
	double* m_ptab;

	/// <summary>
	/// Ecrase les donn�es actuelles et redimensionne la table
	/// </summary>
	void reset();
public:
	//Constructeur par d�faut
	CVecteur();
	//Contructeur avec param�tres
	CVecteur(int n, double* tab=NULL);
	//Constructeur de copie
	CVecteur(const CVecteur& a);
	/// <summary>
	/// D�finit la valeur d'une coordonn�e
	/// </summary>
	/// <param name="i">indice 0-index� de la coordonn�e</param>
	/// <param name="value">Valeur � prendre</param>
	void set(const int& i, const double& value);
	/// <summary>
	/// G�n�rer des composantes al�atoires
	/// </summary>
	void randomize();
	void operator= (const CVecteur& a);
	void operator*= (const double& a);
	void operator/= (const double& a);

	
	double operator[] (const int& i) const;
	
	/// <summary>
	/// R�cup�re le vecteur issu de l'�limination de la composante indiqu�e en param�tre.
	/// </summary>
	/// <param name="i">indice de la case � �liminer (O index�)</param>
	/// <returns>Vecteur r�duit</returns>
	CVecteur operator() (const int& i) const;
	/// <summary>
	/// Produit en croix des coordonn�es
	/// </summary>
	/// <param name="a"></param>
	/// <returns>Le r�el r�sultant du produit en croix</returns>
	double operator| (const CVecteur& a) const;
	
	//Destructeur
	~CVecteur();

	friend CVecteur operator+ (const CVecteur & a, const CVecteur & b);
	friend CVecteur operator- (const CVecteur & a, const CVecteur & b);
	/// <summary>
	/// Produit scalaire
	/// </summary>
	/// <param name="a">Vecteur a</param>
	/// <param name="b">Vecteur b</param>
	/// <returns>a scalaire b</returns>
	friend double operator* (const CVecteur & a, const CVecteur & b);
	friend CVecteur operator* (const CVecteur & a, const double & b);
	friend CVecteur operator/ (const CVecteur & a, const double & b);
	
	friend istream& operator>> (istream& is, CVecteur& a);
	friend ostream& operator<< (ostream& os,const CVecteur& a);
};

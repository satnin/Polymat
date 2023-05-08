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
	/// Ecrase les données actuelles et redimensionne la table
	/// </summary>
	void reset();
public:
	//Constructeur par défaut
	CVecteur();
	//Contructeur avec paramètres
	CVecteur(int n, double* tab=NULL);
	//Constructeur de copie
	CVecteur(const CVecteur& a);
	/// <summary>
	/// Définit la valeur d'une coordonnée
	/// </summary>
	/// <param name="i">indice 0-indexé de la coordonnée</param>
	/// <param name="value">Valeur à prendre</param>
	void set(const int& i, const double& value);
	/// <summary>
	/// Générer des composantes aléatoires
	/// </summary>
	void randomize();
	void operator= (const CVecteur& a);
	void operator*= (const double& a);
	void operator/= (const double& a);

	
	double operator[] (const int& i) const;
	
	/// <summary>
	/// Récupère le vecteur issu de l'élimination de la composante indiquée en paramètre.
	/// </summary>
	/// <param name="i">indice de la case à éliminer (O indexé)</param>
	/// <returns>Vecteur réduit</returns>
	CVecteur operator() (const int& i) const;
	/// <summary>
	/// Produit en croix des coordonnées
	/// </summary>
	/// <param name="a"></param>
	/// <returns>Le réel résultant du produit en croix</returns>
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

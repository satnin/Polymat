#pragma once
#include "CVecteur.h"
#include <fstream>

class CMatrice
{
protected:
	int m_nb_lignes;
	int m_nb_colonnes;
	CVecteur* m_lignes;


	void reset();
public:
	CMatrice();
	CMatrice(const int lignes, const int colonnes);
	CMatrice(const CMatrice& mat);
	/// <summary>
	/// G�n�rer des composantes al�atoires
	/// </summary>
	void randomize();
	bool saveTo(const char* file_name) const;
	void load(const char* file_name);
	void operator=(const CMatrice& mat);
	void operator*= (const double& a);
	void operator/= (const double& a);
	/// <summary>
	/// Transpose la matrice
	/// </summary>
	/// <returns></returns>
	CMatrice operator! ()const;
	/// <summary>
	/// Elimine une ligne et une colonne
	/// </summary>
	/// <param name="ligne"></param>
	/// <param name="colonne"></param>
	/// <returns></returns>
	CMatrice crop (const int& ligne, const int& colonne)const;
	/// <summary>
	/// Calcule la comatrice 
	/// </summary>
	/// <returns></returns>
	CMatrice comatrice() const;
	/// <summary>
	/// Calcule l'inverse 
	/// </summary>
	/// <returns></returns>
	CMatrice inverse() const;
	/// <summary>
	/// D�finis une valeur
	/// </summary>
	/// <param name="ligne"></param>
	/// <param name="colonne"></param>
	/// <param name="value"></param>
	void set(const int& ligne, const int& colonne, const double& value);
	void set(const int& ligne, const CVecteur& value);
	/// <summary>
	/// Recueille la valeur � la position sp�cifi�e
	/// </summary>
	/// <param name="ligne"></param>
	/// <param name="colonne"></param>
	double operator() (const int& ligne, const int& colonne) const;
	/// <summary>
	/// Calcule le d�terminant
	/// </summary>
	/// <returns></returns>
	double operator~ () const;
	CVecteur operator[] (const int& ligne) const;

	~CMatrice();

	friend CMatrice operator+ (const CMatrice& a, const CMatrice& b);
	friend CMatrice operator- (const CMatrice& a, const CMatrice& b);
	
	friend CMatrice operator* (const CMatrice& a, const CMatrice& b);
	friend CMatrice operator* (const CMatrice& a, const double& b);
	friend CMatrice operator/ (const CMatrice& a, const double& b);


	friend istream& operator>> (istream& is, CMatrice& a);
	friend ostream& operator<< (ostream& os, const CMatrice& a);
};


#include "Fonctions.h"

void addition()
{
	cout << endl << endl;
	cout << setfill('*') << setw(100) << std::left << "********************************************ADDITION" << endl << endl;
	cout << setfill(' ');
	cout << endl << "Matrice A : " << endl;
	CMatrice A = getMatrice();
	cout << endl << "A :" << endl << A << endl;
	cout << endl << "Matrice B : " << endl;
	CMatrice B = getMatrice();
	cout << endl << "B :" << endl << B << endl;
	CMatrice res;
	res = (A + B);
	cout << endl << "La somme des matrices " << endl << A << endl << "et : " << endl << B << endl << "est : " << endl << res << endl << endl;
	switch (save_question(3))
	{
	default:
		break;
	case 1:
		sauvegarde(A); break;
	case 2:
		sauvegarde(B); break;
	case 3:
		sauvegarde(res); break;
	}
}

void soustraction()
{
	cout << endl << endl;
	cout << setfill('*') << setw(100) << std::left << "****************************************-SOUSTRACTION" << endl << endl;
	cout << setfill(' ');
	cout << endl << "Matrice A : " << endl;
	CMatrice A = getMatrice();
	cout << endl << "A :" << endl << A << endl;
	cout << endl << "Matrice B : " << endl;
	CMatrice B = getMatrice();
	cout << endl << "B :" << endl << B << endl;
	CMatrice res;
	res = A - B;
	cout << endl << "La différence entre la matrice " << endl << A << endl << "et la matrice : " << endl << B << endl << "est : " << endl << res << endl << endl;
	switch (save_question(3))
	{
	default:
		break;
	case 1:
		sauvegarde(A); break;
	case 2:
		sauvegarde(B); break;
	case 3:
		sauvegarde(res); break;
	} 
}

void multiplication()
{
	cout << endl << endl;
	cout << setfill('*') << setw(100) << std::left << "****************************************-MULTIPLICATION" << endl << endl;
	cout << setfill(' ');
	cout << endl << "Matrice A : " << endl;
	CMatrice A = getMatrice();
	cout << endl << "A :" << endl << A << endl;
	cout << endl << "Matrice B : " << endl;
	CMatrice B = getMatrice();
	cout << endl << "B :" << endl << B << endl;
	CMatrice res;
	res = A * B;
	cout << endl << "Le produit des matrices " << endl << A << endl << "et : " << endl << B << endl << "est : " << endl << res << endl << endl;
	switch (save_question(3))
	{
	default:
		break;
	case 1:
		sauvegarde(A); break;
	case 2:
		sauvegarde(B); break;
	case 3:
		sauvegarde(res); break;
	}
}

void detcalc()
{
	cout << endl << endl;
	cout << setfill('*') << setw(100) << std::left << "**************************************CALCUL DE DETERMINANT" << endl << endl;
	cout << setfill(' ');
	CMatrice mat = getMatrice();
	cout << endl << "Le déterminant de la matrice " << endl << mat << endl << "est : " << ~mat << endl << endl;
	switch (save_question(1))
	{
	default:
		break;
	case 1:
		sauvegarde(mat); break;
	}
}

void inversion()
{
	cout << endl << endl;
	cout << setfill('*') << setw(100) << std::left << "*******************************************INVERSION"<< endl <<endl;
	cout << setfill(' ');
	CMatrice mat = getMatrice();
	CMatrice inv = mat.inverse();
	cout << endl << "L'inverse de la matrice " << endl << mat << endl << "est : " << endl << inv << endl << endl;
	switch (save_question(2))
	{
	default:
		break;
	case 1:
		sauvegarde(mat); break;
	case 2:
		sauvegarde(inv); break;
	}
}

void sauvegarde(const CMatrice& mat)
{
	cout << "Veuillez choisir un nom de fichier : ";
	char* file = getchaine();
	if (mat.saveTo(file))
		cout << "Réussi !!!" << endl;
	else
		cout << "Echec !!!" << endl;
}

void lecture()
{
	cout << endl << endl;
	cout << setfill('*') << setw(100) << std::left << "*******************************************LECTEUR" << endl << endl;
	cout << setfill(' ');
	cout << "Nom du fichier à consulter : ";
	char* file = getchaine();
	CMatrice mat;
	mat.load(file);
	cout << "\nOuverture de la matrice " << file << endl << endl;
	cout << mat << endl << endl;
}

CMatrice getMatrice()
{
	int response = 0;
	do
	{
		cout << "Voulez-vous un ? \n 1- Remplissage manuel \n 2- Chargement depuis un fichier \n 3- Remplissage automatique " << endl;
		cin >> response;
	} while (response < 1 || response >3);

	switch (response)
	{
	default:
		break;
	case 1 :
	{
		CMatrice res;
		cin >> res;
		return res;
	} break;
	case 2 :
	{
		CMatrice res;
		char* file;
		cout << "Nom du fichier : ";
		file = getchaine();
		res.load(file);
		return res;
	} break;
	case 3:
	{
		int ligne = 0, colonne = 0;
		cout << "Nombre de lignes : ";
		cin >> ligne;
		cout << "Nombre de colonnes : ";
		cin >> colonne;
		CMatrice res(ligne, colonne);
		res.randomize();
		return res;
	} break;
	}
}

char* getchaine()
{
	char* temp = new char[100];
	cin >> temp;
	int taille_temp = (int) strlen(temp);
	ifstream extension_file("ext.txt");
	char* temp2 = new char[5];
	extension_file.getline(temp2, 10);
	char* res = new char[taille_temp + 9 + 1];
	strcpy_s(res, taille_temp+1, temp);
	for (int i = taille_temp; i < taille_temp + 10; i++)
		res[i] = temp2[i-taille_temp];
	return res;
}


int save_question(int nb_matrice)
{
	int reponse = 0;
	do
	{
		cout << "Voudriez-vous enregistrer une matrice ?\n";
		cout << "0- Non." << endl;
		for (int i = 0; i < nb_matrice; i++)
		{
			cout << i + 1 << "- Matrice " << i + 1 << " ?\n";
		}
		cin >> reponse;
	} while (reponse < 0 || reponse >nb_matrice);
	return reponse;
}

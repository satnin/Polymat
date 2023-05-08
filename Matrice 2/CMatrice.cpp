#include "CMatrice.h"

void CMatrice::reset()
{
	if (this->m_lignes != NULL)
		delete[] this->m_lignes;
	m_lignes = new CVecteur[m_nb_lignes];
	for (int i = 0; i < m_nb_lignes; i++)
	{
		m_lignes[i] = CVecteur(m_nb_colonnes);
	}
}

CMatrice::CMatrice()
{
	m_nb_lignes = 0;
	m_nb_colonnes = 0;
	m_lignes = NULL;
}

CMatrice::CMatrice(const int lignes, const int colonnes)
{
	m_nb_lignes = lignes;
	m_nb_colonnes = colonnes;
	reset();
}

CMatrice::CMatrice(const CMatrice& mat)
{
	m_nb_colonnes = mat.m_nb_colonnes;
	m_nb_lignes = mat.m_nb_lignes;
	m_lignes = new CVecteur[m_nb_lignes];
	for (int i = 0; i < m_nb_lignes; i++)
	{
		m_lignes[i] = mat.m_lignes[i];
	}
}

void CMatrice::randomize()
{
	for (int i = 0; i < m_nb_lignes; i++)
	{
		m_lignes[i].randomize();
	}
}

bool CMatrice::saveTo(const char* file_name) const
{
	ofstream resource(file_name, ios::binary);
	if (resource.is_open())
	{
		resource.write((char*)&m_nb_lignes, sizeof(int));
		resource.write((char*)&m_nb_colonnes, sizeof(int));
		double temp = 0;
		for (int i = 0; i < m_nb_lignes; i++)
		{
			for (int j = 0; j < m_nb_colonnes; j++)
			{
				temp = this->operator()(i, j);
				resource.write((char*)&temp, sizeof(double));
			}
		}
		resource.close();
		return true;
	}
	else
		return false;
}

void CMatrice::load(const char* file_name)
{
	ifstream resource(file_name, ios::binary);
	if (resource.is_open())
	{
		resource.read((char*)&m_nb_lignes, sizeof(int));
		resource.read((char*)&m_nb_colonnes, sizeof(int));
		reset();
		double temp = 0;
		for (int i = 0; i < m_nb_lignes * m_nb_colonnes; i++)
		{
			resource.read((char*)&temp, sizeof(double));
			this->set((int)i / m_nb_colonnes, i % m_nb_colonnes, temp);
		}
		resource.close();
	}
}

void CMatrice::operator=(const CMatrice& mat)
{
	m_nb_colonnes = mat.m_nb_colonnes;
	m_nb_lignes = mat.m_nb_lignes;
	reset();
	for (int i = 0; i < m_nb_lignes; i++)
	{
		m_lignes[i] = mat.m_lignes[i];
	}
}

void CMatrice::operator*=(const double& a)
{
	for (int i = 0; i < m_nb_lignes; i++)
	{
		m_lignes[i] *= a;
	}
}

void CMatrice::operator/=(const double& a)
{
	for (int i = 0; i < m_nb_lignes; i++)
	{
		m_lignes[i] /= a;
	}
}

CMatrice CMatrice::operator!() const
{
	CMatrice res(m_nb_colonnes, m_nb_lignes);
	for (int i = 0; i < m_nb_colonnes; i++)
	{
		for (int j = 0; j < m_nb_lignes; j++)
			res.set(i, j, m_lignes[j][i]);
	}
	return res;
}

CMatrice CMatrice::crop(const int& ligne, const int& colonne) const
{
	CVecteur* n = new CVecteur[m_nb_lignes - 1];
	for (int j = 0; j < m_nb_lignes && j < ligne; j++)
		n[j] = m_lignes[j](colonne);
	for (int j = ligne + 1; j < m_nb_lignes; j++)
		n[j - 1] = m_lignes[j](colonne);
	CMatrice res;
	res.m_lignes = n;
	res.m_nb_lignes = m_nb_lignes - 1;
	res.m_nb_colonnes = m_nb_colonnes - 1;
	return res;
}

CMatrice CMatrice::comatrice() const
{
	CMatrice res(m_nb_lignes, m_nb_colonnes);
	for (int i = 0; i < m_nb_lignes; i++)
	{
		for (int j = 0; j < m_nb_colonnes; j++)
		{
			if ((i + j) % 2 == 0)
				res.set(i, j, ~crop(i, j));
			else
				res.set(i, j,0 - (~crop(i, j)));
		}
	}
	return res;
}

CMatrice CMatrice::inverse() const
{
	
	if (m_nb_lignes == m_nb_colonnes)
	{
		CMatrice res=!comatrice()/(operator~());
		return res;
	}
	return CMatrice();

}

void CMatrice::set(const int& ligne, const int& colonne, const double& value)
{
	m_lignes[ligne].set(colonne, value);
}

void CMatrice::set(const int& ligne, const CVecteur& value)
{
	m_lignes[ligne] = value;
}

double CMatrice::operator()(const int& ligne, const int& colonne) const
{
	return m_lignes[ligne][colonne];
}

double CMatrice::operator~() const
{
	double res = 0;
	if (m_nb_lignes == m_nb_colonnes)
	{
		switch (m_nb_lignes)
		{
		case 0:
			break;
		case 1:
			return m_lignes[0][0];
			break;
		case 2:
			return m_lignes[0] | m_lignes[1];
		default:
			for (int i = 0; i < m_nb_lignes; i++)
			{
				if (i % 2 == 0)
					res += ~crop(i, 0)*m_lignes[i][0];
				else
					res -= ~crop(i, 0) * m_lignes[i][0];
			}
			break;
		}
	}
	return res;
}

CVecteur CMatrice::operator[](const int& ligne) const
{
	return m_lignes[ligne];
}

CMatrice::~CMatrice()
{
	if (this->m_lignes != NULL)
		delete[] this->m_lignes;
}

CMatrice operator+(const CMatrice& a, const CMatrice& b)
{
	CMatrice res(a.m_nb_lignes, a.m_nb_colonnes);
	for (int i = 0; i < a.m_nb_lignes; i++)
	{
		res.set(i, a[i] + b[i]);
	}
	return res;
}

CMatrice operator-(const CMatrice& a, const CMatrice& b)
{
	CMatrice res(a.m_nb_lignes, a.m_nb_colonnes);
	for (int i = 0; i < a.m_nb_lignes; i++)
	{
		res.set(i, a[i] - b[i]);
	}
	return res;
}

CMatrice operator*(const CMatrice& a, const CMatrice& b)
{
	CMatrice res(a.m_nb_lignes, b.m_nb_colonnes), tb = !b;
	for (int i = 0; i < res.m_nb_lignes; i++)
	{
		for (int j = 0; j < res.m_nb_colonnes; j++)
		{
			res.set(i, j, a[i] * tb[j]);
		}
	}
	return res;
}

CMatrice operator*(const CMatrice& a, const double& b)
{
	CMatrice res = a;
	res *= b;
	return res;
}

CMatrice operator/(const CMatrice& a, const double& b)
{
	CMatrice res = a;
	res /= b;
	return res;
}

istream& operator>>(istream& is, CMatrice& a)
{
	cout << "Veuillez entrer les données de la matrice ! " << endl;
	cout << "Nombre de ligne ";
	is >> a.m_nb_lignes;
	cout << "Nombre de colonne ";
	is >> a.m_nb_colonnes;
	a.reset();
	for (int i = 0; i < a.m_nb_lignes; i++)
	{
		for (int j = 0; j < a.m_nb_colonnes; j++)
		{
			double variable;
			cout << "Ligne " << i + 1 << ", Colonne " << j + 1 << ": ";
			is >> variable;
			a.set(i, j, variable);
			cout << endl;
		}
	}
	return is;
}

ostream& operator<<(ostream& os, const CMatrice& a)
{
	for (int i = 0; i < a.m_nb_lignes; i++)
	{
		os << a.m_lignes[i]<<endl;
	}
	return os;
}

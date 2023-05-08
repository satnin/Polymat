#include "CVecteur.h"
void CVecteur::reset()
{
	if (this->m_ptab != NULL)
		delete[] this->m_ptab;
	this->m_ptab = new double[this->m_dimension];
}
CVecteur::CVecteur()
{
	m_dimension = 0;
	m_ptab = NULL;
}

CVecteur::CVecteur(int n, double* tab)
{
	m_dimension = n;
	m_ptab = new double[m_dimension];
	if (tab != NULL)
	{
		for (int i = 0; i < m_dimension; i++)
			m_ptab[i] = tab[i];
	}
}

CVecteur::CVecteur(const CVecteur& a)
{
	m_dimension = a.m_dimension;
	m_ptab = new double[m_dimension];
	for (int i = 0; i < m_dimension; i++)
	{
		m_ptab[i] = a.m_ptab[i];
	}
}

void CVecteur::set(const int& i, const double& value)
{
	m_ptab[i] = value;
}

void CVecteur::randomize()
{
	std::random_device rd{};
	std::mt19937 gen{ rd() };
	binomial_distribution<> generateur(5, 0.5);
	for (int i = 0; i < m_dimension; i++)
	{
		m_ptab[i] =(double) generateur(gen);
	}
}

void CVecteur::operator=(const CVecteur& a)
{
	m_dimension = a.m_dimension;
	reset();
	for (int i = 0; i < m_dimension; i++)
	{
		m_ptab[i] = a.m_ptab[i];
	}
}

void CVecteur::operator*=(const double& a)
{
	for (int i = 0; i < m_dimension; i++)
	{
		m_ptab[i] *= a;
	}
}

void CVecteur::operator/=(const double& a)
{
	for (int i = 0; i < m_dimension; i++)
	{
		m_ptab[i] /= a;
	}
}

double CVecteur::operator[](const int& i) const
{
	return m_ptab[i];
}

CVecteur CVecteur::operator()(const int& i) const
{
	double* n;
	n = new double[m_dimension-1];
	for (int j= 0; j < m_dimension && j<i; j++)
		n[j] = m_ptab[j];
	for (int j = i+1; j < m_dimension ; j++)
		n[j-1] = m_ptab[j];
	return CVecteur(m_dimension-1, n);
}

double CVecteur::operator|(const CVecteur& a) const
{
	double n=0;
	for (int j = 0; j < m_dimension-1; j++)
		n += m_ptab[j]*a[j+1]-m_ptab[j+1]*a[j];
	return n;
}









CVecteur::~CVecteur()
{
	if (m_ptab != NULL)
		delete[] m_ptab;
}

CVecteur operator+(const CVecteur& a, const CVecteur& b)
{
	if (a.m_dimension != b.m_dimension)
	{
		cout << "Erreur ! Les vecteurs n'appartiennent pas au meme espace vectoriel !" << endl;
		return CVecteur();
	}
	double* n;
	n = new double[a.m_dimension];
	for (int i = 0; i < a.m_dimension; i++)
		n[i] = a.m_ptab[i] + b.m_ptab[i];
	return CVecteur(a.m_dimension, n);
}

CVecteur operator-(const CVecteur& a, const CVecteur& b)
{
	if (a.m_dimension != b.m_dimension)
	{
		cout << "Erreur ! Les vecteurs n'appartiennent pas au meme espace vectoriel !" << endl;
		return CVecteur();
	}
	double* n;
	n = new double[a.m_dimension];
	for (int i = 0; i < a.m_dimension; i++)
		n[i] = a.m_ptab[i] - b.m_ptab[i];
	return CVecteur(a.m_dimension, n);
}

double operator*(const CVecteur& a, const CVecteur& b)
{
	if (a.m_dimension != b.m_dimension)
	{
		cout << "Erreur ! Les vecteurs n'appartiennent pas au meme espace vectoriel !" << endl;
		return 0;
	}
	double n=0;
	for (int i = 0; i < a.m_dimension; i++)
		n += a.m_ptab[i] * b.m_ptab[i];
	return n;
}

CVecteur operator*(const CVecteur& a, const double& b)
{
	CVecteur res = a;
	res *= b;
	return res;
}

CVecteur operator/(const CVecteur& a, const double& b)
{
	CVecteur res = a;
	res /= b;
	return res;
}



istream& operator>>(istream& is, CVecteur& a)
{
	cout << "Entrez le nombre de composantes de votre vecteur : ";
	is >> a.m_dimension;
	a.reset();
	for (int i = 0; i < a.m_dimension; i++)
		is >> a.m_ptab[i];
	return is;
}

ostream& operator<<(ostream& os, const CVecteur& a)
{
	//if (a.m_dimension != 0)
	{
		//os << "(";
		os.setf(ios::right | ios::adjustfield);
		for (int i = 0; i < a.m_dimension; i++)
		{
			os << setw(10)<<setprecision(2) << std::left << a.m_ptab[i];
			if (i + 1 < a.m_dimension)
				os << "";
		}
		//os << ")" << endl;
	}
	return os;
}

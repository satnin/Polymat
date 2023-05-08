#include "Fonctions.h"
#include <stdlib.h>
#include <dos.h>
#include <Windows.h>
#include <locale>

#define M 3

int main() {
    setlocale(LC_CTYPE, "fra");

    cout << "Bonjour !\nCe programme vous permettra d'effectuer des op�rations matricielles\n" << (char)169 << "Ben-taieb ghizlane, Polytech Orl�ans." << endl << endl;
    bool continuer = false;
    do
    {
        int choix = 0;
        do
        {
            cout << "\nVeeuillez choisir une op�ration\n1- Addition\n2- Soustraction\n3- Multiplication\n4- Calcul de d�terminant\n5- Calcul d'inverse\n6- Lecture d'un fichier\nR�ponse : ";
            cin >> choix;
        } while (choix < 1 || choix >6);

        switch (choix)
        {
        default:
            break;
        case 1:
        {
            addition();
        }break;
        case 2:
        {
            soustraction();
        }break;
        case 3:
        {
            multiplication();
        }break;
        case 4:
        {
            detcalc();
        }break;
        case 5:
        {
            inversion();
        } break;
        case 6:
        {
            lecture();
        } break;
        }

        do
        {
            int temp = 1;
            cout << "Voulez-vous continuer ? \n1- Oui\n2- Non\nR�ponse : ";
            cin >> temp;
            if (temp == 1)
                continuer = 1;
            else
                continuer = 0;
        } while (continuer != 0 && continuer != 1);

        if (!continuer)
        {
            cout << "\n\nMerci et � bient�t ! \n\n" << (char)169 <<" Ben-taieb ghizlane, Polytech Orl�ans." << endl;
            Sleep(3000);
        }

    } while (continuer);
    return 0;
}
#include <iostream>
#include <ctime>
using namespace std;


int main() // Rasgele sayı üretme
{
    setlocale(LC_ALL, "Turkish");
    srand(time(0));
    /* Mallok komutu
    int eleman = 8;
    int* alt;
    alt = (int*)malloc(eleman * sizeof(int));
    */
    cout << "             1. SORU: Rasgele sayı üretme" << endl << endl;

    int border1, border2, sayac = 0, adet = 0;
    cout << "NOT: Girdiğiniz alt ve üst sınırlar dahildir.\n";
    cout << "NOT2: Alt sınır Üst sınırdan daha küçük olmalıdır.\n\n";
    do {
        if (sayac != 0)
            cout << "   HATA! Alt sınır üst sınırdan daha küçük olmalı\n\n";
        cout << "     Alt sınırı girin : ";
        cin >> border1;
        cout << "     Üst sınırı girin : ";
        cin >> border2;
        sayac++;
    } while (border1 > border2);
    do {
        cout << "     Kaç adet sayı üretmek istediğinizi giriniz : ";
        cin >> adet;
        if (adet <= 0)
            cout << "   HATA! Gidiğiniz sayı sıfırdan daha büyük olmalıdır.\n\n";
    } while (adet <= 0);

    int* randomNumbers;
    randomNumbers = (int*)malloc(adet * sizeof(int)); // adet kadar elemanlı diziyi oluşturduk
    if (border2 - border1 + 1 >= adet) // rasgele sayılardan sadece bir tane olmak zorunda
    {
        for (int i = 0; i < adet; i++) // rasgele sayı üretme ve aynı olmaması durumu
        {
            randomNumbers[i] = border1 + (rand() % (border2 - border1 + 1));
            for (int j = i; j > 0; j--)
            {
                if (randomNumbers[i] == randomNumbers[j - 1])
                {
                    i--;
                    continue;
                }
            }
        }
    }

    else
    {
        for (int i = 0; i < adet; i++)
        {
            int sayi = border1 + (rand() % (border2 - border1 + 1));
            randomNumbers[i] = sayi;
        }
    }

    // diziyi ekrana yazdırma kısmı
    cout << endl << endl << "     " << border1 << " ve " << border2 << " sınır kabul edilerek " << adet << " adet rasgele üretilen sayılar: " << endl;

    for (int i = 0; i < adet; i++)
    {
        cout << "     " << i + 1 << "- " << randomNumbers[i] << endl;
    }


    cout << endl << endl;
    system("pause");
    return 0;
}
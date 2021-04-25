// Programm zum Umwandeln von ganzen Zahlen des Typ Integer in Binärzahlen
// Autor: Fabian Prestros
// Datum: 25.04.2021
#include <stdio.h>

int einlesen(int num)
{
	int chk = 0;					// Rückgabewert zur Fehlermeldung von scanf_s

	do								// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde.
	{
		printf("Umzuwandelnde ganze Zahl vom Typ Integer = ");
		chk = scanf_s("%d", &num);
		while (getchar() != '\n');	// Tastaturpuffer leeren.
		if (chk == 0)				// Fehlermeldung, wenn Zahl kleiner gleich 0 und Rückgabewert = 0 => scanf_s meldet, dass keine Zahl eingegeben wurde.
			printf("Bite geben Sie eine ganze Zahl vom Typ Integer ein!\n");
	} while (chk == 0);				// Schleifendurchlauf, bis kein Fehler mehr vorliegt.
	return num;
}

// Funktion zum Umwandeln von natürlichen Zahlen in Binärzahlen
int umrechnen_in_binaer(int eingabe, int binaer[32])
{
	int zaehler = 0;
	int arbeit = eingabe;

	if (arbeit <= 0)
		arbeit = arbeit * (-1);

	do
	{
		binaer[zaehler] = arbeit % 2;
		arbeit = arbeit / 2;
		zaehler++;
	} while (arbeit != 0);
	return zaehler;
}

zweierkomplement(int binaer[32], int zaehler, int eingabe)
{
	int y = 0;

	if (eingabe <= 0)				// Prüft, ob die Zahl negativ ist
	{
		// Invertieren
		for (int i = zaehler; i >= 0; i--)
		{
			if (binaer[i] == 1)
				binaer[i] = 0;
			else
				binaer[i] = 1;
		}

		binaer[0] = (binaer[0] + 1);
		if (binaer[0] == 2)
		{
			y = 1;
			binaer[0] = 0;
		}

		// Eins addieren
		for (int i = 1; i <= zaehler; i++)
		{
			binaer[i] = (binaer[i] + y);

			if (binaer[i] == 2)
			{
				y = 1;
				binaer[i] = 0;
			}

			else
				y = 0;
		}

	}
}

int main()
{
	int eingabe = 0;
	int binaer[32] = { 0 };

	eingabe = einlesen(eingabe);
	int zaehler = umrechnen_in_binaer(eingabe, binaer);
	zweierkomplement(binaer, zaehler, eingabe);

	// Ausgabe
	printf("Entsprechende Bin\x84rzahl = ");
	for (int i = zaehler; i >= 0; i--)
	{
		printf("%d", binaer[i]);
	}
	printf("\n");
}
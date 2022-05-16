FILE* E, * T, * R, * M;

COORD coord = { 0, 0 };

void gotoxy(int x, int y)
{
	coord.X = x; coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

typedef struct
{
	int Jour, Mois, Annee, Heure, Minute, Seconde;
}Date;

typedef struct
{
	char Nom[32], Prenom[32], Poste[32];
	double Salaire;
	Date Date_embauche;
	long long int Mat;
}Employe;

Employe MINISCULE(char ch[])
{
	int i = 0;
	Employe e;
	for (i = 0;i < strlen(ch);i++)
	{
		if (ch[i] <= 90 && ch[i] >= 65)
		{
			e.Poste[i] = ch[i] + 32;
		}
		else
			e.Poste[i] = ch[i];
	}
	e.Poste[i] = '\0';
	return e;
}
Employe Rechercher_Employe(long long int matr, int msg, int lng)
{
	R = fopen("Employe.txt", "a");
	fclose(R);
	E = fopen("Employe.txt", "r");
	Employe emp;

	while (!feof(E))
	{
		fscanf(E, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
		if (matr == emp.Mat)
		{
			fclose(E);
			return emp;
		}
	}
	if (matr != emp.Mat && msg == 0)
	{
		gotoxy(36, lng);
		printf("\xB2 \aL'employe n'est existe pas.");
		fclose(E);
	}
}
void Supprimer_Employe(long long int matr, int msg)
{
	Employe emp;
	emp = Rechercher_Employe(matr, msg, 7);

	if (emp.Mat == matr)
	{
		T = fopen("Test.txt", "w");
		E = fopen("Employe.txt", "r");
		while (!feof(E))
		{
			fscanf(E, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
			if (emp.Mat != matr)
			{
				fprintf(T, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
			}
		}
		fclose(E);
		fclose(T);

		T = fopen("Test.txt", "r");
		E = fopen("Employe.txt", "w");
		while (!feof(T))
		{
			fscanf(T, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
			fprintf(E, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
		}
		gotoxy(36, 7);
		if (msg == 0)
		{
			printf("\xB2 L'employe supprime !!");
			gotoxy(32, 9);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}

		fclose(T);
		fclose(E);
		T = fopen("Test.txt", "w");
		fclose(T);
	}
	else
	{
		gotoxy(32, 9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}

}

void Ajouter_Employe()
{
	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ajouter Employe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	Employe emp, emp2, emp3, em;
	char ch, ch1, code[32], code1[32], code2[32];
	int i = 0, ct = 0;
	long long int max = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	emp.Date_embauche.Jour = tm.tm_mday, emp.Date_embauche.Mois = tm.tm_mon + 1, emp.Date_embauche.Annee = tm.tm_year + 1900, emp.Date_embauche.Heure = tm.tm_hour, emp.Date_embauche.Minute = tm.tm_min, emp.Date_embauche.Seconde = tm.tm_sec;

	R = fopen("Employe.txt", "a");
	fprintf(R, " 24568525	00	00	00 Dh	00	00/00/00 00:00:00\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
	fclose(R);

	E = fopen("Employe.txt", "r");
	while (!feof(E))
	{
		fscanf(E, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp3.Mat, emp3.Nom, emp3.Prenom, &emp3.Salaire, emp3.Poste, &emp3.Date_embauche.Jour, &emp3.Date_embauche.Mois, &emp3.Date_embauche.Annee, &emp3.Date_embauche.Heure, &emp3.Date_embauche.Minute, &emp3.Date_embauche.Seconde);
		if (emp3.Mat > max)
		{
			max = emp3.Mat;
		}
		ct++;
	}
	fclose(E);
	if (ct <= 3)
	{
		M = fopen("Employe.txt", "a");
		gotoxy(34, 5);
		printf("Entrer nom d'employe : ");
		scanf("%s", emp.Nom);
		gotoxy(34, 7);
		printf("Entrer prenom d'employe : ");
		scanf("%s", emp.Prenom);
		gotoxy(34, 9);
		printf("Entrer salaire d'employe : ");
		scanf("%lf", &emp.Salaire);
		;gotoxy(34, 11);
		printf("Entrer poste d'employe : ");
		scanf("%s", emp.Poste);
		em = MINISCULE(emp.Poste);
		gotoxy(34, 13);
		printf("Entrer mot de passe d'employe : ");

		while (ch != 13)
		{
			ch = getch();

			if (ch != 13 && ch != 8)
			{
				putch('*');
				code1[i] = ch;
				i++;
			}
		}
		code1[i] = '\0';
		gotoxy(34, 15);
		printf("Confirmer mot de passe : ");

		i = 0;
		while (ch1 != 13)
		{
			ch1 = getch();

			if (ch1 != 13 && ch1 != 8)
			{
				putch('*');
				code2[i] = ch1;
				i++;
			}
		}
		code2[i] = '\0';

		if (strcmp(code1, code2) == 0)
		{
			strcpy(code, code1);
			Cryptage(code, em.Poste, 1);

			max = max + 11111111;
			fprintf(M, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", max, emp.Nom, emp.Prenom, emp.Salaire, em.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
		}
		fclose(M);

		if (strcmp(code1, code2) == 0)
		{
			gotoxy(40, 17);
			printf("*** L'employe a ete ajoute. ***");
			gotoxy(32, 19);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
		else if (strcmp(code1, code2) != 0)
		{
			gotoxy(32, 17);
			printf("\xB2 \ales mots de passe ne sont pas identiques.");
			getch();
			Supprimer_Employe(24568525, 1);
			Ajouter_Employe();
		}

	}
	else
	{
		gotoxy(36, 7);
		printf("\xB2 \aListe d'employes est plein.");
		gotoxy(32, 11);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
	Supprimer_Employe(24568525, 1);
}

void Modifier_Employe()
{
	Employe emp;
	int choix;
	long long int mat;

	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier Employe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	gotoxy(34, 5);
	printf("1- Changer poste d'employe.");
	gotoxy(34, 7);
	printf("2- Modifier salaire d'employe.");
	gotoxy(34, 9);
	printf("3- Retour.");
	gotoxy(32, 11);
	printf("***************************************************");
	gotoxy(36, 12);
	printf("\xB2 Taper votre choix : ");
	scanf("%i", &choix);

	if (choix == 1 || choix == 2)
	{
		system("cls");
		gotoxy(32, 3);
		if (choix == 1)
		{
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Changer poste d'employe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
		else if (choix == 2)
		{
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier salaire d'employe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
		gotoxy(34, 5);
		printf("Entrer matricule de l'employe : ");
		scanf("%lli", &mat);

		emp = Rechercher_Employe(mat, 0, 7);

		if (mat == emp.Mat)
		{
			switch (choix)
			{
			case 1:

				T = fopen("Test.txt", "w");
				E = fopen("Employe.txt", "r");
				char poste[32];

				while (!feof(E))
				{
					fscanf(E, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
					fprintf(T, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
				}
				fclose(E);
				fclose(T);
				T = fopen("Test.txt", "r");
				E = fopen("Employe.txt", "w");

				gotoxy(34, 7);
				printf("Entrer nouveau poste : ");
				scanf("%s", poste);

				while (!feof(T))
				{
					fscanf(T, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
					if (mat == emp.Mat)
					{
						fprintf(E, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
					}
					else
					{
						fprintf(E, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
					}
				}
				gotoxy(36, 9);
				printf("\xB2 Poste bien modifie.");
				gotoxy(32, 11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				fclose(T);
				fclose(E);
				T = fopen("Test.txt", "w");
				fclose(T);
				break;
			case 2:
				T = fopen("Test.txt", "w");
				E = fopen("Employe.txt", "r");
				double salaire;

				while (!feof(E))
				{
					fscanf(E, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
					fprintf(T, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
				}
				fclose(E);
				fclose(T);
				T = fopen("Test.txt", "r");
				E = fopen("Employe.txt", "w");

				gotoxy(34, 7);
				printf("Entrer nouveau salaire : ");
				scanf("%lf", &salaire);

				while (!feof(T))
				{
					fscanf(T, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
					if (mat == emp.Mat)
					{
						fprintf(E, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
					}
					else
					{
						fprintf(E, " %lli	%s	%s	%.2lf Dh	%s	%i/%i/%i %i:%i:%i\n", emp.Mat, emp.Nom, emp.Prenom, emp.Salaire, emp.Poste, emp.Date_embauche.Jour, emp.Date_embauche.Mois, emp.Date_embauche.Annee, emp.Date_embauche.Heure, emp.Date_embauche.Minute, emp.Date_embauche.Seconde);
					}
				}
				gotoxy(36, 9);
				printf("\xB2 Salaire bien modifie.");
				gotoxy(32, 11);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				fclose(T);
				fclose(E);
				T = fopen("Test.txt", "w");
				fclose(T);
				break;
			}
		}
		else
		{
			gotoxy(32, 11);
			if (choix == 2)
			{
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			}
			else if (choix == 1)
			{
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			}
		}
	}
	else
	{
		gotoxy(32, 14);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}


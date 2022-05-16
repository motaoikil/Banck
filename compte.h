FILE* Cl, * T, * A, * P, * R, * F;

char ms[20][20] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };

typedef struct
{
	char CIN[32], TypeCpt[32];
	long long int NmCpt;
	double Montant;
	char Dh[10];
	Date Dt_Cmpt;
}Compte;

typedef struct
{
	char Nom[32], TypeCpt[32];
	long long int NmCpt;
	double Montant;
	Date Dt_Cmpt;
	char Dh[10];
}Association;
Employe e, e1;
Date date_()
{
	Date date;
	const char* JourSemaine[] = { "Dimanche", "Lundi", "Mardi", "Mercredi", "Jeudi", "Vendredi", "Samedi" };
	const char* NMois[] = { "Janvier", "Fevrier", "Mars", "Avril", "Mai", "Juin", "Juillet", "Aout", "Septembre", "Octobre", "Novembre", "Decembre" };
	char jour[32], mois[32];

	struct tm* t;
	time_t te = time(NULL);
	struct tm tme = *localtime(&te);
	t = localtime(&te);

	int njour = tme.tm_mday, nmois = tme.tm_mon + 1, nannee = tme.tm_year + 1900;
	float an = (nannee / 100);
	float ann = nannee - (an * 100);
	int n, k, r, h, j;

	strcpy(mois, NMois[t->tm_mon]);
	strcpy(jour, JourSemaine[t->tm_wday]);

	k = ann * 100;
	r = ann;

	if (k == r * 100)
	{
		h = r;
	}
	if (strcmp(mois, "Janvier") == 0 || strcmp(mois, "Mars") == 0 || strcmp(mois, "Mai") == 0 || strcmp(mois, "Juillet") == 0 || strcmp(mois, "Septembre") == 0 || strcmp(mois, "Novembre") == 0)
	{
		if (strcmp(jour, "Vendredi") == 0)
		{
			if (njour + 3 > 31)
			{
				if (strcmp(mois, "Decembre") == 0)
				{
					nannee = nannee + 1;
					nmois = 1;
					j = 3;
				}
				else
				{
					j = 3;
					nmois = nmois + 1;
				}
			}
			else	j = njour + 3;
		}
		else if ((njour + 1) > 31)
		{
			if (strcmp(mois, "Decembre") == 0)
			{
				nannee = nannee + 1;
				nmois = 1;
				j = 1;
			}
			else
			{
				j = 1;
				nmois = nmois + 1;
			}
		}
		else j = njour + 1;
	}

	if (strcmp(mois, "Avril") == 0 || strcmp(mois, "Juin") == 0 || strcmp(mois, "Aout") == 0 || strcmp(mois, "Octobre") == 0 || strcmp(mois, "Decembre") == 0)
	{
		if (strcmp(jour, "Vendredi") == 0)
		{
			if (njour + 3 > 30)
			{
				if (strcmp(mois, "Decembre") == 0)
				{
					nannee = nannee + 1;
					nmois = 1;
					j = 3;
				}
				else
				{
					j = 3;
					nmois = nmois + 1;
				}
			}

			else	j = njour + 3;
		}
		else if ((njour + 1) > 30)
		{
			if (strcmp(mois, "Decembre") == 0)
			{
				nannee = nannee + 1;
				nmois = 1;
				j = 1;
			}
			else
			{
				j = 1;
				nmois = nmois + 1;
			}
		}
		else j = njour + 1;
	}
	if (h % 4 == 0)
	{
		if (strcmp(mois, "Fevrier") == 0)
		{
			if (strcmp(jour, "Vendredi") == 0)
			{
				if (njour + 3 > 29)
				{
					j = 3 - (29 - njour);
					nmois = nmois + 1;
				}
				else	j = njour + 3;
			}
			else if (njour + 1 > 29)
			{
				j = 1;
				nmois = nmois + 1;
			}
			else j = njour + 1;
		}
	}
	else
	{
		if (strcmp(mois, "Fevrier") == 0)
		{
			if (strcmp(jour, "Vendredi") == 0)
			{
				if (njour + 3 > 28)
				{
					j = j = 3 - (28 - njour);
					nmois = nmois + 1;
				}
				else	j = njour + 3;
			}
			else if (njour + 1 > 28)
			{
				j = 1;
				nmois = nmois + 1;
			}
			else j = njour + 1;
		}
	}
	date.Jour = j;
	date.Mois = nmois;
	return date;
}

Compte Rechercher_Compte(char cin[], int msg, int lng)
{
	Compte cmpt;
	e = MINISCULE(cin);

	F = fopen("Compte.txt", "a");
	fclose(F);
	C = fopen("Compte.txt", "r");
	while (!feof(C))
	{
		fscanf(C, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
		if (strcmp(cmpt.CIN, e.Poste) == 0)
		{
			fclose(C);
			return cmpt;
		}
	}
	if (strcmp(cmpt.CIN, e.Poste) != 0 && msg == 0)
	{
		gotoxy(36, lng);
		printf("\xB2 \aCette compte n'est existe pas !!");
		fclose(C);
	}
}
void Supprimer_Compte(char cin[], int msg)
{
	Compte cmpt;
	e = MINISCULE(cin);
	cmpt = Rechercher_Compte(e.Poste, 0, 7);

	if (strcmp(cmpt.CIN, e.Poste) == 0)
	{
		T = fopen("Test.txt", "w");
		C = fopen("Compte.txt", "r");
		while (!feof(C))
		{
			fscanf(C, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
			if (strcmp(cmpt.CIN, e.Poste) != 0)
			{
				fprintf(T, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
			}
		}
		fclose(C);
		fclose(T);
		T = fopen("Test.txt", "r");
		C = fopen("Compte.txt", "w");
		while (!feof(T))
		{
			fscanf(T, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
			fprintf(C, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
		}
		fclose(T);
		fclose(C);
		T = fopen("Test.txt", "w");
		fclose(T);
		if (msg == 0)
		{
			gotoxy(34, 7);
			printf("\a\xB2 Le compte est supprimer.");
		}
	}
	else
	{
		gotoxy(32, 9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}

void Ajouter_Compte()
{
	Compte cmpt, cmpt2;
	Client clr;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	cmpt.Dt_Cmpt.Jour = tm.tm_mday, cmpt.Dt_Cmpt.Mois = tm.tm_mon + 1, cmpt.Dt_Cmpt.Annee = tm.tm_year + 1900, cmpt.Dt_Cmpt.Heure = tm.tm_hour, cmpt.Dt_Cmpt.Minute = tm.tm_min, cmpt.Dt_Cmpt.Seconde = tm.tm_sec;

	strcpy(cmpt.Dh, "Dh");
	long long int max = 0;

	R = fopen("Compte.txt", "a");
	fprintf(R, " 00	2123658978546525	00000 00	00	00/00/00 00:00:00\n");
	fclose(R);

	do
	{
		system("cls");
		gotoxy(32, 3);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ajouter Compte \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(34, 5);
		printf("Entrer CIN de client : ");
		scanf("%s", cmpt.CIN);
		e = MINISCULE(cmpt.CIN);
		clr = Rechercher_Client(e.Poste, 1, 7);

		if (strcmp(clr.CIN, e.Poste) == 0)
		{
			T = fopen("Compte.txt", "r");
			while (!feof(T))
			{
				fscanf(T, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt2.CIN, &cmpt2.NmCpt, &cmpt2.Montant, cmpt2.Dh, cmpt2.TypeCpt, &cmpt2.Dt_Cmpt.Jour, &cmpt2.Dt_Cmpt.Mois, &cmpt2.Dt_Cmpt.Annee, &cmpt2.Dt_Cmpt.Heure, &cmpt2.Dt_Cmpt.Minute, &cmpt2.Dt_Cmpt.Seconde);
				if (cmpt2.NmCpt > max)
				{
					max = cmpt2.NmCpt;
				}
			}
			cmpt.NmCpt = max + 111111111111111;
			fclose(T);

			C = fopen("Compte.txt", "a");

			gotoxy(34, 7);
			printf("Entrer le montant de compte : ");
			scanf("%lf", &cmpt.Montant);
			gotoxy(34, 9);
			printf("Entrer type de compte : ");
			scanf("%s", cmpt.TypeCpt);

			fprintf(C, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", e.Poste, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
			fclose(C);
			Supprimer_Compte("00", 1);

			gotoxy(43, 11);
			printf("*** Compte a ete ajoute. ***");
			gotoxy(32, 13);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
		else
		{
			Supprimer_Compte("00", 1);
			gotoxy(36, 7);
			printf("\a\xB2 Ce client n'est existe");
			gotoxy(48, 8);
			printf("dans la liste des clients.");
			gotoxy(32, 10);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
	} while (strcmp(clr.CIN, e.Poste) == 0);
}
Association Rechercher_association(long long int Nm, int msg, int lng)
{
	Association ass;
	int tr = 0;

	A = fopen("Association.txt", "r");
	while (!feof(A))
	{
		fscanf(A, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
		if (Nm == ass.NmCpt)
		{
			tr++;
			fclose(A);
			return ass;
		}
	}
	if (tr == 0 && msg == 0)
	{
		gotoxy(36, lng);
		printf("\a\xB2 Cette association n'existe pas !!");
		fclose(A);
	}
	fclose(A);
}
void Supprimer_Association(long long int Nm, int msg)
{
	Association ass, ass1;
	ass1 = Rechercher_association(Nm, 0, 7);

	if (Nm == ass1.NmCpt)
	{
		T = fopen("Test.txt", "w");
		A = fopen("Association.txt", "r");
		while (!feof(A))
		{
			fscanf(A, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
			if (ass.NmCpt != Nm)
			{
				fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
			}
		}
		fclose(A);
		fclose(T);
		T = fopen("Test.txt", "r");
		A = fopen("Association.txt", "w");
		while (!feof(T))
		{
			fscanf(T, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
			fprintf(A, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
		}
		fclose(T);
		fclose(A);
		T = fopen("Test.txt", "w");
		fclose(T);

		if (msg == 0)
		{
			gotoxy(36, 7);
			printf("\a\xB2 L'association supprime !!");
		}
	}
}

void Ajouter_association()
{
	Association ass, asr, ass2;
	long long int max = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	ass.Dt_Cmpt.Jour = tm.tm_mday, ass.Dt_Cmpt.Mois = tm.tm_mon + 1, ass.Dt_Cmpt.Annee = tm.tm_year + 1900, ass.Dt_Cmpt.Heure = tm.tm_hour, ass.Dt_Cmpt.Minute = tm.tm_min, ass.Dt_Cmpt.Seconde = tm.tm_sec;
	strcpy(ass.Dh, "Dh");

	R = fopen("Association.txt", "a");
	fprintf(R, " 2534589675231456	00	000 00	00	00/00/00 00:00:00\n");
	fclose(R);

	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ajouter Association \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

	T = fopen("Association.txt", "r");
	while (!feof(T))
	{
		fscanf(T, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass2.NmCpt, ass2.Nom, &ass2.Montant, ass2.Dh, ass2.TypeCpt, &ass2.Dt_Cmpt.Jour, &ass2.Dt_Cmpt.Mois, &ass2.Dt_Cmpt.Annee, &ass2.Dt_Cmpt.Heure, &ass2.Dt_Cmpt.Minute, &ass2.Dt_Cmpt.Seconde);
		if (ass2.NmCpt > max)
		{
			max = ass2.NmCpt;
		}
	}
	ass.NmCpt = max + 111111111111111;
	fclose(T);

	A = fopen("Association.txt", "a");

	gotoxy(34, 5);
	printf("Entrer nom de l'association : ");
	scanf("%s", ass.Nom);
	gotoxy(34, 7);
	printf("Entrer montant de depart : ");
	scanf("%lf", &ass.Montant);
	gotoxy(34, 9);
	printf("Entrer type de compte : ");
	scanf("%s", ass.TypeCpt);

	fprintf(A, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
	fclose(A);
	Supprimer_Association(2534589675231456, 1);

	gotoxy(43, 11);
	printf("*** Association a ete ajoute. ***");
	gotoxy(32, 13);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}
void Consultation_Compte(char cin[], int x, int y)
{
	Compte Cm;
	e = MINISCULE(cin);
	Cm = Rechercher_Compte(e.Poste, 0, 7);
	if (strcmp(Cm.CIN, e.Poste) == 0)
	{
		gotoxy(x, y);
		printf(" _______________________________________________________________________________");
		gotoxy(x, y += 1);
		printf("|     Numero compte     |    Montant    |     Type      |    Date de creation   |");
		gotoxy(x, y += 1);
		printf("|_______________________|_______________|_______________|_______________________|");
		gotoxy(x, y += 1);
		printf("|                       |               |               |                       |");
		gotoxy(x, y += 1);
		printf("| %lli	| %.2lf Dh	| %s	| %i/%i/%i %i:%i:%i	|", Cm.NmCpt, Cm.Montant, Cm.TypeCpt, Cm.Dt_Cmpt.Jour, Cm.Dt_Cmpt.Mois, Cm.Dt_Cmpt.Annee, Cm.Dt_Cmpt.Heure, Cm.Dt_Cmpt.Minute, Cm.Dt_Cmpt.Seconde);
		gotoxy(x, y += 1);
		printf("|_______________________|_______________|_______________|_______________________|");
	}
	else
	{
		gotoxy(20, 9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}
void Consultation_Association(long long int Nm)
{
	Association ass;
	ass = Rechercher_association(Nm, 0, 7);
	if (ass.NmCpt == Nm)
	{
		gotoxy(10, 8);
		printf(" _______________________________________________________________________________________________");
		gotoxy(10, 9);
		printf("|     Numero compte     |    Nom ass    |   Montant     |     Type      |    Date de creation   |");
		gotoxy(10, 10);
		printf("|_______________________|_______________|_______________|_______________|_______________________|");
		gotoxy(10, 11);
		printf("|                       |               |               |               |                       |");
		gotoxy(10, 12);
		printf("| %lli	| %s	| %.2lf %s	| %s	| %i/%i/%i %i:%i:%i	|", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
		gotoxy(10, 13);
		printf("|_______________________|_______________|_______________|_______________|_______________________|");
		gotoxy(10, 15);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
	else
	{
		gotoxy(32, 9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}

void Paiement()
{
	P = fopen("Traitement.txt", "a");
	Compte cmpt, cmp, cmpv;
	Association ass;
	Date date;
	date = date_();
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	cmpt.Dt_Cmpt.Jour = tm.tm_mday, cmpt.Dt_Cmpt.Mois = tm.tm_mon + 1, cmpt.Dt_Cmpt.Annee = tm.tm_year + 1900, cmpt.Dt_Cmpt.Heure = tm.tm_hour, cmpt.Dt_Cmpt.Minute = tm.tm_min, cmpt.Dt_Cmpt.Seconde = tm.tm_sec;

	int choix;
	char cin[24], cinv[24];
	double somme, som;
	double sommev;
	long long int nmcm;


	char oper[] = { "Viresment_vers_mon_compte" };
	char operp[] = { "Recu_versement_vers_mon_cmpt" };
	char operv[] = { "Viresment_vers_autre_compte" };
	char opera[] = { "Viresment_a_une_association" };
	char operas[] = { "Association_verse_a_son_cmpt" };

	system("cls");
	gotoxy(32, 3);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Viresment \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1- Viresment vers mon compte. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2- Viresment vers autre compte. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3- Verse a une association. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xDB\xDB\xB2 4- Association verse a son compte. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 13);
	printf("\xDB\xDB\xDB\xDB\xB2 5- Retour. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 15);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(36, 17);
	printf("\xB2 Taper votre choix : ");
	scanf("%i", &choix);

	if (choix == 1 || choix == 2 || choix == 3 || choix == 4)
	{
		switch (choix)
		{
		case 1:
			do
			{
				system("cls");
				gotoxy(32, 3);
				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Viresment vers mon compte \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
				gotoxy(34, 5);
				printf("Entrer CIN de client : ");
				scanf("%s", cin);
				e = MINISCULE(cin);
				cmp = Rechercher_Compte(e.Poste, 0, 7);
				if (strcmp(cmp.CIN, e.Poste) == 0)
				{
					gotoxy(34, 7);
					printf("Entrer votre somme d'argent : ");
					scanf("%lf", &somme);

					cmp.Montant = cmp.Montant + somme;
					T = fopen("Test.txt", "w");
					C = fopen("Compte.txt", "r");
					while (!feof(C))
					{
						fscanf(C, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
						if (strcmp(cmpt.CIN, cin) != 0)
						{
							fprintf(T, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
						}
					}
					gotoxy(36, 9);
					printf("\xB2\a Le montant verse.");
					gotoxy(32, 11);
					printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
					fprintf(T, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmp.CIN, cmp.NmCpt, cmp.Montant, cmp.Dh, cmp.TypeCpt, cmp.Dt_Cmpt.Jour, cmp.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmp.Dt_Cmpt.Heure, cmp.Dt_Cmpt.Minute, cmp.Dt_Cmpt.Seconde);
					fclose(T);
					fclose(C);
					T = fopen("Test.txt", "r");
					C = fopen("Compte.txt", "w");

					while (!feof(T))
					{
						fscanf(T, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
						fprintf(C, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
					}
					fclose(T);
					fclose(C);
					T = fopen("Test.txt", "w");
					fclose(T);
					fprintf(P, " %s	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", e.Poste, oper, somme, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
					fclose(P);
				}
				else
				{
					gotoxy(32, 9);
					printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
					getch();
				}
			} while (strcmp(cmp.CIN, e.Poste) != 0);
			break;
		case 2:
			system("cls");
			gotoxy(28, 3);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Viresment vers autre compte \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(34, 5);
			printf("Entrer CIN de client : ");
			scanf("%s", cin);
			e = MINISCULE(cin);
			cmp = Rechercher_Compte(e.Poste, 0, 7);
			if (strcmp(cmp.CIN, e.Poste) == 0)
			{
				gotoxy(34, 7);
				printf("Taper CIN de la compte que vous voulez verse : ");
				scanf("%s", cinv);
				e1 = MINISCULE(cinv);
				cmpv = Rechercher_Compte(e1.Poste, 0, 9);
				if (strcmp(cmpv.CIN, cinv) == 0)
				{
					gotoxy(34, 9);
					printf("Taper votre somme d'agrent : ");
					scanf("%lf", &sommev);

					if (cmp.Montant >= sommev)
					{
						Supprimer_Compte(e.Poste, 1);
						Cl = fopen("Compte.txt", "a");
						cmp.Montant = cmp.Montant - sommev;
						fprintf(Cl, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", e.Poste, cmp.NmCpt, cmp.Montant, cmp.Dh, cmp.TypeCpt, cmp.Dt_Cmpt.Jour, cmp.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmp.Dt_Cmpt.Heure, cmp.Dt_Cmpt.Minute, cmp.Dt_Cmpt.Seconde);
						fclose(Cl);

						Supprimer_Compte(e1.Poste, 1);
						C = fopen("Compte.txt", "a");
						cmpv.Montant = cmpv.Montant + sommev;
						fprintf(C, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", e1.Poste, cmpv.NmCpt, cmpv.Montant, cmp.Dh, cmpv.TypeCpt, cmpv.Dt_Cmpt.Jour, cmpv.Dt_Cmpt.Mois, cmpv.Dt_Cmpt.Annee, cmpv.Dt_Cmpt.Heure, cmpv.Dt_Cmpt.Minute, cmpv.Dt_Cmpt.Seconde);
						fclose(C);

						fprintf(P, " %s	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", e.Poste, operv, sommev, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
						fprintf(P, " %s	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", e.Poste, operp, sommev, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
						gotoxy(36, 11);
						printf("\xB2\a Le montant verse.");
						gotoxy(28, 13);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						fclose(P);
					}
					else
					{
						gotoxy(36, 11);
						printf("\xB2\a Montant insuffisant!!");
						gotoxy(28, 13);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
					}
				}
				else
				{
					gotoxy(28, 11);
					printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
				}
			}
			else
			{
				gotoxy(28, 9);
				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			}
			break;
		case 3:
			fclose(P);
			system("cls");
			gotoxy(28, 3);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Verse a une association \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(34, 5);
			printf("Entrer CIN de votre compte : ");
			scanf("%s", cin);
			e = MINISCULE(cin);

			cmp = Rechercher_Compte(e.Poste, 0, 7);
			if (strcmp(cmp.CIN, e.Poste) == 0)
			{
				gotoxy(34, 7);
				printf("Entrer le numero compte de l'association");
				gotoxy(41, 8);
				printf("que vous voulez verse : ");
				scanf("%lli", &nmcm);

				ass = Rechercher_association(nmcm, 0, 10);
				if (ass.NmCpt == nmcm)
				{
					gotoxy(34, 10);
					printf("Taper votre somme d'agrent : ");
					scanf("%lf", &somme);

					if (cmp.Montant < somme)
					{
						gotoxy(36, 12);
						printf("\a\xB2 Montant insuffisant!!");
						gotoxy(28, 14);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
					}
					else
					{
						Supprimer_Compte(cin, 1);
						C = fopen("Compte.txt", "a");
						cmp.Montant = cmp.Montant - somme;
						fprintf(C, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", e.Poste, cmp.NmCpt, cmp.Montant, cmp.Dh, cmp.TypeCpt, cmp.Dt_Cmpt.Jour, cmp.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmp.Dt_Cmpt.Heure, cmp.Dt_Cmpt.Minute, cmp.Dt_Cmpt.Seconde);
						fclose(C);
						fclose(T);
						fclose(A);
						A = fopen("Association.txt", "r");
						T = fopen("Test.txt", "w");
						while (!feof(A))
						{
							fscanf(A, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
							if (ass.NmCpt == nmcm)
							{
								ass.Montant = ass.Montant + somme;
								fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
							}
							else
								fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
						}
						gotoxy(36, 12);
						printf("\xB2\a Le montant verse.");
						gotoxy(28, 14);
						printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
						fclose(T);
						fclose(A);
						T = fopen("Test.txt", "r");
						A = fopen("Association.txt", "w");
						while (!feof(T))
						{
							fscanf(T, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
							fprintf(A, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
						}
						fclose(T);
						fclose(A);
						T = fopen("Test.txt", "w");
						fclose(T);
						P = fopen("Traitement.txt", "a");
						fprintf(P, " %s	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", e.Poste, operp, somme, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
						fclose(P);
						P = fopen("Traitement2.txt", "a");
						fprintf(P, " %lli	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", nmcm, operp, somme, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);

						fclose(P);
					}
				}
				else
				{
					gotoxy(28, 12);
					printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
				}
			}
			else
			{
				gotoxy(28, 9);
				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			}
			break;
		case 4:
			system("cls");
			gotoxy(28, 3);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Verse a une association \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(34, 5);
			printf("Entrer le numero compte de l'association");
			gotoxy(41, 6);
			printf("que vous voulez verse : ");
			scanf("%lli", &nmcm);

			ass = Rechercher_association(nmcm, 0, 8);
			if (ass.NmCpt == nmcm)
			{
				gotoxy(34, 8);
				printf("Taper votre somme d'agrent : ");
				scanf("%lf", &som);
				A = fopen("Association.txt", "r");
				T = fopen("Test.txt", "w");
				while (!feof(A))
				{
					fscanf(A, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
					if (ass.NmCpt == nmcm)
					{
						ass.Montant = ass.Montant + som;
						fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
					}
					else
						fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
				}
				fclose(T);
				fclose(A);
				T = fopen("Test.txt", "r");
				A = fopen("Association.txt", "w");
				while (!feof(T))
				{
					fscanf(T, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
					fprintf(A, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
				}
				fclose(T);
				fclose(A);
				T = fopen("Test.txt", "w");
				fclose(T);
				P = fopen("Traitement2.txt", "a");
				fprintf(P, " %lli	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", nmcm, operas, som, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
				fclose(P);
				gotoxy(36, 10);
				printf("\xB2 Le montant verse.");
				gotoxy(28, 12);
				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");

			}
			else
			{
				gotoxy(28, 10);
				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			}
			break;
		}
	}
	else
	{
		gotoxy(32, 19);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}
void Retrait()
{
	fclose(T);
	fclose(C);
	Compte cmpt, cmp;
	Date date;
	date = date_();
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	cmpt.Dt_Cmpt.Jour = tm.tm_mday, cmpt.Dt_Cmpt.Mois = tm.tm_mon + 1, cmpt.Dt_Cmpt.Annee = tm.tm_year + 1900, cmpt.Dt_Cmpt.Heure = tm.tm_hour, cmpt.Dt_Cmpt.Minute = tm.tm_min, cmpt.Dt_Cmpt.Seconde = tm.tm_sec;

	int choix;
	double agt;
	long long int nm;
	Association ass;
	char cin[12];

	system("cls");
	gotoxy(32, 3);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Retrait \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1- Retrait depuis mon compte. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2- Retrait depuis compte d'association. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3- Retour. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(36, 13);
	printf("\xB2 Taper votre choix : ");
	scanf("%i", &choix);

	char retc[] = { "Retraite__sur_mon__compte" };
	char retas[] = { "Association_Retraite_du_cmpt" };

	if (choix == 1 || choix == 2)
	{
		switch (choix)
		{
		case 1:
			do
			{
				system("cls");
				gotoxy(32, 3);
				printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Retrait depuis mon compte \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
				gotoxy(34, 5);
				printf("Entrer CIN de votre compte : ");
				scanf("%s", cin);
				e = MINISCULE(cin);
				cmp = Rechercher_Compte(e.Poste, 0, 7);
				if (strcmp(cmp.CIN, e.Poste) == 0)
				{
					gotoxy(34, 7);
					printf("Entrer votre somme d'argent : ");
					scanf("%lf", &agt);
					if (cmp.Montant < agt)
					{
						gotoxy(36, 9);
						printf("\xB2\a Montant insuffisant !!");
						gotoxy(32, 11);
						printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					}
					else
					{
						cmp.Montant = cmp.Montant - agt;
						T = fopen("Test.txt", "w");
						C = fopen("Compte.txt", "r");
						while (!feof(C))
						{
							fscanf(C, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
							if (strcmp(cmpt.CIN, e.Poste) != 0)
							{
								fprintf(T, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
							}
						}
						fprintf(T, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", e.Poste, cmp.NmCpt, cmp.Montant, cmp.Dh, cmp.TypeCpt, cmp.Dt_Cmpt.Jour, cmp.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmp.Dt_Cmpt.Heure, cmp.Dt_Cmpt.Minute, cmp.Dt_Cmpt.Seconde);
						fclose(T);
						fclose(C);

						T = fopen("Test.txt", "r");
						C = fopen("Compte.txt", "w");

						while (!feof(T))
						{
							fscanf(T, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
							fprintf(C, " %s	%lli	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, cmpt.NmCpt, cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee, cmpt.Dt_Cmpt.Heure, cmpt.Dt_Cmpt.Minute, cmpt.Dt_Cmpt.Seconde);
						}
						fclose(T);
						fclose(C);
						T = fopen("Test.txt", "w");
						fclose(T);
						gotoxy(36, 9);
						printf("\xB2 Le montant retraite.");
						gotoxy(32, 11);
						printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
						fclose(C);
						P = fopen("Traitement.txt", "a");
						fprintf(P, " %s	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", e.Poste, retc, agt, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
						fclose(P);
					}
				}
				else
				{
					gotoxy(32, 9);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					getch();
				}
			} while (strcmp(cmp.CIN, e.Poste) != 0);
			break;
		case 2:
			fclose(T);
			fclose(A);
			system("cls");
			gotoxy(25, 3);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Retrait depuis compte d'association \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(34, 5);
			printf("Entrer le numero compte de l'association : ");
			scanf("%lli", &nm);
			ass = Rechercher_association(nm, 0, 7);
			if (ass.NmCpt == nm)
			{
				A = fopen("Association.txt", "r");
				T = fopen("Test.txt", "w");

				gotoxy(34, 7);
				printf("Taper la somme d'agrent : ");
				scanf("%lf", &agt);
				if (ass.Montant < agt)
				{
					gotoxy(36, 9);
					printf("\xB2 Montant insuffisant !!");
					gotoxy(25, 11);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				}
				else
				{
					while (!feof(A))
					{
						fscanf(A, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
						if (ass.NmCpt == nm)
						{
							ass.Montant = ass.Montant - agt;
							fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
						}
						else
							fprintf(T, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
					}
					gotoxy(36, 9);
					printf("\xB2 Le montant retraite.");
					gotoxy(25, 11);
					printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
					fclose(T);
					fclose(A);

					T = fopen("Test.txt", "r");
					A = fopen("Association.txt", "w");
					while (!feof(T))
					{
						fscanf(T, " %lli	%s	%lf %s	%s	%i/%i/%i %i:%i:%i\n", &ass.NmCpt, ass.Nom, &ass.Montant, ass.Dh, ass.TypeCpt, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde);
						fprintf(A, " %lli	%s	%.2lf %s	%s	%i/%i/%i %i:%i:%i\n", ass.NmCpt, ass.Nom, ass.Montant, ass.Dh, ass.TypeCpt, ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois, ass.Dt_Cmpt.Annee, ass.Dt_Cmpt.Heure, ass.Dt_Cmpt.Minute, ass.Dt_Cmpt.Seconde);
					}
					fclose(T);
					fclose(A);
					T = fopen("Test.txt", "w");
					fclose(T);
					P = fopen("Traitement2.txt", "a");
					fprintf(P, " %lli	%s	%.2lf	%i/%i/%i %i:%i:%i %i/%i\n", nm, retas, agt, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec, date.Jour, date.Mois);
					fclose(P);
				}
			}
			else
			{
				gotoxy(25, 9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				getch();
			}
			break;
		}
	}
}
void ReleveParMois(char cin[], int mois, int annee)
{
	e = MINISCULE(cin);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Compte cmpt, cmpt1;
	Client cl;
	Date date;
	char oper[50];
	double credit = 0, debit = 0;

	cmpt1 = Rechercher_Compte(e.Poste, 1, 7);
	cl = Rechercher_Client(e.Poste, 1, 7);

	if (strcmp(cmpt1.CIN, e.Poste) == 0 && strcmp(cl.CIN, e.Poste) == 0)
	{
		R = fopen("ReleveParMois.doc", "w");

		fprintf(R, "\t\t\t\t Extrait de compte :\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
		
		fprintf(R, " ______________________\n");
		fprintf(R, "|________ Agence ______|\n");
		fprintf(R, "|                      |\n");
		fprintf(R, "| TIZNIT MY AL HASSAN	|\n");
		fprintf(R, "|  19 AV MLAY HASSAN 	|\n");
		fprintf(R, "|     BEN YOUSSEF   	|\n");
		fprintf(R, "|   05 28 70 85 02 	|\n");
		fprintf(R, "|______________________|\n");
		fprintf(R, "\n");

		fprintf(R, " _______________________________________\n");
		fprintf(R, "|___ Num�ro de compte __|_____ MOIS ____|\n");
		fprintf(R, "|				 |			|\n");
		fprintf(R, "|    %lli	 | %s %i 	|\n", cmpt1.NmCpt, ms[mois - 1], annee);
		fprintf(R, "|_______________________|_______________|\n");

		fprintf(R, "\t\t\t\t\t\t\t\t\t %s %s\n", cl.Prenom, cl.Nom);
		fprintf(R, "\t\t\t\t\t\t\t\t\t %s\n", cl.Adress);
		fprintf(R, "\t\t\t\t\t\t\t\t\t *%lli*\n\n", cmpt1.NmCpt);
		fprintf(R, "Nous avons l'Honneur de vous remettre ci-dessous\nLe relev� de votre Compte : \n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Compte %s\n\n", cmpt1.TypeCpt);
		fprintf(R, " _______________________________________________________________________\n");
		fprintf(R, "|_Dat_|____________ Libell� ____________|_Val_|___ D�bit __|__ Cr�dit __|\n");
		fprintf(R, "|     | 						|     |		  |		   |\n");

		P = fopen("Traitement.txt", "r");
		while (!feof(P))
		{
			fscanf(P, " %s	%s	%lf	%i/%i/%i %i:%i:%i %i/%i\n", cmpt.CIN, oper, &cmpt.Montant, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde, &date.Jour, &date.Mois);
			if (strcmp(cmpt.CIN, e.Poste) == 0 && cmpt.Dt_Cmpt.Mois == mois && cmpt.Dt_Cmpt.Annee == annee)
			{
				fprintf(R, "|%i %i |", cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois);
				if (strcmp(oper, "Viresment_vers_mon_compte") == 0 || strcmp(oper, "Recu_versement_vers_mon_cmpt") == 0)
				{
					credit = credit + cmpt.Montant;
					fprintf(R, "   %s	|%i %i |		  | %.2lf	   |\n", oper, date.Jour, date.Mois, cmpt.Montant);
				}
				else
				{
					debit = debit + cmpt.Montant;
					fprintf(R, "   %s	|%i %i | %.2lf	  |		   |\n", oper, date.Jour, date.Mois, cmpt.Montant);
				}
			}
		}
		fprintf(R, "|_____|_________________________________|_____|____________|____________|\n\n\n");
		fprintf(R, "\t\t\t\t _____________________________________________\n");
		fprintf(R, "\t\t\t\t|   Total  |  Total    |  Solde   |   Solde   |\n");
		fprintf(R, "\t\t\t\t|__ d�bit _|_ cr�dit __|_d�biteur_|_cr�diteur_|\n");
		fprintf(R, "\t\t\t\t|          |           |          |           |\n");

		fprintf(R, "\t\t\t\t| %.2lf	| %.2lf	|", debit, credit);

		if (debit > credit)
		{
			fprintf(R, "      	| %.2lf	|\n", debit - credit);
		}
		else
		{
			fprintf(R, " %.2lf	|      	|\n", debit - credit);
		}

		fprintf(R, "\t\t\t\t|__________|___________|__________|___________|\n");

		fprintf(R, "\n\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Cache d'agence :");

		gotoxy(32, 11);
		printf("\xB2 Le Releve de %s %s a ete cree.", cl.Nom, cl.Prenom);
		gotoxy(36, 13);
		printf("\xB2 Mois : %s", ms[mois - 1]);
		gotoxy(28, 15);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");					
		fclose(R);
		fclose(P);
	}
	fclose(R);
	fclose(P);
}
void ReleveParIntervalle(char cin[])
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Compte cmpt, cmpt1;
	Client cl, cl1, cl2, cl3;
	Date date;
	char opera[50];
	double credit = 0, debit = 0;
	
	e = MINISCULE(cin);
	cmpt1 = Rechercher_Compte(e.Poste, 1, 7);
	cl1 = Rechercher_Client(e.Poste, 1, 7);

	if (strcmp(cmpt1.CIN, e.Poste) == 0 && strcmp(cl1.CIN, e.Poste) == 0)
	{
		gotoxy(34, 7);
		printf("Entrer la date debut : ");
		scanf("%i/%i/%i", &cl2.Dt_Naiss.Jour, &cl2.Dt_Naiss.Mois, &cl2.Dt_Naiss.Annee);
		gotoxy(34, 9);
		printf("Entrer la date fin : ");
		scanf("%i/%i/%i", &cl3.Dt_Naiss.Jour, &cl3.Dt_Naiss.Mois, &cl3.Dt_Naiss.Annee);

		R = fopen("ReleveParIntervalle.doc", "w");
		fprintf(R, "\t\t\t\t Extrait de compte :\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);

		fprintf(R, " ______________________\n");
		fprintf(R, "|________ Agence ______|\n");
		fprintf(R, "|                      |\n");
		fprintf(R, "| TIZNIT MY AL HASSAN	|\n");
		fprintf(R, "|  19 AV MLAY HASSAN 	|\n");
		fprintf(R, "|     BEN YOUSSEF   	|\n");
		fprintf(R, "|   05 28 70 85 02 	|\n");
		fprintf(R, "|______________________|\n");
		fprintf(R, "\n");
		
		fprintf(R, " ________________________________________________________\n");
		fprintf(R, "|___ Num�ro de compte __|_____ Du ______|_____ Au _______|\n");
		fprintf(R, "|				 |           	|           	|\n");
		fprintf(R, "|    %lli	 |   %i/%i/%i	|   %i/%i/%i	|\n", cmpt1.NmCpt, cl2.Dt_Naiss.Jour, cl2.Dt_Naiss.Mois, cl2.Dt_Naiss.Annee, cl3.Dt_Naiss.Jour, cl3.Dt_Naiss.Mois, cl3.Dt_Naiss.Annee);
		fprintf(R, "|_______________________|_______________|________________|\n");
		fprintf(R, "\n");
		
		fprintf(R, "\t\t\t\t\t\t\t\t\t %s %s\n", cl1.Prenom, cl1.Nom);
		fprintf(R, "\t\t\t\t\t\t\t\t\t %s\n", cl1.Adress);
		fprintf(R, "\t\t\t\t\t\t\t\t\t *%lli*\n\n", cmpt1.NmCpt);
		fprintf(R, "Nous avons l'Honneur de vous remettre ci-dessous\nLe relev� de votre Compte : \n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Compte %s\n\n", cmpt1.TypeCpt);
		fprintf(R, " _______________________________________________________________________\n");
		fprintf(R, "|_Dat_|____________ Libell� ____________|_Val_|___ D�bit __|__ Cr�dit __|\n");
		fprintf(R, "|     | 						|     |		  |		   |\n");

		P = fopen("Traitement.txt", "r");
		while (!feof(P))
		{
			fscanf(P, " %s	%s	%lf	%i/%i/%i %i:%i:%i %i/%i\n", cmpt.CIN, opera, &cmpt.Montant, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde, &date.Jour, &date.Mois);
			if (strcmp(e.Poste, cmpt.CIN) == 0 && cmpt.Dt_Cmpt.Jour >= cl2.Dt_Naiss.Jour && cmpt.Dt_Cmpt.Mois >= cl2.Dt_Naiss.Mois && cmpt.Dt_Cmpt.Annee >= cl2.Dt_Naiss.Annee && cmpt.Dt_Cmpt.Jour <= cl3.Dt_Naiss.Jour && cmpt.Dt_Cmpt.Mois <= cl3.Dt_Naiss.Mois && cmpt.Dt_Cmpt.Annee <= cl3.Dt_Naiss.Annee)
			{
				fprintf(R, "|%i %i |", cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois);
				if (strcmp(opera, "Viresment_vers_mon_compte") == 0 || strcmp(opera, "Recu_versement_vers_mon_cmpt") == 0)
				{
					credit = credit + cmpt.Montant;
					fprintf(R, "   %s	|%i %i |		  | %.2lf	   |\n", opera, date.Jour, date.Mois, cmpt.Montant);
				}
				else
				{
					debit = debit + cmpt.Montant;
					fprintf(R, "   %s	|%i %i | %.2lf	  |		   |\n", opera, date.Jour, date.Mois, cmpt.Montant);
				}
			}
		}
		fprintf(R, "|_____|_________________________________|_____|____________|____________|\n\n");
		fprintf(R, "\n");
		fprintf(R, "\t\t\t\t _____________________________________________\n");
		fprintf(R, "\t\t\t\t|   Total  |  Total    |  Solde   |   Solde   |\n");
		fprintf(R, "\t\t\t\t|__ d�bit _|_ cr�dit __|_d�biteur_|_cr�diteur_|\n");
		fprintf(R, "\t\t\t\t|          |           |          |           |\n");

		fprintf(R, "\t\t\t\t| %.2lf	| %.2lf	|", debit, credit);

		if (debit > credit)
		{
			fprintf(R, "      	| %.2lf	|\n", debit - credit);
		}
		else
		{
			fprintf(R, " %.2lf	|      	|\n", debit - credit);
		}

		fprintf(R, "\t\t\t\t|__________|___________|__________|___________|\n");

		fprintf(R, "\n\n\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Cache d'agence :");

		gotoxy(32, 11);
		printf("\xB2 Le Releve de %s %s a ete cree.", cl1.Nom, cl1.Prenom);
		gotoxy(34, 13);
		printf("\xB2 De %i %s %i Au %i %s %i", cl2.Dt_Naiss.Jour, ms[cl2.Dt_Naiss.Mois - 1], cl2.Dt_Naiss.Annee, cl3.Dt_Naiss.Jour, ms[cl3.Dt_Naiss.Mois - 1], cl3.Dt_Naiss.Annee);
		gotoxy(28, 15);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
	fclose(P);
	fclose(R);
}
int GenerRIB(long long int NmCmpt)
{
	int ClRib;

	ClRib = 97 - (((89 * 88) + (15 * 37) + (3 * NmCmpt)) % 97);
	return ClRib;
}

void RIB(char cin[])
{
	e = MINISCULE(cin);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Client cl;
	Compte cmpt;
	char CdBn[] = { "088" };
	char CdVl[] = { "037" };
	int Grb;

	cmpt = Rechercher_Compte(e.Poste, 1, 7);
	cl = Rechercher_Client(e.Poste, 1, 7);

	if (strcmp(cmpt.CIN, e.Poste) == 0)
	{
		R = fopen("RIB.doc", "w");

		fprintf(R, "\t\t\t\tIntitule du compte :\n\n");
		fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
		
		fprintf(R, "\n ______________________\n");
		fprintf(R, "|________ Agence ______|\n");
		fprintf(R, "|                      |\n");
		fprintf(R, "| TIZNIT MY AL HASSAN	|\n");
		fprintf(R, "|  19 AV MLAY HASSAN 	|\n");
		fprintf(R, "|     BEN YOUSSEF   	|\n");
		fprintf(R, "|   05 28 70 85 02 	|\n");
		fprintf(R, "|______________________|\n");
		fprintf(R, "\n");
		
		fprintf(R, "\n\nNom et Pr�nom : %s %s\n", cl.Nom, cl.Prenom);
		Grb = GenerRIB(cmpt.NmCpt);
		GenerRIB(cmpt.NmCpt);
		fprintf(R, "\t\t\t\t\t\t\t\t Compte %s\n\n", cmpt.TypeCpt);
		fprintf(R, "\nRIB :\n %s %s %lli %i\n\n\n", CdBn, CdVl, cmpt.NmCpt, Grb);
		fprintf(R, "\t ________________________________________________________\n");
		fprintf(R, "\t|   Code   |   Code    |        Num�ro        |    Cl�   |\n");
		fprintf(R, "\t|_ Banque _|__ Ville __|_______ Compte _______|___ RIB __|\n");
		fprintf(R, "\t|          |           |                      |          |\n");
		fprintf(R, "\t|    %s	|    %s	|   %lli	|    %i	|\n", CdBn, CdVl, cmpt.NmCpt, Grb);
		fprintf(R, "\t|__________|___________|______________________|__________|\n\n\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t\t Cache d'agence :");

		gotoxy(28, 7);
		printf("\xB2 Releve d'identite bancaire de %s %s a ete cree.", cl.Nom, cl.Prenom);
		gotoxy(28, 9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		fclose(R);
	}
}
void ReleveAssociationMois(long long int Nm, int mois, int annee)
{
	fclose(R);
	fclose(P);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Association ass, ass1;
	Date date;
	char opera[50];
	double credit = 0, debit = 0;

	ass1 = Rechercher_association(Nm, 1, 7);
	if (ass1.NmCpt == Nm)
	{
		R = fopen("ReleveMoisAssociation.doc", "w");
		fprintf(R, "\t\t\t\t Extrait de compte :\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
		
		fprintf(R, " ______________________\n");
		fprintf(R, "|________ Agence ______|\n");
		fprintf(R, "|                      |\n");
		fprintf(R, "| TIZNIT MY AL HASSAN	|\n");
		fprintf(R, "|  19 AV MLAY HASSAN 	|\n");
		fprintf(R, "|     BEN YOUSSEF   	|\n");
		fprintf(R, "|   05 28 70 85 02 	|\n");
		fprintf(R, "|______________________|\n");
		fprintf(R, "\n");
		
		fprintf(R, " _______________________________________\n");
		fprintf(R, "|___ Num�ro de compte __|_____ MOIS ____|\n");
		fprintf(R, "|				 |			|\n");
		fprintf(R, "|    %lli	 | %s %i 	|\n", ass1.NmCpt, ms[mois - 1], annee);
		fprintf(R, "|_______________________|_______________|\n");
		fprintf(R, "\n\n");

		fprintf(R, "\t\t\t\t\t\t\t\t\t %s \n", ass1.Nom);
		fprintf(R, "\t\t\t\t\t\t\t\t\t *%lli*\n\n", ass1.NmCpt);
		fprintf(R, "Nous avons l'Honneur de vous remettre ci-dessous\nLe relev� de votre Compte : \n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Compte %s\n\n\n", ass1.TypeCpt);

		fprintf(R, " _______________________________________________________________________\n");
		fprintf(R, "|_Dat_|____________ Libell� ____________|_Val_|___ D�bit __|__ Cr�dit __|\n");
		fprintf(R, "|     | 						|     |		  |		   |\n");

		P = fopen("Traitement2.txt", "r");
		while (!feof(P))
		{
			fscanf(P, " %lli	%s	%lf	%i/%i/%i %i:%i:%i %i/%i\n", &ass.NmCpt, opera, &ass.Montant, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde, &date.Jour, &date.Mois);
			if ((Nm == ass.NmCpt) && (ass.Dt_Cmpt.Mois == mois) && (ass.Dt_Cmpt.Annee == annee))
			{
				fprintf(R, "|%i %i |", ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois);
				if (strcmp(opera, "Association_verse_a_son_cmpt") == 0 || strcmp(opera, "Recu_versement_vers_mon_cmpt") == 0)
				{
					credit = credit + ass.Montant;
					fprintf(R, "   %s	|%i %i |		  | %.2lf	   |\n", opera, date.Jour, date.Mois, ass.Montant);
				}
				else
				{
					debit = debit + ass.Montant;
					fprintf(R, "   %s	|%i %i | %.2lf	  |		   |\n", opera, date.Jour, date.Mois, ass.Montant);
				}
			}
		}
		fprintf(R, "|_____|_________________________________|_____|____________|____________|\n");
		fprintf(R, "\n\n");
		fprintf(R, "\t\t\t\t _____________________________________________\n");
		fprintf(R, "\t\t\t\t|   Total  |  Total    |  Solde   |   Solde   |\n");
		fprintf(R, "\t\t\t\t|__ d�bit _|_ cr�dit __|_d�biteur_|_cr�diteur_|\n");
		fprintf(R, "\t\t\t\t|          |           |          |           |\n");

		fprintf(R, "\t\t\t\t| %.2lf	| %.2lf	|", debit, credit);

		if (debit > credit)
		{
			fprintf(R, "      	| %.2lf	|\n", debit - credit);
		}
		else
		{
			fprintf(R, " %.2lf	|      	|\n", debit - credit);
		}

		fprintf(R, "\t\t\t\t|__________|___________|__________|___________|\n");

		fprintf(R, "\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Cache d'agence :");

		gotoxy(32, 11);
		printf("\xB2 Le Releve de l'association %s a ete cree.", ass1.Nom);
		gotoxy(36, 13);
		printf("\xB2 Mois : %s", ms[mois - 1]);
		gotoxy(28, 15);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		fclose(R);
		fclose(P);
	}
	fclose(R);
	fclose(P);
}
void ReleveAssociationInter(long long int Nmco)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Association ass, ass1, ass2, ass3;
	Date date;
	char opera[50];
	double credit = 0, debit = 0;

	ass1 = Rechercher_association(Nmco, 0, 7);

	if (ass1.NmCpt == Nmco)
	{
		gotoxy(34, 7);
		printf("Entrer la date debut : ");
		scanf("%i/%i/%i", &ass2.Dt_Cmpt.Jour, &ass2.Dt_Cmpt.Mois, &ass2.Dt_Cmpt.Annee);
		gotoxy(34, 9);
		printf("Entrer la date fin : ");
		scanf("%i/%i/%i", &ass3.Dt_Cmpt.Jour, &ass3.Dt_Cmpt.Mois, &ass3.Dt_Cmpt.Annee);

		R = fopen("ReleveAssociatioInter.doc", "w");
		fprintf(R, "\t\t\t\t Extrait de copmte :\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
		
		fprintf(R, " ______________________\n");
		fprintf(R, "|________ Agence ______|\n");
		fprintf(R, "|                      |\n");
		fprintf(R, "| TIZNIT MY AL HASSAN	|\n");
		fprintf(R, "|  19 AV MLAY HASSAN 	|\n");
		fprintf(R, "|     BEN YOUSSEF   	|\n");
		fprintf(R, "|   05 28 70 85 02 	|\n");
		fprintf(R, "|______________________|\n");
		fprintf(R, "\n");
		
		fprintf(R, " ________________________________________________________\n");
		fprintf(R, "|___ Num�ro de compte __|_____ Du ______|_____ Au _______|\n");
		fprintf(R, "|				 |          	|           	|\n");
		fprintf(R, "|    %lli	 |   %i/%i/%i	|   %i/%i/%i	|\n", ass1.NmCpt, ass2.Dt_Cmpt.Jour, ass2.Dt_Cmpt.Mois, ass2.Dt_Cmpt.Annee, ass3.Dt_Cmpt.Jour, ass3.Dt_Cmpt.Mois, ass3.Dt_Cmpt.Annee);
		fprintf(R, "|_______________________|_______________|________________|\n");
		fprintf(R, "\n\n");

		fprintf(R, "\t\t\t\t\t\t\t\t\t %s\n", ass1.Nom);
		fprintf(R, "\t\t\t\t\t\t\t\t\t *%lli*\n\n", ass1.NmCpt);
		fprintf(R, "Nous avons l'Honneur de vous remettre ci-dessous\nLe relev� de votre Compte : \n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Compte %s\n\n\n\n", ass1.TypeCpt);
		fprintf(R, " _______________________________________________________________________\n");
		fprintf(R, "|_Dat_|____________ Libell� ____________|_Val_|___ D�bit __|__ Cr�dit __|\n");
		fprintf(R, "|     | 						|     |		  |		   |\n");

		P = fopen("Traitement2.txt", "r");
		while (!feof(P))
		{
			fscanf(P, " %lli	%s	%lf	%i/%i/%i %i:%i:%i %i/%i\n", &ass.NmCpt, opera, &ass.Montant, &ass.Dt_Cmpt.Jour, &ass.Dt_Cmpt.Mois, &ass.Dt_Cmpt.Annee, &ass.Dt_Cmpt.Heure, &ass.Dt_Cmpt.Minute, &ass.Dt_Cmpt.Seconde, &date.Jour, &date.Mois);
			if (Nmco == ass.NmCpt && ass.Dt_Cmpt.Jour >= ass2.Dt_Cmpt.Jour && ass.Dt_Cmpt.Mois >= ass2.Dt_Cmpt.Mois && ass.Dt_Cmpt.Annee >= ass2.Dt_Cmpt.Annee && ass.Dt_Cmpt.Jour <= ass3.Dt_Cmpt.Jour && ass.Dt_Cmpt.Mois <= ass3.Dt_Cmpt.Mois && ass.Dt_Cmpt.Annee <= ass3.Dt_Cmpt.Annee)
			{
				fprintf(R, "|%i %i |", ass.Dt_Cmpt.Jour, ass.Dt_Cmpt.Mois);
				if (strcmp(opera, "Association_verse_a_son_cmpt") == 0 || strcmp(opera, "Recu_versement_vers_mon_cmpt") == 0)
				{
					credit = credit + ass.Montant;
					fprintf(R, "   %s	|%i %i |		  | %.2lf	   |\n", opera, date.Jour, date.Mois, ass.Montant);
				}
				else
				{
					debit = debit + ass.Montant;
					fprintf(R, "   %s	|%i %i | %.2lf	  |		   |\n", opera, date.Jour, date.Mois, ass.Montant);
				}

			}
		}
		fprintf(R, "|_____|_________________________________|_____|____________|____________|\n");
	//	fprintf(R, "|_____|_________________________________|_____|____________|____________|\n");

		fprintf(R, "\n");
		fprintf(R, "\t\t\t\t _____________________________________________\n");
		fprintf(R, "\t\t\t\t|   Total  |  Total    |  Solde   |   Solde   |\n");
		fprintf(R, "\t\t\t\t|__ d�bit _|_ cr�dit __|_d�biteur_|_cr�diteur_|\n");
		fprintf(R, "\t\t\t\t|          |           |          |           |\n");

		fprintf(R, "\t\t\t\t| %.2lf	| %.2lf	|", debit, credit);

		if (debit > credit)
		{
			fprintf(R, "      	| %.2lf	|\n", debit - credit);
		}
		else
		{
			fprintf(R, " %.2lf	|      	|\n", debit - credit);
		}

		fprintf(R, "\t\t\t\t|__________|___________|__________|___________|\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t Cache d'agence :");

		gotoxy(32, 11);
		printf("\xB2 Le Releve de l'association %s a ete cree.", ass1.Nom);
		gotoxy(36, 13);
		printf("\xB2 De %i %s %i Au %i %s %i", ass2.Dt_Cmpt.Jour, ms[ass2.Dt_Cmpt.Mois - 1], ass2.Dt_Cmpt.Annee, ass3.Dt_Cmpt.Jour, ms[ass3.Dt_Cmpt.Mois - 1], ass3.Dt_Cmpt.Annee);
		gotoxy(20, 15);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		fclose(R);
		fclose(P);
	}
}
void AssociationRIB(long long int Nmco)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Association ass;
	char CdBn[] = { "088" };
	char CdVl[] = { "037" };
	int code;

	ass = Rechercher_association(Nmco, 1, 7);
	code = GenerRIB(Nmco);

	if (ass.NmCpt == Nmco)
	{
		R = fopen("AssociationRIB.doc", "w");

		fprintf(R, "\t\t\t\tIntitule du compte :\n\n");
		fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
		
		fprintf(R, "\n ______________________\n");
		fprintf(R, "|________ Agence ______|\n");
		fprintf(R, "|                      |\n");
		fprintf(R, "| TIZNIT MY AL HASSAN	|\n");
		fprintf(R, "|  19 AV MLAY HASSAN 	|\n");
		fprintf(R, "|     BEN YOUSSEF   	|\n");
		fprintf(R, "|   05 28 70 85 02 	|\n");
		fprintf(R, "|______________________|\n");
		fprintf(R, "\n");
		
		fprintf(R, "\n\nNom de l'association : %s\n", ass.Nom);
		fprintf(R, "Type de compte : %s\n", ass.TypeCpt);
		fprintf(R, "\nRIB :\n %s %s %lli %i", CdBn, CdVl, ass.NmCpt, code);
		fprintf(R, "\n\n\n\n");
		fprintf(R, "\t ________________________________________________________\n");
		fprintf(R, "\t|   Code   |   Code    |        Num�ro        |    Cl�   |\n");
		fprintf(R, "\t|_ Banque _|__ Ville __|_______ Compte _______|___ RIB __|\n");
		fprintf(R, "\t|          |           |                      |          |\n");
		fprintf(R, "\t|    %s	|    %s	|   %lli	|    %i	|\n", CdBn, CdVl, ass.NmCpt, code);
		fprintf(R, "\t|__________|___________|______________________|__________|\n\n\n\n\n\n\n");
		fprintf(R, "\t\t\t\t\t\t\t\t\t Cache d'agence :");

		gotoxy(32, 7);
		printf("\xB2 Releve d'identite bancaire");
		gotoxy(36, 8);
		printf("de l'association %s a ete cree.", ass.Nom);
		gotoxy(28, 10);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");			
		fclose(R);
	}
}
double Echange()
{
	double som = 0;
	int choix, chx;

	system("cls");
	gotoxy(32, 3);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Echange Devise \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1- Changer vers autre devise. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2- Changer autre devise vers dirham. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3- Retour. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(36, 13);
	printf("\xB2 Taper votre choix : ");
	scanf("%i", &choix);

	if (choix == 1 || choix == 2)
	{
		switch (choix)
		{
		case 1:

			system("cls");
			gotoxy(32, 3);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Echange MAD vers autre Devise \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(32, 5);
			printf("\xDB\xDB\xDB\xDB\xB2 1- MAD vers USD. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 7);
			printf("\xDB\xDB\xDB\xDB\xB2 2- MAD vers EUR. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 9);
			printf("\xDB\xDB\xDB\xDB\xB2 3- MAD vers Livre sterling. \t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 11);
			printf("\xDB\xDB\xDB\xDB\xB2 4- Quitter. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 13);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(36, 15);
			printf("\xB2 Taper votre choix : ");
			scanf("%i", &chx);

			if (chx == 1)
			{
				gotoxy(34, 17);
				printf("Entrer votre somme d'agent : ");
				scanf("%lf", &som);
				som = som / 9.48;
			}
			else if (chx == 2)
			{
				gotoxy(34, 17);
				printf("Entrer votre somme d'agent : ");
				scanf("%lf", &som);
				som = som / 10.71;
			}
			else if (chx == 3)
			{
				gotoxy(34, 17);
				printf("Entrer votre somme d'agent : ");
				scanf("%lf", &som);
				som = som / 12.32;
			}
			else
			{
				gotoxy(32, 17);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			}
			break;
		case 2:
			system("cls");
			gotoxy(32, 3);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Echange Devise vers MAD \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(32, 5);
			printf("\xDB\xDB\xDB\xDB\xB2 1- USD vers MAD. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 7);
			printf("\xDB\xDB\xDB\xDB\xB2 2- EUR vers MAD. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 9);
			printf("\xDB\xDB\xDB\xDB\xB2 3- Livre sterling vers MAD. \t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 11);
			printf("\xDB\xDB\xDB\xDB\xB2 4- Quitter. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
			gotoxy(32, 13);
			printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
			gotoxy(36, 15);
			printf("\xB2 Taper votre choix : ");
			scanf("%i", &chx);

			if (chx == 1)
			{
				gotoxy(34, 17);
				printf("Entrer votre somme d'agent : ");
				scanf("%lf", &som);
				som = som * 9.48;
			}
			else if (chx == 2)
			{
				gotoxy(34, 17);
				printf("Entrer votre somme d'agent : ");
				scanf("%lf", &som);
				som = som * 10.71;
			}
			else if (chx == 3)
			{
				gotoxy(34, 17);
				printf("Entrer votre somme d'agent : ");
				scanf("%lf", &som);
				som = som * 12.32;
			}
			else
			{
				gotoxy(32, 17);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			}
			break;
		}
	}
	else
	{
		gotoxy(32, 15);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
	return som;
}
void Nombre_Compte()
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	Compte cmpt, cmpt3, cmpt2;
	Client cl;
	int i = 0;
	int choix;
	gotoxy(34, 5);
	printf("Entrer la date debut : ");
	scanf("%i/%i/%i", &cmpt2.Dt_Cmpt.Jour, &cmpt2.Dt_Cmpt.Mois, &cmpt2.Dt_Cmpt.Annee);
	gotoxy(34, 7);
	printf("Entrer la date fin : ");
	scanf("%i/%i/%i", &cmpt3.Dt_Cmpt.Jour, &cmpt3.Dt_Cmpt.Mois, &cmpt3.Dt_Cmpt.Annee);

	Cl = fopen("Compte.txt", "r");
	while (!feof(Cl))
	{
		fscanf(Cl, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
		if (cmpt.Dt_Cmpt.Jour >= cmpt2.Dt_Cmpt.Jour && cmpt.Dt_Cmpt.Mois >= cmpt2.Dt_Cmpt.Mois && cmpt.Dt_Cmpt.Annee >= cmpt2.Dt_Cmpt.Annee && cmpt.Dt_Cmpt.Jour <= cmpt3.Dt_Cmpt.Jour && cmpt.Dt_Cmpt.Mois <= cmpt3.Dt_Cmpt.Mois && cmpt.Dt_Cmpt.Annee <= cmpt3.Dt_Cmpt.Annee)
		{
			i++;
		}
	}
	fclose(Cl);
	gotoxy(30, 9);
	printf("\xB2 Nombre comptes existe de %i/%i/%i et %i/%i/%i sont : %i", cmpt2.Dt_Cmpt.Jour, cmpt2.Dt_Cmpt.Mois, cmpt2.Dt_Cmpt.Annee, cmpt3.Dt_Cmpt.Jour, cmpt3.Dt_Cmpt.Mois, cmpt3.Dt_Cmpt.Annee, i);
	
	if(i !=0)
	{
		gotoxy(30, 11);
		printf("\xB2 Pour afficher et imprimer ces comptes taper (1-Oui/ 2-Non) : ");
		scanf("%i", &choix);
		if (choix == 1)
		{
			system("cls");
			gotoxy(32, 3);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Les comptes \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
			T = fopen("Compte.txt", "r");
			R = fopen("ListeCompte.doc", "w");
			
				fprintf(R, "\t\t\t\tListe des comptes :\n\n");
				fprintf(R, "\t\t\t\t\t\t\t Tiznit le : %i/%i/%i %i:%i\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min);
				
				fprintf(R, "\n ______________________________________________________________\n");
				fprintf(R, "|   Numero compte      |     Montant    |   Type   |    Date   |\n");
				fprintf(R, "|______________________|________________|__________|___________|\n");
				fprintf(R, "|                      |                |          |           |\n");

			int x = 22, y = 5;
			while (!feof(T))
			{
				fscanf(T, " %s	%lli	%lf %s	%s	%i/%i/%i %i:%i:%i\n", cmpt.CIN, &cmpt.NmCpt, &cmpt.Montant, cmpt.Dh, cmpt.TypeCpt, &cmpt.Dt_Cmpt.Jour, &cmpt.Dt_Cmpt.Mois, &cmpt.Dt_Cmpt.Annee, &cmpt.Dt_Cmpt.Heure, &cmpt.Dt_Cmpt.Minute, &cmpt.Dt_Cmpt.Seconde);
				if (cmpt.Dt_Cmpt.Jour >= cmpt2.Dt_Cmpt.Jour && cmpt.Dt_Cmpt.Mois >= cmpt2.Dt_Cmpt.Mois && cmpt.Dt_Cmpt.Annee >= cmpt2.Dt_Cmpt.Annee && cmpt.Dt_Cmpt.Jour <= cmpt3.Dt_Cmpt.Jour && cmpt.Dt_Cmpt.Mois <= cmpt3.Dt_Cmpt.Mois && cmpt.Dt_Cmpt.Annee <= cmpt3.Dt_Cmpt.Annee)
				{
					Consultation_Compte(cmpt.CIN, x, y);
					y = y + 8;
					
					fprintf(R,"| %lli	| %.2lf Dh	| %s	| %i/%i/%i	|\n", cmpt.NmCpt, cmpt.Montant, cmpt.TypeCpt, cmpt.Dt_Cmpt.Jour, cmpt.Dt_Cmpt.Mois, cmpt.Dt_Cmpt.Annee);
				}
			}
				fprintf(R, "|______________________|________________|__________|___________|\n");
			
			fclose(T);
			fclose(R);
			gotoxy(22, y);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
		else
		{
			gotoxy(25, 13);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}		
	}
	else
	{
		gotoxy(25, 11);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}

FILE* C, * T;

typedef struct
{
	char CIN[32], Nom[32], Prenom[32], Profession[32], Email[32], Adress[32];
	double Tele;
	Date Dt_Naiss;
}Client;
Employe e;
Client Rechercher_Client(char cin[], int msg, int lng)
{
	e = MINISCULE(cin);
	T = fopen("Client.txt", "a");
	fclose(T);
	C = fopen("Client.txt", "r");
	Client cl;
	while (!feof(C))
	{
		fscanf(C, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
		if (strcmp(cl.CIN, e.Poste) == 0)
		{
			fclose(C);
			return cl;
		}
	}
	if (msg == 0)
	{
		gotoxy(36, lng);
		printf("\a\xB2 Ce client n'est existe pas.");
	}
	fclose(C);
}
void Ajouter_Client()
{
	Client cl, c2;

	do
	{
		system("cls");
		gotoxy(32, 3);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Ajouter Client \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		gotoxy(34, 5);
		printf("Entrer CIN de client : ");
		scanf("%s", cl.CIN);
		e = MINISCULE(cl.CIN);
		c2 = Rechercher_Client(e.Poste, 1, 7);

		if (strcmp(e.Poste, c2.CIN) != 0)
		{
			C = fopen("Client.txt", "a");

			gotoxy(34, 7);
			printf("Entrer prenom de client : ");
			scanf("%s", cl.Prenom);
			gotoxy(34, 9);
			printf("Entrer nom de client : ");
			scanf("%s", cl.Nom);
			gotoxy(34, 11);
			printf("Entrer adress de client : ");
			scanf("%s", cl.Adress);
			gotoxy(34, 13);
			printf("Entrer email de client : ");
			scanf("%s", cl.Email);
			gotoxy(34, 15);
			printf("Entrer telephone de client : ");
			scanf("%lf", &cl.Tele);
			gotoxy(34, 17);
			printf("Entrer la date de naissance de client : ");
			scanf("%i/%i/%i", &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee);
			gotoxy(34, 19);
			printf("Entrer le profession de client : ");
			scanf("%s", cl.Profession);
			fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", e.Poste, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);

			gotoxy(43, 21);
			printf("*** Client a ete ajoute. ***");
		}
		else
		{
			gotoxy(36, 7);
			printf("\a\xB2 Ce client deja existe.");
			getch();
		}
		fclose(C);
	} while (strcmp(e.Poste, c2.CIN) == 0);
	gotoxy(32, 23);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}
void Afficher_Client(char cin[], int x, int y)
{
	e = MINISCULE(cin);
	Client cl;
	cl = Rechercher_Client(e.Poste, 1, 7);
	if (strcmp(cl.CIN, e.Poste) == 0)
	{
		gotoxy(x, y);
		printf(" __________________________________________________________________");
		gotoxy(x, y += 1);
		printf("|    CIN   |      Nom      |    Prenom     |         Adresse       |");
		gotoxy(x, y += 1);
		printf("|__________|_______________|_______________|_______________________|");
		gotoxy(x, y += 1);
		printf("|          |               |               |                       |");
		gotoxy(x, y += 1);
		printf("| %s	| %s	| %s	| %s	|", e.Poste, cl.Prenom, cl.Nom, cl.Adress);
		gotoxy(x, y += 1);
		printf("|__________|_______________|_______________|_______________________|");

		gotoxy(x - 6, y += 2);
		printf(" _______________________________________________________________________________");
		gotoxy(x - 6, y += 1);
		printf("|         Email         |       Telephone       |   Date naiss  |   Profession  |");
		gotoxy(x - 6, y += 1);
		printf("|_______________________|_______________________|_______________|_______________|");
		gotoxy(x - 6, y += 1);
		printf("|                       |                       |               |               |");
		gotoxy(x - 6, y += 1);
		printf("| %s	| (+212)-%.lf	| %i/%i/%i	| %s	|", cl.Email, cl.Tele, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
		gotoxy(x - 6, y += 1);
		printf("|_______________________|_______________________|_______________|_______________|");
		gotoxy(x - 6, y += 2);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}
void Supprimer_Client(char cin[], int msg, int lng)
{
	e = MINISCULE(cin);
	Client cl;
	cl = Rechercher_Client(e.Poste, msg, lng);
	if (strcmp(cl.CIN, e.Poste) == 0)
	{
		T = fopen("Test.txt", "w");
		C = fopen("Client.txt", "r");
		while (!feof(C))
		{
			fscanf(C, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
			if (strcmp(cl.CIN, e.Poste) != 0)
			{
				fprintf(T, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
			}
		}
		fclose(C);
		fclose(T);
		T = fopen("Test.txt", "r");
		C = fopen("Client.txt", "w");
		while (!feof(T))
		{
			fscanf(T, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
			fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
		}
		fclose(T);
		fclose(C);
		T = fopen("Test.txt", "w");
		fclose(T);
		if (msg == 0)
		{
			gotoxy(34, lng);
			printf("\a\xB2 Le client a ete supprime !!");

		}
	}
}
void Modifier_Client()
{
	Client cl, clr;
	int choix;
	char cin[32];

	system("cls");
	gotoxy(32, 3);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB Modifier Client \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(32, 5);
	printf("\xDB\xDB\xB2 1- Changer numero telephone de client. \t\xB2\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xB2 2- Changer adresse de client. \t\t\xB2\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xB2 3- Changer email de client. \t\t\xB2\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xB2 4- Changer profession de client. \t\t\xB2\xDB\xDB");
	gotoxy(32, 13);
	printf("\xDB\xDB\xB2 5- Retour. \t\t\t\t\t\xB2\xDB\xDB");
	gotoxy(32, 15);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	gotoxy(36, 17);
	printf("\xB2 Taper votre choix : ");
	scanf("%i", &choix);

	if (choix == 1 || choix == 2 || choix == 3 || choix == 4)
	{
		gotoxy(34, 19);
		printf("Entrer CIN de client : ");
		scanf("%s", cin);
		e = MINISCULE(cin);
		clr = Rechercher_Client(e.Poste, 0, 21);
		if (strcmp(clr.CIN, e.Poste) == 0)
		{
			switch (choix)
			{
			case 1:
				system("cls");
				gotoxy(28, 3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier numero telephone \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				T = fopen("Test.txt", "w");
				C = fopen("Client.txt", "r");
				while (!feof(C))
				{
					fscanf(C, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					fprintf(T, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				fclose(C);
				fclose(T);
				T = fopen("Test.txt", "r");
				C = fopen("Client.txt", "w");

				double num;
				gotoxy(34, 5);
				printf("Entrer nouveau numero : ");
				scanf("%lf", &num);
				while (!feof(T))
				{
					fscanf(T, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					if (strcmp(cl.CIN, e.Poste) != 0)
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
					else
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, num, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				gotoxy(36, 7);
				printf("\xB2 Le numero telephone est bien modifier.");
				gotoxy(28, 9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				fclose(T);
				fclose(C);
				T = fopen("Test.txt", "w");
				fclose(T);
				break;
			case 2:
				system("cls");
				gotoxy(28, 3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier adresse de client \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				T = fopen("Test.txt", "w");
				C = fopen("Client.txt", "r");
				while (!feof(C))
				{
					fscanf(C, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					fprintf(T, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				fclose(C);
				fclose(T);
				T = fopen("Test.txt", "r");
				C = fopen("Client.txt", "w");

				char adr[24];

				gotoxy(34, 5);
				printf("Entrer la nouvelle adresse : ");
				scanf("%s", adr);
				while (!feof(T))
				{
					fscanf(T, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					if (strcmp(cl.CIN, e.Poste) != 0)
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
					else
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, adr, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				gotoxy(36, 7);
				printf("\xB2 La adresse est bien modifier.");
				gotoxy(28, 9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				fclose(T);
				fclose(C);
				T = fopen("Test.txt", "w");
				fclose(T);
				break;
			case 3:
				system("cls");
				gotoxy(32, 3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier adresse email \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				T = fopen("Test.txt", "w");
				C = fopen("Client.txt", "r");
				while (!feof(C))
				{
					fscanf(C, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					fprintf(T, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				fclose(C);
				fclose(T);
				T = fopen("Test.txt", "r");
				C = fopen("Client.txt", "w");

				char email[24];
				gotoxy(34, 5);
				printf("Entrer nouveau adresse email : ");
				scanf("%s", email);
				while (!feof(T))
				{
					fscanf(T, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					if (strcmp(cl.CIN, e.Poste) != 0)
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
					else
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				gotoxy(36, 7);
				printf("\xB2 Adresse email est bien modifier.");
				gotoxy(32, 9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				fclose(T);
				fclose(C);
				T = fopen("Test.txt", "w");
				fclose(T);
				break;
			case 4:
				system("cls");
				gotoxy(32, 3);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier profession \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				T = fopen("Test.txt", "w");
				C = fopen("Client.txt", "r");
				while (!feof(C))
				{
					fscanf(C, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					fprintf(T, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
				}
				fclose(C);
				fclose(T);
				T = fopen("Test.txt", "r");
				C = fopen("Client.txt", "w");

				char prof[10];
				gotoxy(34, 5);
				printf("Entrer la nouvelle profession : ");
				scanf("%s", prof);

				while (!feof(T))
				{
					fscanf(T, " %s	%s	%s	%s	(+212)-%lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, &cl.Tele, cl.Email, &cl.Dt_Naiss.Jour, &cl.Dt_Naiss.Mois, &cl.Dt_Naiss.Annee, cl.Profession);
					if (strcmp(cl.CIN, e.Poste) != 0)
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, cl.Profession);
					else
						fprintf(C, " %s	%s	%s	%s	(+212)-%.lf	%s	%i/%i/%i	%s\n", cl.CIN, cl.Prenom, cl.Nom, cl.Adress, cl.Tele, cl.Email, cl.Dt_Naiss.Jour, cl.Dt_Naiss.Mois, cl.Dt_Naiss.Annee, prof);
				}
				gotoxy(36, 7);
				printf("\xB2 La profession est bien modifier.");
				gotoxy(32, 9);
				printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
				fclose(T);
				fclose(C);
				T = fopen("Test.txt", "w");
				fclose(T);
				break;
			}
		}
		else
		{
			gotoxy(32, 23);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
	}
	else
	{
		gotoxy(32, 19);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}

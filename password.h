FILE* W, * E;

int Cryptage(char ch[12], char user[12], int cpt)
{
	char tmt2[32], us[32], cd[32];
	int tmt[32];
	int i = 0, j = 0, cp = 0;
	int mt3, mt, mt2;

	while (ch[i] != '\0')
	{
		mt = ch[i];
		if (mt > 85 && mt <= 90)
		{
			mt2 = 90 - mt;
			mt3 = 5 - mt2;
			tmt[j] = mt3 + 64;
		}
		else if (mt > 117 && mt <= 122)
		{
			mt2 = 122 - mt;
			mt3 = 5 - mt2;
			tmt[j] = mt3 + 96;
		}
		else
		{
			tmt[j] = mt + 5;
		}
		i++;
		j++;
	}
	tmt[j] = -1;
	i = 0;
	while (tmt[i] != -1)
	{
		tmt2[i] = tmt[i];
		i++;
	}
	tmt2[i] = '\0';

	W = fopen("Code.txt", "a");
	fprintf(W, " 00	00\n");
	fclose(W);

	W = fopen("Code.txt", "r");
	E = fopen("Test.txt", "w");

	while (!feof(W))
	{
		fscanf(W, " %s	%s\n", us, cd);
		if (strcmp(us, user) != 0 && strcmp(cd, "00") != 0)
		{
			fprintf(E, " %s	%s\n", us, cd);
		}
		if (cpt == 0)
		{
			if (strcmp(us, user) == 0)
			{
				cp++;
			}
		}
	}
	if (cpt == 0)
	{
		if (cp == 0)
		{
			gotoxy(36, 13);
			printf("\a\xB2 L'employe n'existe pas.");
		}
		else
		{
			fprintf(E, " %s	%s\n", user, tmt2);
			gotoxy(36, 13);
			printf("\xB2 Mode passe bien modifie.");
		}
	}
	else
	{
		fprintf(E, " %s	%s\n", user, tmt2);
	}

	fclose(W);
	fclose(E);

	W = fopen("Code.txt", "w");
	E = fopen("Test.txt", "r");

	while (!feof(E))
	{
		fscanf(E, " %s	%s\n", us, cd);
		fprintf(W, " %s	%s\n", us, cd);
	}
	fclose(W);
	fclose(E);

	E = fopen("Test.txt", "w");
	fclose(E);
	return 0;
}

int Decryptage(char user[], int tmt[])
{
	char us[32], cd[32], mt[32];
	int i = 0, j = 0;
	int mt1, mt2;

	W = fopen("Code.txt", "r");
	while (!feof(W))
	{
		fscanf(W, " %s	%s\n", us, cd);
		if (strcmp(us, user) == 0)
		{
			strcpy(mt, cd);
			break;
		}
	}
	fclose(W);

	while (mt[i] != '\0')
	{
		mt1 = mt[i];
		if (mt1 > 64 && mt1 < 70)
		{
			if (mt1 == 'E')
			{
				tmt[i] = 'Z';
			}
			else if (mt1 == 'D')
			{
				tmt[i] = 'Y';
			}
			else if (mt1 == 'C')
			{
				tmt[i] = 'X';
			}
			else if (mt1 == 'B')
			{
				tmt[i] = 'W';
			}
			else if (mt1 == 'A')
			{
				tmt[i] = 'V';
			}
			i++;
		}
		else if (mt1 > 96 && mt1 < 102)
		{
			if (mt1 == 'e')
			{
				tmt[i] = 'z';
			}
			else if (mt1 == 'd')
			{
				tmt[i] = 'y';
			}
			else if (mt1 == 'c')
			{
				tmt[i] = 'x';
			}
			else if (mt1 == 'b')
			{
				tmt[i] = 'w';
			}
			else if (mt1 == 'a')
			{
				tmt[i] = 'v';
			}
			i++;
		}
		else
		{
			tmt[i] = mt1 - 5;
			i++;
		}
	}
	return i;
}

int Password()
{
	char ident[] = { "\xB2 Authentification" };
	char pass1[32];
	char user[32];
	char ch, pass[32];
	int cod[32], ret, k;
	int i = 0, y = 0;
	int j;
	Employe e;

	system("cls");

	gotoxy(29, 4);

	for (j = 0;j < 20;j++)
	{
		delay(20);
		printf("\xDB");
	}
	for (j = 0;j < 20;j++)
	{
		delay(20);
		printf("%c", ident[j]);
	}
	printf(" \xB2");
	for (j = 0;j < 20;j++)
	{
		delay(20);
		printf("\xDB");
	}

	gotoxy(31, 7);
	printf("\xB2 Entrer Nom d'utilisateur : ");
	scanf("%s", user);
	e = MINISCULE(user);

	gotoxy(31, 9);
	printf("\xB2 Entrer Mot de passe : ");

	while (ch != 13)
	{
		ch = getch();

		if (ch != 13 && ch != 8)
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
	}

	pass[i] = '\0';
	ret = Decryptage(e.Poste, cod);

	for (k = 0;k < ret;k++)
	{
		pass1[k] = cod[k];
	}
	pass1[k] = '\0';

	if (strcmp(pass, pass1) == 0 && strcmp(e.Poste, "commercail") == 0)
	{
		y = 2;
	}
	else if (strcmp(pass, pass1) == 0 && strcmp(e.Poste, "directeur") == 0)
	{
		y = 1;
	}
	else if (strcmp(pass, pass1) == 0 && strcmp(e.Poste, "caissier") == 0)
	{
		y = 3;
	}

	if (strcmp(pass, pass1) == 0 && strcmp(e.Poste, "commercail") == 0 || strcmp(pass, pass1) == 0 && strcmp(e.Poste, "directeur") == 0 || strcmp(pass, pass1) == 0 && strcmp(e.Poste, "caissier") == 0)
	{
		gotoxy(32, 12);
		printf("Connexion reussie");
		gotoxy(34, 13);
		printf("Appuyez sur n'importe quelle touche pour continuer.....");
	}
	else
	{
		gotoxy(34, 16);
		printf("\aAttention!! Nom d'utilisateur ou Mot de passe incorrect");
		getch();
		y = Password();
	}
	gotoxy(29, 19);
	printf("\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB");
	getch();
	return y;
}
void Afficher_code()
{
	char code[13], Code1[12], us[12], cd[12], ch1;
	int	Y, X = 22, crpt, i;
	Employe emp;
	int Code[12];

	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Liste de mot de passe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(34, 5);
	printf("Entrer le poste : Directeur ");
	gotoxy(34, 7);
	printf("Entrer le mot de passe : ");

	i = 0;
	while (ch1 != 13)
	{
		ch1 = getch();

		if (ch1 != 13 && ch1 != 8)
		{
			putch('*');
			code[i] = ch1;
			i++;
		}
	}
	code[i] = '\0';

	crpt = Decryptage("directeur", Code);

	for (i = 0; i < crpt; i++)
	{
		Code1[i] = Code[i];
	}

	if (strcmp(code, Code1) != 0)
	{
		gotoxy(36, 9);
		printf("**  \aMot de passe incorrecte **");
		X = 13;
		getch();
	}
	else
	{
		E = fopen("Code.txt", "r");

		system("cls");
		gotoxy(32, 3);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Liste des mots de passe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

		Y = 5;
		while (!feof(E))
		{
			fscanf(E, " %s	%s\n", us, cd);

			gotoxy(38, Y);
			printf("\xB2 Poste : %s", us);

			Y = Y + 2;
			gotoxy(38, Y);
			crpt = Decryptage(us, Code);

			for (i = 0; i < crpt; i++)
			{
				Code1[i] = Code[i];
			}

			Code1[i] = '\0';
			printf("\xB2 Mot de passe : ");

			for (i = 0; i < crpt; i++)
			{
				printf("%c", Code1[i]);
			}
			Y = Y + 4;
		}
		fclose(E);
	}
	gotoxy(32, X);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
}

void Modifier_Code()
{
	Employe emp, emp2, e;
	char ch, ch1, ch2, code[32], code1[32], code2[32], poste[32], CdAn[32], CdAn2[32];
	int i = 0, j, ret[32], mdAn, br = 0;

	system("cls");
	gotoxy(32, 2);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Modifier mode passe \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 (Directeur /Commercail / Caissier) \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(34, 5);
	printf("Entrer poste d'employe : ");
	scanf("%s", poste);
	e = MINISCULE(poste);
	E = fopen("Employe.txt", "r");
	while (!feof(E))
	{
		fscanf(E, " %lli	%s	%s	%lf Dh	%s	%i/%i/%i %i:%i:%i\n", &emp.Mat, emp.Nom, emp.Prenom, &emp.Salaire, emp.Poste, &emp.Date_embauche.Jour, &emp.Date_embauche.Mois, &emp.Date_embauche.Annee, &emp.Date_embauche.Heure, &emp.Date_embauche.Minute, &emp.Date_embauche.Seconde);
		if (strcmp(emp.Poste, e.Poste) == 0)
		{
			fclose(E);
			br++;
			break;
		}
	}
	fclose(E);

	if (br != 0)
	{
		mdAn = Decryptage(e.Poste, ret);
		for (j = 0; j < mdAn; j++)
		{
			CdAn[j] = ret[j];
		}
		CdAn[j] = '\0';

		i = 0;
		gotoxy(34, 7);
		printf("Entrer Ancien mode passe : ");

		while (ch2 != 13)
		{
			ch2 = getch();

			if (ch2 != 13 && ch2 != 8)
			{
				putch('*');
				CdAn2[i] = ch2;
				i++;
			}
		}

		CdAn2[i] = '\0';
		if (strcmp(CdAn2, CdAn) != 0)
		{
			gotoxy(36, 9);
			printf("\a\xB2 Mot de passe incorrecte");
			getch();
			Modifier_Code();
		}

		if (strcmp(CdAn2, CdAn) == 0)
		{
			i = 0;
			gotoxy(34, 9);
			printf("Entrer Nouveau mode passe : ");
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
			gotoxy(34, 11);
			printf("Confirmer Nouveau mot de passe : ");

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
				Cryptage(code, e.Poste, 0);
			}
			else
			{
				gotoxy(32, 13);
				printf("\a*** les mots de passe entres ne sont pas identiques ***");
				getch();
			}
			gotoxy(32, 15);
			printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
		}
	}
	else
	{
		gotoxy(36, 7);
		printf("\a\xB2 Nom de poste d'employe incorrecte");
		gotoxy(32, 9);
		printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	}
}

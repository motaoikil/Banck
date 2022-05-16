void Accueil(char ch)
{
	int i = 0, j = 0;
	while (j != 54)
	{
		gotoxy(35 + i, 1);
		printf("%c", ch);
		i++;
		j++;
		delay(50);
	}

	j = 0;
	while (j != 15)
	{
		gotoxy(31, 2);
		if (j == 0) {                    printf("    %c\t ___________________________________________\t%c", ch, ch);j++; }delay(200);
		if (j == 1) { gotoxy(31, j + 2); printf("    %c\t| **  TDI International Bank of Morocco  ** |\t%c", ch, ch);j++; }delay(200);
		if (j == 2) { gotoxy(31, j + 2); printf("    %c\t|___________________________________________|\t%c", ch, ch);j++; }delay(200);
		if (j == 3) { gotoxy(31, j + 2); printf("    %c\t     \t __________________________\t        %c", ch, ch);j++; }delay(200);
		if (j == 4) { gotoxy(31, j + 2); printf("    %c\t* *\t| ________________________ |\t *****  %c", ch, ch);j++; }delay(200);
		if (j == 5) { gotoxy(31, j + 2); printf("    %c\t* *\t||                        ||\t*     * %c", ch, ch);j++; }delay(200);
		if (j == 6) { gotoxy(31, j + 2); printf("    %c  ******* \t||   Application Gestion  ||\t*       %c", ch, ch);j++; }delay(200);
		if (j == 7) { gotoxy(31, j + 2); printf("    %c * 	* *  \t||     Agence Bancaire    ||  * * * *   %c", ch, ch);j++; }delay(200);
		if (j == 8) { gotoxy(31, j + 2); printf("    %c  ******* \t||________________________||  * * * *   %c", ch, ch);j++; }delay(200);
		if (j == 9) { gotoxy(31, j + 2); printf("    %c\t* *  *\t|__________________________|    *       %c", ch, ch);j++; }delay(200);
		if (j == 10) { gotoxy(31, j + 2); printf("    %c  *******\t\t\t\t        *     * %c", ch, ch);j++; }delay(200);
		if (j == 11) { gotoxy(31, j + 2); printf("    %c\t* *    \t   _______________________ \t *****  %c", ch, ch);j++; }delay(200);
		if (j == 12) { gotoxy(31, j + 2); printf("    %c\t* *   \t *|                       |*\t\t%c", ch, ch);j++; }delay(200);
		if (j == 13) { gotoxy(31, j + 2); printf("    %c\t     \t**|    Realise par :      |**\t        %c", ch, ch);j++; }delay(200);
		if (j == 14) { gotoxy(31, j + 2); printf("    %c\t     \t**| 1- Zakaria Motaoikil  |**\t        %c", ch, ch);j++; }delay(200);
		if (j == 15) { gotoxy(31, j + 2); printf("    %c\t       ***| 2- Abdellah Elbanouge |***\t        %c", ch, ch);j++; }delay(200);
		if (j == 16) { gotoxy(31, j + 2); printf("    %c\t      ****| 3- Farid Aammi        |****\t        %c", ch, ch);j++; }delay(200);
		if (j == 17) { gotoxy(31, j + 2); printf("    %c\t     *****|_______________________|*****        %c", ch, ch);j++; }delay(200);
		if (j == 18) { gotoxy(31, j + 2); printf("    %c\t*****  \t   _______________________ \t*****   %c", ch, ch);j++; }delay(200);
		if (j == 19) { gotoxy(31, j + 2); printf("    %c\t         *|                       |*  \t        %c", ch, ch);j++; }delay(200);
		if (j == 20) { gotoxy(31, j + 2); printf("    %c\t        **|    Encadre par :      |** \t        %c", ch, ch);j++; }delay(200);
		if (j == 21) { gotoxy(31, j + 2); printf("    %c\t       ***| - Mohamed Khalifi     |***\t        %c", ch, ch);j++; }delay(200);
		if (j == 22) { gotoxy(31, j + 2); printf("    %c\t      ****|_______________________|****         %c", ch, ch);j++; }delay(200);
		if (j == 23) { gotoxy(31, j + 2); printf("    %c\t\t\t\t\t\t\t%c", ch, ch);j++; }delay(200);
			int i = 0, j = 0;
	while (j != 54)
	{
		gotoxy(35 + i, 26);
		printf("%c", ch);
		i++;
		j++;
		delay(50);
	}

		getch();
		break;
	}	
}
void Charge_compte()
{
	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Charge compte \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Ajouter client. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Ajouter compte. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Ajouter association. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Afficher les informations d'une compte. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Afficher les informations d'une association. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Modifier les informations d'un client. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Recherche client. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 19);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Supprimer compte. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 21);
	printf("\xDB\xDB\xDB\xDB\xB2 9. Supprimer association. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 23);
	printf("\xDB\xDB\xDB\xDB\xB2 10. Quitter. \t\t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 25);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(37, 27);
}
void Caissier()
{
	system("cls");
	gotoxy(32, 1);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Caissier \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(32, 3);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Versement. \t\t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Retrait. \t\t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Echange devise. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Releve compte Mensuelle. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Releve compte entre deux dates. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 13);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Releve compte association Mensuelle. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 15);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Releve compte association entre deux dates. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 17);
	printf("\xDB\xDB\xDB\xDB\xB2 8. RIB compte. \t\t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 19);
	printf("\xDB\xDB\xDB\xDB\xB2 9. RIB compte association. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 21);
	printf("\xDB\xDB\xDB\xDB\xB2 10. Nombre compte cree entre deux dates. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 23);
	printf("\xDB\xDB\xDB\xDB\xB2 11. Quitter. \t\t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 25);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(38, 27);
}
void  Directeur()
{
	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Directeur \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Ajouter employe. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Modifier employe. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Voir les informations d'un employe. \t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xDB\xDB\xDB\xDB\xB2 4. Supprimer employe. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 13);
	printf("\xDB\xDB\xDB\xDB\xB2 5. Supprimer compte. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 15);
	printf("\xDB\xDB\xDB\xDB\xB2 6. Supprimer association. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 17);
	printf("\xDB\xDB\xDB\xDB\xB2 7. Consulter compte. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 19);
	printf("\xDB\xDB\xDB\xDB\xB2 8. Gestion Mot de passe. \t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 21);
	printf("\xDB\xDB\xDB\xDB\xB2 9. Quitter. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 23);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(37, 25);
}
void  Mode_passe()
{
	system("cls");
	gotoxy(32, 3);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 Directeur \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(32, 5);
	printf("\xDB\xDB\xDB\xDB\xB2 1. Afficher Mode de passe. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 7);
	printf("\xDB\xDB\xDB\xDB\xB2 2. Modifier Mode de passe. \t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 9);
	printf("\xDB\xDB\xDB\xDB\xB2 3. Retour. \t\t\t\t\xB2\xDB\xDB\xDB\xDB");
	gotoxy(32, 11);
	printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	gotoxy(34, 13);
}

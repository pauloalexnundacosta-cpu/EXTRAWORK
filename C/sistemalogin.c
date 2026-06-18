#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

void Menu()
{
    printf("1-Registar\n2-Fazer login\n3-Sair\nEscolha uma opção:");
}

int main()
{
    system("chcp 65001");
    system("cls");

    FILE *login;
    int escolha;
    int i = 0;
    bool sair = false;
    char user[20];
    char senha[12];
    char tecla;
    char user_gd[20];
    char passe_gd[6];

    do
    {
        Menu();
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
        {
            system("cls");
            login = fopen("login.txt", "w");

            if (login != NULL)
            {
                printf("Digite o seu username: ");
                fflush(stdin);
                fgets(user, sizeof(user), stdin);
                user[strcspn(user, "\n")] = '\0';

                printf("Digite sua senha até 12 digitos: ");
                fflush(stdin);
                while (tecla != '\r' && i < 12)
                {
                    tecla = getch();

                    if (tecla != '\r')
                    {
                        senha[i] = tecla;
                        printf("*");
                        i++;
                    }
                }
                senha[i] = '\0';


                fprintf(login, "%s@%s", user, senha);

                fclose(login);

                printf("\nDados guardados com sucesso.\n");
                Sleep(6000);
            }
            else
            {
                printf("Ficheiro não encontrado ou sem permissão para acede-lo.");
            }        
            
            system("cls");
        }
        break;
        


        case 2:
        {
            system("cls");
            login = fopen("login.txt", "r");

            if (login != NULL)
            {
                fscanf(login, "%19[^@]@%19[^\n]", user_gd, passe_gd);
                fclose(login);
            }
            else
            {
                printf("Ficheiro não encontrado ou sem permissão para acede-lo.");
            }

            printf("Digite o seu username: ");
            fflush(stdin);
            fgets(user, sizeof(user), stdin);
            user[strcspn(user, "\n")] = '\0';

            printf("Digite a sua palavra-passe: ");
            fflush(stdin);
            fgets(senha, sizeof(senha), stdin);
            senha[strcspn(senha, "\n")] = '\0';

            if (strcmp(user, user_gd) == 0 && strcmp(senha, passe_gd) == 0)
            {
                printf("Validação efetuada! Bem-vindo/a.\n");
            }
            else
            {
                printf("Username ou palavra-passe incorretas!\n");
            }
        }
        break;

        case 3:
        {
            sair = true;
            printf("Adeus!\n");
        }
        break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    } while (sair == false);

    return 0;
}
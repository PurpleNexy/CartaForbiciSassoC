
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>


void stringaMaiuscola(char amplif[])
{
    int i = 0;
    while (amplif[i] != '\0')
    {
        if (amplif[i] >= 'a' && amplif[i] <= 'z')
        {
            amplif[i] -= 32;
        }
        i++;
    }
}

int main(void)
{
    srand(time(NULL));
    setlocale(LC_ALL, "");
    short modalita, mossaGiocatore, mossaAvversario;
    char ancora = 'M';
    char mossaTesto[][8] = { "nongioc", "CARTA", "FORBICI", "SASSO" };
    char scrittaUtente[] = "cippalip";
    puts("--- CARTA, FORBICI E SASSO ---\n(c) 2024 Lorenzo Brambilla");

    while (ancora == 'M')
    {
        puts("\n\nDigita:\n1) Modalità equa\n2) Modalità favoritissima\n3) Modalità invincibile\n4) Modalità ostile");
        modalita = 0;
        while (!(modalita > 0 && modalita < 5))
        {
            scanf("%hd", &modalita);
        }
        puts("");
        ancora = 'S';
        while (ancora == 'S')
        {
            if (modalita == 1 || modalita == 2)
            {
                mossaAvversario = (rand() % 3) + 1;
                if (modalita == 1)
                {
                    puts("Per garantire la massima correttezza, la mossa del computer è già stata generata, ma rimane nascosta.\n\n");
                }
                else
                {
                    printf("Il computer in questo turno ha già scelto: %s.\nPiù facile di così...?\n\n", mossaTesto[mossaAvversario]);
                }
            }
            mossaGiocatore = -1;
            ancora = 'S';
            puts("Ora è il tuo turno! Digita CARTA, FORBICI o SASSO:");
            while (mossaGiocatore == -1)
            {
                scanf("%8s", scrittaUtente);
                getchar();
                stringaMaiuscola(scrittaUtente);

                for (int verifica = 1; verifica < 4; verifica++)
                {
                    if (strcmp(scrittaUtente, mossaTesto[verifica]) == 0)
                    {
                        mossaGiocatore = verifica;
                    }
                }
            }
            if (modalita == 3)
            { // INVINCIBILE
                switch (mossaGiocatore)
                {
                case 1:
                    mossaAvversario = 3;
                    break;

                case 2:
                    mossaAvversario = 1;
                    break;

                case 3:
                    mossaAvversario = 2;
                    break;
                }
            }

            if (modalita == 4)
            { // OSTILE
                switch (mossaGiocatore)
                {
                case 1:
                    mossaAvversario = 2;
                    break;

                case 2:
                    mossaAvversario = 3;
                    break;

                case 3:
                    mossaAvversario = 1;
                    break;
                }
            }

            if (mossaGiocatore == mossaAvversario)
            {
                printf("\n\nPARI! Sia tu che il computer avete scelto %s.\n\n", mossaTesto[mossaGiocatore]);
            }
            else if ((mossaGiocatore == 1 && mossaAvversario == 3) || (mossaGiocatore == 2 && mossaAvversario == 1) || (mossaGiocatore == 3 && mossaAvversario == 2))
            {
                printf("VITTORIA! Il computer ha scelto %s.\n\n", mossaTesto[mossaAvversario]);
            }
            else
            {
                printf("SCONFITTA! Il computer ha scelto %s.\n\n", mossaTesto[mossaAvversario]);
            }
            puts("Ancora? Digita s per giocare ancora con la stessa modalità, m per sceglierne un'altra, o n per smettere.");
            ancora = 'U';
            mossaGiocatore = -1;
            mossaAvversario = -1;
            while (!(ancora == 'S' || ancora == 'M' || ancora == 'N'))
            {
                scanf("%c", &ancora);
                getchar();
                if (ancora >= 'a' && ancora <= 'z')
                {
                    ancora -= 32;
                }
            }
            puts("\n");
        }
    }
}
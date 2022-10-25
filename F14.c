#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    FILE *fin;
    int index = 0, count = 0, i = 0, indin = -1, indsf = -1, indinv = -1, indsfv = -1;
    size_t nread;
    if (argc != 3)
    {
        fprintf(stderr, "Utilizare: %s sir fisier\n", argv[0]);
        return 2;
    }
    // char *fn = calloc(strlen(argv[2]) + 1, sizeof(char));
    // if (fn == NULL)
    // {
    //     perror(argv[2]);
    //     return 2;
    // }
    // char *str = calloc(strlen(argv[1]) + 1, sizeof(char));
    // if (str == NULL)
    // {
    //     perror(argv[1]);
    //     free(fn);
    //     return 2;
    // }
    char *pos;

    // char *txt=calloc(strlen(argv[1]) + 1, sizeof(char));
    char *txt1 = calloc(2 * (strlen(argv[1]) + 1), sizeof(char));
    char *txt2 = calloc(strlen(argv[1]) + 1, sizeof(char));
    char *txt3 = calloc(strlen(argv[1]) + 1, sizeof(char));
    // strcpy(str, argv[1]);
    // strcpy(fn, argv[2]);
    fin = fopen(argv[2], "r");
    printf("%d\n", strlen(argv[1]));
    // fgets(txt3, strlen(argv[1]) + 1, fin);
    fread(txt3, 1, strlen(argv[1]), fin);
    for(i=1;(nread = fread(txt2, 1, strlen(argv[1]), fin)) > 0;++i)
    // for (i = 1; ((fgets(txt2, strlen(argv[1]) + 1, fin)) != NULL); ++i)
    {
        strcpy(txt1, txt3);
        // fgets(txt2, strlen(argv[1])+1, fin);
        strcat(txt1, txt2);
        index = 0;
        while ((pos = strstr(txt1 + index, argv[1])) != NULL)
        {
            index = (pos - txt1) + 1;
            indin = pos - txt1;
            indsf = indin + strlen(argv[1]) - 1;
            if ((indinv - strlen(argv[1]) != indin) && (indsfv - strlen(argv[1]) != indsf))
                count++;
        }
        // s = false;
        // index = 0;
        // while ((pos = strstr(txt2 + index, argv[1])) != NULL)
        // {
        //     index = (pos - txt2) + 1;
        //     s = true;
        //     break;
        // }
        // if (s != true)
        indinv = indin;
        indsfv = indsf;

        strcpy(txt3, txt2);
        // else
        //     memset(txt3, 0, strlen(txt3));
    }

    printf("%d times in file\n", count);

    return 0;
}
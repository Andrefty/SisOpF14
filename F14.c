#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fin;
    int index = 0, count = 0, indin = -1, indsf = -1, indinv = -1, indsfv = -1;
    char *pos;
    size_t nread, iread;
    if (argc != 3)
    {
        fprintf(stderr, "Utilizare: %s sir fisier\n", argv[0]);
        return 1;
    }
    fin = fopen(argv[2], "r");
    if (fin == NULL)
    {
        perror(argv[2]);
        return 2;
    }
    char *txt1 = calloc(2 * (strlen(argv[1]) + 1), sizeof(char));
    if (txt1 == NULL)
    {
        perror(txt1);
        fclose(fin);
        return 2;
    }
    char *txt2 = calloc(strlen(argv[1]) + 1, sizeof(char));
    if (txt2 == NULL)
    {
        perror(txt2);
        free(txt1);
        fclose(fin);
        return 2;
    }
    char *txt3 = calloc(strlen(argv[1]) + 1, sizeof(char));
    if (txt3 == NULL)
    {
        perror(txt3);
        free(txt1);
        free(txt2);
        fclose(fin);
        return 2;
    }
    iread = fread(txt3, 1, strlen(argv[1]), fin);
    while (((nread = fread(txt2, 1, strlen(argv[1]), fin)) > 0) || (iread > 0))
    {
        strcpy(txt1, txt3);
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
        indinv = indin;
        indsfv = indsf;
        strcpy(txt3, txt2);
        iread = 0;
    }
    printf("De %d ori in fisier\n", count);
    free(txt1);
    free(txt2);
    free(txt3);
    fclose(fin);
    return 0;
}
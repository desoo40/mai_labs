#include "io.h"

int graduate_read_txt(Graduate *gr, FILE *in)
{
    fscanf(in, "%s", gr->surname);
    fscanf(in, "%s", gr->initials);
    fscanf(in, " %c", &(gr->gender));
    fscanf(in, "%d", &(gr->issue));
    fscanf(in, " %c", &(gr->class_letter));
    fscanf(in, "%s", gr->university);

    return !feof(in);
}

int graduate_read_bin(Graduate *gr, FILE *in)
{
    fread(gr->surname, sizeof(char), STR_SIZE, in);
    fread(gr->initials, sizeof(char), STR_SIZE, in);
    fread(&(gr->gender), sizeof(char), 1, in);
    fread(&(gr->issue), sizeof(Date), 1, in);
    fread(&(gr->class_letter), sizeof(char), 1, in);
    fread(gr->university, sizeof(char), STR_SIZE, in);

    return !feof(in);
}

void graduate_write_bin(Graduate *gr, FILE *out)
{
    fwrite(gr->surname,  sizeof(char), STR_SIZE, out);
    fwrite(gr->initials, sizeof(char), STR_SIZE, out);
    fwrite(&(gr->gender), sizeof(char), 1, out);
    fwrite(&(gr->issue), sizeof(Date), 1, out);
    fwrite(&(gr->class_letter), sizeof(char), 1, out);
    fwrite(gr->university, sizeof(char), STR_SIZE, out);
}

void class_print(Class *cl)
{
    printf("%d      %c        %d        %d\n", cl->issue, cl->letter, cl->male_qty, cl->female_qty);
}


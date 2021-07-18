#include <stdlib.h>
#include <stdio.h>

long int findSize(char file_name[])
{
    // opening the file in read mode
    FILE *fp = fopen(file_name, "r");

    // checking if the file exist or not
    if (fp == NULL)
    {
        printf("File Not Found!\n");
        return -1;
    }

    fseek(fp, 0L, SEEK_END);

    // calculating the size of the file
    long int res = ftell(fp);

    // closing the file
    fclose(fp);

    return res;
}

void swap(int *xp, int *yp, char xc[], char yc[])
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    char tempc[20] = *xc;
    *xc = *yc;
    *yc = tempc;
}

void bubbleSort(int arr[], int n, char *names)
{
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1], &names[j], &names[j + 1]);
}

void printArray(char arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%s ", arr[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    char filenames[argc][20];
    long int filesizes[argc];

    // store all the filenames
    for (int i = 1; i <= argc; i++)
    {
        *filenames[i] = argv[i];
    }

    // calc file sizes
    for (int i = 0; i < argc; i++)
    {
        filesizes[i] = findSize(filenames[i]);
    }

    // sort filesize n names array
    bubbleSort(filesizes, argc, filenames);

    // print the filenames
    printArray(filenames, argc);

    return 0;
}
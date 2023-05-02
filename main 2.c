#include <stdio.h>
#include <ctype.h>
#include <string.h>

int read_file(char filename[20],char table[20][20], int row[1], int column[1]);
int calculation(char table[20][20], int row[1], int column[1]);

int main() {
    char filename[20], table[20][20];
    int row[1], column[1];
    read_file(filename, table, row, column);
    calculation(table, row, column);
    return 0;
}

int read_file(char filename[20], char table[20][20], int row[1], int column[1]){
    FILE *fp;
    printf("Enter the name of the file (max:20 char):\n");
    scanf("%s", filename);
    if ((fp= fopen(filename, "r"))==NULL){
        printf("Invalid file");
    }
    fscanf(fp, "%d %d", &row[0], &column[0]);
    for (int i=0;i<row[0];i++){
        for (int j=0; j<column[0]; j++){
            fscanf(fp, "%d", &table[i][j]);
        }
    }
    for (int i=0;i<row[0];i++){
        for (int j=0; j<column[0]; j++){
            printf("%d ", table[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    fclose(fp);
    return 0;
}

int calculation(char table[20][20], int row[1], int column[1]){
    char score_table[0][column[0]];
    int max=0, count=0, first;
    printf("There are %d teams which played for %d days\n", row[0], column[0]);
    for (int g=0;g<column[0];g++){
        score_table[0][g] = 0;
    }
    score_table[0][4]= score_table[0][4]-1;
    for (int i=0;i<column[0];i++){
        for (int j=0;j<row[0];j++){
            score_table[0][j] = score_table[0][j] + table[j][i];
            if (score_table[0][j]>max){
                max = score_table[0][j];
                first = j;
            }
            printf(" ");
            printf("%d", score_table[0][j]);

        }
        count++;
        printf("\nFirst of the day %d is team %d\n", count, first);
        max=0;
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

void printField(int field[9][9]);
void shuffle(int field[9][9]);
void setMarks(int field[9][9], int marks[9][9]);
int countMines(int field[9][9], int i, int j);
void setMask(int field[9][9], int marks[9][9], char mask[9][9]);
void printMask(char mask[9][9]);

int main() {
    
    int field[9][9] = {1,1,1,1,1,1,1,1,1,1,0};
    int marks[9][9];
    char mask[9][9];
    
    shuffle(field);
    printField(field);
    
    setMarks(field, marks);
    printField(marks);
    
    setMask(field, marks, mask);
    printMask(mask);
    
    return 0;
}

void setMarks(int field[9][9], int marks[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            marks[i][j] = countMines(field, i, j);
        }
    }
}

int countMines(int field[9][9], int i, int j){
    int mines = 0;
    
    if(field[i][j] > 0){
        return mines;
    }
    
    _Bool up,down, left, right;
    
    up = i > 0;
    down = i < 8;
    left = j > 0;
    right = j < 8;
    
    if(up){
        mines = mines + field[i-1][j];
        
        if(left){
            mines = mines + field[i-1][j-1];
        }
        
        if(right){
            mines = mines + field[i-1][j+1];
        }
    }
    
    if(down){
        mines = mines + field[i+1][j];
        
        if(left){
            mines = mines + field[i+1][j-1];
        }
        
        if(right){
            mines = mines + field[i+1][j+1];
        }
    }
    
    if(left){
        mines = mines + field[i][j-1];
    }
    
    if(right){
        mines = mines + field[i][j+1];
    }    
    
    return mines;
}

void setMask(int field[9][9], int marks[9][9], char mask[9][9]){
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            
            if(field[i][j] > 0){
                mask[i][j] = '*';
            }else if(marks[i][j]>0){
                switch(marks[i][j]){
                    case 1:
                        mask[i][j] = '1';
                        break;
                    case 2:
                        mask[i][j] = '2';
                        break;                
                    case 3:
                        mask[i][j] = '3';
                        break;                    
                    case 4:
                        mask[i][j] = '4';
                        break;
                    case 5:
                        mask[i][j] = '5';
                        break;                
                    case 6:
                        mask[i][j] = '6';
                        break;                
                    case 7:
                        mask[i][j] = '7';
                        break;            
                    case 8:
                        mask[i][j] = '8';
                        break;                   
                    default:
                        break;
                }
            }else{
                mask[i][j] = '_';
            }
            
        }
    }
    
}


void shuffle(int field[9][9]){
    int irand, jrand, aux;
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            irand = rand()%9;
            jrand = rand()%9;
            
            aux = field[i][j];
            field[i][j] = field[irand][jrand];
            field[irand][jrand] = aux;
        }
    }
    
}

void printField(int field[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%d", field[i][j]);
            
            if(j == 8){
                printf("\n");
            }
        }
    }
    printf("\n");
}

void printMask(char mask[9][9]){
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            printf("%c ", mask[i][j]);
            
            if(j == 8){
                printf("\n");
            }
        }
    }
    printf("\n");    
}

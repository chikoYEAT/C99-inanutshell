#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <ncurses.h>

#define ROWS 20        /*macros*/
#define COLS 15
#define TRUE 1
#define FALSE 0

char Table[ROWS][COLS] = {};
int score = 0;
char GameOn = TRUE;
suseconds_t timer = 400000;
int decrease = 1000;

typedef struct              /* def shape */
{
    char **array;
    int width, row, col;
}Shape;
Shape current;

const Shape ShapesArray[7] = {
    {(char *[]){(char []){0,1,1},(char []){1,1,0}, (char []){0,0,0}}, 3},                           //S shape     
	{(char *[]){(char []){1,1,0},(char []){0,1,1}, (char []){0,0,0}}, 3},                           //Z shape     
	{(char *[]){(char []){0,1,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //T shape     
	{(char *[]){(char []){0,0,1},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //L shape     
	{(char *[]){(char []){1,0,0},(char []){1,1,1}, (char []){0,0,0}}, 3},                           //flipped L shape    
	{(char *[]){(char []){1,1},(char []){1,1}}, 2},                                                 //square shape
	{(char *[]){(char []){0,0,0,0}, (char []){1,1,1,1}, (char []){0,0,0,0}, (char []){0,0,0,0}}, 4} //long bar shape
};

Shape Copyshape(Shape shape){
    Shape new_shape = shape;
    char **copyshape = shape.array;
    new_shape.array = (char **)malloc(new_shape.width*sizeof(char*));
    int i,j;
    for(i = 0; i < new_shape.width; i++){
        new_shape.array[1] = (char *)malloc(new_shape.width*sizeof(char));
        for(j=0 ; j< new_shape.width ; j++){
            new_shape.array[i][j] = copyshape[i][j];
        }
    }
    return new_shape;
};

void Deleteshape(Shape shape){
    int i;
    for(i=0 ; i< shape.width ; i++){
        free(shape.array[i]);
    }
    free(shape.array);
}

int Checkposition (Shape shape){
    char **array = shape.array;
    int i,j;
    for(i= 0 ; i <shape.width; i++){
        for(j = 0; j < shape.width; j++){
            if(shape.col+j <  0 || shape.col+j == COLS || shape.col+i >= ROWS){
                if (array[i][j]){
                    return FALSE;
                }
            }
            else if(Table[shape.row+i][shape.col+j] && array[i][j])
                return FALSE;
            
        }
    }
    return TRUE;
}

void Setradommshape(){
    Shape new_shape = Copyshape(ShapesArray[rand()%7]);
    new_shape.col = rand()%(COLS - new_shape.width - 1);
    new_shape.row = 0;
    Deleteshape(current);
    current = new_shape;
    if(!Checkposition(current)){
        GameOn = FALSE;
    }
}

void Rotateshape(Shape shape){
    Shape temp = Copyshape(shape);
    int i, j , k, width;
    width = shape.width;
    for(i = 0; i < width ; i++){
		for(j = 0, k = width-1; j < width ; j++, k--){
				shape.array[i][j] = temp.array[k][i];
		}
	}
    Deleteshape(temp);
}

void Writetotable(){
    int i,j;
    for(i = 0; i < current.width ; i ++){
        for (j = 0 ; i <current.width ; j ++){
            if(current.array[i][j]){
                Table[current.row+1][current.col+1] = current.array[i][j];
            }
        }
    }
}

void Remfullrowsandupdatescore(){
    int i,j , sum , count =0;
    for (i = 0; i < ROWS ; i ++){
        sum = 0;
        for(j = 0; j< COLS ; j++){
            sum += Table[i][j];
        }
        if (sum == COLS){
            count++;
            int j,k;
            for (k = i; k >= 1; k--){
                for(j =0; j< COLS; j++){
                    Table[k][j] = Table[k-1][j];
                }
            }
            for(j = 0; j< COLS; j++){
                Table[k][j] = 0;
            }
            timer -= decrease;
        }
    }
    score += 100*count;
}

void Printtable(){
    char Buffer[ROWS][COLS] = {0};
    int i,j;
    for(i = 0; i < current.width; i++){
        for (j= 0 ; j < current.width; j++){
            if(current.array[i][j]){
                Buffer[current.row+i][current.col+j] = current.array[i][j];
            }
        }
    }
    clear();
    for(i = 0; COLS-9; i++){
        printw(" ");
    }
    printw("Tetris");
    for( i = 0; i< ROWS; i++){
        for(j = 0; j< COLS ; j++){
            printw("%c",(Table[i][j] + Buffer[i][j])? '#' : '.');
        }
        printw("\n");
    }
    printw("\nScore : %d\n", score);
}

void ManipulateCurrent(int Action){
    Shape temp = Copyshape(current);
    switch(Action){
        case 's':
            temp.row++;
            if(Checkposition(temp)){
                current.row++;
            } else {
                Writetotable();
                Remfullrowsandupdatescore();
                Setradommshape();
            
            }break;
        case 'd':
            temp.col++;
            if(Checkposition(temp)){
                current.col++;
            }
            break;
        case 'a':
            temp.col--;
            if(Checkposition(temp)){
                current.col--;
            }
            break;
        case 'w':
            Rotateshape(temp);
            if(Checkposition(temp)){
                Rotateshape(current);
            }
            break;
    }
    Deleteshape(temp);
    Printtable();
}

struct timeval before_now, now;
int hastoupdate(){
    return((suseconds_t)(now.tv_sec*10000000 + now.tv_usec) - ((suseconds_t)before_now.tv_sec*1000000 +before_now.tv_usec)) > timer;
}

int main(){
    srand(time(0));
    score = 0;
    int c;
    initscr();
    gettimeofday(&before_now, NULL);
    timeout(1);
    Setradommshape();
    Printtable();
    while(GameOn){
        if ((c = getch()) != ERR) {
		  ManipulateCurrent(c);
		}
		gettimeofday(&now, NULL);
		if (hastoupdate()) { 
			ManipulateCurrent('s');
			gettimeofday(&before_now, NULL);
		}
    }
    Deleteshape(current);
    endwin();
    int i,j;
    for(i = 0; i < ROWS;i++){
        for(j = 0; j < COLS; j++){
            printf("%c ", Table[i][j] ? '#': '.');
        }
        printf("\n");
    }
    printf("GameOver\n");
    printf("\nScore: %d\n", score);
    return 0;
}




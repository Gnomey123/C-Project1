/* Maze generator in C.
 * Joe Wingbermuehle
 * 19990805
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Display the maze. */
void makeMazeFile(const char *maze, int width, int height) {
   
   FILE *out;
   
   out = fopen("maze.txt", "w");
   
   int x, y;
   for(y = 0; y < height; y++) {
      for(x = 0; x < width; x++) {
         switch(maze[y * width + x]) {
         case 1:  fputc('|', out);  break;
         case 2:  fputc('$', out);  break;
         default: fputc(' ', out);  break;
         }
      }
      fputc('\n', out);
   }
   fclose(out);
}

/*  Carve the maze starting at x, y. */
void CarveMaze(char *maze, int width, int height, int x, int y) {

   int x1, y1;
   int x2, y2;
   int dx, dy;
   int dir, count;
	int addGold;
   dir = rand() % 4;
   count = 0;
   while(count < 4) {
      dx = 0; dy = 0;
      switch(dir) {
      case 0:  dx = 1;  break;
      case 1:  dy = 1;  break;
      case 2:  dx = -1; break;
      default: dy = -1; break;
      }
      x1 = x + dx;
      y1 = y + dy;
      x2 = x1 + dx;
      y2 = y1 + dy;
      if(   x2 > 0 && x2 < width && y2 > 0 && y2 < height
         && maze[y1 * width + x1] == 1 && maze[y2 * width + x2] == 1) {
         if((rand() % 100) < 15)
         {
         maze[y1 * width + x1] = 2;	
		 }
		 else
		 {
		 maze[y1 * width + x1] = 0;		
		 }
		 
		 if((rand() % 100) < 15)
		 {
		 maze[y2 * width + x2] = 2;
		 }
		 else
		 {
		 maze[y2 * width + x2] = 0;	
		 }
         
         x = x2; y = y2;
         dir = rand() % 4;
         count = 0;
      } else {
         dir = (dir + 1) % 4;
         count += 1;
      }
   }

}

/* Generate maze in matrix maze with size width, height. */
void GenerateMaze(char *maze, int width, int height) {

   int x, y;

   /* Initialize the maze. */
   for(x = 0; x < width * height; x++) {
      maze[x] = 1;
   }
   maze[1 * width + 1] = 0;

   /* Seed the random number generator. */
   srand(time(0));

   /* Carve the maze. */
   for(y = 1; y < height; y += 2) {
      for(x = 1; x < width; x += 2) {
         CarveMaze(maze, width, height, x, y);
      }
   }
}

int mazeGen(int height,int width) {

   char *maze;

   //printf("Maze by Joe Wingbermuehle 19990805\n");

   /* Get and validate the size. */
   width += 3;
   height += 3;

   /* Allocate the maze array. */
   maze = (char*)malloc(width * height * sizeof(char));
   if(maze == NULL) {
      printf("error: not enough memory\n");
      exit(EXIT_FAILURE);
   }

   /* Generate and display the maze. */
   GenerateMaze(maze, width-3, height-3);
   makeMazeFile(maze, width-3, height-3);

   /* Clean up. */
   free(maze);

}
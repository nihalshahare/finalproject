/*****************************************************************************
 * Copyright (C) NIHAL KHEMCHAND SHAHARE shaharenk15.it@coep.ac.in
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#include <stdio.h>

#include <stdlib.h>

char check(void);

void init_matrix(void);

void get_player2_move(void);

void get_player_move(void);

void get_computer_move(void);

void disp_matrix(void);

/* Board formation */

char matrix[3][3];

int main()
{

	int p;
	printf("1=ONE PLAYER\n");

	printf("2=TWO PLAYER\n");
 
	scanf("%d",&p);

	if(p == 1)	
		{
			char done;

			printf("**********TIC TAC TOE**********\n");


			done = ' ';

			init_matrix();

				do {

					disp_matrix();

					get_player_move();

					done = check(); /* see if winner */

					if(done!= ' ') break; /* winner!*/

					get_computer_move();

					done = check(); /* see if winner */

				} while(done== ' ');

				if(done=='X')
 
				 	printf("You won!\n");

				else 

					printf("I won!!!!\n");

				  	disp_matrix(); 

					/* show final positions */
  
					return 0;

		}
			

	if(p == 2)	
	{
			
			char done;

			printf("**********TIC TAC TOE**********\n");

			done = ' ';

			init_matrix();

			disp_matrix();

				do {

					

					get_player_move();

					done = check(); /* see if winner */
					
					disp_matrix();		
					
					if(done!= ' ') break; /* winner!*/
					


					get_player2_move();

					done = check(); /* see if winner */
						
					disp_matrix();


				} while(done== ' ');

				if(done=='X')	

					printf("Player 1 won\n");

				else 

					printf("Player 2 won\n");

					disp_matrix(); 

					/* show final positions */

					return 0;
		}

}
	
void init_matrix(void)

{

int i, j;

for(i=0; i<3; i++)

	for(j=0; j<3; j++) 

		matrix[i][j] = ' ';

}


void disp_matrix(void)

{

int t;

for(t=0; t<3; t++) 
{

	printf(" %c | %c | %c ",matrix[t][0],

	matrix[t][1], matrix [t][2]);

	if(t!=2) 

		printf("\n---|---|---\n");

}

printf("\n");

}


/* Get a player's move. */

void get_player_move(void)

{

int x, y;

printf("Enter X,Y coordinates for your move: ");

scanf("%d%*c%d", &x, &y);

x--; y--;

	if(matrix[x][y]!= ' ')
	{

		printf("Invalid move, try again.\n");

		get_player_move();

	}

	else 

		matrix[x][y] = 'X';

}

/* Get a second player's move. */

void get_player2_move(void)

{

int x, y;

	printf("Player 2 enter X,Y coordinates for your move: ");

	scanf("%d%*c%d", &x, &y);

	x--; y--;

if(matrix[x][y]!= ' '){

	printf("Invalid move, try again.\n");

	get_player_move();

}

else 

	matrix[x][y] = 'O';

}


/* Get a move from the computer. */

void get_computer_move(void)

{

int i, j;

for(i=0; i<3; i++){

	for(j=0; j<3; j++)

		if(matrix[i][j]==' ') break;

			if(matrix[i][j]==' ') break;

}

if(i*j==9) {

	printf("draw\n");

	exit(0);

}

else

	matrix[i][j] = 'O';

}

/* See if there is a winner. */

char check(void)	{

int i;

	/* check rows */

	for(i=0; i<3; i++) 

		if(matrix[i][0]==matrix[i][1] &&

			matrix[i][0]==matrix[i][2]) 

			return matrix[i][0];

	/* check columns */

	for(i=0; i<3; i++) 

		if(matrix[0][i]==matrix[1][i] &&

			matrix[0][i]==matrix[2][i]) 	

			return matrix[0][i];

	/* test diagonals */

	if(matrix[0][0]==matrix[1][1] &&

		matrix[1][1]==matrix[2][2])

		return matrix[0][0];

	if(matrix[0][2]==matrix[1][1] &&

		matrix[1][1]==matrix[2][0])

		return matrix[0][2];

return ' ';

}




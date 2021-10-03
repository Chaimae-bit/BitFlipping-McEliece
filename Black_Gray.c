#include <stdio.h>
#include <stdlib.h>
#include "bitflipiter.h"
#include "bitflipmasckedblackiter.h"
#include "bitflipmasckedgrayiter.h"
#include "CompterNombreEquationViolant_j_eme_bit.h"


#define P 0





int main(int argc, char const *argv[])
{
		//		declaration des vaariables
		int j,i,n,m,k, gama=1;
		int nb_equation_parite_bit=0;
		int** H;
		int* S;
		int* s;
		int* ss;
		int* yy;
		int* Y;
		int* y;
		int* Black;
		int* Gray;
		
		//		les dimensions des matrices 
		
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter m: ");
		scanf("%d", &m);
		
		//		initialisation des matrices
			
		H = (int**) malloc(sizeof(int*)*n);
		 
		for (k=0;k<n;k++)
			H[k]=(int*)malloc(sizeof(int)*m); 
			  
        Y = (int*) malloc(sizeof(int)*m);
        y = (int*) malloc(sizeof(int)*m);
        yy = (int*) malloc(sizeof(int)*m);
        S = (int*) malloc(sizeof(int)*n);
        s = (int*) malloc(sizeof(int)*n);
        ss = (int*) malloc(sizeof(int)*n);
        Black = (int*) malloc(sizeof(int)*m);
        Gray = (int*) malloc(sizeof(int)*m);
        
       for (i=0;i<m;i++){
	  
            Black[i]=0;
            Gray[i]=0;
         }
         
		printf("entrer la matrice H :\n");
		for (i=0;i<n;i++)
			for (j=0;j<m;j++){
				
		    	printf("H[%d][%d]=",i,j);
				scanf("%d",&H[i][j]);
			}
		//		matrice Y
		printf("entrer la matrice Y :\n");
		for (i=0;i<m;i++){
			printf("Y[%d]=",i);
			scanf("%d",&Y[i]);
		}	    
		
//		y=&Y;
//		s=&S;
	for (i=0;i<m;i++){
			y[i]=Y[i];
		}
	for (i=0;i<n;i++){
			s[i]=S[i];
		}
	for (i=0;i<m;i++){
			yy[i]=Y[i];
		}
	for (i=0;i<n;i++){
			ss[i]=S[i];
		}
		
		//		affichage de la matrice H
		printf("*** Matrice H ***\n");
		for (i=0;i<n;i++){
			printf("||\t");
			for (j=0;j<m;j++){
					printf("%d\t",H[i][j]);
					}
				printf("||\n");
		}		
		//		affichage de la matrice Y
		printf("\n*** Matrice Y ***\n");
		printf("||\t");
		for (i=0;i<m;i++){
		
			printf("%d\t",Y[i]);
		}
		printf("||\n");	
		
		printf(" Step I");
		bitflipiter(S,Y,H,Black,Gray,n,m,P);
		
		//		affichage de la matrice Y
		printf("\n*** Matrice Y ***\n");
		printf("||\t");
		for (i=0;i<m;i++){
		
			printf("%d\t",Y[i]);
		}
		printf("||\t");	
		
		//	affichage de la matrice S
		
	//	printf("\n*** Matrice S ***\n");
		//printf("||\t");
		//for (i=0;i<n;i++){
		//	printf("%d\t",S[i]);
	//	}
		//printf("||\t");	
		
		//	affichage de la matrice Black
		
		printf("\n*** Matrice Black ***\n");
		printf("||\t");
		for (i=0;i<m;i++){
			printf("%d\t",Black[i]);
		}
		printf("||\t");	
		
		//	affichage de la matrice Gray
		
		printf("\n*** Matrice Gray ***\n");
		printf("||\t");
		for (i=0;i<m;i++){
			printf("%d\t",Gray[i]);
		}
		printf("||\n");	

//		affichage de Black & Gray 

    	printf(" Step II");
	    bitflipmasckedblackiter(s,y,Black,H,n,m);
	    
	    		//		affichage de la matrice Y
		printf("\n*** Matrice Y en ajoutant le masque Black ***\n");
		printf("||\t");
		for (i=0;i<m;i++){
		
			printf("%d\t",y[i]);
		}
		printf("||\n");	
	   
	    
//	    affichage de 
		printf(" Step III");
		bitflipmasckedgrayiter(ss,yy,Gray,H,n,m);
		
		//		affichage de la matrice Y
		printf("\n*** Matrice y en ajoutant le maqsue Gray ***\n");
		printf("||\t");
		for (i=0;i<m;i++){
		
			printf("%d\t",yy[i]);
		}
		printf("||\n");	
		
		// affihage du syndrome
			printf("\n*** Matrice S ***\n");
		printf("||\t");
		for (i=0;i<n;i++){
			printf("%d\t",ss[i]);
		}
		printf("||\t");	
}


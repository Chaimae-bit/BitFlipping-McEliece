#include <stdio.h>
#include <stdlib.h>
#include "inverseNew.h"
#include "bitflipping.h"

int main(){

	int r,W,i,j,n,m,k,w;
	int **H,**H1,**H0,**MatId,**P,**G;
	int *h0,*h1,*M,*e,*Produit,*C,*S,*D;
	
	printf("entrer dimension de vecteur :");
	scanf("%d", &r);
	n=2*r;
	
	S = (int*) malloc(sizeof(int)*n);
	D = (int*) malloc(sizeof(int)*n);
	C = (int*) malloc(sizeof(int)*n);
    Produit = (int*) malloc(sizeof(int)*n);
	h0 = (int*) malloc(sizeof(int)*r);
	h1 = (int*) malloc(sizeof(int)*r);
	M = (int*) malloc(sizeof(int)*r);
	e = (int*) malloc(sizeof(int)*r);
	
	
		
    MatId=(int**)malloc(sizeof(int*)*r);
    
    for(k=0;k<r;k++){
    	MatId[k]=(int*)malloc(sizeof(int)*r);
	}
    
	H0 = (int**)malloc(sizeof(int*)*r);
		 
	for (k=0;k<r;k++)
			H0[k]=(int*)malloc(sizeof(int)*r);	

	H1 = (int**) malloc(sizeof(int*)*r);
		 
	for (k=0;k<r;k++)
			H1[k]=(int*) malloc(sizeof(int)*r);	
			
	P = (int**) malloc(sizeof(int*)*r);
		 
	for (k=0;k<r;k++)
			P[k]=(int*) malloc(sizeof(int)*r);		

	H = (int**) malloc(sizeof(int*)*r);
		 
	for (k=0;k<n;k++)
			H[k]=(int*) malloc(sizeof(int)*n);
			
	G = (int**) malloc(sizeof(int*)*r);
		 
	for (k=0;k<n;k++)
			G[k]=(int*) malloc(sizeof(int)*n);
		 
		

	
	do {

		printf("entrer la vecteur  h0 \n");
			w=0;
			for(i=0;i<r;i++){
				printf("h0[%d]=",i);
				scanf("%d",&h0[i]);
			}
			for(i=0;i<r;i++){
		        if (h0[i]==1)
				w+=1;
				}
				if(w%2==0)
			printf("le poids doit etre impaire !!! ");
			
    }while(w%2==0);

	do {

		printf("entrer la vecteur  h1 \n");
			w=0;
			for(i=0;i<r;i++){
				printf("h1[%d]=",i);
				scanf("%d",&h1[i]);
			}
			for(i=0;i<r;i++){
		        if (h1[i]==1)
				w+=1;
				}
				if(w%2==0)
			printf("le poids doit etre impaire !!! ");
			
   	}while(w%2==0);

// Affichage des vecteur

	printf("Affichage de la vecteur h0 ");
	printf ("|");
	for(i=0;i<r;i++){
  		printf("%d\t",h0[i]);
	}
	printf("|\n");

	printf("Affichage de la vecteur h1 ");
	printf ("|");
	for(i=0;i<r;i++){
		
		printf("%d\t",h1[i]);
	}
	printf("|\n");
	
// shift
	
// h0 vecteur 
	for (i=0;i<r;i++){
		
		if (i==0){
		for (j=0;j<r;j++)
			H0[i][j]=h0[j];
		}else {
		
		m=0;
	 	for (j=0;j<r;j++){	
		 	
		 	if (m==0){
			 	
				H0[i][j]=H0[i-1][r-1];
				m++;
			}
			else{
				H0[i][j]=H0[i-1][j-1];
				} 	
			}
		}	
	}
	
//affichage de H0
	printf("affichage de H0\n");
 	
 	for (i=0;i<r;i++){
 		for(j=0;j<r;j++){
 			printf("%d\t",H0[i][j]);
		 }
 		 printf("\n");
	 }

//####### h1 vecteur 
	
	for (i=0;i<r;i++){
		
		if (i==0){
		for (j=0;j<r;j++)
			H1[i][j]=h1[j];
		}else {
		
		m=0;
	 	for (j=0;j<r;j++){	
		 	
		 	if (m==0){
			 	
				H1[i][j]=H1[i-1][r-1];
				m++;
			}
			else{
				H1[i][j]=H1[i-1][j-1];
				} 	
			}
		}	
	}
//########	affichage de H1
 	printf("affichage de H1\n");
 	for (i=0;i<r;i++){
 		for(j=0;j<r;j++){
 			printf("%d\t",H1[i][j]);
		 }
 		 printf("\n");
	 }
	 
//######## calcule de H matrice de parity 
	 
	for(i=0;i<r;i++){
	 	for (j=0;j<n;j++){
	 		if (j<r)
	 		H[i][j]=H0[i][j];
	 		else
	 		H[i][j]=H1[i][j-r];
		 }
	 }

	
//######## affichage de la matrice de parity 
	printf("affichage de la matrice de parity \n");
	for (i=0;i<r;i++){
			for (j=0;j<n;j++){
				printf ("%d\t",H[i][j]);	
			}
			printf ("\n");
		}
//######## calcul de la matrice Generatrice 
 
//######## l'inverse de H1

	P=Inverse(r,H1,H0);
	
    printf("affichage de la matrice P \n");
	for (i=0;i<r;i++){
			for (j=0;j<r;j++){
				printf ("%d\t",P[i][j]);	      
			}
			printf ("\n");
		}
		
//	creation de la matrice generatrice G

        MatId=creerMatriceId(r,MatId);
 		for(i=0;i<r;i++){
	 	for (j=0;j<n;j++){
	 		if (j<r)
	 		G[i][j]=MatId[i][j];
	 		else
	 		G[i][j]=P[j-r][i];
		 }
	 } 
//######## affichage de la matrice G 
	printf("affichage de la matrice G \n");
	for (i=0;i<r;i++){
			for (j=0;j<n;j++){
				printf ("%d\t",G[i][j]);	
			}
			printf ("\n");
		}
		
//  creation du message M

	printf("entrer le message M \n");
	
			for(i=0;i<r;i++){
				printf("M[%d]=",i);
				scanf("%d",&M[i]);
        		}

//  creation de l'erreur e

	printf("entrer le vecteur d'erreur e \n");
	
			for(i=0;i<n;i++){
				printf("e[%d]=",i);
				scanf("%d",&e[i]);
        }

//  calcul de Produit M*G  

		for (i=0;i<n;i++){
			Produit[i]=0;
			for (j=0;j<r;j++){
				
				if ((Produit[i]==1 && (M[j]*G[j][i])==1)||(Produit[i]==0 && (M[j]*G[j][i])==0)){
				
				    Produit[i]=0;
				}
				else {
					
					Produit[i]=1;
				}
			}
		}
//    Affichage du produit 	


		printf("Affichage du produit \n");
		printf ("|\t");
	for(i=0;i<n;i++){
  		printf("%d\t",Produit[i]);
	}
	printf("|\n");
	
//    calcul de Msg chi	
		
	for(i=0;i<n;i++){
		
		if((e[i]==0 && Produit[i]==0 )|| (e[i]==1 && Produit[i]==1 ))
			C[i]=0;
		else
			C[i]=1;
		}
//    Affichage du msg chiff  	


		printf("Affichage du msg chiff \n");
		printf ("|\t");
	for(i=0;i<n;i++){
  		printf("%d\t",C[i]);
	}
	printf("|\n");
	
// dechiff  (Bitflipping )   

	
	if (BitFlipping(n,r,w,H,C,S)==1)	
	{
	printf ("\nsucces du decryptage  !\n ");
	printf("\nAffichage du msg Dechiff \n");
	printf ("|\t");
	for(i=0;i<r;i++){
  		printf("%d\t",M[i]);
	}
	printf ("|\t");
	}else {
		printf ("\nechec de decodage\n ");
	}
	
	

    	
}








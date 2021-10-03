#include <stdio.h>
#include <stdlib.h>
#define P 0

int CompterNombreEquationViolant_j_eme_bit(int j,int n,int m,int** H,int* Y);
float computeTTL(int gama);

int main(int argc, char const *argv[])
{
		//		declaration des vaariables
		int j,i,n,m,k,b,Maxupc=0, Gama;
		float time=1,affiche;
		int nb_equation_parite_bit=0;
		float* ttl;
		int** H;
		int* S;
		int* Y;

		//		les dimensions des matrices 
		
		printf("Enter n: ");
		scanf("%d", &n);
		printf("Enter m: ");
		scanf("%d", &m);
		
		//		initialisation des matrices
			
		H = (int**) malloc(sizeof(int*)*n);
		 		
		ttl = (float*) malloc(sizeof(float)*m);
		 
		for (k=0;k<n;k++)
			H[k]=(int*)malloc(sizeof(int)*m); 
			  
        Y = (int*) malloc(sizeof(int)*m);
        S = (int*) malloc(sizeof(int)*n);
		printf("entrer la matrice H :\n\n");
		for (i=0;i<n;i++)\
			for (j=0;j<m;j++){
				
		    	printf("H[%d][%d]=",i,j);
				scanf("%d",&H[i][j]);
			}
		//		matrice Y
		printf("entrer la matrice Y :\n\n");
		for (i=0;i<m;i++){
			printf("Y[%d]=",i);
			scanf("%d",&Y[i]);
		}	    
		//		affichage de la matrice H
		printf("*** Matrice H ***\n\n");
		for (i=0;i<n;i++){
			printf("||\t");
			for (j=0;j<m;j++){
					printf("%d\t",H[i][j]);
					}
				printf("||\n");
		}		
		//		affichage de la matrice Y
		printf("\n*** Matrice Y ***\n\n");
		printf("||\t");
		for (i=0;i<m;i++){
		
			printf("%d\t",Y[i]);
		}
		printf("||\t");	
		//	 calcul de Syndrome 
		for (i=0;i<n;i++){
			S[i]=0;
			for (j=0;j<m;j++){
				
				if ((S[i]==1 && (H[i][j]*Y[j])==1)||(S[i]==0 && (H[i][j]*Y[j])==0)){
				
				    S[i]=0;
				}
				else {
					
					S[i]=1;
				}
			}
		}
		//	affichage de la matrice S
		printf("\n*** Matrice S ***\n\n");
		printf("||\t");
		for (i=0;i<n;i++){
			printf("%d\t",S[i]);
		}
		printf("||\t");	
		
		//	calcul max upc 	
		
		for (i=0;i<n;i++){
		
			if(S[i]==1)
			Maxupc=Maxupc+1;
			else 
			continue;
		}
		printf (" \n\nMaxupc=%d",Maxupc);
		if (Maxupc==0){
			printf ("\n\n Syndrome null donc il y pas d\'erreur");
		}else {
				// calcul de b
				printf ("\n\nsyndrome non null donc il y a des erreurs a corriger");
				b = Maxupc-P;
				printf ("\n\nb=%d",b);
				
				do{ 
					for (j=0;j<m;j++){
						nb_equation_parite_bit = CompterNombreEquationViolant_j_eme_bit(j,n,m,H,Y);
						Gama=nb_equation_parite_bit-b;
						
						if (nb_equation_parite_bit>=b){
							// correction de l'erreur Y(j)
							if (Y[j]==0){
								Y[j]=1;
							}else {
								Y[j]=0;
							}
							affiche=computeTTL(Gama);
							printf("\n\nComputeTtl = %.2f",affiche);
							ttl[i] = time + affiche;
							printf("\n\nTTl[%d]=%.2f\n\n",i,ttl[i]);	
						}
					}
					
					
					
					// calcul de syndrome S
					
					for (i=0;i<n;i++){
						S[i]=0;
						for (j=0;j<m;j++){
							
							if ((S[i]==1 && (H[i][j]*Y[j])==1)||(S[i]==0 && (H[i][j]*Y[j])==0)){
							
							    S[i]=0;
							
							}
							else {
								
								S[i]=1;
							}
						}
					}
		// calcul de b 
			Maxupc=0;		
			for (i=0;i<n;i++)
			{
					if(S[i]==1)
						Maxupc+=1;
	    	}
				
				}while(Maxupc!=0);
				
				
				for(i=0;i<m;i++){
					if (ttl[i]==time){
						if (Y[i]==0)
								Y[i]=1;
							else 
								Y[i]=0;
							
					}
					ttl[i]=0;
				}

					
			// calcul de syndrome S
							
			for (i=0;i<n;i++){
				S[i]=0;
				for (j=0;j<m;j++){
									
					if ((S[i]==1 && (H[i][j]*Y[j])==1)||(S[i]==0 && (H[i][j]*Y[j])==0))				
						S[i]=0;
					else 
						S[i]=1;
					 	
								}
							}
							
							
				//	affichage de la matrice S
					printf("\n*** Matrice S ***\n\n");
					printf("||\t");
					for (i=0;i<n;i++){
				
					printf("%d\t",S[i]);
				}
				printf("||\t");	
				
				//		affichage de la matrice Y
				
				printf("\n*** Matrice Y ***\n\n");
				printf("||\t");
				for (i=0;i<m;i++){
				
					printf("%d\t",Y[i]);
				}
				printf("||\t");		
				  		
				}	
		 
}












     	//		fonction

int CompterNombreEquationViolant_j_eme_bit(int j,int n,int m,int** H,int* Y)
	{
		int t,i,k;
	    int nb_equation_parite_bit_viole=0;
		int S[n];
		
		// calcul de syndrome S

					
					for (i=0;i<n;i++){
						S[i]=0;
						for (k=0;k<m;k++){
							
							if ((S[i]==1 && (H[i][k]*Y[k])==1)||(S[i]==0 && (H[i][k]*Y[k])==0)){
							
							    S[i]=0;
							
							}
							else {
								
								S[i]=1;
							}
						}
					}

		        	for(t=0;t<n;t++){
		        		if (H[t][j]==1 && S[t]!=0){
		        			nb_equation_parite_bit_viole+=1;
						}
						
							}
				return nb_equation_parite_bit_viole;
				
		}	
		
		
	float computeTTL(int gama){
		float A,B,C;
		
		A = 1.1 + (0.45*(float)gama);
		
		if (A > 5.0){
			B=5.0;	
		}else if (A<5.0){
			B=A;
		}
		
		if (B > 1.0){
			C=B;	
		}else if (B<1.0){
			C=1.0;
		}
		return C;
	}



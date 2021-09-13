#include <stdio.h>
#include <stdlib.h>

int CompterNombreEquationViolant_j_eme_bit(int j,int r,int n,int** H,int* C);
int BitFlipping(int n,int r,int w,int** H,int* C,int* S);



int BitFlipping(int n,int r,int w,int** H,int* C,int* S){

		int j,i,k,b,Maxupc=0,P=0;
		int nb_equation_parite_bit=0;
	    
	    //	calcul de Syndrome 
		
		for (i=0;i<r;i++){
			S[i]=0;
			for (j=0;j<n;j++){
				
				if ((S[i]==1 && (H[i][j]*C[j])==1)||(S[i]==0 && (H[i][j]*C[j])==0)){
				
				    S[i]=0;
				}
				else {
					
					S[i]=1;
				}
			}
		}
		
		//	affichage de la matrice S
		
		printf("\n*** Matrice S ***\n");
		printf("||\t");
		for (i=0;i<r;i++){
		
			printf("%d\t",S[i]);
		}
		printf("||\t");	
		
		//	calcul max upc 	
		
		for (i=0;i<r;i++){
			if(S[i]==1)
			Maxupc=Maxupc+1;
			else 
			continue;
		}
		printf (" \n\nMaxupc=%d",Maxupc);
		if (Maxupc>w){
	
			return 0;
		}	
		else if(Maxupc==0){
			printf ("\n Syndrome null donc il y pas d\'erreur");
		}else{
		
		// calcul de b
		
				printf ("\n Syndrome non null donc il y a des erreurs a corriger");
				b = Maxupc-P;
				printf ("\nb=%d",b);
				
				do{ 
					for (j=0;j<n;j++){
						nb_equation_parite_bit = CompterNombreEquationViolant_j_eme_bit(j,r,n,H,C);
						if (nb_equation_parite_bit>=b){
							
		// correction de l'erreur Y(j)
		
							if (C[j]==0){
								C[j]=1;
							}else {
								C[j]=0;
							}	
						}
					}
		
		// calcul de syndrome S
					
					for (i=0;i<r;i++){
						S[i]=0;
						for (j=0;j<n;j++){	
							if ((S[i]==1 && (H[i][j]*C[j])==1)||(S[i]==0 && (H[i][j]*C[j])==0)){
							    S[i]=0;
							}
							else {
								S[i]=1;
							}
						}
					}
			// calcul de b 
			Maxupc=0;		
			for (i=0;i<r;i++)
			{
					if(S[i]==1)
						Maxupc+=1;
	    	}
				
				}while(Maxupc!=0);
		
		//	affichage de la matrice S
		printf("\n*** Syndrome S ***\n");
		printf("||\t");
		for (i=0;i<r;i++){
		
			printf("%d\t",S[i]);
		}
		printf("||\t");	
		
//		//		affichage de la matrice C
//		printf("\n*** le MSG Dechiff C ***\n");
//		printf("||\t");
//		for (i=0;i<n;i++){
//		
//			printf("%d\t",C[i]);
//		}
//		printf("||\t");		
		  		
		}	
	return 1;
	
			 
}



////////////////////////////////////////////////////////////////////////////////

     	//		fonction

int CompterNombreEquationViolant_j_eme_bit(int j,int r,int n,int** H,int* C)
	{
		int t,i,k;
	    int nb_equation_parite_bit_viole=0;  
		int S[r];
		        // calcul de syndrome S
 				// printf ("j=%d n=%d m=%d \n",j,n,m);
					
				for (i=0;i<r;i++){
					S[i]=0;
						for (k=0;k<n;k++){	
							if ((S[i]==1 && (H[i][k]*C[k])==1)||(S[i]==0 && (H[i][k]*C[k])==0)){

							    S[i]=0;
							
							}
							else {
								
								S[i]=1;
							}
						}
					}

		        	for(t=0;t<r;t++){
		        		if (H[t][j]==1 && S[t]!=0){
		        			nb_equation_parite_bit_viole+=1;
						}	}
				return nb_equation_parite_bit_viole;
				
		}	

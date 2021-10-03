#include <stdio.h>
#include <stdlib.h>




int bitflipmasckedgrayiter(int* S, int* Y, int* Gray, int** H, int n, int m){
 		
	    int i,j,nb_equation_parite_bit=0,Maxupc=0 ,P=0, b;

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
		
		printf("\n*** Matrice S ***\n");
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
		printf (" \nMaxupc=%d",Maxupc);
		if (Maxupc==0){
			printf ("\n Syndrome null donc il y pas d\'erreur");
		}else {
				// calcul de b
				printf ("\nsyndrome non null donc il y a des erreurs a corriger");
				b = Maxupc-P;
				printf ("\nb=%d",b);
				
				do{ 
					for (j=0;j<m;j++){
						nb_equation_parite_bit = CompterNombreEquationViolant_j_eme_bit(j,n,m,H,Y);
						
						if (nb_equation_parite_bit>=b){
//							// correction de l'erreur Y(j)
//							if (Y[j]==0){
//								Y[j]=1;
//							}else {
//								Y[j]=0;
//							}


                            if (Gray[j]==1 && Y[j]==1||Gray[j]==0 && Y[j]==0){
							
							    Y[j]=0;
							
							}
							else {
								
								Y[j]=1;
							}	
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
			
		  		
}
		 
}



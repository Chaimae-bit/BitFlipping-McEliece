#include <stdio.h>
#include <stdlib.h>


int bitflipmasckedblackiter(int* s, int* y, int* Black, int** H, int n, int m){
 		
	    int i,j,nb_equation_parite_bit=0,Maxupc=0, b ,P=0;

		//	 calcul de Syndrome 
		for (i=0;i<n;i++){
			s[i]=0;
			for (j=0;j<m;j++){
				
				if ((s[i]==1 && (H[i][j]*y[j])==1)||(s[i]==0 && (H[i][j]*y[j])==0)){
				
				    s[i]=0;
				}
				else {
					
					s[i]=1;
				}
			}
		}
		//	affichage de la matrice S
		
		printf("\n*** Matrice S ***\n");
		printf("||\t");
		for (i=0;i<n;i++){
			printf("%d\t",s[i]);
		}
		printf("||\t");	
		
	
		//	calcul max upc 	
		
		for (i=0;i<n;i++){
		
			if(s[i]==1)
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
				b = Maxupc- P;
				printf ("\nb=%d",b);
				
				do{ 
					for (j=0;j<m;j++){
						nb_equation_parite_bit = CompterNombreEquationViolant_j_eme_bit(j,n,m,H,y);
						
						if (nb_equation_parite_bit>=b){

                            if (Black[j]==1 && y[j]==1||Black[j]==0 && y[j]==0){
							
							    y[j]=0;
							
							}
							else {
								
								y[j]=1;
							}	
						}

					}
					
					// calcul de syndrome S
					
					for (i=0;i<n;i++){
						s[i]=0;
						for (j=0;j<m;j++){
							
							if ((s[i]==1 && (H[i][j]*y[j])==1)||(s[i]==0 && (H[i][j]*y[j])==0)){
							
							    s[i]=0;
							
							}
							else {
								
								s[i]=1;
							}
						}
					}
			// calcul de b 
			Maxupc=0;		
			for (i=0;i<n;i++)
			{
					if(s[i]==1)
						Maxupc+=1;
	    	}
				
				}while(Maxupc!=0);
			
		  		
}
		 
}



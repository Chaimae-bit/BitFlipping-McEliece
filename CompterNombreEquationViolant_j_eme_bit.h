#include <stdio.h>
#include <stdlib.h>

int CompterNombreEquationViolant_j_eme_bit(int j,int n,int m,int** H,int* Y){
	
		int t,i,k;
	    int nb_equation_parite_bit_viole=0;
		int S[n];
		        
                
//					printf(" la fonction compter !!!!!");
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
						}	}
				return nb_equation_parite_bit_viole;
				
		}	
		


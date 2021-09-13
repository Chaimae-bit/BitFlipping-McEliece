#include <stdio.h>
#include <math.h>

int** Inverse(int r,int** H1,int** H0);
int is_identity(int r,int** H1);
int add_two_rowsH0(int r,int row1,int row2,int** H0);
int add_two_rowsH1(int r,int row1,int row2,int** H1);
int** creerMatriceId(int r,int** MatId);
void afficherMatriceINVERSE(int r,int** H0);



void afficherMatriceINVERSE(int r,int** H0)
{
    int i,j;
    
   
    for (i=0;i<r;i++)
    {
        for (j=0;j<r;j++)
        {
            printf("%d  ",H0[i][j]);
        }
        printf("\n" );
    }
}
 


int is_identity(int r,int** H1){

	int var =1;
	int i,j;
	for(i=0;i<r;i++)
		for(j=0;j<r;j++){
			if (i==j){
				if(H1[i][j]==0)
				    var=0;
			}
			else{
				if (H1[i][j]==1)
					var =0;
			}
		}
	return var;
}


int add_two_rowsH1(int r,int row1,int row2,int** H1){

	int i;

		for (i=0;i<r;i++){
       		if ((H1[row2][i]==1 && H1[row1][i]==1)||(H1[row2][i]==0 && H1[row1][i]==0))
	     		H1[row2][i]=0;
	  		else 
	  	 		H1[row2][i]=1;
		}
	}
	int add_two_rowsH0(int r,int row1,int row2,int** H0){
		int i;
		for (i=0;i<r;i++){
       		if ((H0[row2][i]==1 && H0[row1][i]==1)||(H0[row2][i]==0 && H0[row1][i]==0))
	     		H0[row2][i]=0;
	  		else 
	  	 		H0[row2][i]=1;
		}
	}
	


int** creerMatriceId(int n,int** MatId)
{
    int i,j;
    for (i=0;i<n;i++)
    {
        for (j=0;j<n;j++)
        {
            if (i==j)
            {
                MatId[i][j] = 1;
            }
            else
            {
                MatId[i][j] = 0;
            }
        }
    }
    return MatId;
}
 

int** Inverse(int r,int** H1,int** H0){
	int i,j,k;
	
	
	if(is_identity(r,H1)==1){
		printf("H1 est identite !!!");
		return H1;
	}
		
//	creerMatriceId(n,MatId);
	
	for(i=0;i<r;i++){
		if (H1[i][i]==1){
			for (j=0;j<r;j++)
			if (i!=j && H1[j][i]==1){
				add_two_rowsH1(r,i,j,H1);
				add_two_rowsH0(r,i,j,H0);	
			}
		}else {
			
			for (k=i+1;k<r;k++)
				if (H1[k][i]==1){
					add_two_rowsH1(r,k,i,H1);
					add_two_rowsH0(r,k,i,H0);
					i=i-1;
					break;
				}
			}	
		}
	if (is_identity(r,H1)==0)
    	printf("could not find inverse!");
   
//   	afficherMatriceINVERSE(r,H0);
   	return H0;
	}


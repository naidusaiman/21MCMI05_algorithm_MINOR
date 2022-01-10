//@Saiman
#include<stdio.h>
#include<stdlib.h>

int min(int v1,int v2,int v3){
	int min = (v1<v2)?(v1<v3)?v1:v3:(v2<v3)?v2:v3;
	return min;
}

void formMAT(int** mat,int row,int col){
	int i=0,j=0;
	printf("Enter Matrix Data (Can Be 0 or 1 only, if other data given program will terminate) :\n");
 	for(i=0;i<row;i++){
 		for(j=0;j<col;j++){
 			printf("[%d][%d] = ",i+1,j+1);
 			scanf("%d",&mat[i][j]);	
 		}
 	}
 	printf("\nINPUT BOOLEAN MATRIX:\n\n");
 	for(i=0;i<row;i++){
 		for(j=0;j<col;j++){
 			printf("%d ",mat[i][j]);
 		}
 		printf("\n");
 	}
 	
 	 for(i=0;i<row;i++){
 		for(j=0;j<col;j++){
 			if(mat[i][j] == 0 || mat[i][j] == 1)
 				continue;
 			else{
 				printf("\nInput Matrix is not Boolean.\n\n\n\n");
 				exit (0);
 			}
 		}
 	}
 	
 	printf("\n");


}

void conv(int** a,int row,int col){
	int i,j;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(a[i][j] == 0)
				a[i][j] = 1;
			else
				a[i][j] = 0;
		}
	}
}	

void subMAT(int** M,int R,int C){
	int i,j;
	conv(M,R,C);
	
	int** S = (int**)malloc(sizeof(int*)*R);
	for(i=0;i<R;i++)
		S[i] = (int*)malloc(sizeof(int)*C);
	int max_of_s, max_i, max_j;
	for(i=0;i<R;i++)
    		S[i][0] = M[i][0];   
	for(j=0;j<C;j++)
    		S[0][j] = M[0][j];
	for(i=1;i<R;i++){
    		for(j=1;j<C;j++){
    			if(M[i][j] == 1)
        			S[i][j] = min(S[i][j-1],S[i-1][j],S[i-1][j-1])+1;
    			else
        			S[i][j] = 0;
    		}
	}
	max_of_s = S[0][0]; 
	max_i = 0; 
	max_j = 0;
	for(i=0;i<R;i++){
    		for(j=0;j<C;j++){
    			if(max_of_s < S[i][j]){
        			max_of_s = S[i][j];
        			max_i = i;
        			max_j = j;
    			}    
    		}                
	}
	conv(M,R,C);    
 	
 	printf("Maximum size sub-matrix is: \n");
	for(i=max_i;i>max_i-max_of_s;i--){
    		for(j=max_j;j>max_j-max_of_s;j--){
    			printf("%d ", M[i][j]);
    		}
    		printf("\n");
	}
}


int main(){
	int row,col,i=0,j=0;
	printf("\n\n\nROW SIZE: ");
		scanf("%d",&row);
	printf("COLUMN SIZE: ");
		scanf("%d",&col);
	int** mat = (int**)malloc(sizeof(int*)*row);
	for(i=0;i<row;i++)
		mat[i] = (int*)malloc(sizeof(int)*col);
	
	formMAT(mat,row,col);
	
	subMAT(mat,row,col);
	
	printf("\n\n\n"); 	
	return 0;
}

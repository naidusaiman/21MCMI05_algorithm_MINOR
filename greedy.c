#include<stdio.h>
#include<stdlib.h>

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

int min(int n1,int n2){
	int m = (n1 < n2)? n1:n2;
	return m;
}

void findSUB(int** mat,int row,int col){
	int i,j,sr=0,sc=0;
	int l,m,max = 0;
	int finr,finc,fini,finj;
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			if(mat[i][j] == 0){
				sr = min(row-i,col-j);
				sc = min(row-i,col-j);
				//printf("BEFORE LABEL:\t\ti: %d\tj: %d\tsr: %d\tsc: %d\n",i,j,sr,sc);
				label:
				for(l=i;l<sr;l++){
					for(m=j;m<sc;m++){
						//printf("Inside: %d,%d.\n",l,m);
						if(mat[l][m] == 1){
							sr = sr-1;
							sc = sc-1;
							//l=i;
							//m=j;
							//printf("LABEL: sr: %d\tsc: %d\n",sr,sc);
							goto label;
						}				
					}
				}
				if(max < sr){
					//printf("%d\n",sr);
					max = sr;
					finr = sr;
					finc = sc;
					fini = i;
					finj = j;
				}
			}
		}
	}
	printf("Maximum Square Submatrix Size: %d.\n",max);
	//printf("i:%d fini:%d j:%d finj:%d finr:%d finc:%d\n",i,fini,j,finj,finr,finc);
	if(finj != 0)
		finc+=1;
	for(i=fini;i<finr;i++){
		for(j=finj;j<finc;j++){
			printf("%d ",mat[i][j]);		
		}
		printf("\n");
	}
}


int main(){
	int row,col,i=0,j=0;
	printf("ROW SIZE: ");
		scanf("%d",&row);
	printf("COLUMN SIZE: ");
		scanf("%d",&col);
	int** mat = (int**)malloc(sizeof(int*)*row);
	for(i=0;i<row;i++)
		mat[i] = (int*)malloc(sizeof(int)*col);
	
	formMAT(mat,row,col);
	
	findSUB(mat,row,col);
 	
	return 0;
}

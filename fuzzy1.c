#include <stdio.h>

int main(){
	float hasil=0, max=0, min=0;
    
	int input, data1,data2,data3 = 3, hasilHimpunan=3;
	printf("Banyak variabel = ");scanf("%d",&data1);
	printf("Banyak himpunan = ");scanf("%d",&data2);

	int rangeHimpunan[data1][data2][data3];
	char var[data1][50], himpunan[data1][data2][50];
	float domain[data1][hasilHimpunan];
	int inputUser[data1];
	
	// Input nilai range
	for(int a=0; a<data1; a++){
		printf("Masukkan variabel ke-%d = ",a+1); scanf("%s",var[a]);
        for(int b=0; b<data2; b++){
        	printf("	Masukkan himpunan ke-%d = ",b+1); scanf("%s",himpunan[a][b]);
        	for (int c = 0; c < data3; c++){
	            printf("		Range ke [%d] [%d] [%d] = ", a+1, b+1, c+1);
	            scanf("%d",&rangeHimpunan[a][b][c]);    
        	}
        }
        printf("Masukkan input user ke-%d = ",a+1); scanf("%d",&inputUser[a]);
        if (data1 > 1) {
	            	printf("===========================================\n");
	    }	    
	}

	// proses membership function
	for(int a=0; a<data1; a++){
		if (inputUser[a] >= rangeHimpunan[a][0][1] && inputUser[a] <= rangeHimpunan[a][0][2]) {
			max = rangeHimpunan[a][0][2];
			min = rangeHimpunan[a][0][1];
			hasil = (max-inputUser[a])/(max-min);
			domain[a][0] = hasil;
			hasil = 0;
		}else if (inputUser[a] >= rangeHimpunan[a][0][0] && inputUser[a] <= rangeHimpunan[a][0][1]){
			hasil = 1;
			domain[a][0] = hasil;
		}else{
			hasil = 0;
			domain[a][0] = hasil;
		}
	}
	hasil = 0;
	if (data2 > 1) {
		for (int a=0; a<data1;a++ ) {
			for(int b=1; b<data2-1;b++ ) {
				if (inputUser[a] >= rangeHimpunan[a][b][0] && inputUser[a] <= rangeHimpunan[a][b][1]) {
					max = rangeHimpunan[a][b][1];
					min = rangeHimpunan[a][b][0];
					hasil = (inputUser[a]-min)/(max-min);
					domain[a][b] = hasil;
					hasil = 0;
				}else if (inputUser[a] >= rangeHimpunan[a][b][1] && inputUser[a] <= rangeHimpunan[a][b][2]) {
					max = rangeHimpunan[a][b][2];
					min = rangeHimpunan[a][b][1];
					hasil = (max-inputUser[a])/(max-min);
					domain[a][b] = hasil;
					hasil = 0;
				}else {
					domain[a][b] = hasil;
				} 
			}
		}
		hasil = 0;
		for(int a=0; a<data1; a++){
			if (inputUser[a] >= rangeHimpunan[a][data2-1][0] && inputUser[a] <= rangeHimpunan[a][data2-1][1]) {
				max = rangeHimpunan[a][data2-1][1];
				min = rangeHimpunan[a][data2-1][0];
				hasil = (inputUser[a]-min)/(max-min);
				domain[a][data2-1] = hasil;
				hasil = 0;
			}else if (inputUser[a] >= rangeHimpunan[a][data2-1][1] && inputUser[a] <= rangeHimpunan[a][data2-1][2]){
				hasil = 1;
				domain[a][data2-1] = hasil;
			} else {
				hasil = 0;
				domain[a][data2-1] = hasil;
			}
		}
	}
	
	printf("Hasil membersip function\n");
	for (int a=0; a<data1; a++){
		for(int b=0; b<data2;b++ ) {
			printf("	%s %s = %.2f\n", var[a], himpunan[a][b], domain[a][b]);
		}
	}
	
	printf("===========================================\n");
	for (int a=0; a<data1; a++){
		for(int b=0; b<data2;b++ ) {
			for (int c=1; c<data1; c++){
				if ((domain[a][b] < domain[c][b]) && (domain[a][b] > 0)){						
					printf("	Rule %s %s(%.2f) ke %s %s(%.2f)\n", var[a], himpunan[a][b], domain[a][b],/**/var[c], himpunan[c][b], domain[c][b]);
				}/* else if ((domain[a][b] > domain[c][d]) && (domain[a][b] > 0.0)){
					printf("	Rule %s %s(%.2f) ke %s %s(%.2f)\n", var[a], himpunan[a][b], domain[a][b],var[c], himpunan[c][d], domain[c][d]);
				}*/		        
			}
		}
	}
	return 0;
}

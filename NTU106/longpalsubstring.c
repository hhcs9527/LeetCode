#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestPalindrome(char *s);

int main(void)
{
	char pall[100]={};
	//scanf("%s",pall);
	int len = strlen(pall);
	char *pal = (char*)malloc(len*sizeof(char));
	for (int i = 0; i < len; i++)
	{
		pal[i]=pall[i];
	}
	
	char * go112;
	go112 = longestPalindrome(pal); 

	printf("%s\n",go112);
}
char* longestPalindrome(char * s){
	int i,j,len,l;
	i = 0; j = 0; len = strlen(s);
	if (len==0) return s;
	else{

	int check[len][len];
	int getans[len][len];

	char reverse[len];
	
		// initialize check
	for(i = 0; i < len; i++){
		reverse[len-i-1] = s[i];
		for(j = 0; j < len ; j++){
			check[i][j] = 0;
			getans[i][j] = 0;
		}		
	}

	int max_l = 0;
	int max_i = 0;
	int max_j = 0;
// DP find max length
		for(i = 0; i < len; i++){
			for(j = 0; j < len ; j++){
				if (s[i] == reverse[j]){
					if (i==0){
						check[i][j] = 1;
						getans[i][j] = 2;
						if (max_l <= check[i][j]){
						max_l = check[i][j];
						max_i = i;
						max_j = j;		
						}			
					}
					else if (j==0){
						check[i][j] = 1;
						getans[i][j] = 3;
						if (max_l <= check[i][j]){
						max_l = check[i][j];
						max_i = i;
						max_j = j;		
						}			
					}

					else{
						check[i][j] = check[i-1][j-1]+1;
						getans[i][j] = 2;
						if (max_l <= check[i][j]){
						max_l = check[i][j];
						max_i = i;
						max_j = j;			
						}	
					}			
				}
				else{
					check[i][j] = 0;
					getans[i][j] = 0;
				}
			}
		}
	char palsubstring[max_l] ;
// show ans
	//printf("The longest pal subsequence is ");
	i = max_i;
	j = max_j;
	l = 0;
	while((i >= 0 && j >= 0) && getans[i][j] > 0) {
		if(getans[i][j] == 1){
			i--; palsubstring[l] = s[i];	
			l++;
		} 
		if(getans[i][j] == 3){
			j--; palsubstring[l] = s[i];	
			l++;	
		} 
		if(getans[i][j] == 2) {
			palsubstring[l] = s[i];
			j--;i--;l++;
		}
	}
	for (i = 0; i < l ;i++){
		s[i] = palsubstring[i];
	}
	if (i < len)
		s[i+1] = '\0';
	return s;
	}
}
// CABDAACBADFA




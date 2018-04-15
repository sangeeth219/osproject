#include<stdio.h>

int main(){
	int numR,numP,i,Max[20][20],j,Allocation[20][20],Need[20][20],SafeSeq[20],Finish[20],k,Available[20],ssnum,l;
	printf("Enter the number of resources : ");
	scanf("%d",&numR);
	printf("Enter the number of processes : ");
	scanf("%d",&numP);
	printf("___________________________________\n");
	printf("\nEnter number of instances available for each resource :\n");
	for(i=0;i<numR;i++){
		printf("R%d :",i);
		scanf("%d",&Available[i]);
	}
	printf("\nAvailable <");
	for(i=0;i<numR;i++){
		printf(" %d",Available[i]);
	}
	printf(" >");
	printf("\n___________________________________\n\n");
	
	printf("Enter maximum demand of each process(Max) and resource currently allocated to it :\n");
	for(i=0;i<numP;i++){
		printf("\nFor process P%d :\n",i);
		Finish[i]=0;
		for(j=0;j<numR;j++){
			printf("\tMaximum R%d required : ",j);
			scanf("%d",&Max[i][j]);
			printf("\tCurrently R%d allocated : ",j);
			scanf("%d",&Allocation[i][j]);
		}
	}
	printf("\nMax :\n    ");
	for(i=0;i<numR;i++){
		printf(" R%d",i);
	}
	for(i=0;i<numP;i++){
		printf("\nP%d ",i);
		for(j=0;j<numR;j++){
			printf("  %d",Max[i][j]);
		}
	}
	
	printf("\n\nAllocation :\n    ");
	for(i=0;i<numR;i++){
		printf(" R%d",i);
	}
	for(i=0;i<numP;i++){
		printf("\nP%d ",i);
		for(j=0;j<numR;j++){
			printf("  %d",Allocation[i][j]);
		}
	}
	
	printf("\n\nNeed :\n    ");
	for(i=0;i<numR;i++){
		printf(" R%d",i);
	}
	for(i=0;i<numP;i++){
		printf("\nP%d ",i);
		for(j=0;j<numR;j++){
			Need[i][j]=Max[i][j]-Allocation[i][j];
			printf("  %d",Need[i][j]);
		}
	}
	printf("\n___________________________________\n\n");
	
	k=0;
	ssnum=0;
	l=0;
	while(1){
		for(i=0;i<numP;i++){
			if(Finish[i]==0){
				for(j=0;j<numR;j++){
					if(Available[j] >= Need[i][j]){
						//do nothing
					}
					else{
						break;
					}
				}
				if(j==numR){	//Process can proceed further
					for(j=0;j<numR;j++){
						Available[j]=Available[j]+Allocation[i][j];
					}
					Finish[i]=1;
					SafeSeq[ssnum]=i;
					ssnum++;
					l++;
				}
			}
		}
		
		if(k==numP){
			if(l == numP){
				printf("\n___________________________________\n\n");
				printf("\nSystem is in safe state with safe sequence : <");
				for(i=0;i<numP;i++){
					printf(" P%d",SafeSeq[i]);
				}
				printf(" >");
				printf("\n___________________________________\n\n");
				break;
			}
			else{
				printf("\nSystem is in unsafe state");
				break;
			}
		}
		k++;
	}
}

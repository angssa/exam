/*
휴비츠  - 지원자 양영준

총알 직경으로 양품 불량품 판단하기 입니다.

 

*/

#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
	float v[361]={0};                      
	int i=0,ii=0,a=4; 
	float Dsum=0;
	float DDsum=0;
	float Sum=0;
	float D=0;
	float j;
	float jj;
	float ref;
	FILE *fp;
	char *add;
	add = (char *) malloc(20);
	printf("파일 주소를 입력하세요 ex)c:/ideal.txt \n");
	gets(add);
	fp=fopen(add,"r"); 	
	if(fp==NULL)
	{
		printf("파일 개방 실패.\n");
		return 0;
	}                            
	printf("직경의 이론값을 입력해 주세요\n");
	scanf("%f",&ref);
	if(200<ref || ref<0){
		printf("잘못된 입력값입니다.");
		return 0;
	}
	for(i=1;i<=360; i++)
   {
 	  fscanf(fp,"%f",&v[i]);
	  fseek(fp,a,SEEK_SET);                // 콤마로 구분된 txt파일을 읽기 위해 처음 위치에서 a바이트 떨어진 위치에 파일 포인터를 재 위치하도록 했습니다.
                                           //printf("%d도의 직경값은 %f입니다.\n",i,v[i]);
	  a=a+4;
	  Sum=Sum + v[i];                      // 직경의 평균을 구하기 위한 합을 구하는 부분
	 	 }
 

	for(ii=1;ii<360;ii++)                  //기울기를 구하기위한 부분 
	{
		D=(v[ii+1]-v[ii])/2;
		if(D>=0)
		DDsum = DDsum + D;                // 기울기의 합을 절대값으로 계산하는 부분
		else
			DDsum =DDsum-D;
		
	}
 

	j=Sum/(i-1);              // 직경의 평균값 구하기.
	jj=DDsum/360;             // 중심 인지 편심인지 기울기 평균 구하기-> 0이면 중심. ->0이 아니면 불량품이나 편심.

	                                //printf("기울기 절대합의 평균값은 %f입니다.\n",jj);
	
	if(jj==0 & j==ref)              //평균이 입력한 레퍼런스 값과 같고 기울어진 구간이 없다면 중심에서 측정된 양품입니다.
		printf("입력된 직경값 : %f입니다.\n측정된 평균 직경값 : %f입니다.\n이 제품은 중심에서 측정된 양품입니다.\n",ref,j);
	else if(jj!=0 & j==ref)         //평균은 같은데 기울어진 구간이 있다면 편심에서 측정된 양품입니다.
		printf("입력된 직경값 : %f입니다.\n측정된 평균 직경값 : %f입니다.\n이 제품은 편심에서 측정된 양품입니다.\n",ref,j);
	else                            // 평균값이 입력한 값과 다르면 불량품입니다. 
	printf("입력된 직경값 : %f입니다.\n측정된 평균 직경값은 %f입니다.\n이 제품은 불량품입니다.\n",ref,j);
	  
    system("pause");
   
} 
 
   
   
    

 

       

        


 

 
   
 
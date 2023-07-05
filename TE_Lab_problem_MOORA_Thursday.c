/*This program is to find a suitable alternative for road design using multi-objective optimization of road design alternatives with an 
application of MOORA method */
#include<stdio.h>
#include<math.h>
int main()
{
    int row_number,coloumn_number;
    printf("Enter number of Alternatives in the Decision matrix : ");
    scanf("%d",&row_number);
    printf("Enter number of Objectives in the Decision matrix : ");
    scanf("%d",&coloumn_number);
    float decision_matrix[row_number][coloumn_number], square_matrix[row_number][coloumn_number], normalized_matrix[row_number][coloumn_number], assessment_matrix[row_number][coloumn_number], weightage[coloumn_number], sum[5]={0,0,0,0,0},bo[coloumn_number],nbo[coloumn_number];
    double assessment_values[row_number], rank[row_number];
    float num=0,normsum=0,max=-7777,min=7777,swap;
    int i=0,j=0,maxindex=0,minindex=0;
    printf(" Enter Data\n");
    for (i=0;i<row_number;i++)
    {
        for (j=0;j<coloumn_number;j++)
        {
            printf("Enter value for Alternative %d and Objective %d\n",i+1,j+1);
            scanf("%f", &num);
            decision_matrix[i][j]=num;
        }
    }
    printf("Desition matrix : \n");
    for(i=0;i<row_number;i++)
    {
        for(j=0;j<coloumn_number;j++)
        {
            printf("%f    ",decision_matrix[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<row_number;i++)
    {
        for (j=0;j<coloumn_number;j++)
        {
            num=decision_matrix[i][j]*decision_matrix[i][j];
            square_matrix[i][j]=num;
        }
    }
    for (i=0;i<coloumn_number;i++)
    {
        for (j=0;j<row_number;j++) 
        {
            normsum=normsum+square_matrix[j][i];
        }
        sum[i]=sqrt(normsum);
        normsum=0;
    }
    for (i=0;i<row_number;i++)
    {
        for (j=0;j<coloumn_number;j++)
        {
            normalized_matrix[i][j]=((decision_matrix[i][j])/sum[j]);
        }
    }
    printf("Normalized matrix : \n");
    for(i=0;i<row_number;i++)
    {
        for(j=0;j<coloumn_number;j++)
        {
            printf("%f    ",normalized_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Please enter Weightages of different objectives\n");
    for (i=0;i<coloumn_number;i++)
    {
        printf("Enter weightage of %d Objective\n",i+1);
        scanf("%f", &num);
        weightage[i]=num;
    }
    for (i=0;i<row_number;i++)
    {
        for (j=0;j<coloumn_number;j++)
        {
            assessment_matrix[i][j]=((weightage[j])*(normalized_matrix[i][j]));
        }
    }
    printf("Assessment matrix : \n");
    for(i=0;i<row_number;i++)
    {
        for(j=0;j<coloumn_number;j++)
        {
            printf("%f    ",assessment_matrix[i][j]);
        }
        printf("\n");
    }
    printf("Enter 1 or -1 for classifying an objective as benificial or non-benificial; 1 for benificial and -1 for non-benificial\n");
    for(i=0;i<coloumn_number;i++)
    {
        printf("For objective %d : ",i+1);
        scanf("%f",&bo[i]);
    }
    for(i=0;i<row_number;i++)
    {
        for(j=0;j<coloumn_number;j++)
        {
            assessment_values[i]=assessment_values[i]+bo[j]*assessment_matrix[i][j];
        }
    }
    printf("Assessment values are: \n");
    for(i=0;i<row_number;i++)printf("%f    ",assessment_values[i]);
    printf("\n");
    for(i=0;i<row_number;i++)
    {
        rank[i]=assessment_values[i];
    }
    for(i=0;i<row_number;i++)
    {
        for(j=i+1;j<coloumn_number;j++)
        {
            if(rank[i]<rank[j])
            {
                swap=rank[i];
                rank[i]=rank[j];
                rank[j]=swap;
            }
        }
    }
    if((rank[0])==assessment_values[0])
    {
        printf("Alternative 1: Construction of a new road by changing the axis and gradients of the highway and using concrete surfacing. Change of gradients requires deep excavations and embankments, i.e. large amount of earthwork. It makes up 70 m3 /m in average.(Variant 1)\n");
        maxindex=1;
    }
    if((rank[0])==assessment_values[1])
    {
        printf("Alternative 2: Construction of a new road by changing the axis and gradients of the highway and using asphalt concrete surfacing. Only the surfacing differs compared to Variant 1.(Variant 2).\n");
        maxindex=2;
    }
    if((rank[0])==assessment_values[2])
    {
        printf("Alternative 3: Construction of a new road by changing the axis and retaining the gradients of the highway with concrete surfacing. When the gradients are retained, the amount of earthwork is reduced in Variant 3. It makes up 36.2 m3 /m.(Variant 3).\n");
        maxindex=3;
    }
    if((rank[0])==assessment_values[3])
    {
        printf("Alternative 4: Construction of a new road by changing the axis and retaining the gradients of the highway but with asphalt concrete surfacing. This variant corresponds to Variant 3, only the surfacing differs.(Variant 4).\n");
        maxindex=4;
    }
    if((rank[0])==assessment_values[4])
    {
        printf("Alternative 5: Construction of a new road retaining the axis and the gradient of the highway with concrete surfacing. The amount of earthworks in this variant is similar to that of Variant 3. Only duration differs.(Variant 5).\n");
        maxindex=5;
    }
    if((rank[0])==assessment_values[5])
    {
        printf("Alternative 6: Construction of a new road retaining the axis and the gradient of the highway with asphalt concrete surfacing. Variant 6 corresponds to Variant 5, only the road surfacing differs.(Variant 6).\n");
        maxindex=6;
    }
    printf("Best Variant after feeding data to MOORA Algorith is Variant: %d\n",maxindex);
    return 0;
}

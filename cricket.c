#include <stdio.h>
#include<string.h>
#include <stdlib.h>
int n;
struct cricket
{
char name[23], country[23], category[23];
int age, odi, t20, batscore, wkt;
};
void batsman(struct cricket p[]);
void no_Bowler(struct cricket p[]);
void mostwickets(struct cricket p[]);
void display(struct cricket p[]);
void max_avg_score(struct cricket p[]);
int main()
{
struct cricket s[10];
int i, obs;
char ctry[25], num[25];
printf("\nEnter number of players: ");
scanf("%d",&n);
printf("\nEnter data of %d players:\n",n);
for(i=0;i<n;i++)
{ 
printf("Enter name of the player: ");
scanf("%s", s[i].name);
printf("Enter age of the player: ");
scanf("%d", &s[i].age);
printf("Enter country of the player: ");
scanf("%s", s[i].country);
printf("Enter category of the player: ");
scanf("%s", s[i].category);
printf("Enter Number of ODIs played: ");
scanf("%d", &s[i].odi);
printf("Enter Number of 20-20s played: ");
scanf("%d", &s[i].t20);
printf("Enter average batting score: ");
scanf("%d", &s[i].batscore);
printf("Enter total number of wkts taken: ");
scanf("%d", &s[i].wkt);
}
do
{
printf("\n\n   *********   \n1) Number of batsman of a particular country \n");
printf("2) Number of bowlers of a  country \n");
printf("3) Bowler taken most wickets \n");
printf("4) Display board information of player  \n");
printf("5) Display average batting score of a player.\n");
printf("6) Exit\n");
printf("Enter you choice: "); 
scanf("%d",&obs);
switch(obs)
{
 case 1: batsman(s);
 break;
 case 2:  no_Bowler(s);
 break;
 case 3: mostwickets(s);
 break;
 case 4: display(s);
 break;
 case 5: max_avg_score(s);
 break;
 default:printf("\n  *****  ");
}
}while(obs!=6);
}
void batsman(struct cricket p[])
{
 int ctr;
 char x[25]; 
 ctr=0;
printf("\nEnter country to display number of batsman: ");
scanf("%s",x);
for(int i=0; i<n; i++)
{
if((strcmp(x,p[i].country)==0)&&(strcmp("batsman",(p[i].category))==0)){
    ctr++;
}

}
printf("\nNo. of batsman of  country %s is = %d ",x,ctr);
}
void  no_Bowler(struct cricket a[])
{
 int count=0;
 char ctry[15];
printf("\nEnter country to display number of bowlers: ");
scanf("%s", ctry);
for(int i=0; i<n; i++)
{
if((strcmp(ctry,a[i].country)==0)&&(strcmp("bowler",a[i].category)==0))
count++;
}
printf("\nNumber of bowlers of a %s country is = %d ", ctry,count);
}
void mostwickets(struct cricket p[])
{
int count=0;
int index=0; 
for(int i=0; i<n; i++)
{
if(strcmp("bowler",p[i].category)==0)
{
if (p[i].wkt>count)
{
count=p[i].wkt;
index=i;
}
}
}
printf("\n The Bowler who take most wickets = %s\n", p[index].name);
}
void display(struct cricket p[])
{
 printf("\n name\t age\tcountry\t category\t ODI\t T_20\t batscore\t wicket");
 for(int j=0;j<n;j++)
 {
 printf("\n%s\t%d\t%s\t %s\t %d\t %d\t %d \t\t%d",p[j].name,p[j].age,p[j].country,p[j].category,p[j].odi,p[j].t20,p[j].batscore,p[j].wkt);
 }
}
void max_avg_score(struct cricket p[])
{
int count=p[0].batscore;
int index=0; 
for(int i=0; i<n; i++)
{
if(strcmp("batsman",p[i].category)==0)
{
if (p[i].batscore>count)
{
count=p[i].batscore;
index=i;
}
}
}
printf("\n  %s has Highest batting average with score=%d\n",p[index].name,count);
}

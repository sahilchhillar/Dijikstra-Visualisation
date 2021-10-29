#include<stdio.h>
#include <graphics.h>
#include<stdbool.h>
#define IN 999
#define N 12
#define true 1
#define false 0
int Change_Graph_Map(int path[N],int j)
{
    int gd = DETECT, gm,i;

    initgraph(&gd, &gm, "");
    outtextxy(525,20,"unvisited nodes");
    outtextxy(525,45,"visited nodes");

    ///////////////////////////SPECIFYING DISTANCE////////////////////////////
    outtextxy(80,400,"16,12");
    outtextxy(205,400,"13,9");
    outtextxy(335,400,"38");
    outtextxy(432.5,400,"35,12");
    outtextxy(537.5,400,"20,11");
    outtextxy(205,300,"12,8");
    outtextxy(205,200,"12,8");
    outtextxy(155,350,"32");
    outtextxy(260,350,"42");
    outtextxy(55,350,"15,12");
    outtextxy(150,250,"137");
    outtextxy(280,250,"97");
    outtextxy(280,150,"48");
    outtextxy(205,150,"75");
    outtextxy(325,300,"105");
    outtextxy(225,335,"75");
    outtextxy(200,340,"70");
    outtextxy(195,240,"96");
    outtextxy(220,235,"131");


    ///////////////////////////BACKGROUND COLOR //////////////////////////////
    setfillstyle(SOLID_FILL,BLUE);
    floodfill(30,350,WHITE);

    /////////////////////////// CIRCLE DRAWING ///////////////////////////////
    setfillstyle(SOLID_FILL,GREEN);
    circle(30,  400, 20); //BLOCK 1
    floodfill(31,401,WHITE);
    circle(150, 400, 20); //BLOCK 2
    floodfill(151,401,WHITE);
    circle(150, 300, 20); //BLOCK 4
    floodfill(151,301,WHITE);
    circle(150, 200, 20); //BLOCK 6
    floodfill(151,201,WHITE);
    circle(280, 400, 20); //BLOCK 3
    floodfill(281,401,WHITE);
    circle(280, 300, 20); //BLOCK 5
    floodfill(281,301,WHITE);
    circle(280, 200, 20); //BLOCK 7
    floodfill(281,201,WHITE);
    circle(280, 100, 20); //BLOCK 8
    floodfill(281,101,WHITE);
    circle(390, 400, 20); //BLOCK 9
    floodfill(391,401,WHITE);
    circle(495, 400, 20); //BLOCK 10
    floodfill(496,401,WHITE);
    circle(600, 400, 20); //BLOCK 11
    floodfill(601,401,WHITE);
    circle(500,30,10);
    floodfill(501,31,WHITE);
    setfillstyle(SOLID_FILL,RED);
    circle(500,55,10);
    floodfill(501,56,WHITE);

    /////////////////////////// LINE DRAWING /////////////////////////////////
    line(300,400,370,400);
    line(150,380,150,320);
    line(150,280,150,220);
    line(280,380,280,320);
    line(280,280,280,220);
    line(280,180,280,120);
    line(170,200,280,120);
    line(170,300,280,220);
    line(170,400,280,320);
    line(260,400,150,320);
    line(260,300,150,220);
    line(280,220,370,400);
    /////////////////////////////////////////////////////////////////////////
    line(50,400,130,400);
    line(50,400,150,320);
    line(170,300,260,300);
    line(170,200,260,200);
    line(170,400,260,400);
    line(410,400,475,400);
    line(515,400,580,400);
    /////////////////////////// HIGHLIGHTING THE PATH ///////////////////////
    for(i=j-1; i>=0; i--)
    {

    		if(path[i]==1)
            {
             delay(2000);
             floodfill(31,401,WHITE);
             outtextxy(25,395,"1");
            }
            else if(path[i]==2)
            {
             delay(2000);
             floodfill(151,401,WHITE);
             outtextxy(145,395,"2");
            }
            else if(path[i]==3)
            {
             delay(2000);
             floodfill(281,401,WHITE);
             outtextxy(275,395,"3");
            }
            else if(path[i]==4)
            {
             delay(2000);
             floodfill(151,301,WHITE);
             outtextxy(145,295,"4");
            }
            else if(path[i]==5)
            {
             delay(2000);
             floodfill(281,301,WHITE);
             outtextxy(275,295,"5");
            }
            else if(path[i]==6)
            {
             delay(2000);
             floodfill(151,201,WHITE);
             outtextxy(145,195,"6");
            }
            else if(path[i]==7)
            {
             delay(2000);
             floodfill(281,201,WHITE);
             outtextxy(275,195,"7");
            }
            else if(path[i]==8)
            {
             delay(2000);
             floodfill(281,101,WHITE);
             outtextxy(275,95,"8");
            }
            else if(path[i]==9)
            {
             delay(2000);
             floodfill(391,401,WHITE);
             outtextxy(385,395,"9");
            }
            else if(path[i]==10)
            {
             delay(2000);
             floodfill(496,401,WHITE);
             outtextxy(490,395,"10");
            }
            else
            {
             delay(2000);
             floodfill(601,401,WHITE);
             outtextxy(595,395,"11");
            }
     }
     delay(1000);
     //////////////////////////// ADDING TEXT //////////////////////////////
    outtextxy(25,395,"1");
    outtextxy(145,395,"2");
    outtextxy(275,395,"3");
    outtextxy(385,395,"9");
    outtextxy(490,395,"10");
    outtextxy(595,395,"11");
    outtextxy(145,295,"4");
    outtextxy(145,195,"6");
    outtextxy(275,295,"5");
    outtextxy(275,195,"7");
    outtextxy(275,95,"8");

     getch();
     closegraph();
}
int DijsktraAlgorithm(int cost1[][N],int cost2[][N], int source, int destination,int d)
{
    int dist[N], prev[N],time;
    bool visited[N] = {false};
    int cost[N][N],path[N],i,j;
    for( i = 0; i < N; i++)
        for( j = 0; j < N; j++)
          {
            if(cost1[i][j]<=cost2[i][j])
             cost[i][j]=cost1[i][j];

            else
             cost[i][j]=cost2[i][j];

          }

    for ( i = 0; i < N; i++) {
        prev[i] = -1;
        dist[i] = IN;
    }

    int start = source;
    visited[start] = true;
    dist[start] = 0;

    while (visited[destination] == false) {
        int minDistance = IN;
        int nextStart = 0;
        for (int i = 1; i < N; i++) {
            if(visited[i] == false && cost[start][i] != 99) {
                int h = dist[start] + cost[start][i];
                if (h < dist[i]) {
                    dist[i] = h;
                    prev[i] = start;
                }
                if (dist[i] < minDistance) {
                    minDistance = dist[i];
                    nextStart = i;
                }
            }
        }
        start = nextStart;
        visited[nextStart] = true;
    }

    start = destination;
    j = 0;
    while (start != -1) {
        path[j++] = start;
        start = prev[start];
    }
    printf("\n\n\nThe shortest path route is....\n");
    for(int k = j - 1; k >= 0; k--) {
        printf("%d", path[k]);
        if(k != 0) {
            printf("----->");
        }
    }
	printf("\n \n ");
	if(d>=dist[destination])
	 {
      printf("\nThe minimum distance covered: %d meters\n\n", dist[destination]);
      time=dist[destination]*0.6;     /////Average human take 60 seconds to cover 100 meters
      printf("\nThe time taken to cover the distance:%d seconds(approx)",time);
	 }
	else
      printf("Note: The distance will not be convenient\n");
	Change_Graph_Map(path,j);
}

int main()
{
    int d;
    printf("\t \t \t \tGRAPHICAL MAP REPRESENTATION USING DIJKSTRA ALGORITHM\n\n");
    printf("NOTE:\n\n");
    printf("1)Distance is taken from one block to another block with the help of steps.Each step is taken as 1 meter approx.\n\n");
    printf("2)Time is calculated based on the fact that an average person takes 60 seconds for 100 steps.\n\n");
    printf("3)There are multiple paths in some of the blocks.Always chose the connected or bridge path(ie the second path in the map) for the shortest distance and the distance shown by the algorithm is considering the connected path only.\n\n");

    ////////////////////////// COST MATRIX FOR ROAD PATHS ///////////////////////////
    int cost1[12][12]={{999,999,999,999,999,999,999,999,999,999,999,999},
                       {999,999,16,999,15,999,999,999,999,999,999,999},
                       {999,16,999,13,32,75,999,999,999,999,999,999},
                       {999,999,13,999,70,42,999,999,999,38,999,999},
                       {999,15,32,70,999,12,137,131,999,999,999,999},
                       {999,999,75,42,12,999,96,97,999,999,999,999},
                       {999,999,999,999,137,96,999,12,50,999,999,999},
                       {999,999,999,999,131,97,12,999,48,105,999,999},
                       {999,999,999,999,999,999,50,48,999,999,999,999},
                       {999,999,999,38,999,999,999,105,999,999,35,999},
                       {999,999,999,999,999,999,999,999,999,35,999,20},
                       {999,999,999,999,999,999,999,999,999,999,20,999}};

    ////////////////////////// COST MATRIX FOR CONNECTED BLOCKS(BRIDGE) ///////////////////
    int cost2[12][12]={{999,999,999,999,999,999,999,999,999,999,999,999},
                       {999,999,12,999,12,999,999,999,999,999,999,999},
                       {999,12,999,9,999,999,999,999,999,999,999,999},
                       {999,999,9,999,999,999,999,999,999,999,999,999},
                       {999,12,999,999,999,8,999,999,999,999,999,999},
                       {999,999,999,999,8,999,999,999,999,999,999,999},
                       {999,999,999,999,999,999,999,8,999,999,999,999},
                       {999,999,999,999,999,999,8,999,999,999,999,999},
                       {999,999,999,999,999,999,999,999,999,999,999,999},
                       {999,999,999,999,999,999,999,999,999,999,12,999},
                       {999,999,999,999,999,999,999,999,999,12,999,11},
                       {999,999,999,999,999,999,999,999,999,999,11,999}};


	int source, destination;
	A:
    printf("\nEnter the source block: ");
    scanf("%d", &source);
    if((source < 1)||(source > 11))
    {
        printf("\nError:Please enter the correct block\n");
        goto A;
    }
    B:
    printf("\nEnter the destination block: ");
    scanf("%d", &destination);
    if((destination < 1)||(destination > 11))
    {
        printf("\nError:Please enter the correct block\n");
        goto B;
    }
    printf("\nHow much of distance will be convenient to you(in meters)? ");
    scanf("%d",&d);
    DijsktraAlgorithm(cost1,cost2, source, destination,d);
}

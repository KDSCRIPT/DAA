#include <iostream>
using namespace std;
int orientation(int point1[],int point2[],int point3[])
{
	int d=(point3[1]-point2[1])*(point2[0]-point1[0])-(point2[1]-point1[1])*(point3[0]-point2[0]);
	if (d>0) return 1;
    if(d<0)return -1;
	else return 0;
}
int main()
{
    int n,points[100][2],hull[100][2];
    cout<<"Enter number of points:";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter x coordinate of point "<<i+1<<":";
        cin>>points[i][0];
        cout<<"Enter y coordinate of point "<<i+1<<":";
        cin>>points[i][1];
    }
	int leftindex=0;
	for (int i = 1; i < n; i++)if (points[i][0] < points[leftindex][0])leftindex = i;
	int currentindex = leftindex, nextindex,hullindex=0;
	do
	{
		hull[hullindex][0]=points[currentindex][0];
        hull[hullindex][1]=points[currentindex][1];
        hullindex++;
		nextindex = (currentindex+1)%n;
		for (int i = 0; i < n; i++)
		{
		    if (orientation(points[currentindex],points[nextindex],points[i]) == 1)nextindex = i;
		}
		currentindex=nextindex;
	} while (currentindex!= leftindex);
	for (int i = 0; i < hullindex; i++)cout<< hull[i][0]<<","<<hull[i][1]<<"\n";
}
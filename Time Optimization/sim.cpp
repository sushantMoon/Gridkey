/**
**	Written By: gridkey
**	Description: Optimizes the average wait time per car by varrying 
**				 the values of green-signal times
**	Output: Provides the optimized wait time along with the green-signal length for obtaining the 
**			optimized result. It also shows the base average wait time per car considering the green 
**			signal times to be 2.0
**	Output is shown in command line.
**	Input: In argv provide the filename to read input from.
**	In the input file: 
**		There are 3 lines each with 4 values.
**		first line contains the number of cars initially present at each direction.
**		second line contains the rate(car/min) at which new cars are arriving at the signal from that direction
**		Third line contains the rate(car/min) at which cars decrease from a direction if the signal is green
**/

#include<bits/stdc++.h>
using namespace std;
double max( double a, double b )
{
	return( (a<b)?b:a);
}
int main( int argc, char *argv[] )
{
	freopen( argv[1], "r", stdin );
	double initCap[4], inflows[4], outflows[4];
	for( int i = 0; i<4;i++)
		cin>> initCap[i];
	for( int i = 0; i<4;i++)
		cin>> inflows[i];
	for( int i = 0; i<4;i++)
		cin>> outflows[i];
	double time[4] = {2,2,2,2};
	double sumTime = time[0]+time[1]+time[2]+time[3];
	double wait[4];
	double lag[4];
	double minTotalWait = 1000000000;
	double optTime[4];
	for( int k1 = 0; k1 < 400; k1++)
	{
		for( int k2 = 0; k2 < 400 - k1; k2++)
		{
			for( int k3 = 0; k3 < 400 -k1 -k2; k3++)
			{
				double totalCars = 0;
				
				time[0] = 8.0*(double(k1)/400.0);
				time[1] = 8.0*(double(k2)/400.0);
				time[2] = 8.0*(double(k3)/400.0);;
				time[3] = 8.0 - time[0] - time[1] -time[2];
				
				//time[0]=time[1]=time[2]=time[3]=2.0;
				for( int i =0; i< 4;i++)
				{
					lag[i] = sumTime - time[i];
					wait[i] = max(initCap[i]-outflows[i]*time[i], 0)*lag[i] + inflows[i]*lag[i]*lag[i];
					totalCars += initCap[i]+ inflows[i]*lag[i];
				}
				double totalWait = (wait[0]+wait[1]+wait[2]+wait[3])/totalCars;
				if( (time[0] == 2.0) && (time[2] == 2.0) && (time[3] == 2.0 ) )
					cout<<"basetime: "<<totalWait<<endl;
				if( totalWait < minTotalWait )
				{
					minTotalWait = totalWait;
					for( int i =0; i<4; i++)
						optTime[i] = time[i];
				}
			}
		}
	}
	cout<<"opttimized Time: "<<minTotalWait<<endl;
	cout<<"times: "<<optTime[0]<<" "<<optTime[1]<<" "<<optTime[2]<<" "<<optTime[3]<<endl;
	return(0);
}
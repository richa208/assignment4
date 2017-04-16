#include<bits/stdc++.h>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define Pi pair<int,int>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
using namespace std;
set<Pi>hull;
int n;
Pi a[1000000];
int side(Pi p1,Pi p2,Pi p)
{
	int val=(p.S-p1.S)*(p2.F-p1.F)-(p2.S-p1.S)*(p.F-p1.F);
	if(val>0)
		return 1;
	if(val<0)
		return -1;
	return 0;
}
int dist(Pi p,Pi q)
{
	int res=0;
	res+=(p.S-q.S);
	res*=res;
	int tes=(p.F-q.F);
	tes*=tes;
	res+=tes;
	return res;
}
double line_dist(Pi p1,Pi p2,Pi p)
{
	int val=abs((p.S-p1.S)*(p2.F-p1.F)-(p2.S-p1.S)*(p.F-p1.F));
	double temp=sqrt(dist(p1,p2));
	double res=1.0*val/temp;
	return res;
}
void solve(Pi p1,Pi p2,int num)
{
	int ind=-1;
	double max_dist=0.0;
	for(int i=0;i<n;i++)
	{
		double temp=line_dist(p1,p2,a[i]);
		if(side(p1,p2,a[i])==num&&temp>max_dist)
		{
			ind=i;
			max_dist=temp;
		}
	}
	if(ind==-1)
	{
		hull.insert(p1);
		hull.insert(p2);
		return;
	}
	solve(a[ind],p1,-side(a[ind],p1,p2));
	solve(a[ind],p2,-side(a[ind],p2,p1));

}
int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter the number of points\n";
    cin>>n;
    cout<<"enter the points\n";
    for(int i=0;i<n;i++)
    	cin>>a[i].F>>a[i].S;
    int min_x=0,max_x=0;
    for(int i=1;i<n;i++)
    {
    	if(a[i].F<a[min_x].F)
    		min_x=i;
    	if(a[i].F>a[max_x].F)
    		max_x=i;
    }
    cout<<"the points in convex hull are:\n";
    solve(a[min_x],a[max_x],1);
    solve(a[min_x],a[max_x],-1);
    while(!hull.empty())
    {
    	cout<<"("<<(*hull.begin()).F<<","<<(*hull.begin()).S<<")";
    	hull.erase(hull.begin());
    }
    clock_t tStart = clock();
	double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
	printf("Time : %.6fs \n",tEnd);
    return 0;
}

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
Pi p0;
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
Pi next_top(stack<Pi>s)
{
	s.pop();
	return s.top();
}
int orientation(Pi p,Pi q,Pi r)
{
	int res=(q.S-p.S)*(r.F-q.F)-(r.S-q.S)*(q.F-p.F);
	if(res==0)
		return 0;//collinear
	if(res<0)
		return 2;//counter-clockwise
	return 1;// clockwise
}
bool compare(Pi p1,Pi p2)
{
	int val=(p1.S-p0.S)*(p2.F-p0.F)-(p1.F-p0.F)*(p2.S-p0.S);
	if(val<0)
		return 1;
	if(val>0)
		return 0;
	return (dist(p1,p0)<=dist(p2,p0));
}
int main()
{

    ios::sync_with_stdio(0);
    cout<<"enter the number of points\n";
    int n;
    cin>>n;
    Pi a[n];
    cout<<"enter the points\n";
    for(int i=0;i<n;i++)
    	cin>>a[i].F>>a[i].S;
    if(n<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	int mini=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].S<a[mini].S)
			mini=i;
		else if(a[i].S==a[mini].S)
			if(a[i].F<a[mini].F)
				mini=i;
	}
	p0=a[mini];
	swap(a[mini],a[0]);
	sort(a,a+n,compare);

	vector<Pi>final;
	final.pb(a[0]);
	for(int i=1;i<n;i++)
	{
		while(i+1<n&&orientation(p0,a[i],a[i+1])==0)
			i++;
		final.pb(a[i]);
	}
	if(sz(final)<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	stack<Pi>s;
	s.push(final[0]);
	s.push(final[1]);
	s.push(final[2]);
	for(int i=3;i<sz(final);i++)
	{
		while(orientation(next_top(s),s.top(),final[i])!=2)
			s.pop();
		s.push(final[i]);
	}
	cout<<"the points in convex hull are:\n";
	while(!s.empty())
	{
		Pi temp=s.top();
		cout<<"("<<temp.F<<","<<temp.S<<")";
		s.pop();
	}
	clock_t tStart = clock();
	double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;

	printf("Time : %.6fs \n",tEnd);
    return 0;
}

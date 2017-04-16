
# include <bits/stdc++.h>

using namespace std;

struct point
{
	int x,y;
};

int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return 0;  // collinear
    return (val > 0)? 1: 2; // clock or counterclock wise
}

void ConvexHull(int n,point pts[],vector<point>& v)
{
    if (n < 3) return;
    int left = 0;
    for (int i = 1; i < n; i++)
        if (pts[i].x < pts[left].x)
            left = i;
    int prev = left, next;
    do
    {
        v.push_back(pts[prev]);
 
        next = (prev+1)%n;
        for (int i = 0; i < n; i++)
        {
           if (orientation(pts[prev], pts[i], pts[next]) == 2)
               next = i;
        }
 
        prev = next;
 
    } while (prev != left);  
}

int main()
{
	int n;
	cout<<"Enter the no. of points\n";
	cin>>n;
	point *pts = new point[n];
	for(int i = 0; i<n; i++)
	{
		cin>>pts[i].x>>pts[i].y;
	}
	vector<point> v;

	clock_t tStart = clock();

	ConvexHull(n,pts,v);

	double tEnd = (double)(clock() - tStart)/CLOCKS_PER_SEC;
	
	for(int i = 0;i<v.size();i++)
		cout<<v[i].x<<" "<<v[i].y<<endl;
	cout<<"h="<<v.size()<<endl;

	printf("Time : %.6fs \n",tEnd);
}

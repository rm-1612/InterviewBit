/*

Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]


*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> result;
	
	int n=A.size(),m=A[0].size(),i=0,j;
	int top=0,bottom=n-1,left=0,right=m-1,dir=0;
	while(top<=bottom && left<=right)
	{
	    if(dir==0)
	    {
	        for(j=left;j<=right;++j)
	        {
	            result.push_back(A[top][j]);
	        }
	        ++top;
	        dir=1;
	    }
	    else if(dir==1)
	    {
	        for(i=top;i<=bottom;++i)
	        {
	            result.push_back(A[i][right]);
	        }
	        --right;
	        dir=2;
	    }
	    else if(dir==2)
	    {
	        for(j=right;j>=left;--j)
	        {
	            result.push_back(A[bottom][j]);
	        }
	        --bottom;
	        dir=3;
	    }
	    else if(dir==3)
	    {
	        for(i=bottom;i>=top;--i)
	        {
	            result.push_back(A[i][left]);
	        }
	        ++left;
	        dir=0;
	    }
	}
	
	
	return result;
}

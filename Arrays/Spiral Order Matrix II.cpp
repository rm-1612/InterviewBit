/*

Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
 [ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ] 
 
 */
 
 vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    vector<vector<int> >sol(A, vector<int>(A, 0));
    
    int left = 0;
    int right = A-1;
    int top = 0;
    int bottom = A-1;
    int dir = 0;
    int number = 1;
    int i, j;
    
    LOOP:while((left <= right) && (top <= bottom)){
        if(dir == 0){
            for(j = left; j <= right; j++){
                sol[top][j] = number;
                number++;
            }
            top++;
            dir = 1;
            goto LOOP;
        }
        else if(dir == 1){
            for(i = top; i <= bottom; i++){
                sol[i][right] = number;
                number++;
            }
            right--;
            dir = 2;
            goto LOOP;
        }
        else if(dir == 2){
            for(j = right; j >= left; j--){
                sol[bottom][j] = number;
                number++;
            }
            bottom--;
            dir = 3;
            goto LOOP;
        }
        else if(dir == 3){
            for(i = bottom; i >= top; i--){
                sol[i][left] = number;
                number++;
            }
            left++;
            dir = 0;
            goto LOOP;
        }
    }
    
    return sol;
    
    
    
    /*vector<vector<int> > result;
    result.resize(A);
    result[0].resize(A);
    int top=0,bottom=A-1,left=0,right=A-1,i,j,dir=0;
    int element=1;
    while(top<=bottom && left<=right)
    {
        if(dir==0)
        {
            for(j=left;j<=right;++j)
        {result[top][j]=element;
            ++element;
        }
        ++top;
            dir=1;
        }
        else if(dir==1)
        {
            for(i=top;i<=bottom;++i)
        {
            result[i][right]=element;
            ++element;
        }
        --right;
            dir=2;
        }
        
        else if(dir==2)
        {
            for(j=right;j>=left;--j)
        {
            result[bottom][j]=element;
            ++element;
        }
        --bottom;
        dir=3;
        }
       else if(dir==3)
        {
            for(i=bottom;i>=top;--i)
        {
            result[i][left]=element;
            ++element;
        }
        ++left;
        dir=0;
        }
        
    }
    
    return result;
    */
    
}

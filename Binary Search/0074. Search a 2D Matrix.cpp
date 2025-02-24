class Solution {
    public :
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size(); //koi bhi ek row ka size willl be col

        int s=0;
        int e=row*col-1;
        int mid=(s+e)/2;
    
        while(s<=e)
            {
                //mid/col calculates the row index of the element in the original matrix.
                //mid%col calculates the column index of the element in the original matrix
                //matrix[mid/col][mid%col] accesses the element in the matrix at the calculated row and column indices.
                int element=matrix[mid/col][mid%col]; 
                if(element==target)
                {
                    return 1;
                }
                else if(element<target)
                {
                    s=mid+1;
                }
                else
                {
                    e=mid-1;
                }
                mid=(s+e)/2;
            }
        return 0;
    }
};
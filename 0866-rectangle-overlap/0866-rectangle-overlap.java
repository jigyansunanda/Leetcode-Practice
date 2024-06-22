class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        if(rec1[2] <= rec2[0] ||  //rec2 right 
           rec2[2] <= rec1[0] ||  // rec2 left
           rec1[3] <= rec2[1] ||  //rec2 Top
           rec2[3] <= rec1[1])   //rec2 bottom
            return false;
        return true;
    }
}
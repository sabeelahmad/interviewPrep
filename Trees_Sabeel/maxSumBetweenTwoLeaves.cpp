int maxPathSumUtil(struct Node* root, int &max_sum) {
    if(root == NULL) {
        return 0;
    }

    // if leaf node, return its value
    if(root -> left == NULL && root -> right == NULL) {
        return root -> data;
    }

    // get left sum from current node and right sum from current node
    int leftSum = maxPathSumUtil(root -> left, max_sum);
    int rightSum = maxPathSumUtil(root -> right, max_sum);

    // now that we have both sums, we see if none of them is 0,
    // means no node on that side is null and current node has both children
    if(leftSum != 0 && rightSum != 0) {
        // maxsum from leaf on left side to leaf on rightside
        // passing thru current node
        max_sum = max(max_sum, leftSum + rightSum + root -> data);

        // to parent node we return the max path sum eg
        /*
            8
            |
            1
           / \
          2   3

          if current node is with data 1, to 8 it should return the path
          that has max sum that is either 1-2 or 1-3(here 1-3)
        */
        return max(leftSum + root -> data, rightSum + root -> data);
    }

    // however if one of the children was null, we simply return from non null path
    if(leftSum == 0) {
        return rightSum + root -> data;
    } else {
        return leftSum + root -> data;
    }


}


int maxPathSum(struct Node *root)
{
    // we maintain a max_sum by reference so that we dont need
    // to recalculate sum again
    int max_sum = INT_MIN;
    maxPathSumUtil(root, max_sum);
    return max_sum;
}

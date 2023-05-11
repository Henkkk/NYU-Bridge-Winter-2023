//find the height of the BST
int getHeight(Node* currNode){ 
    if (currNode == nullptr){
        return 0;
    }

    int heightLeftTree = getHeight(currNode->left);
    int heightRightTree = getHeight(currNode->right);

    return max(heightLeftTree, heightRightTree) + 1;
}
//end

//Determine if the tree is balanced/
bool isBalanced(Node* currNode){
    if (currNode == nullptr){
        return 0;
    }   

    int heightLeftTree = getHeight(currNode->left);
    int heightRightTree = getHeight(currNode->right);

    if (abs(heightLeftTree - heightRightTree) > 1){
        return false;
    }

    return (isBalanced(currNode->left) && isBalanced(currNode->right));
}
//end

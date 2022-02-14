from tkinter.tix import Tree
from typing import List, Optional

class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


def pathSum(root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
    res = []
    dfs(root, targetSum, [], res)
    return res
    
def dfs(root, targetSum, temp, res):
    
    if root:
        if (not root.left) and (not root.right) and (root.val==targetSum):
            temp.append(root.val)
            res.append(temp)
    
        dfs(root.left, targetSum-root.val, temp+[root.val], res)
        dfs(root.right, targetSum-root.val, temp+[root.val], res)

def initTree():
    root = TreeNode(5)
    root.left = TreeNode(4)
    root.right = TreeNode(8)

    root.left.left = TreeNode(11)
    root.left.right = None

    root.left.left.left = TreeNode(7)
    root.left.left.left.left = None
    root.left.left.left.right = None

    root.left.left.right = TreeNode(2)
    root.left.left.right.left = None
    root.left.left.right.right = None

    root.right.right = TreeNode(4)

    root.right.right.left = TreeNode(5)
    root.right.right.left.left = None
    root.right.right.left.right = None

    root.right.right.right = TreeNode(1)
    root.right.right.right.left = None
    root.right.right.right.right = None

    return root

    '''
        5
       / \ 
      /   \ 
     4     8 
    /       \ 
   11        4
  /  \      / \  
 7    2    5   1

    '''

if __name__ == "__main__":
    root = initTree()

    targetSum = int(input("Enter target sum: "))
    res = pathSum(root, targetSum)

    print(f"Paths with target sum = {targetSum}: {res}")
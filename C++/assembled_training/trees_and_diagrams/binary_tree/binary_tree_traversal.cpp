/*

遍历
所谓的便利就是按照一定规律和次序访问树中的各个节点，而且每个节点只访问一次。4种遍历方法

前序遍历

中序遍历

后序遍历

层次遍历

*/

/*

*-------------*
|      A      |
|     / \     |
|    /   \    |
|   B     C   |
|  /\    /\   |
| /  \  /  \  |
|D	 F G   I  |
|   /  \      |
|  /    \     |
|  E    H     |
*-------------*


先序遍历：根左右
先访问根结点,再访问左子树,最后访问右子树
A B D F E C G H I


中序电力：左跟右
先访问左子树，再访问根结点，最后访问右子树
D B E F A G H C I


右序遍历 ：左右跟
先访问左子树 再访问右子树，最后访问根节点
D E F B H G I C A


层次遍历：
从左到右每一层访问每一个节点层次遍历用的很少，理解就行
A B C D F G I E H

*/

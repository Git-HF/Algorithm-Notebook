## Q：矩阵的循环打印，即将矩阵由外向内打印，将外层打印完，再打印内层，额外空间复杂度为**O(1)**
> * 分层打印
> * [《剑指offer》（顺时针打印矩阵）](https://www.nowcoder.com/practice/9b4c81a02cd34f76be2659fa0d54342a?tpId=13&tqId=11172&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking)

## Q：方形矩阵旋转90度，额外空间复杂度为**O(1)**
> * 分层旋转，对于每一层的旋转，需要自己找规律
> * [《leetcode》(旋转矩阵)](https://leetcode-cn.com/problems/rotate-matrix-lcci/)

## Q：“之”字打印，额外空间复杂度为**O(1)**
> * 主要就是确定对角线，使用两个标记，从左上角开始，一个向右走，走到右边界，则向下走；另一个往下走，走到下边界，则往右走。最终两个标记重合；一次打印两个标记对角线上的元素
> * [《leetcode》(对角线遍历)](https://leetcode-cn.com/problems/diagonal-traverse/)

## Q：给定一个M*N的矩阵matrix和一个整数K，matrix中的每一行和每一列都是排好序的。判断给定的K是否在矩阵中，要求时间复杂度为**O(M+N)**，空间复杂度为**O(1)**。
> * 从左下角或者右上角开始寻找。因为此时可行走的两条查找路径的数与要查找的数大小关系不同，这样查找的目的性更强。如果当前数小了，就像大的那条路径查找。否则反过来。
> * [《leetcode》（排序矩阵查找）](https://leetcode-cn.com/problems/sorted-matrix-search-lcci/)
> * **一个算法的最优解与数据状况和问的方式有很大关系，所以可以从这两个出发点开始，思考最优解**。

## Q：打印两个有序链表的公共部分
> * 和外排序类似，使用两个指针，小的指针往后移；如果相等一起移；任意一个链表结束则停止。
> * [《leetcode》（合并两个有序链表）](https://leetcode-cn.com/submissions/detail/57397652/)

- - -
### **对于链表结构题目的优化大部分都是在额外空间复杂度上优化，即从O(N)降到O(1)的**
- - -

## Q：判断一个链表是否为回文结构，时间复杂度为**O(N)**
> * 如果可以使用 **O(N)** 的额外空间复杂度，可以将链表逆序，然后与原链表逐元素比较即可。（**逆序可以用栈来完成**）。
> * 如果要求额外空间复杂度为**O(1)**，则使用快慢指针，找到链表的中部；然后将链表后半部分逆序；从两头往中间走，逐一比较。
> * [《leetcode》（回文链表）](https://leetcode-cn.com/problems/palindrome-linked-list/)

## Q：将单链表按某值划分为左边小、中间相等、右边大；**时间复杂度为O(N)**
> * 链表形式的荷兰国旗问题；如果对空间复杂度没有要求，可以将链表形式转换为数组形式，数组的元素为链表的结点，然后按数组形式的荷兰国旗问题处理。处理完后，再将数组中相邻元素按链表形式相连。
> * 如果要求空间复杂度为**O(1)**，则可以使用`less`、`equal`和`more`指针，然后遍历链表，将相应的结点挂在三个指针后，最后将三个链表首尾相连。
> * [《leetcode》（分割链表）](https://leetcode-cn.com/problems/partition-list-lcci/)（这是荷兰国旗问题的简单版本）

## Q：复制含有随机指针结点的链表，时间复杂度为**O(N)**
> * 本题的关键就是怎么解决原结点和复制后的结点的对应关系，通过原结点可以找到复制结点。
> * 如果空间复杂度可以为**O(N)**，则使用`hashmap`结构（c++中为`unorder_map`），将原结点和复制结点一一对应。第一次遍历链表建立这种一一对应关系，第二次遍历链表处理指向问题。
> * 在原链表上，将每个链表复制一遍，并放在原结点后面，这样就可以通过原结点找到复制结点。然后处理随机指针的指向问题；最后将新的链表从原链表分离出来。
> * [《leetcode》复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)

## Q：两个单链表相交的一系列问题。
> * 判断一个单链表是否有环的方法，如果有返回第一个入环节点。
>   > * 使用`hashset`的结构，每遍历一个结点，先判断`hashset`中是否有此节点，如果有，则有环；如果没有，加入`hashset`。直到链表遍历完毕。
>   > * 快慢指针。如果快指针走到链表尾，则无环；如果快慢指针指向同一个节点，则有环；此时快指针从链表头开始走，并且速度与慢指针相同，再次相遇的节点即为入环节点。(**注意，快慢指针在一开始必须指向同一个节点，否则该结论不成立**)**（这是个结论，记住即可，或者[评论](https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode/)）**
> * [《leetcode》(环形链表)](https://leetcode-cn.com/problems/linked-list-cycle/)
> * 判断两个无环单链表是否相交，如果相交则找出第一个相交的结点？
>   > * 使用`hashset`
>   > * 遍历两个链表，分别求出链表长度和链表最后一个结点。判断两个链表最后一个结点是否为同一个结点，如果不是，则不相交；如果是，则将长链表指针先走两个链表的差值长度，然后两个链表指针一起走，第一次相遇即为第一次相交的节点。
> * [《leetcode》（相交链表）](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)
> * 一个有环单链表和无环单链表不可能相交。
> * 判断两个有环链表是否相交？
>   > * 如果两个有环链表的入环节点相同，则相交；相交节点必定在入环节点之前，将入环节点作为两个单链表的最后一个节点，使用单链表相交的方法查找。
>   > * 如果两个有环链表的入环节点不同，则以一个入环节点为基准，遍历一圈，判断是否碰到另一个入环节点。如果碰上，则相交，返回任意一个入环节点；如果碰不上，则不相交。
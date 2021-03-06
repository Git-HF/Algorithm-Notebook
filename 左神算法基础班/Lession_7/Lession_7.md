## Q：并查集
> * 功能：
>   > * 快速查询某两个元素是否处于同一个集合
>   > * 快速合并两个元素所在的集合，以后这两个集合可以算作同一个集合
> * 一般来说，并查集中每个节点都有一个指针，可以理解成父节点。最后根节点的父节点就是自己。
> * 判断两个元素是否处于同一个集合就是判断两个元素所在并查集的头节点是否是同一个节点（有点像判断两个无环链表是否相交）。
> * 合并两个元素所在集合就是先找到两个元素所在集合头节点，然后将一个头节点的父指针修改为另一个头节点。
> * **并查集优化**：在查找某个节点所在集合的头节点时，将沿途路上的所有元素的父节点都修改为头节点。
> * 对于数据样本为N的并查集，如果查询和合并的次数也是逼进**O(N)** 的，那么每一个此查询或者合并的平均时间复杂度为**O(1)**。
> * [leetcode中并查集代码](source/UnionSet.h)

## Q：对于一个M*N的矩阵，矩阵中每一个元素都为0或者1。每个元素都可以和自己的上下左右相连。如果有一片1连在一起，那么就将这一部分叫做一个岛。求一个矩阵中有多少个岛？
> * **单核**处理情况：利用递归函数，对于每一个节点如果它是1，则设置一个标记，并且递归处理其上下左右的节点。遍历矩阵中所有元素即可（DFS）。
> * **多核**处理情况：将一个大矩阵分块，对于每一个小块递归处理，利用并查集的思想将属于同一个岛的元素拥有相同的父节点。在合并两个小块时，只需要考虑两个小块相邻的边界。如果相邻的两个元素属于不同的并查集，则合并他们，否则处理下一个元素。
> * [《leetcode》(岛屿数量)](https://leetcode-cn.com/problems/number-of-islands/)

## Q：何为前缀树，如何生成前缀树？
> * 生成前缀树时，对于每一个字符串，生成一个路径。如果具有相同前缀的字符串会复用相同的路径。前缀树中，每条路径表示一个字符串，每个节点会存储以该节点结束的字符串的数量和以该节点及以前节点为前缀字符的字符串数量。
> * 前缀树一般提供**增加字符串**、**删除字符串**、**查询字符串(查询字符串被插入了几次)** 和 **查询以某个节点为前缀的字符串数量有多少** 的功能。
> * 建立前缀树的时间复杂度为**O(N*len)**。插入和查询的时间复杂度为**O(len）**，也就是树的高度即**O(logN)**。
> * [《leetcode》(实现Trie（前缀树）)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)
> * 一个前缀树一般对应着好多字符串，而一个后缀树一般对应一个字符串，表示其所有后缀的可能性
> * [前缀树与后缀树详解](https://blog.csdn.net/v_july_v/article/details/6897097)
> * 前缀树的应用
> > * **打字时代码补全**,当输入`ap`,显示以当前字符为前缀的字符串有哪些。例如`app`,`apple`等。
> > * **拼写检查**，当某个单词不在我的字典树中时，很可能该单词拼写错误，所以用特殊东西标出来。
> > * **IP路由匹配**，在进行路由选择时，利用Trie树进行最长前缀匹配算法进行路由选择。
> * 前缀树的优点：
> > * 虽然哈希表的查找效率是**O(1)**,但是无法查找以某个字符串为前缀的所有字符串
> > * 字符串可以按字典序排列出所有字符串，而哈希表不可以。
> > * 当随着样本数增多时，哈希表会出现冲突，时间复杂度可能会增加，或者就是扩容。而字典树不会，字典树查找一个字符串的时间复杂度为**O(len)**，不会改变。当使用平衡时，查找一个字符串的时间复杂度为**O(logn)**（leetcode官方解答说是**O(mlogn)**???）。

## Q：给定N个字符串，将N个小字符串连接成大的字符串，求最终大字符串最小的连接顺序。（贪心算法）
> * **字典序**：
>   > * 当两个字符串比较大小时，如果长度相等，按每一个字符比较；当长度不等时，先将短的字符扩充到和长字符串一样长，然后再比较大小。
> * 将任意两个字符串连接成两种不同的字符串，看两种情况哪种字符串更小，则这两个字符串按按照这种先后顺序连接。将所有字符串都这样排序后，再连接即可。
> * 一般贪心策略的证明很复杂，不用证明。
## 1 说明
这是堂测相关的内容


## 2 个人李姐
反正第一次做都是不会的，你想过了还是错的就不要为难自己了，取模仿别人更好的思路，提取经验就行了

### 2.1 Josephus Problem
肯定不能用链表模拟的性能太低了，根据[约瑟夫问题 - OI Wiki](https://oi-wiki.org/misc/josephus/)、[【新定义数列】约瑟夫环的递推公式，如何推导？详细讲解_哔哩哔哩_bilibili](https://www.bilibili.com/video/BV1c3PQzrEVb/?spm_id_from=333.337.search-card.all.click&vd_source=67359d7dddb7c4db12237b008a0f5370)的讲解
其中有一个难点，也是很难直观接受的点就是为什么将 上一轮淘汰之后的下一个人 重新编号为0，一直这样重复做下去不影响结果？

因为根据迭代的思想我们可以知道
比如说有围成的一个圈，报数是$m$，最后报数到最后一个人剩下的人为$k$
$$
	0,1,2,3\cdots n
$$
那么第$m-1$个人淘汰之后，
$$
	0,1,2\cdots m-2,m,m+1 \cdots n
$$
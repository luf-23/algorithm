package com.task.leetcode;

import com.task.common.ListNode;

public class _206 {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;//初始化前一个节点为空，这个节点将是反转之后链表的头节点
        ListNode curr = head;
        while (curr != null){
            ListNode next = curr.next;//预留下一个节点，方便遍历
            curr.next = prev;//更改当前节点的next指针为前一个节点
            prev = curr;//更新反转之后的链表的头节点，同时为下一轮迭代提供上一个节点
            curr = next;//更新当前节点为下一个节点，继续遍历
        }
        return prev;//返回反转之后的链表的头节点
    }
}

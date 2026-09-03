package com.task.leetcode;

import com.task.leetcode.common.ListNode;

public class _19 {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        if (head != null && head.next==null && n == 1) return null;
        n++;
        ListNode newHead = new ListNode(0);
        newHead.next = head;
        ListNode fast = newHead;
        ListNode slow = newHead;
        while (fast != null && n>0){
            fast = fast.next;
            n--;
        }
        while (fast != null){
            fast = fast.next;
            slow = slow.next;
        }
        if (slow != null && slow.next != null) slow.next = slow.next.next;
        return newHead.next;
    }
}

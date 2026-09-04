package com.task.leetcode;

import com.task.common.ListNode;

public class _24 {
//    public ListNode swapPairs(ListNode head) {
//        if (head == null || head.next == null) return head;
//        ListNode ans = new ListNode(0);
//        ListNode newHead = ans;
//        ListNode cur = head;
//        while (cur != null && cur.next != null) {
//            newHead.next = new ListNode(cur.next.val);
//            newHead.next.next = new ListNode(cur.val);
//            newHead = newHead.next.next;
//            cur = cur.next.next;
//        }
//        return ans.next;
//    }
    public ListNode swapPairs(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode newHead = new ListNode();
        newHead.next = head;
        ListNode cur = newHead;
       while (cur.next != null && cur.next.next != null){
           ListNode pre = cur.next;
           ListNode suf = cur.next.next;
           pre.next = suf.next;
           suf.next = pre;
           cur.next = suf;
           cur = cur.next.next;
       }
        return newHead.next;
    }
}

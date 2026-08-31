package com.task.leetcode;

import com.task.leetcode.common.ListNode;

public class _142 {
    //142. 环形链表II，找环入口
    //从头节点出发的指针和从相遇点出发的指针，每次都走一步，它们一定会在环入口相遇
    public ListNode detectCycle(ListNode head) {
        if (!new _141().hasCycle(head)) return null;
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
            if (slow == fast) break;
        }
        ListNode encounter = fast;
        ListNode begin = head;
        while (begin != encounter){
            begin = begin.next;
            encounter = encounter.next;
        }
        return begin;
    }
}

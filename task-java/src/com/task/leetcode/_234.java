package com.task.leetcode;

import com.task.leetcode.common.ListNode;

public class _234 {
    public boolean isPalindrome(ListNode head) {
        //快慢指针寻找中点
        ListNode slow = head;
        ListNode fast = head;
        while (fast != null && fast.next != null){
            slow = slow.next;
            fast = fast.next.next;
        }
        //ListNode reverse = new _206().reverseList(slow);
        ListNode reverse = null;
        while (slow != null){
            ListNode next = slow.next;
            slow.next = reverse;
            reverse = slow;
            slow = next;
        }
        while (reverse != null){
            if (head.val != reverse.val) return false;
            head = head.next;
            reverse = reverse.next;
        }
        return true;
    }
}

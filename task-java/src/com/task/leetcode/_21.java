package com.task.leetcode;

import com.task.leetcode.common.ListNode;

public class _21 {
    //21. 合并两个有序链表
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) return list2;
        if (list2 == null) return list1;
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
        while (list1 != null && list2 != null){
            ListNode now = new ListNode();
            if (list1.val < list2.val){
                now.val = list1.val;
                list1 = list1.next;
            }else{
                now.val = list2.val;
                list2 = list2.next;
            }
            p.next = now;
            p = p.next;
        }
        while (list1 != null){
            ListNode now = new ListNode(list1.val);
            list1 = list1.next;
            p.next = now;
            p = p.next;
        }
        while (list2 != null){
            ListNode now = new ListNode(list2.val);
            list2 = list2.next;
            p.next = now;
            p = p.next;
        }
        return dummy.next;
    }
}

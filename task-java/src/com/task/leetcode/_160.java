package com.task.leetcode;

import com.task.leetcode.common.ListNode;

import java.util.HashSet;
import java.util.Set;

public class _160 {
//    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
//        Set<ListNode> nodes = new HashSet<>();
//        ListNode ha = headA;
//        while (ha != null){
//            nodes.add(ha);
//            ha = ha.next;
//        }
//        ListNode hb = headB;
//        while (hb != null){
//            if (nodes.contains(hb)) return hb;
//            hb = hb.next;
//        }
//        return null;
//    }

    // Time: O(m+n) Space: O(1)
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode ha = headA;
        ListNode hb = headB;
        while (ha != hb){
            ha = ha == null ? headB : ha.next;
            hb = hb == null ? headA : hb.next;
        }
        return ha;
    }
}

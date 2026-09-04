package com.task.common;

public class DoublyListNode {
    public Object val;
    public DoublyListNode prev;
    public DoublyListNode next;
    public DoublyListNode() {}
    public DoublyListNode(Object val) { this.val = val; }
    public DoublyListNode(Object val, DoublyListNode prev, DoublyListNode next) { this.val = val; this.prev = prev; this.next = next; }
    public static DoublyListNode build(int[] nums) {
        DoublyListNode head = new DoublyListNode(nums[0]);
        DoublyListNode cur = head;
        for (int i = 1; i < nums.length; i++) {
            cur.next = new DoublyListNode(nums[i]);
            cur.next.prev = cur;
            cur = cur.next;
        }
        return head;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        DoublyListNode cur = this;
        while (cur != null) {
            sb.append(cur.val).append(" ");
            cur = cur.next;
        }
        return sb.toString();
    }
}

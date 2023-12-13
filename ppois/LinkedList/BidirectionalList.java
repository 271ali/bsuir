package org.example;
public class BidirectionalList  <T extends Comparable <T>>{
    private Node<T> begin;
    private Node<T> end;
    public BidirectionalList(T info)
    {
        Node<T> node = new Node<T>(info,null,null);
        begin = end = node;
        node=null;
    }
   public void addPrev(T info)
    {
        Node<T> node = new Node<T>(info,null,begin);
        begin.prev = node;
        begin=node;
        node=null;
    }
    public void addNext(T info)
    {
        Node<T> node = new Node<T>(info,end,null);
        end.next = node;
        end = node;
        node=null;
    }
   public void deleteFirst() {
        begin = begin.next;
        begin.prev = null;
    }
    public void deleteLast() {
        end = end.prev;
        end.next = null;
    }
    public void deleteNode(T info)
    {
        Node<T> iter=begin;
        while (iter != null)
        {
            if (iter.info == info)
            {
                (iter.next).prev = iter.prev;
                (iter.prev).next = iter.next;
                iter = null;
                return;
            }
            iter=iter.next;
        }
        System.out.println("No node with the same info");
    }
    public void viewFromBeg()
    {
        Node<T> iter = begin;
        while (iter!=null)
        {
            System.out.println(iter.info);
            iter = iter.next;
        }
    }
    public void viewFromEnd()
    {
        Node<T> iter = end;
        while (iter != null)
        {
            System.out.println(iter.info);
            iter = iter.prev;
        }
    }
    public void changeFirstAndLast()
    {
        Node<T> t=new Node<T>(begin.info,begin.prev,begin.next);
        Node<T> n=new Node<T>(end.info,end.prev,end.next);
        (t.next).prev=n;
        (n.prev).next=t;
        t.prev=n.prev;
        n.next=t.next;
        t.next=null;
        n.prev=null;
        begin=n;
        end=t;
    }
    public Node<T> findNote(T info)
    {
        Node<T> iter=begin;
        while(iter!=null)
        {
            if(iter.info==info) return iter;
            iter=iter.next;
        }
        return null;
    }
    public Node<T> getMax()
    {
      Node<T> iter=begin;
      Node<T> max=begin;
      while(iter!=null)
      {
          if(iter.info.compareTo(max.info)>0) max=iter;
          iter=iter.next;
      }
      return max;
    }
    public Node<T> getMin()
    {
        Node<T> iter=begin;
        Node<T> min=begin;
        while(iter!=null)
        {
            if(iter.info.compareTo(min.info)<0) min=iter;
            iter=iter.next;
        }
        return min;
    }

    public void swapMinMax() {
        Node<T> min = getMin();
        Node<T> max = getMax();

        if (min == max) {
            return;
        }

        if (min.prev == null) {
            begin = max;
        }

        if (max.prev == null) {
            begin = min;
        }
        if (min.next == null) {
            end = max;
        }

        if (max.next == null) {
            end = min;
        }

        if (min.next == max) {
            Node<T> minPrev = min.prev;
            Node<T>maxNext = max.next;
            min.prev = max;
            min.next = maxNext;
            max.prev = minPrev;
            max.next = min;
            if (minPrev != null) {
                minPrev.next = min;
            }
            if (maxNext != null) {
                maxNext.prev = max;
            }
            return;
        }
        Node<T> minNodePrev = min.prev;
        Node <T> minNodeNext = min.next;
        Node<T> maxNodePrev = max.prev;
        Node<T> maxNodeNext = max.next;
        min.prev = maxNodePrev;
        min.next = maxNodeNext;
        max.prev = minNodePrev;
        max.next = minNodeNext;
        if (minNodePrev != null) {
            minNodePrev.next = max;
        }
        if (minNodeNext != null) {
            minNodeNext.prev = max;
        }
        if (maxNodePrev != null) {
            maxNodePrev.next = min;
        }
        if (maxNodeNext != null) {
            maxNodeNext.prev = min;
        }
    }

}

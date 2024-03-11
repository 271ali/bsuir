package org.example;
public class BidirectionalList  <T extends Comparable <T>>{
    private Node<T> begin;
    private Node<T> end;
    public BidirectionalList(T info)
    {
        Node<T> node = new Node<T>(info,null,null);
        begin = end = node;
    }
   public void addPrev(T info)
    {
        Node<T> node = new Node<T>(info,null,begin);
        begin.setPrev(node) ;
        begin=node;
    }
    public void addNext(T info)
    {
        Node<T> node = new Node<T>(info,end,null);
        end.setNext(node);
        end = node;
    }
   public void deleteFirst() {
        begin = begin.getNext();
        begin.setPrev(null);
    }
    public void deleteLast() {
        end = end.getPrev();
        end.setNext(null);//доделать узел перед end
    }
    public void deleteNode(T info)
    {
        Node<T> iter=begin;
        while (iter != null)
        {
            if (iter.getInfo() == info)
            {
                (iter.getNext()).setPrev(iter.getPrev());
                (iter.getPrev()).setNext(iter.getNext());
                iter = null;
                return;
            }
            iter=iter.getNext();
        }
        System.out.println("No node with the same info");
    }
    public void viewFromBeg()
    {
        Node<T> iter = begin;
        while (iter!=null)
        {
            System.out.println(iter.getInfo());
            iter = iter.getNext();
        }
    }
    public void viewFromEnd()
    {
        Node<T> iter = end;
        while (iter != null)
        {
            System.out.println(iter.getInfo());
            iter = iter.getPrev();
        }
    }
    public void changeFirstAndLast()
    {
        Node<T> t=new Node<T>(begin.getInfo(),begin.getPrev(),begin.getNext());
        Node<T> n=new Node<T>(end.getInfo(),end.getPrev(),end.getNext());
        (t.getNext()).setPrev(n);
        (n.getPrev()).setNext(t);
        t.setPrev(n.getPrev());
        n.setNext(t.getNext());
        t.setNext(null);
        n.setPrev(null);
        begin=n;
        end=t;
    }
    public Node<T> findNote(T info) throws IllegalArgumentException
    {
        Node<T> iter=begin;
        while(iter!=null)
        {
            if(iter.getInfo()==info) return iter;
            iter=iter.getNext();
        }
        throw new IllegalArgumentException("Нет узла с такой информацией");
    }
    public Node<T> getMax()
    {
      Node<T> iter=begin;
      Node<T> max=begin;
      while(iter!=null)
      {
          if(iter.getInfo().compareTo(max.getInfo())>0) max=iter;
          iter=iter.getNext();
      }
      return max;
    }
    public Node<T> getMin()
    {
        Node<T> iter=begin;
        Node<T> min=begin;
        while(iter!=null)
        {
            if(iter.getInfo().compareTo(min.getInfo())<0) min=iter;
            iter=iter.getNext();
        }
        return min;
    }

    public void swapMinMax() {
        Node<T> min = getMin();
        Node<T> max = getMax();

        if (min == max) {
            return;
        }

        if (min.getPrev() == null) {
            begin = max;
        }

        if (max.getPrev() == null) {
            begin = min;
        }
        if (min.getNext() == null) {
            end = max;
        }

        if (max.getNext() == null) {
            end = min;
        }

        if (min.getNext() == max) {
            Node<T> minPrev = min.getPrev();
            Node<T>maxNext = max.getNext();
            min.setPrev(max);
            min.setNext(maxNext);
            max.setPrev(minPrev);
            max.setNext(min);
            if (minPrev != null) {
                minPrev.setNext(min);
            }
            if (maxNext != null) {
                maxNext.setPrev(max);
            }
            return;
        }
        Node<T> minNodePrev = min.getPrev();
        Node <T> minNodeNext = min.getNext();
        Node<T> maxNodePrev = max.getPrev();
        Node<T> maxNodeNext = max.getNext();
        min.setPrev(maxNodePrev);
        min.setNext(maxNodeNext);
        max.setPrev(minNodePrev);
        max.setNext(minNodeNext);
        if (minNodePrev != null) {
            minNodePrev.setNext(max);
        }
        if (minNodeNext != null) {
            minNodeNext.setPrev(max);
        }
        if (maxNodePrev != null) {
            maxNodePrev.setNext(min);
        }
        if (maxNodeNext != null) {
            maxNodeNext.setPrev(min);
        }
    }

}

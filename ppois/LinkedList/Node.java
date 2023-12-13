package org.example;

public class Node <T extends Comparable <T>>{
    Node(T info,Node<T> prev,Node<T> next)
    {
        this.info=info;
        this.prev=prev;
        this.next=next;
    }
    T info;
    Node<T> prev;
    Node<T> next;

    public Node<T> getNext() {
        return next;
    }

    public Node<T> getPrev() {
        return prev;
    }

    public T getInfo() {
        return info;
    }
}

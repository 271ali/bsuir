package org.example;

public class Node <T extends Comparable <T>>{
    Node(T info,Node<T> prev,Node<T> next)
    {
        this.info=info;
        this.prev=prev;
        this.next=next;
    }
    private T info;
    private Node<T> prev;
    private Node<T> next;

    public Node<T> getNext() {
        return next;
    }

    public Node<T> getPrev() {
        return prev;
    }

    public T getInfo() {
        return info;
    }

    public void setInfo(T info) {
        this.info = info;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }

    public void setPrev(Node<T> prev) {
        this.prev = prev;
    }
}

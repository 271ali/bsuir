package org.example;

public class Book implements Comparable<Book> {
    private String name;
    private String author;
    private int year;
    public Book(String name, String author, int year)
    {
        this.author=author;
        this.name=name;
        this.year=year;
    }
    public String getName()
    {
        return name;
    }
    public String getAuthor()
    {
        return author;
    }
    public int getYear()
    {
        return year;
    }

    @Override
    public int compareTo(Book anotherBook)
    {
       return year-anotherBook.getYear();
    }

    @Override
    public String toString() {
        return "Book: " +
                "Author=" + author +
                ", name=" + name +
                ", year=" + year;
    }


}

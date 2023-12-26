import org.junit.jupiter.api.Assertions;
import org.example.Book;
import org.example.BidirectionalList;
import org.junit.jupiter.api.Test;
public class BidirectionalListTest {

    @Test
    void addPrev()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addPrev(book2);
        Assertions.assertEquals(list.findNote(book2) ,list.findNote(book1).getPrev());
    }
    @Test
    void addNext()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book3);
        Assertions.assertEquals(list.findNote(book3) ,list.findNote(book1).getNext());
    }

    @Test
    void deleteFirst()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book2);
        list.addNext(book3);
        list.deleteFirst();
        Assertions.assertNull(list.findNote(book2).getPrev());
    }
    @Test
    void deleteLast()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book2);
        list.addNext(book3);
        list.deleteLast();
        Assertions.assertNull(list.findNote(book2).getNext());
    }
    @Test
    void deleteNode()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book2);
        list.addNext(book3);
        list.deleteNode(book2);
        Assertions.assertEquals(list.findNote(book1).getNext() ,list.findNote(book3));
        //Assertions.assertEquals(list.findNote(book3).prev ,list.findNote(book1));
    }
    @Test
    public void changeFirstAndLast()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book2);
        list.addNext(book3);
        list.changeFirstAndLast();
        Assertions.assertEquals(list.findNote(book2).getNext(),list.findNote(book1));
        Assertions.assertEquals(list.findNote(book2).getPrev(),list.findNote(book3));
    }

    @Test
    public void getMax()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book2);
        list.addNext(book3);
        Assertions.assertEquals(list.findNote(book2),list.getMax());
    }
    @Test
    public void getMin()
    {   Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book1);
        list.addNext(book2);
        list.addNext(book3);
        Assertions.assertEquals(list.findNote(book3),list.getMin());
    }
    @Test
    public void swapMinMax()
    {
        Book book1 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3= new Book("Dracula", "Bram Stoker", 1897);
        BidirectionalList<Book> list=new BidirectionalList<Book>(book2);
        list.addNext(book1);
        list.addNext(book3);
        list.swapMinMax();
        Assertions.assertEquals(list.findNote(book1).getNext(),list.findNote(book2));
        Assertions.assertEquals(list.findNote(book1).getPrev(),list.findNote(book3));
        Assertions.assertEquals(list.findNote(book2).getPrev(),list.findNote(book1));
        Assertions.assertEquals(list.findNote(book3).getNext(),list.findNote(book1));
    }

}

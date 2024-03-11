
import java.util.Arrays;
import java.util.ArrayList;
import java.util.Comparator;

import static org.junit.jupiter.api.Assertions.assertTrue;
import org.junit.jupiter.api.Test;

public class PatienceSortTest {
    boolean arrayEquals(Book[] books1, Book[] books2) {
        if (books1.length != books2.length) return false;
        for (int i = 0; i < books1.length; i++) {
            if (books1[i].getName().equals(books2[i].getName())) {
                if (books1[i].getAuthor().equals(books2[i].getAuthor())) {
                    if (books1[i].getYear() == books2[i].getYear()) {
                        continue;
                    } else return false;
                } else return false;
            } else return false;
        }
        return true;
    }

    boolean arrayListEquals(ArrayList<Book> books1, ArrayList<Book> books2) {
        if (books1.size() != books2.size()) return false;
        for (int i = 0; i < books1.size(); i++) {
            if (books1.get(i).getName().equals(books2.get(i).getName())) {
                if (books1.get(i).getAuthor().equals(books2.get(i).getAuthor())) {
                    if (books1.get(i).getYear() == books2.get(i).getYear()) {
                        continue;
                    } else return false;
                } else return false;
            } else return false;
        }
        return true;
    }


    @Test
    void patienceSortArray() {
        Book[] array = {
                new Book("Dracula", "Bram Stoker", 1897),
                new Book("Perfume", "Patrick Suskind", 1985),
                new Book("Gone with the wind", "Margaret Mitchell", 1936)

        };
        Book[] result = {
                new Book("Dracula", "Bram Stoker", 1897),
                new Book("Gone with the wind", "Margaret Mitchell", 1936),
                new Book("Perfume", "Patrick Suskind", 1985),
        };
        PatienceSort sort = new PatienceSort();
        sort.patienceSort(array);
        assertTrue(arrayEquals(array, result));
    }

    @Test
    void patienceSortArrayWithComparator() {
        Book[] array = {
                new Book("The Shining", "Stephen King", 1977),
                new Book("It", "Stephen King", 1986),
                new Book("Carrie", "Stephen King", 1974)

        };
        Book[] result = {
                new Book("Carrie", "Stephen King", 1974),
                new Book("It", "Stephen King", 1986),
                new Book("The Shining", "Stephen King", 1977),
        };
        PatienceSort sort = new PatienceSort();
        sort.patienceSort(array, new BookComparator());
        assertTrue(arrayEquals(array, result));
    }

    @Test
    void patienceSortArrayList() {
        Book book1 = new Book("Dracula", "Bram Stoker", 1897);
        Book book2 = new Book("Perfume", "Patrick Suskind", 1985);
        Book book3 = new Book("Gone with the wind", "Margaret Mitchell", 1936);
        ArrayList<Book> vector = new ArrayList<Book>();
        vector.add(book2);
        vector.add(book1);
        vector.add(book3);
        ArrayList<Book> result = new ArrayList<Book>();
        result.add(book1);
        result.add(book3);
        result.add(book2);
        PatienceSort sort = new PatienceSort();
        sort.patienceSort(vector);
        assertTrue(arrayListEquals(vector, result));
    }
    @Test
    void patienceSortArrayListWithComparator() {
        Book book1 =  new Book("The Shining", "Stephen King", 1977);
        Book book2 = new Book("It", "Stephen King", 1986);
        Book book3 =  new Book("Carrie", "Stephen King", 1977);
        ArrayList<Book> vector = new ArrayList<Book>();
        vector.add(book2);
        vector.add(book1);
        vector.add(book3);
        ArrayList<Book> result = new ArrayList<Book>();
        result.add(book3);
        result.add(book2);
        result.add(book1);
        PatienceSort sort = new PatienceSort();
        sort.patienceSort(vector, new BookComparator());
        assertTrue(arrayListEquals(vector, result));
    }
}


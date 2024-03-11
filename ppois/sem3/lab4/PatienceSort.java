import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.Comparator;

public class PatienceSort {
    public static <T extends Comparable <T>> void patienceSort(T[] array) {
        List<Stack<T>> piles = new ArrayList<>();
        findPile(array,piles);
        int index = 0;
        while (!piles.isEmpty()) {
            int minIndex = minPileIndex(piles);
            Stack<T> minPile = piles.get(minIndex);
            array[index] = minPile.pop();
            if (minPile.isEmpty()) {
                piles.remove(minIndex);
            }
            index++;
        }
    }
    public static <T> void patienceSort(T[] array,Comparator <T> comparator) {
        List<Stack<T>> piles = new ArrayList<>();
       findPile(array,piles,comparator);
        int index = 0;
        while (!piles.isEmpty()) {
            int minIndex = minPileIndex(piles,comparator);
            Stack<T> minPile = piles.get(minIndex);
            array[index] = minPile.pop();
            if (minPile.isEmpty()) {
                piles.remove(minIndex);
            }
            index++;
        }
    }
    public static <T extends Comparable <T>> void patienceSort(ArrayList<T> arrayList) {
        List<Stack<T>> piles = new ArrayList<>();
        findPile(arrayList,piles);
        int index = 0;
        while (!piles.isEmpty()) {
            int minIndex = minPileIndex(piles);
            Stack<T> minPile = piles.get(minIndex);
            arrayList.set(index,minPile.pop());
            if (minPile.isEmpty()) {
                piles.remove(minIndex);
            }
            index++;
        }
    }
    public static <T> void patienceSort(ArrayList<T> arrayList,Comparator <T> comparator) {
        List<Stack<T>> piles = new ArrayList<>();
        findPile(arrayList,piles,comparator);
        int index = 0;
        while (!piles.isEmpty()) {
            int minIndex = minPileIndex(piles,comparator);
            Stack<T> minPile = piles.get(minIndex);
            arrayList.set(index,minPile.pop());
            if (minPile.isEmpty()) {
                piles.remove(minIndex);
            }
            index++;
        }
    }

    private static<T extends Comparable <T>> int minPileIndex(List<Stack<T>> piles) {
        int minIndex = 0;
        for (int i = 1; i < piles.size(); i++) {
            if (piles.get(i).peek().compareTo(piles.get(minIndex).peek())<0)
            {
                minIndex = i;
            }
        }
        return minIndex;
    }
    private static<T> int minPileIndex(List<Stack<T>> piles,Comparator<T> comparator) {
        int minIndex = 0;
        for (int i = 1; i < piles.size(); i++) {
            if (comparator.compare(piles.get(i).peek(),piles.get(minIndex).peek())<0)
            {
                minIndex = i;
            }
        }
        return minIndex;
    }
    private static<T extends Comparable <T>>void findPile( T[] array,List<Stack<T>> piles)
    {
        for (T item : array)
        {
            boolean placed = false;
            for (Stack<T> pile : piles) {
                if (item.compareTo(pile.peek())<0) {
                    pile.push(item);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                Stack<T> newPile = new Stack<>();
                newPile.push(item);
                piles.add(newPile);
            }
        }
    }
    private static<T extends Comparable <T>>void findPile(ArrayList<T> arrayList,List<Stack<T>> piles)
    {
        for (T item : arrayList) {
            boolean placed = false;
            for (Stack<T> pile : piles) {
                if (item.compareTo(pile.peek())<0) {
                    pile.push(item);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                Stack<T> newPile = new Stack<>();
                newPile.push(item);
                piles.add(newPile);
            }
        }
    }
    private static<T>void findPile( T[] array,List<Stack<T>> piles,Comparator<T> comparator)
    {
        for (T item : array) {
            boolean placed = false;
            for (Stack<T> pile : piles) {
                if (comparator.compare(item,pile.peek())<0) {
                    pile.push(item);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                Stack<T> newPile = new Stack<>();
                newPile.push(item);
                piles.add(newPile);
            }
        }
    }
    private static<T>void findPile(ArrayList<T> arrayList,List<Stack<T>> piles,Comparator<T> comparator)
    {
        for (T item : arrayList) {
            boolean placed = false;
            for (Stack<T> pile : piles) {
                if (comparator.compare(item,pile.peek())<0) {
                    pile.push(item);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                Stack<T> newPile = new Stack<>();
                newPile.push(item);
                piles.add(newPile);
            }
        }
}  }
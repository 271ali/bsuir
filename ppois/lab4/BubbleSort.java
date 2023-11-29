import java.util.Comparator;
import java.util.ArrayList;
public class BubbleSort {

    public <T extends Comparable <T>> void bubbleSort(T[] array)
    {
        if(array==null || array.length==0) return;
        for (int i = 0; i < array.length - 1; i++)
        {
            for (int j = i + 1; j < array.length; j++)
            {
                if (array[i].compareTo(array[j])>0)
                {
                    T t=array[i];
                    array[i]=array[j];
                    array[j]=t;
                }
            }
        }
    }
    public <T> void bubbleSort(T[] array,Comparator<T> comparator)
    {
        if(array==null || array.length==0 || comparator==null) return;
        for (int i = 0; i < array.length- 1; i++)
        {
            for (int j = i + 1; j < array.length; j++)
            {
                if (comparator.compare(array[i],array[j])>0)
                {
                    T t=array[i];
                    array[i]=array[j];
                    array[j]=t;
                }
            }
        }
    }
    public <T extends Comparable <T>> void bubbleSort(ArrayList<T> arrayList)
    {
        if(arrayList==null || arrayList.size()==0) return;
        for (int i = 0; i < arrayList.size()- 1; i++)
        {
            for (int j = i + 1; j < arrayList.size(); j++)
            {
                if (arrayList.get(i).compareTo(arrayList.get(j))>0) {
                    T t = arrayList.get(i);
                    arrayList.set(i, arrayList.get(j));
                    arrayList.set(j, t);
                }
            }
        }
    }
    public <T> void bubbleSort(ArrayList<T> arrayList,Comparator<T> comparator)
    {
        if(arrayList==null || arrayList.size()==0 || comparator==null) return;
        for (int i = 0; i < arrayList.size()- 1; i++)
        {
            for (int j = i + 1; j < arrayList.size(); j++)
            {
                if (comparator.compare(arrayList.get(i),arrayList.get(j))>0) {
                    T t = arrayList.get(i);
                    arrayList.set(i, arrayList.get(j));
                    arrayList.set(j, t);
                }
            }
        }
    }

}

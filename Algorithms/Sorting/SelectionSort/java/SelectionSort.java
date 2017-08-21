import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class SelectionSort {

	List<Integer> selectionSort(List<Integer> list)
	{
		List<Integer> ret = new ArrayList<Integer>();
		int len = list.size();
		for (int foo = 0; foo < len; foo++)
		{
			int idx=0;
			for (int i = 1; i<list.size(); i++)
				if (list.get(i)<list.get(idx))
					idx=i;
			ret.add(list.get(idx));
			System.out.println(idx);
			list.remove(idx);

			System.out.println(list.size());
		}
		return ret;
	}

	void printList(List<Integer> list)
	{
		int len = list.size();
		for (int i=0; i<list.size(); ++i)
		{
			System.out.print(list.get(i));
			if(i<len-1)
				System.out.print(", ");
		}
		System.out.println();
	}

	// main func
	public static void main(String args[])
	{
		System.out.println("Bubble Sort!");
		
		SelectionSort bs = new SelectionSort();
		Integer[] int_list = new Integer[] {1,5,2,0,88,12,3};
		List<Integer> list = Arrays.asList(int_list);
		
		System.out.println(list);
		
		List<Integer> sorted_list=bs.selectionSort(list);
		System.out.println("Sorted array");
		bs.printList(sorted_list);
	}
}
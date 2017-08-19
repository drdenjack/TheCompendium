class BubbleSort {

	void bubbleSort(int arr[])
	{
		int len = arr.length;
		for (int foo = 0; foo < len; foo++)
			for (int i = 0; i<len-1; i++)
				if (arr[i+1]<arr[i])
				{
					int tmp = arr[i];
					arr[i] = arr[i+1];
					arr[i+1] = tmp;
				}
	}

	void printArray(int arr[])
	{
		int len = arr.length;
		for (int i=0; i<len; ++i)
		{
			System.out.print(arr[i]);
			if(i<len-1)
				System.out.print(", ");
		}
		System.out.println();
	}

	// main func
	public static void main(String args[])
	{
		System.out.println("Bubble Sort!");
		
		BubbleSort bs = new BubbleSort();
		int arr[] = {1,5,2,0,88,12,3};

		System.out.println("Original array");
		bs.printArray(arr);
		
		bs.bubbleSort(arr);
		System.out.println("Sorted array");
		bs.printArray(arr);
	}
}
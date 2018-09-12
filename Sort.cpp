void selectionSort(vector<int>& v)
{
	int minIdx;
	for(int i = 0; i < n - 1; i++)
	{
		minIdx = i;
		for(int j = i + 1; j < n; j++)
		{
			if (v[j] < v[minIdx])
				minIdx = j;
		}
		swap(v[minIdx], v[i]);
	}	
}

void insertionSort(vector<int>& v)
{
	for(int i = 1; i < n; i++)
	{
		key = v[i];
		j = i - 1;
		while(j >= 0 && v[j] > key)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = key;
	}
}

void bubbleSort(vector<int>& v)
{
	for(int i = 0; i < n -1; i++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}
	}
}

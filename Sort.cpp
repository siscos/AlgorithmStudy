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

void mergeSort(vector<int>& v, int low, int high)
{
    if (low < high)
    {
	int middle = (low + high) / 2;
	mergeSort(v, low, middle);
	mergeSort(v, middle + 1, high);
	merge(v, low, middle, high);
    }
}

void merge(vector<int>& v, int low, int middle, int high)
{
    vector<int> helper(v.size());
    for(int i = low; i <= high; i++)
	helper[i] = v[i];

    int helperLeft = low;
    int helperRight = middle + 1;
    int current = low;

    while(helperLeft <= middle && helperRight <= high)
    {
	if (helper[helperLeft] <= helper[helperRight])
	{
	    v[current] = helper[helperLeft];
	    helperLeft++;
	}
	else
	{
	    v[current] = helper[helperRight];
	    helperRight++;
	}
	current++;
    }
    // 왼쪽에 절반 배열에 남은 원소들을 원래 배열에 복사
    int remaining = middle - helperLeft;
    for(int i = 0; i <= remaining; i++)
	v[current + i] = helper[helperLeft + i];
}

void quickSort(vector<int>& v, int left, int right)
{
    int index = partition(v, left, right);
    if (left < index - 1)
	quickSort(v, left, index - 1);
    else
	quickSort(v, index, right);
}

void partition(vector<int>& v, int left, int right)
{
    int pivot = v[(left + right) / 2];
    while(left <= right)
    {
	while(arr[left] < pivot) 
	    left++;

	while(arr[right] > pivot)
	    right--;

	// 원소들의 자리를 바꾸고 left, right 이동
	if (left <= right)
	{
	    swap(v[left], v[right]);
	    left++;
	    right--;
	}
    }
    return left;
}

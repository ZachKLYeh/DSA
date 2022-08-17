template <typename T>
void merge(const vector<T>& data, vector<T>& out, const int s, const int M, const int N) {
	//s&M指向兩個子集合相應的位置
	//data是輸入的數列，out是輸出的數列
	int i = s, j = M + 1, k = s;
	while (i <= M && j <= N) { //兩個序列都還有數據
		if (data[i] < data[j]) 
			out[k++] = data[i++];
		else
			out[k++] = data[j++];
	} //序列剩餘數據依次寫入目標序列
	while (i <= M) 
		out[k++] = data[i++];
	while (j <= N) 
		out[k++] = data[j++];
}

template <typename T>
void copy(const vector<T>& B, vector<T>& A, int s, int e) {
	//拷貝B到A內；s,t為範圍
	for (int i = s; i <= e; i++)
		A[i] = B[i];
}

template <typename T>
void merge_sort(vector<T>& A, int s, int t) {
	if (s == t) { return; } //代表已經排序好，可以直接傳回
	merge_sort(A, s, (s + t) / 2); //解決此區間(s,(s + t) / 2)的遞迴問題
	merge_sort(A, (s + t) / 2 + 1, t); //解決另一區間的問題
	vector<T> B(A.size()); //定義數列B
	merge(A, B, s, (s + t) / 2, t); //將A內的元素和B( s, (s + t) / 2, t)區間合併
	copy(B, A, s, t); //拷貝B至A內可以保證排序好的數列不會再被動到
}

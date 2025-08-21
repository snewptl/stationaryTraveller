struct dsu {
	vector<int> ds, wt;
	dsu(int n) {
		ds.assign(n, -1);
		wt.assign(n, INT_MAX);
	}
	int find(int i) {
		return ds[i] < 0 ? i : find(ds[i]);
	}
	void merge(int i, int j, int weight) {
		i = find(i), j = find(j);
		if (i != j) {
			if (ds[i] > ds[j])
				swap(i, j);
			ds[i] += ds[j], ds[j] = i;
			wt[j] = weight;
		}
	}
	int weight(int i, int j) {
		int w = 0;
 
		while (i != j) {
			if (wt[i] < wt[j])
				w = wt[i], i = ds[i];
			else
				w = wt[j], j = ds[j];
		}
		return w;
	}
};
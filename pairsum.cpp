vector<vector<int>> pairSum(vector<int> &arr, int s){
    int n=arr.size();
   sort(arr.begin(),arr.end());
	vector<vector<int>> v;
    for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if((arr[i]+arr[j])==s)
				v.push_back({arr[i],arr[j]});
		}
	}
	return v;
}

class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }

    queue<pair<int, int>> sortFreqs(map<int, int>& frequencies){
        vector<pair<int, int>> sorter;
        queue<pair<int, int>> result;

        for(auto& x : frequencies){
            sorter.push_back(x);
        }

        sort(sorter.begin(), sorter.end(), cmp);

        for(pair<int, int>& x : sorter){
            result.push(x);
        }
        return result;
    }
    
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int, int> frequencies;
        for(int x : arr){
            if(frequencies.find(x) == frequencies.end()){
                frequencies[x] = 1;
            }
            else {
                frequencies[x] = frequencies[x] + 1;
            }
        }

        queue<pair<int, int>> sortedFreqs = sortFreqs(frequencies);

        int frontFreq = sortedFreqs.front().second;
        while(k >= frontFreq){
            //cout << k << ' ' << sortedFreqs.size() << ' ' << sortedFreqs.front().first << ' ' << sortedFreqs.front().second << '\n';
            k = k - frontFreq;
            sortedFreqs.pop();
            if(sortedFreqs.empty()){
                return 0;
            }
            else {
                frontFreq = sortedFreqs.front().second;
            }
        }

        return sortedFreqs.size();
    }
};

class Solution {
public:
    int shortestWay(string source, string target) {
        int n = target.size(), m = source.size(), res = 0;
        
        for(int i = 0; i < n;){
            int j = 0;
            int flg = 0;
            for(int j = 0; j < m;){
                // at least one match for the source vs target, increment both indices
                if(target[i] == source[j]){
                    i++;
                    j++;
                    flg = 1; 
                }
                // try the best matching target with source, if not match, increment the position in source
                else{
                    j++;                    
                }
            }
            // does not match any character in source vs target, early stop
            if(!flg){
                return -1;
            }
            // complete a matching
            res++;
        }
        return res;
    }
};

// follow up 2: fine. what's the time complexity for above solutions. O(MN). could u make it better?
// the time complexity is better than O (MN), should be O(logM * N) or O (N)
// to find a logM way, it is easy to think of binary search. for each char in tar, we need loop from j to end, to find a char same as tar[i].
// we can build a map which key is from 'a' -> 'z', the value is idx for this char in src. because idx is add from small to big. when we iterate tar[i], we can easily to find the tar[i]'s idx list. to search is there a idx is larger or equal than j+1. it is logM. and we have N char in tar, so the time complexity is N * logM
// the time is to build the map is O(M);

// public int shortestWay(String source, String target) {
// 	char[] cs = source.toCharArray(), ts = target.toCharArray();
// 	int res = 1;
// 	List<Integer>[] idx = new List[26];
// 	for (int i = 0; i < 26; i++) idx[i] = new ArrayList<>();
// 	for (int i = 0; i < cs.length; i++) idx[cs[i] - 'a'].add(i);
// 	int j = 0;
// 	for (int i = 0; i < ts.length; ) {
// 		List<Integer> tar = idx[ts[i] - 'a'];
// 		if (tar.isEmpty()) return -1;
// 		int k = Collections.binarySearch(tar,j);
// 		if (k < 0) k = -k - 1;
// 		if (k == tar.size()) {
// 			res++;
// 			j = 0;
// 		} else {
// 			j = tar.get(k) + 1;
// 			i++;
// 		}

// 	}
// 	return res;
// }
// follow up 3: great. could u improve it more?
// so we have to think a solution which is O(N), how should we use O(1) to know the next J pos?
// maybe we can use more to save time.
// in binary search solution we will have a map like a ->{1,3,7,16} (total src length is 20), so we need binary search.
// if we can flatten them, i mean for each pos in 20 length, we just save the next idx, we can use O 1 to find the next J.
// a -> {1,1,3,3,7,7,7,7,16,16,16,16,16,16,16,16,16,0,0,0}
// for example if now j is 4, we can just check map[4] = 7; we know 7 pos have an 'a', so next j will be 7 + 1.
// if now j is 17, we get map[17] = 0, we know there is no more j after. so j = 0, res++;
// the time complexity is O (N) , and build the map cost 26 * M

// public int shortestWay(String source, String target) {
// 	char[] cs = source.toCharArray(), ts = target.toCharArray();
// 	int[][] idx = new int[26][cs.length];
// 	for (int i = 0; i < cs.length; i++) idx[cs[i] - 'a'][i] = i + 1;
// 	for (int i = 0; i < 26; i++) {
// 		for (int j = cs.length - 1, pre = 0; j >= 0; j--) {
// 			if (idx[i][j] == 0) idx[i][j] = pre;
// 			else pre = idx[i][j];
// 		}
// 	}
// 	int res = 1, j = 0;
// 	for (int i = 0; i < ts.length; i++) {
// 		if (j == cs.length) {
// 			j = 0;
// 			res++;
// 		}
// 		if (idx[ts[i] - 'a'][0] == 0) return -1;
// 		j = idx[ts[i] - 'a'][j];
// 		if (j == 0 ) {
// 			res++;
// 			i--;
// 		}
// 	}
// 	return  res;
// }
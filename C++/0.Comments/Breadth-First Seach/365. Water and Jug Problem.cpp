class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
		if (z > x + y || z < 0) {
			return false;
		} else if (z == x || z == y || z == x + y) {
			return true;
		}
		
		int smaller = min(x, y); 
		int larger = max(x, y);
		return bfs(smaller, larger, z, 0);
    }
private:
	bool bfs(int smaller, int larger, int z, int water) {
		unordered_set<int> visited;
		queue<int> myqueue;
		
		myqueue.push(water);
		visited.insert(water);
		while (!myqueue.empty()) {
			int curr = myqueue.front();
			//visited.insert(curr);
			if (curr == z) {
				return true;
			}
			myqueue.pop();
			
			// 3 cases
			vector<int> next;
			if (curr < smaller) {
				next.push_back(larger - (smaller - curr));
			} else if (curr < larger) {
				next.push_back(curr - smaller);
			} else if (curr < larger + smaller) {
				next.push_back(curr - smaller);
				next.push_back(curr - larger);
			}
		
			while(curr < larger && smaller > 0) {
				curr += smaller;
				next.push_back(curr);
			}
			
			for (int i : next) {
				if (visited.find(i) == visited.end()) {
					visited.insert(i);
					myqueue.push(i);
				}
			}
		}
		return false;
	}
};
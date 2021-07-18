class UndergroundSystem {
    
    unordered_map<int, pair<string, int>> customers;
    unordered_map<string, pair<int, int>> trips;
    
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        customers[id].first = stationName;
        customers[id].second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string trip = customers[id].first + "_" + stationName;
        int duration = t - customers[id].second;
        trips[trip].first++;
        trips[trip].second += duration;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string trip = startStation + "_" + endStation;
        return 1.0 * trips[trip].second / trips[trip].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
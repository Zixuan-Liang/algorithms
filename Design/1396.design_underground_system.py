class UndergroundSystem:

    def __init__(self):
        self.customers = {}
        self.stations = {}

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.customers[id] = [stationName, t]

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startStation = self.customers[id][0]
        startTime = self.customers[id][1]
        self.customers[id] = []
        if startStation not in self.stations:
            self.stations[startStation] = {}
        if stationName not in self.stations[startStation]:
            self.stations[startStation][stationName] = [0, 0]
        prev_avg, prev_num = self.stations[startStation][stationName]
        update_num = prev_num + 1
        update_avg = (prev_avg * prev_num + t - startTime) / update_num
        self.stations[startStation][stationName] = [update_avg, update_num]

    def getAverageTime(self, startStation: str, endStation: str) -> float:
        if startStation not in self.stations:
            self.stations[startStation] = {}
        if endStation not in self.stations[startStation]:
            self.stations[startStation][endStation] = [0, 0]
        return self.stations[startStation][endStation][0]


# Your UndergroundSystem object will be instantiated and called as such:
# obj = UndergroundSystem()
# obj.checkIn(id,stationName,t)
# obj.checkOut(id,stationName,t)
# param_3 = obj.getAverageTime(startStation,endStation)
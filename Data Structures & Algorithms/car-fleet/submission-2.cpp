class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        for (int i = 0; i < speed.size(); i++){
            cars.push_back({position[i], speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<pair<int,int>>());
        int fleets = 1; 
        double fleet_time = (double)(target - cars[0].first)/cars[0].second;
        for (int i = 1; i < cars.size(); i++){
            double time = (double)(target - cars[i].first)/cars[i].second;
            if (time > fleet_time){
                fleets++;
                fleet_time = time;
            }
        }
        return fleets;
    }
};

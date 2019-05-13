/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */
class Solution {
public:
    
    void dfs(set<pair<int,int>> &used, int x, int y, int d, Robot& robot) {
        // cout << "c" << x << "," << y;
        robot.clean();
        used.insert({x, y});
        
        //Turn to dir 0;
        for (int i = 0 ; i < d; i++) {
            robot.turnLeft();
        }
        
        
        //Try all four ways
        int count = 0;
        if (used.find({x + 1, y}) == used.end()) {
            if (robot.move()) {
                dfs(used, x + 1, y, 0, robot);
                robot.turnRight();
                robot.turnRight();
            }
        }
        robot.turnLeft();
        if (used.find({x, y - 1}) == used.end()) {
            if (robot.move()) {
                dfs(used, x, y - 1, 3, robot);
                robot.turnRight();
                robot.turnRight();
            }
        }
        robot.turnLeft();
        if (used.find({x - 1, y}) == used.end()) {
            if (robot.move()) {
                dfs(used, x - 1, y, 2, robot);
                robot.turnRight();
                robot.turnRight();
            }
        }
        robot.turnLeft();
        if (used.find({x, y + 1}) == used.end()) {
            if (robot.move()) {
                dfs(used, x, y + 1, 1, robot);
                robot.turnRight();
                robot.turnRight();
            }
        }
        //left to dir 1
        
        //Return to dir opposite to d
        if (d == 0) {
            robot.turnRight();
        }
        if (d == 1) {
            robot.turnRight();
            robot.turnRight();
        }
        if (d == 2) {
            robot.turnLeft();
        }
        robot.move();
    }
    
    void cleanRoom(Robot& robot) {
        set<pair<int,int>> used;
        dfs(used, 1, 3, 2, robot);
    }
};

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 原始车辆信息
struct Car {
    int id;
    long long arr; // 到达时间
    long long dur; // 业务时长
};

// 停在停车场的车辆信息
struct ParkedCar {
    int id;
    long long arr; // 原始到达时间
    long long exp_leave; // 预期离开时间
};

int main() {
    // 优化输入输出流速度
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m))
        return 0;

    vector<Car> cars(m);
    for (int i = 0; i < m; ++i) {
        cars[i].id = i;
        cin >> cars[i].arr >> cars[i].dur;
    }

    vector<ParkedCar> parking_lot; // 使用 vector 模拟栈
    queue<Car> waiting_queue; // 等候区队列
    vector<long long> results(m, 0);

    int unarrived_idx = 0;
    long long current_time = 0;

    while (unarrived_idx < m || !parking_lot.empty()) {
        long long next_arr = (unarrived_idx < m) ? cars[unarrived_idx].arr : -1;
        long long next_dep = (!parking_lot.empty()) ? parking_lot.back().exp_leave : -1;

        long long t_next;
        if (next_arr != -1 && next_dep != -1) {
            t_next = min(next_arr, next_dep);
        } else if (next_arr != -1) {
            t_next = next_arr;
        } else {
            t_next = next_dep;
        }

        // 时间步进
        current_time = max(current_time, t_next);

        // 1. 优先让能够离开的车辆离开
        while (!parking_lot.empty() && parking_lot.back().exp_leave <= current_time) {
            ParkedCar car = parking_lot.back();
            parking_lot.pop_back();
            results[car.id] = current_time - car.arr;
        }

        // 2. 将到达的车辆加入便道等候区
        while (unarrived_idx < m && cars[unarrived_idx].arr <= current_time) {
            waiting_queue.push(cars[unarrived_idx]);
            unarrived_idx++;
        }

        // 3. 从便道放行车辆进入停车场
        while (parking_lot.size() < n && !waiting_queue.empty()) {
            Car car = waiting_queue.front();
            waiting_queue.pop();
            // 预期离开时间 = 当前时间 + 业务时长
            long long exp_leave = current_time + car.dur;
            parking_lot.push_back({car.id, car.arr, exp_leave});
        }
    }

    // 输出最终结果
    for (int i = 0; i < m; ++i) {
        cout << results[i] << "\n";
    }

    return 0;
}

/*
描述
## 描述：
设某银行停车场内只有一个可停放 n
辆汽车的狭长通道（宽度仅容许一辆车驶入，尽头是死胡同），且只有一个大门可供汽车进出。汽车在停车场内按车辆到达时间的先后顺序依次排列。
若车场内已停满 n
辆汽车，则后来的汽车只能在门外便道上等候，一旦有车开走，则排在便道上的第一辆车即可开入停车场；如果有车要开进来的同时有车要开出，则优先让车开出来；
车主停好车后会离开停车场去银行办理业务，业务办理结束后回到停车场内要离开时，只能等待在它之后开入的车辆都离开停车场后才能开出。
现在请你编写一个程序计算每个车主的总停留时间（从到达到离开停车场的总时间）。
## 输入格式：
第一行输入两个个整数n，m；n表示停车场能容纳的汽车总数，m表示需要进入停车场的车辆数目。
接着输入m行，每行由两个整数组成，分别表示第i辆车的到达时间和其车主在银行办理业务所花的时长，已按车辆到达的时间排序。
## 输出格式：
输出m行，每行分别表示第i辆车的总停留时间。
## 输入样例：
3 5
1 3
2 5
3 6
4 1
5 3

## 输出样例：
8
7
6
8
7
提示：
到达时间    业务时长    开入时间    预期离开时间    实际离开时间    停留时长
1		3          1           4		9	        8 （需要等待第2、3辆车开出才能开出）
2               5          2           7                9               7 （需要等待第3辆车开出才能开出）
3               6          3           9          	9          	6
4          	1          9           10          	12          	8
（等待第3、2、1辆车依次开出后才能开入，等待第5辆车开出才能开出） 5          	3	   9	       12          	12 7
（等待第3、2、1辆车依次开出后才能开入）

测试样例2：
输入
5 3
3 9
12 8
21 25
输出
9
8
25
*/

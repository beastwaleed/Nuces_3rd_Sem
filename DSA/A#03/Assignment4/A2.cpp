//#include <iostream>
//#include <vector> //better to use vector for graphs then arrays
//#include <climits> //for int_min and int_max
//using namespace std;
//
//bool nextPermutation(vector<int>& arr) {
//    int n = arr.size();
//    int	i = n - 2;
//
//    while (i >= 0 && arr[i] >= arr[i + 1])
//        i--;
//
//    if (i < 0)
//        return false;
//
//    int j = n - 1;
//    while (arr[j] <= arr[i])
//        j--;
//
//    swap(arr[i], arr[j]);
//    reverse(arr.begin() + i + 1, arr.end());
//
//    return true;
//}
//
//void reverse(vector<int>& arr, int start) {
//    int end = arr.size() - 1;
//    while (start < end) {
//        swap(arr[start], arr[end]);
//        start++;
//        end--;
//    }
//}
//
//
//void travellingSalesmanProblem(int graph[][4], int s, int size) {
//    vector<int> vertex;
//    for (int i = 0; i < size; i++)
//        if (i != s)
//            vertex.push_back(i);
//
//    int min_path = INT_MAX;
//    vector<int> min_route; //array for storing the path
//
//    do {
//        int current_weight = 0;
//        int k = s;
//        vector<int> current_route = { s };
//
//        for (int i = 0; i < vertex.size(); i++) {
//            current_weight += graph[k][vertex[i]];
//            k = vertex[i];
//            current_route.push_back(k);
//        }
//
//        current_weight += graph[k][s];
//        current_route.push_back(s);
//
//        if (current_weight < min_path) {
//            min_path = current_weight;
//            min_route = current_route;
//        }
//
//    } while (nextPermutation(vertex));
//
//     Print the minimum path
//    cout << "Minimum Path: ";
//    for (int i = 0; i < min_route.size(); i++) {
//        cout << char('A' + min_route[i]);
//        if (i != min_route.size() - 1)
//            cout << " -> ";
//    }
//    cout << endl;
//
//    cout << "Minimum Cost: " << min_path << endl;
//}
//
//int main() {
//    int graph[4][4] = {  //    A  B  C  D
//        {0, 10, 15, 20}, // A [0  10 15 20 ]
//        {10, 0, 35, 25}, // B |10  0 35 25 |
//        {15, 35, 0, 30}, // C |15 35  0 30 |
//        {20, 25, 30, 0}  // D [20 25 30  0 ]
//    };
//
//    int start = 0; // Starting city
//    travellingSalesmanProblem(graph, start, 4);
//
//    system("pause");
//    return 0;
//}
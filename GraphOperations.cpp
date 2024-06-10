#include<iostream>
#include<stack>
#include<queue>
#define Max 100
using namespace std;
// 定义图
class Graph
{
    public:
        Graph(int vexnum)
        {
            this->vexnum = vexnum;
            this->arcnum = 0;
            for(int i = 0; i < vexnum; i++)
            {
                for(int j = 0; j < vexnum; j++)
                    this->a[i][j] = 0;
            }
        }
        void addEdge(int u, int v)
        {
            this->a[u][v] = 1;
            this->a[v][u] = 1;
            this->arcnum++;
        }
        void print()
        {
            for(int i = 0; i < this->vexnum; i++)
            {
                for(int j = 0; j < this->vexnum; j++)
                    cout << this->a[i][j] << " ";
                cout << endl;
            }
        }
        // 非递归深度优先遍历
        void dfs()
        {
            int visited[100] = {0};
            stack<int> s;
            for (int i = 0; i < this->vexnum; i++)
            {
                if (visited[i] == 0)
                {
                    s.push(i);
                    visited[i] = 1;
                    while (!s.empty())
                    {
                        int v = s.top();
                        s.pop();
                        cout << v << " ";
                        for (int j = 0; j < this->vexnum; j++)
                        {
                            if (this->a[v][j] == 1 && visited[j] == 0)
                            {
                                s.push(j);
                                visited[j] = 1;
                            }
                        }
                    }
                }
            }
        }
        // 广度优先遍历
        void bfs()
        {
            int visited[100] = {0};
            queue<int> q;
            for (int i = 0; i < this->vexnum; i++)
            {
                if (visited[i] == 0)
                {
                    q.push(i);
                    visited[i] = 1;
                    while (!q.empty())
                    {
                        int v = q.front();
                        q.pop();
                        cout << v << " ";
                        for (int j = 0; j < this->vexnum; j++)
                        {
                            if (this->a[v][j] == 1 && visited[j] == 0)
                            {
                                q.push(j);
                                visited[j] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        // 哈曼顿回路的递归函数
        void hamiltonian(int pos = 0) {
            static int path[Max] = {0};
            static int visited[Max] = {0};
            if (pos == vexnum) {
                if (a[path[pos-1]][path[0]] == 1) {
                    for (int i = 0; i < vexnum; i++)
                        cout << path[i] << " ";
                    cout << path[0] << endl;
                }
                return;
            }

            for (int v = 1; v <= vexnum; v++) {
                if (a[path[pos-1]][v] == 1) {
                    if (visited[v] == 0) {
                        visited[v] = 1;
                        path[pos] = v;
                        hamiltonian(pos + 1);
                        visited[v] = 0;
                    }
                }
            }
        }

            

        // 判断图中是否存在环
        bool hasCycle() {
            vector<bool> visited(vexnum, false);

            for (int i = 0; i < vexnum; ++i) {
                if (!visited[i]) {
                    if (hasCycleUtil(i, -1, visited)) {
                        cout << "图中存在环" << endl;
                        return true;
                    }
                }
            }

            cout << "图中不存在环" << endl;
            return false;
        }

        bool hasCycleUtil(int v, int parent, vector<bool>& visited) {
            visited[v] = true;

            for (int i = 0; i < vexnum; ++i) {
                if (a[v][i]) {
                    if (!visited[i]) {
                        if (hasCycleUtil(i, v, visited)) {
                            return true;
                        }
                    } else if (i != parent) {
                        return true;
                    }
                }
            }

            return false;
        }

        // 求无向图的两个顶点之间的简单路径
        void findSimplePath(int start, int end) {
            vector<bool> visited(vexnum, false);
            vector<int> path;

            findSimplePathUtil(start, end, visited, path);

            if (path.size() == 0) {
                cout << "不存在简单路径" << endl;
            } else {
                cout << "简单路径：";
                for (int i : path) {
                    cout << i << " ";
                }
                cout << endl;
            }
        }

        bool findSimplePathUtil(int current, int end, vector<bool>& visited, vector<int>& path) {
            visited[current] = true;
            path.push_back(current);

            if (current == end) {
                return true;
            }

            for (int i = 0; i < vexnum; ++i) {
                if (a[current][i] && !visited[i]) {
                    if (findSimplePathUtil(i, end, visited, path)) {
                        return true;
                    }
                }
            }

            path.pop_back();
            visited[current] = false;

            return false;
        }
    private:
        int vexnum, arcnum; // n个顶点，m条边
        int a[Max][Max];
};
int main()
{
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(0, 5);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(2, 5);
    graph.addEdge(3, 4);
    graph.print();
    graph.dfs();
    cout << endl;
    graph.bfs();
    cout << endl;
    vector<int> path;
    
    cout << "包含所有顶点的回路: ";
    graph.hamiltonian();
    graph.hasCycle();

    cout << "simplePath: ";
    graph.findSimplePath(0, 4);
    cout << endl;

    Graph graph2(6);
    graph2.addEdge(0, 1);
    graph2.addEdge(1, 2);
    graph2.addEdge(1, 3);
    graph2.addEdge(1, 5);
    graph2.addEdge(3, 4);
    graph2.print();
    graph2.dfs();
    cout << endl;
    graph2.bfs();
    cout << endl;

    cout << "包含所有顶点的回路: ";
    graph2.hamiltonian();
    graph2.hasCycle();

    cout << "simplePath: ";
    graph2.findSimplePath(0, 4);

    system("pause");
    return 0;
}
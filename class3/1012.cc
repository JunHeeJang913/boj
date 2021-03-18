#include <iostream>
#include <cstring>

using namespace std;

const int MAX(50);

bool visited[MAX][MAX];
bool cabMap[MAX][MAX];

int n_move = 4;
int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

int width, height;
int n_worm;

inline bool inRange(int y, int x)
{
    return !((y < 0) || (y>=height) || (x < 0) || (x >= width));
}

void dfs(int y, int x)
{
    visited[y][x] = true;

    for(int i = 0; i < n_move; ++i)
    {
        int next_y = y+dy[i];
        int next_x = x+dx[i];

        if(inRange(next_y, next_x) && !visited[next_y][next_x] && cabMap[next_y][next_x])
            dfs(next_y, next_x);
    }
}

void dfsAll(){
    for(int y = 0; y < height; ++y)
        for(int x = 0; x < width; ++x)
            if(visited[y][x] == false && cabMap[y][x] == true)
            {
                dfs(y, x);
                ++n_worm;
            }
}

void init()
{
    n_worm = 0;

    memset(cabMap, false, sizeof(cabMap));
    memset(visited, false, sizeof(visited));

    int n_cab;
    cin >> width >> height >> n_cab;
    
    for(int i = 0; i < n_cab; ++i)
    {
        static int y, x;
        cin >> x >> y;
        cabMap[y][x] = true;
    }
}

int main()
{
    int T; cin >> T;

    for(int i = 0; i < T; ++i)
    {
        init();
        dfsAll();
        cout << n_worm << endl;
    }
}
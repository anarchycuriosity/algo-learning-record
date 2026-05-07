// 自行引入头文件
#include <bits/stdc++.h>

// C/C++:
//  -------------------- 数据设计 --------------------
/*
    棋盘:
        board[i][j]表示坐标(i,j)的值
        0表示空地
        1表示黑子
        2表示白子
    如: board[3][6] = 1  表示(3,6)的位置是黑子
*/
int board[19][19];

// 表示当前回合数  偶数表示黑棋落子  奇数表示白棋落子
// 如: flag = 20 表示当前是第[20]次落子  由黑方落子
int flag = 0;

// -------------------- 数据设计 --------------------

// -------------------- service --------------------
/*
    负责人: 张三
    功能: init: 初始化游戏数据
        将棋盘的值初始化为0
        当前回合设为黑棋(flag设为0)
    参数: void
    返回值: void
*/
void init();

/*
    *难点1
    负责人: 张三
    功能: isWin: 根据传入的坐标(board对应位置)和flag值 判断落点后是否获胜
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示没有获胜
        1表示黑子胜利
        2表示白子胜利
*/
int isWin(int x, int y);

/*
    负责人: 张三
    功能: playerMove: 在指定位置落子
        如果board[x][y]是空地 则修改board[x][y]的值:改为相应颜色(flag对应颜色)        否则不操作
    参数:
        x: 当前回合落子的x坐标
        y: 当前回合落子的y坐标
    返回值:
        0表示落子失败 (棋盘已经有子)
        1表示落子成功

*/
int playerMove(int x, int y);
// -------------------- service --------------------

// -------------------- view --------------------
/*
    负责人: 张三
    功能: menuView: 展示选项, 玩家可以在这里选择进入游戏, 进入设置或退出游戏
        while(1){
            1. 展示选项
            2. 用户输入
            3. 根据输入进行对应处理
                进入游戏: 调用游戏界面函数gameView();
                进入设置: 打印敬请期待... 重新循环
                退出游戏: 调用exit(0);
        }
    参数: void
    返回值: void
*/
void menuView();

/*
    负责人: 张三
    功能: gameView_ShowBoard: 根据board数组 打印游戏棋盘
    参数: void
    返回值: void
*/
void gameView_ShowBoard();

/*
    负责人: 张三
    功能: winView:
        根据flag的值  打印游戏胜利界面  用户可以按任意键(使用getch函数)退出当前界面
    参数: void
    返回值: void
*/
void winView();

/*
    *难点2
    负责人: 张三
    功能: gameView: 游戏界面整合
        初始化游戏数据(调用函数init())
        while(1){
            打印游戏界面(调用函数gameView_ShowBoard())
            接收玩家坐标输入

            落子(调用落子函数playerMove())
                (如果落子失败 重新开始循环)

            判断游戏是否胜利(调用胜利判断函数isWin())
                (如果游戏胜利 调用胜利界面函数 然后结束当前界面)
            切换玩家(修改flag值)
        }
    参数: void
    返回值: void
*/
void gameView();
// -------------------- view --------------------

int main()
{
    menuView();
    return 0;
}

void init()
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            board[i][j] = 0;
        }
    }
    flag = 0;
}
bool inside(int x, int y)
{
    if (x >= 0 && x < 19 && y >= 0 && y < 19)
    {
        return true;
    }
    return false;
}
int isWin(int x, int y)
{
    std::vector<int> row_step = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
    std::vector<int> col_step = {-4, -3, -2, -1, 0, 1, 2, 3, 4};
    int tar = flag % 2 + 1;

    int count = 0;
    for (int j = 0; j < col_step.size(); j++)
    {

        int f_y = y + col_step[j];
        if (!inside(x, f_y))
        {
            continue;
        }
        if (board[x][f_y] == tar)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 5)
        {
            return tar;
        }
    }

    count = 0;
    for (int i = 0; i < row_step.size(); i++)
    {

        int f_x = x + row_step[i];
        if (inside(f_x, y) && board[f_x][y] == tar)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 5)
        {
            return tar;
        }
    }

    count = 0;
    for (int k = 0; k < row_step.size(); k++)
    {

        int f_x = x + row_step[k];
        int f_y = y + col_step[k];
        if (!inside(f_x, f_y))
        {
            continue;
        }
        if (board[f_x][f_y] == tar)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 5)
        {
            return tar;
        }
    }

    count = 0;
    for (int k = 0; k < row_step.size(); k++)
    {

        int f_x = x + row_step[k];
        int f_y = y - col_step[k];
        if (inside(f_x, f_y) && board[f_x][f_y] == tar)
        {
            count++;
        }
        else
        {
            count = 0;
        }
        if (count == 5)
        {
            return tar;
        }
    }
    return 0;
}
bool is_avai(int x, int y)
{
    if (board[x][y] == 0)
    {
        return true;
    }
    return false;
}
int playerMove(int x, int y)
{
    if (flag % 2 == 0 && is_avai(x, y))
    {
        board[x][y] = 1;
        return 1;
    }
    else if (flag % 2 != 0 && is_avai(x, y))
    {
        board[x][y] = 2;
        return 1;
    }
    return 0;
}

void menuView()
{
    while (true)
    {
        std::cout << "1. 开始游戏\n2. 设置\n3. 退出\n";
        int choice;
        std::cin >> choice;
        if (choice == 1)
        {
            gameView();
        }
        else if (choice == 2)
        {
            std::cout << "敬请期待\n";
        }
        else if (choice == 3)
        {
            exit(0);
        }
    }
}

void gameView_ShowBoard()
{
    std::cout << "   ";
    for (int j = 0; j < 19; j++)
        std::cout << j % 10 << " ";
    std::cout << "\n";
    for (int i = 0; i < 19; i++)
    {
        std::cout << i % 10 << "  ";
        for (int j = 0; j < 19; j++)
        {
            if (board[i][j] == 0)
                std::cout << ". ";
            else if (board[i][j] == 1)
                std::cout << "X ";
            else
                std::cout << "O ";
        }
        std::cout << "\n";
    }
}
/*
void clear_screen() {
 #ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
*/

void clear_screen()
{
    for (int i = 0; i < 50; i++)
    {
        std::cout << "\n";
    }
}
void winView()
{
    clear_screen();
    std::cout << "====================================\n";
    std::cout << "############ 游戏结束 ##############\n";
    std::cout << "====================================\n\n";

    if (flag % 2 == 0)
    {
        std::cout << ">>> 黑棋获胜！ <<<\n\n";
    }
    else
    {
        std::cout << ">>> 白棋获胜！ <<<\n\n";
    }

    std::cout << "按任意键退出胜利界面...\n";
    std::cin.ignore();
    std::cin.get();
}

void gameView()
{
    init();
    while (true)
    {
        clear_screen();
        std::cout << "如果不想玩了就输入-1 -1\n我不会嘲笑你的，真的" << "\n";
        gameView_ShowBoard();
        std::cout << (flag % 2 == 0 ? "黑棋" : "白棋") << "请输入坐标: ";
        int x, y;
        std::cin >> x >> y;
        if (x == -1 && y == -1)
        {
            std::cout << "哎，半途而废的半吊子\n";
            break;
        }
        while ((!inside(x, y)) || !is_avai(x, y))
        {
            std::cout << "重新输入\n";
            std::cin >> x >> y;
        }
        playerMove(x, y);
        if (isWin(x, y))
        {
            winView();
            break;
        }
        flag++;
        if (flag >= 19 * 19)
        {
            std::cout << "平局";
            break;
        }
    }
}
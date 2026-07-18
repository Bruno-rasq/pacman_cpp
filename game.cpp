#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <unordered_map>
#include <windows.h>
#include <tuple>
#include <iomanip>
using namespace std;

const unordered_map<uint32_t, size_t> hash_score_coord_and_idx = {
    {257, 0},    {513, 1},    {769, 2},    {1025, 3},   {1281, 4},   {1537, 5}, 
    {1793, 6},   {2049, 7},   {2305, 8},   {2561, 9},   {4609, 10},  {4865, 11}, 
    {5121, 12},  {5377, 13},  {5633, 14},  {2817, 15},  {3073, 16},  {3841, 17}, 
    {4097, 18},  {4353, 19},  {5889, 20},  {6145, 21},  {6401, 22},  {6657, 23}, 
    {258, 24},   {1538, 25},  {3074, 26},  {3842, 27},  {5378, 28},  {6658, 29}, 
    {259, 30},   {1539, 31},  {3075, 32},  {3843, 33},  {5379, 34},  {6659, 35}, 
    {260, 36},   {1540, 37},  {3076, 38},  {3844, 39},  {5380, 40},  {6660, 41}, 
    {261, 42},   {517, 43},   {773, 44},   {1029, 45},  {1285, 46},  {1541, 47}, 
    {1797, 48},  {2053, 49},  {2309, 50},  {2565, 51},  {2821, 52},  {3077, 53}, 
    {3333, 54},  {3589, 55},  {3845, 56},  {4101, 57},  {4357, 58},  {4613, 59}, 
    {4869, 60},  {5125, 61},  {5381, 62},  {5637, 63},  {5893, 64},  {6149, 65}, 
    {6405, 66},  {6661, 67},  {262, 68},   {1542, 69},  {2310, 70},  {4614, 71}, 
    {5382, 72},  {6662, 73},  {263, 74},   {1543, 75},  {2311, 76},  {4615, 77}, 
    {5383, 78},  {6663, 79},  {264, 80},   {520, 81},   {776, 82},   {1032, 83}, 
    {1288, 84},  {1544, 85},  {2312, 86},  {2568, 87},  {2824, 88},  {3080, 89}, 
    {3848, 90},  {4104, 91},  {4360, 92},  {4616, 93},  {5384, 94},  {5640, 95}, 
    {5896, 96},  {6152, 97},  {6408, 98},  {6664, 99},  {1545, 100}, {5385, 101}, 
    {1546, 102}, {5386, 103}, {1547, 104}, {5387, 105}, {1548, 106}, {5388, 107}, 
    {1549, 108}, {5389, 109}, {1550, 110}, {5390, 111}, {1551, 112}, {5391, 113}, 
    {1552, 114}, {5392, 115}, {1553, 116}, {5393, 117}, {1554, 118}, {5394, 119}, 
    {1555, 120}, {5395, 121}, {276, 122},  {532, 123},  {788, 124},  {1044, 125}, 
    {1300, 126}, {1556, 127}, {1812, 128}, {2068, 129}, {2324, 130}, {2580, 131}, 
    {2836, 132}, {3092, 133}, {3860, 134}, {4116, 135}, {4372, 136}, {4628, 137}, 
    {4884, 138}, {5140, 139}, {5396, 140}, {5652, 141}, {5908, 142}, {6164, 143}, 
    {6420, 144}, {6676, 145}, {277, 146},  {1557, 147}, {3093, 148}, {3861, 149}, 
    {5397, 150}, {6677, 151}, {278, 152},  {1558, 153}, {3094, 154}, {3862, 155}, 
    {5398, 156}, {6678, 157}, {535, 158},  {791, 159},  {1559, 160}, {1815, 161}, 
    {2071, 162}, {2327, 163}, {2583, 164}, {2839, 165}, {3095, 166}, {3863, 167}, 
    {4119, 168}, {4375, 169}, {4631, 170}, {4887, 171}, {5143, 172}, {5399, 173}, 
    {6167, 174}, {6423, 175}, {792, 176},  {1560, 177}, {2328, 178}, {4632, 179}, 
    {5400, 180}, {6168, 181}, {793, 182},  {1561, 183}, {2329, 184}, {4633, 185}, 
    {5401, 186}, {6169, 187}, {282, 188},  {538, 189},  {794, 190},  {1050, 191}, 
    {1306, 192}, {1562, 193}, {2330, 194}, {2586, 195}, {2842, 196}, {3098, 197}, 
    {3866, 198}, {4122, 199}, {4378, 200}, {4634, 201}, {5402, 202}, {5658, 203}, 
    {5914, 204}, {6170, 205}, {6426, 206}, {6682, 207}, {283, 208},  {3099, 209}, 
    {3867, 210}, {6683, 211}, {284, 212},  {3100, 213}, {3868, 214}, {6684, 215}, 
    {285, 216},  {541, 217},  {797, 218},  {1053, 219}, {1309, 220}, {1565, 221}, 
    {1821, 222}, {2077, 223}, {2333, 224}, {2589, 225}, {2845, 226}, {3101, 227}, 
    {3357, 228}, {3613, 229}, {3869, 230}, {4125, 231}, {4381, 232}, {4637, 233}, 
    {4893, 234}, {5149, 235}, {5405, 236}, {5661, 237}, {5917, 238}, {6173, 239}, 
    {6429, 240}, {6685, 241}, 
};

vector<uint32_t> bitmask_score_coord_and_flag = {
    65793, 66049, 66305, 66561, 66817, 67073, 67329, 67585, 67841, 68097, 70145, 70401, 
    70657, 70913, 71169, 68353, 68609, 69377, 69633, 69889, 71425, 71681, 71937, 72193, 
    65794, 67074, 68610, 69378, 70914, 72194, 65795, 67075, 68611, 69379, 70915, 72195, 
    65796, 67076, 68612, 69380, 70916, 72196, 65797, 66053, 66309, 66565, 66821, 67077, 
    67333, 67589, 67845, 68101, 68357, 68613, 68869, 69125, 69381, 69637, 69893, 70149, 
    70405, 70661, 70917, 71173, 71429, 71685, 71941, 72197, 65798, 67078, 67846, 70150, 
    70918, 72198, 65799, 67079, 67847, 70151, 70919, 72199, 65800, 66056, 66312, 66568, 
    66824, 67080, 67848, 68104, 68360, 68616, 69384, 69640, 69896, 70152, 70920, 71176, 
    71432, 71688, 71944, 72200, 67081, 70921, 67082, 70922, 67083, 70923, 67084, 70924, 
    67085, 70925, 67086, 70926, 67087, 70927, 67088, 70928, 67089, 70929, 67090, 70930, 
    67091, 70931, 65812, 66068, 66324, 66580, 66836, 67092, 67348, 67604, 67860, 68116, 
    68372, 68628, 69396, 69652, 69908, 70164, 70420, 70676, 70932, 71188, 71444, 71700, 
    71956, 72212, 65813, 67093, 68629, 69397, 70933, 72213, 65814, 67094, 68630, 69398, 
    70934, 72214, 66071, 66327, 67095, 67351, 67607, 67863, 68119, 68375, 68631, 69399, 
    69655, 69911, 70167, 70423, 70679, 70935, 71703, 71959, 66328, 67096, 67864, 70168, 
    70936, 71704, 66329, 67097, 67865, 70169, 70937, 71705, 65818, 66074, 66330, 66586, 
    66842, 67098, 67866, 68122, 68378, 68634, 69402, 69658, 69914, 70170, 70938, 71194, 
    71450, 71706, 71962, 72218, 65819, 68635, 69403, 72219, 65820, 68636, 69404, 72220, 
    65821, 66077, 66333, 66589, 66845, 67101, 67357, 67613, 67869, 68125, 68381, 68637, 
    68893, 69149, 69405, 69661, 69917, 70173, 70429, 70685, 70941, 71197, 71453, 71709, 
    71965, 72221 
};

const vector<string> maze = {
    "############################", "#            ##            #",
    "# #### ##### ## ##### #### #", "# #  # #   # ## #   # #  # #",
    "# #### ##### ## ##### #### #", "#                          #",
    "# #### ## ## ## ## ## #### #", "# #### ## ## ## ## ## #### #",
    "#      ##    ##    ##      #", "###### ##### ## ##### ######",
    "     # ##### ## ##### #     ", "     # ##          ## #     ",
    "     # ## ###--### ## #     ", "###### ## #      # ## ######",
    "          #      #          ", "###### ## #      # ## ######",
    "     # ## ######## ## #     ", "     # ##          ## #     ",
    "     # ## ######## ## #     ", "###### ## ######## ## ######",
    "#            ##            #", "# #### ##### ## ##### #### #",
    "# #### ##### ## ##### #### #", "#   ##                ##   #",
    "### ## ## ######## ## ## ###", "### ## ## ######## ## ## ###",
    "#      ##    ##    ##      #", "# ########## ## ########## #",
    "# ########## ## ########## #", "#                          #",
    "############################",
};

enum Direction {UP, DOWN, LEFT, RIGHT, NONE};

struct Coord { 
    int8_t row, col;
};

const unordered_map<Direction, Coord> delta = {
    {Direction::UP, {-1, 0}},   {Direction::DOWN, {1, 0}},
    {Direction::LEFT, {0, -1}}, {Direction::RIGHT, {0, 1}},
    {Direction::NONE, {0, 0}},
};

struct Sprite { Coord coord; char spr; };

struct Frame {
    vector<string> frame = maze;
    void Draw(Sprite& sprite){
        frame[sprite.coord.row][sprite.coord.col] = sprite.spr;
    };
    void Render(){
        ostringstream oss;
        oss << "\n\n\n";
        for(string& line : frame)
            oss << "    " << line << "\n";
        //oss << "\n\n\n";
        oss << "\n";
        cout << oss.str();
    };
};

struct Pacman {
    const unordered_map<Direction, char> faces = {
        {Direction::UP, 'V'},   {Direction::DOWN, '^'},
        {Direction::LEFT, '>'}, {Direction::RIGHT, '<'}
    };
    const unordered_map<Direction, char> togglefaces = {
        {Direction::UP, '|'},   {Direction::DOWN, '|'},
        {Direction::LEFT, '-'}, {Direction::RIGHT, '-'}
    };

    Coord coord = {17, 14};
    Direction dir = Direction::LEFT;
    char spr = faces.at(dir);
    bool toggle = true;

    Sprite get(){
        return {coord, spr};
    };
    void togglePacDirection(){
        toggle = !toggle;
        spr = (toggle ? faces.at(dir) : togglefaces.at(dir));
    };
    void changedir(const Direction nd){
        Coord delt = delta.at(nd);
        int nx = coord.row + delt.row;
        int ny = coord.col + delt.col;
        if(nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size())
            if(maze[nx][ny] != '#' && maze[nx][ny] != '-')
                dir = nd;
    };
    void move(){
        togglePacDirection();
        Coord delt = delta.at(dir);
        int8_t nx = coord.row + delt.row;
        int8_t ny = coord.col + delt.col;
        // redireciona o pac quando ele atravessa uma das saidas laterais.
        if(nx == 14){
            if(ny == -1) ny = maze[0].size() - 1;
            else if(ny == maze[0].size()) ny = 0;
        }
        // valida se a coordenada esta dentro dos limites do labirinto.
        if(nx >= 0 && nx < maze.size() && ny >= 0 && ny < maze[0].size())
            if(maze[nx][ny] != '#' && maze[nx][ny] != '-')
                coord = {nx, ny}; 
    };
};

uint32_t empacotarCoord(uint8_t x, uint8_t y){
    uint32_t pacote = (y << 8) | x;
    return pacote;
}

tuple<uint8_t, uint8_t> desempacotarCoord(uint32_t pacote){
    int x = pacote & 0xFF;
    int y = (pacote >> 8) & 0xFF;
    return {x, y};
}

uint32_t empacotarCoordEFlag(uint8_t x, uint8_t y, bool flag){
    uint32_t pacote = (uint32_t(flag) << 16) | (uint32_t(y) << 8) | uint32_t(x);
    return pacote;
}

tuple<uint8_t, uint8_t, bool> desempacotarCoordEFlag(uint32_t pacote){
    int x = pacote & 0xFF;
    int y = (pacote >> 8) & 0xFF;
    bool flag = (pacote >> 16) & 1;
    return {x, y, flag};
}

int keypress() {
    const int KEY_MSB_MASK = 0x8000;
    int resp = 0;
    if((GetAsyncKeyState(VK_UP) & KEY_MSB_MASK) != 0) resp = VK_UP;
    if((GetAsyncKeyState(VK_DOWN) & KEY_MSB_MASK) != 0) resp = VK_DOWN;
    if((GetAsyncKeyState(VK_LEFT) & KEY_MSB_MASK) != 0) resp = VK_LEFT;
    if((GetAsyncKeyState(VK_RIGHT) & KEY_MSB_MASK) != 0) resp = VK_RIGHT;
    if((GetAsyncKeyState('W') & KEY_MSB_MASK) != 0) resp = VK_UP;
    if((GetAsyncKeyState('S') & KEY_MSB_MASK) != 0) resp = VK_DOWN;
    if((GetAsyncKeyState('A') & KEY_MSB_MASK) != 0) resp = VK_LEFT;
    if((GetAsyncKeyState('D') & KEY_MSB_MASK) != 0) resp = VK_RIGHT;
    if((GetAsyncKeyState(VK_ESCAPE) & KEY_MSB_MASK) != 0) resp = VK_ESCAPE;
    return resp;
};

void Create_interface(int capturedScore, int lifes){
    ostringstream oss;
    oss << "    " << "SCORE: ";
    oss << setw(4) << setfill('0') << capturedScore;
    oss << string(7, ' ');

    string lf = "";
    if(lifes == 3) lf = "ooo";
    if(lifes == 2) lf = " oo";
    if(lifes == 1) lf = "   ";
    oss << "LIFES: " << lf;

    oss << "\n\n";
    cout << oss.str();
}

void logge_frame(Sprite pac){

    system("cls");
    Frame fr;

    // desenha os pontos
    for(const uint32_t& scorePoint: bitmask_score_coord_and_flag){

        tuple<uint8_t, uint8_t, bool> packet = desempacotarCoordEFlag(scorePoint);
        int8_t row = int8_t(get<0>(packet));
        int8_t col = int8_t(get<1>(packet));
        bool flag = get<2>(packet);

        if(flag){
            Sprite score = {row, col, '.'};
            fr.Draw(score);
        }
    }
    fr.Draw(pac);
    fr.Render();
}

int catchScore(Sprite pac){

    int8_t row = pac.coord.row;
    int8_t col = pac.coord.col;

    uint32_t coord = empacotarCoord(uint8_t(row), uint8_t(col));

    // caso o pacman estiver em uma coordenada que não seja coordenada de ponto
    // tentar pega o idx vai lançar um erro de out_range. evito isso verificando se
    // a chave esta no hash antes.
    if(hash_score_coord_and_idx.find(coord) == hash_score_coord_and_idx.end())
        return 0;

    size_t idx = hash_score_coord_and_idx.at(coord);
    uint32_t state = bitmask_score_coord_and_flag[idx];

    tuple<uint8_t, uint8_t, bool> packet = desempacotarCoordEFlag(state);
    uint8_t r = get<0>(packet);
    uint8_t c = get<1>(packet);
    bool flag = get<2>(packet);

    if(!flag) return 0;

    bitmask_score_coord_and_flag[idx] = empacotarCoordEFlag(r, c, !flag);

    return 5;
}

void game(){

    int lifes = 3;
    int capturedScore = 0;
    const int TOTAL_SCORE_POINTS=242;
    const int TOTAL_SCORE = TOTAL_SCORE_POINTS * 5;

    Pacman pac;
    logge_frame(pac.get());
    Create_interface(capturedScore, lifes);
    while(true){
        Sleep(150);
        int key = keypress();
        if(key == VK_ESCAPE || capturedScore == TOTAL_SCORE || lifes == 0) break;
        switch(key){
            case VK_UP:     { pac.changedir(Direction::UP);    break; }
            case VK_DOWN:   { pac.changedir(Direction::DOWN);  break; }
            case VK_LEFT:   { pac.changedir(Direction::LEFT);  break; }
            case VK_RIGHT:  { pac.changedir(Direction::RIGHT); break; }
            default: break;
        }
        pac.move();
        capturedScore += catchScore(pac.get());
        logge_frame(pac.get());
        Create_interface(capturedScore, lifes);
    }
    logge_frame(pac.get());
    Create_interface(capturedScore, lifes);
}

int main() {
    game();
}
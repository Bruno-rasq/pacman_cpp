#include "./includes/config.hpp"
#include "./includes/stdCore.hpp"
#include "./includes/mazeModel.hpp"
#include "./includes/frameManager.hpp"
#include "./includes/keyboardManager.hpp"
#include "./includes/pacman.hpp"


void log_frame_game(Pacman& pac){

    Frame currentFrame(mazeModel);
    Coord_t PacmanCoord = pac.GetCoord();
    currentFrame.Draw(PacmanCoord.row, PacmanCoord.col, '@');
    system("cls");
    currentFrame.Render();

}


bool check_valid_coord(int x, int y){

    const int mazeHeight = 31;
    const int mazeWidth = 28;
    const bool inBolds = x >= 0 && x < mazeHeight && y >= 0 && y < mazeWidth;
    const bool noWalls = mazeModel[x * (mazeWidth + 1) + y] != '#';
    const bool noghostPit = mazeModel[x * (mazeWidth + 1) + y] != '-';
    if(inBolds && noWalls && noghostPit) return true;
    return false;
}


void update_pacman_status(Pacman& pac, Direction newdirection){

    pac.ChangeDirections(newdirection);
    pac.UpdateCoord();
}


void update_pacman_coord_case_keypress_0(Pacman& pac){

    Direction currentPacmanDir = pac.GetDir();
    Coord_t currentPacmancoord = pac.GetCoord();
    Coord_t currentDelta = DeltaDirections.at(currentPacmanDir);
    int x = currentPacmancoord.row + currentDelta.row;
    int y = currentPacmancoord.col + currentDelta.col;
    if(check_valid_coord(x, y)) pac.UpdateCoord();
}


void check_valid_change_direction(Pacman& pac, int keypressed){

    if(keypressed == 0){
        update_pacman_coord_case_keypress_0(pac);
        return;
    }

    Coord_t delta;
    Direction newDirection;
    Coord_t currentPacmancoord = pac.GetCoord();


    if(keypressed == VK_UP){
        delta = DeltaDirections.at(Direction::UP);
        newDirection = Direction::UP;
    }
    if(keypressed == VK_DOWN){
        delta = DeltaDirections.at(Direction::DOWN);
        newDirection = Direction::DOWN;
    }
    if(keypressed == VK_LEFT){
        delta = DeltaDirections.at(Direction::LEFT);
        newDirection = Direction::LEFT;
    }
    if(keypressed == VK_RIGHT){
        delta = DeltaDirections.at(Direction::RIGHT);
        newDirection = Direction::RIGHT;
    }

    int x = currentPacmancoord.row + delta.row;
    int y = currentPacmancoord.col + delta.col;

    if(check_valid_coord(x, y)){
        update_pacman_status(pac, newDirection);
        return;
    }

    /* Tenta mover o pacman com base nos dados antigos caso não for possivel mudar a direção. */
    update_pacman_coord_case_keypress_0(pac); 

}


int main(){

    Pacman pac;
    KeyboardManager km;

    log_frame_game(pac);

    while(true){

        Sleep(CONFIG::TIMESLEEP);

        int key = km.KeyPressed();

        if(key == VK_ESCAPE) break;

        check_valid_change_direction(pac, key);

        log_frame_game(pac);
    }

    log_frame_game(pac);

    return 0;
}
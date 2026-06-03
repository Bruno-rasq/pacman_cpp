#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void readFile(std::vector<std::string>& content, const std::string& path){

    std::ifstream file(path);

    if(file.is_open()){
        std::string currentLine;
        while(std::getline(file, currentLine)){
            content.push_back(currentLine);
        }
        file.close();
        return;
    }

    std::cout << "Ocorreu um erro de leitura.\n";
}


void writeFile(std::vector<std::string>& content, const std::string& path){

    std::ofstream filefruitsCells(path);
    

    if(!filefruitsCells.good()){
        std::cout << "ocorreu um erro ao escrever arquivo.\n";
        return;
    }

    for(size_t x = 0 ; x < content.size(); x++){
        for(size_t y = 0; y < content[0].size(); y++){
            char currentCell = content[x][y];

            if(currentCell == '.'){
                filefruitsCells << "{" << std::to_string(x);
                filefruitsCells << "," << std::to_string(y);
                filefruitsCells << "}, ";
            }
        }

        filefruitsCells << "\n";
    }
}


int main(){
    std::vector<std::string> maze;

    readFile(maze, "./asciiMazeModels/pacmanModel.txt");

    writeFile(maze, "./asciiMazeModels/fruits.txt");

    for(size_t i = 0; i < maze.size(); i++){
        for(size_t j = 0; j < maze[0].size(); j++){
            std::cout << maze[i][j];
        }
        std::cout << "\n";
    }

    return 0;
}
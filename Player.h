#pragma once
#include "Utilities.h"
#include <string>

class Player
{
public:
	Player() 
	{
		this->lives = Utilities::playerLives;
		this->score = 0;
	};
	int lives;
	int score;
	std::string name;
};

class PlayerSingleton
{
public:
    static PlayerSingleton& getInstance()
    {
        static PlayerSingleton    instance; // Guaranteed to be destroyed.
                              // Instantiated on first use.
        return instance;
    }
private:
    PlayerSingleton() {
        this->lives = Utilities::playerLives;
        this->score = 0;
    }                    // Constructor? (the {} brackets) are needed here.

    // C++ 03
    // ========
    // Don't forget to declare these two. You want to make sure they
    // are inaccessible(especially from outside), otherwise, you may accidentally get copies of
    // your singleton appearing.
   // PlayerSingleton(PlayerSingleton const&);              // Don't Implement
   // void operator=(PlayerSingleton const&); // Don't implement

    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
    int lives;
    int score;
    std::string name;
public:
    int GetLives() {return this->lives;};
    void SetLives(int lives) {this->lives = lives;};

    int GetScore() {return this->score;};
    void SetScore(int score) {this->score = score;};

    std::string GetName() {return this->name;};
    void SetName(std::string name) {this->name = name;};

    void ResetPlayer() {
        this->lives = Utilities::playerLives;
        this->score = 0;
        this->name = "";
    }

    PlayerSingleton(PlayerSingleton const&) = delete;
    void operator=(PlayerSingleton const&) = delete;

    // Note: Scott Meyers mentions in his Effective Modern
    //       C++ book, that deleted functions should generally
    //       be public as it results in better error messages
    //       due to the compilers behavior to check accessibility
    //       before deleted status
};
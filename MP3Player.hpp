//
// Created by Chris Hartman on 4/27/20.
//

#ifndef CS372SPRING2020EXAMPLECODE_MP3PLAYER_HPP
#define CS372SPRING2020EXAMPLECODE_MP3PLAYER_HPP
#include "MP3PlayerState.hpp"

#include <iostream>
#include <memory>

class MP3Player {
   friend class MP3PlayerState;
public:
   ~MP3Player();
   explicit MP3Player(std::unique_ptr<MP3PlayerState> newState);
   void pushNextButton();
   void pushSourceButton();

private:
   void setState(std::unique_ptr<MP3PlayerState> newState);

   void playRadio() {
      std::cout << "Playing the radio.\n";
   }

   void stopRadio() {
      std::cout << "Stopping the radio.\n";
   }

   void nextRadioStation() {
      std::cout << "Next radio station.\n";
   }

   void playMp3() {
      std::cout << "Playing MP3.\n";
   }

   void stopMp3() {
      std::cout << "Stopping MP3.\n";
   }

   void nextMp3() {
      std::cout << "Next MP3.\n";
   }
private:
   std::unique_ptr<MP3PlayerState> _state;
};

#endif  // CS372SPRING2020EXAMPLECODE_MP3PLAYER_HPP

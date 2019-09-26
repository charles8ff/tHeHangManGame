#include <iostream>
#include <string>
#include <array>

void theHangmanGame()//Function that plays the game
{
  //Parameters, what we play with
  std::string secretWord;
  std::string hiddenWord;
  int lifeTotal{7};
  char letter;//letter that inputs each time
  bool solved{false};//checker
  std::array<std::string,7> body={" |\n O\n/|\\\n/ \\\n"," |\n O\n/|\\\n/ \ \n"," |\n O\n/|\\\n \ \n"," |\n O\n/|\ \n \ \n"," |\n O\n/ \ \n \ \n"," |\n O\n  \ \n \ \n"," |\n  \n  \ \n \ \n"};//i've seen preetier bodies

  //starting the game
  std::cout << "Enter your word to play The Hangman Game, by pyrex_BAUS: \n\n >>";
  std::getline(std::cin, secretWord);
  hiddenWord.resize(secretWord.length(), '*');
  std::cout << "Let's play, the hidden word has " << hiddenWord.length() << " characters: \n\n" << hiddenWord << "\n\nAnd you have "<< lifeTotal <<" lives to play.\nGLHF!\n";

  //the game
  while(lifeTotal > 0 && solved == false){//this keeps us into the game until we solve (solved== true) or we run out of lives.

    std::cout << "\n\n\tYou are still playing The Hangman Game, by pyrex_BAUS.\nYou have only "<< lifeTotal <<" life points left.\n"; //test purposes not 100% necessary
    std::cout << "Type a letter to try to guess: \n >>";
    std::cin >> letter ;

    //mainloop
    if(secretWord.find(letter)!=-1){//Check the find returns a position
    /*
      int pos{-1};
      do{
        pos=secretWord.find(letter,pos+1);
        hiddenWord.at(pos)=letter;
        }while(secretWord.find(letter,pos+1)!=-1);
    */
      int pos{-1};
      for(auto elem:secretWord){
        pos++;
        if(elem==letter){
          hiddenWord.at(pos)=letter;
        }
      }//replacing all instances of the letter if it repeats 

      std::cout <<"\n"<< hiddenWord<<"\n";

      if(hiddenWord.find("*")!=-1){
        solved=false;
      }else{solved=true;}

    }else{
    lifeTotal--;
    std::cout << "\nDing Dong your letter is wrong.\n";//mistake
    std::cout << body.at(lifeTotal);//this prints the hanged man with a very ugly array up there in parametres
    }

  }
  if(solved==true){
    std::cout << "\n\n\n    YOU WIN   \n\n\nYou got "<<lifeTotal<<" spare lives.GGWP!\n";//win msg
  }else {
  std::cout << "\n\n\n    GAME OVER  \n\n\nggezn00b xd\n";//lose msg
  }
}
void menu(){
    int userChooses{1};
    do{
      std::cout << "\t\tWelcometo play The Hangman Game, by pyrex_BAUS! Choose between: \n\n" <<
          "1. New Game\n" <<
          "0. Exit\n\n >>";
      std::cin >> userChooses;

      if(std::cin.fail()){
        std::cin.clear();
        std::cin.ignore();
        userChooses = 2;
      }//Checker of input
      
      switch(userChooses){//get in or get out
        case 1:
          std::cin.clear();
			    std::cin.ignore();
			    theHangmanGame();
        break;

        default:
        break;
      }
    }while(userChooses!=0);
}

int main(){

  menu();
  return 0;
}

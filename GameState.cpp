#include "ShootEmUp.h"
#include "GameState.h"

GameState::GameState(ShootEmUp* shootEmUpP, int gameModeChoiceArg): Menu(shootEmUpP)
{
    //tkn = NULL;//l image est choisi dans start en fonction de c est a qui de jouer
    //turnNumber=0;
    //whosTurn = false; // jetons rouge = false ; jetons jaune = true
    //gameModeChoice=gameModeChoiceArg;
    //if(gameModeChoice == 0){
    //    img=SDL_LoadBMP("Images/cpuvscpu.bmp");
    //}
    //else {
    //    img=SDL_LoadBMP("Images/grille.bmp");
    //}
}
GameState::~GameState(){
    //SDL_FreeSurface(tkn);

}


void GameState::start(){
    //Le menu creer son propre background aka image
    //image=new Image(puissance4->getEngineManager(),img);
    //cao = new CloseApplicationObject(puissance4->getEngineManager());



    //grid = new Grid(puissance4->getEngineManager());
    //curseurGS = new CurseurGameState(puissance4->getEngineManager(), grid, gameModeChoice);


    //while(turnNumber < 42){ // || grid->whosWinner()

        /*debut
         *
         *  choisi la bonne couleur du jetons en fonction de whosTurn
         **/

        /* faire une classe qui detect touche apuyer espace*/
        // est ce que ici plusieur token son créé a chak tour de boucle


        /* fin*/
       /* if(this->curseurGS->spaceBar){
            token = new Token(puissance4->getEngineManager(),whosTurn,this->curseurGS->getX(),this->grid->checkFreeY(this->curseurGS->getX()));
         }
        */
        // wait la position du cursor

        //grid->addToken(token); // ajoute le token a la grille

       //whosTurn = !whosTurn; // inverse le booleen qui permet de passer a un autre joueur
       // turnNumber++;
  // }

    //voir qui a gagner
    //lancer le menu de fin
    //lancerMenuDeFin(); egaliter jpense ici
    //
}

void GameState::stop(){

    //Token::nbToken=0;
    //delete grid;
    //delete cao;
    //delete image;
    //delete curseurGS;


}

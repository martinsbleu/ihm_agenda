#include "agenda.h"
#include <QApplication>
#include <QWidget>


int main(int argc, char *argv[])
{

/*Créer un nouvel objet de type QApplication, appelé a.
Le constructeur de QApplication exige que on lui passe les arguments du programme
c'est-à-dire les paramètres argc et argv que reçoit la fonction main.
Cela permet de démarrer le programme avec certaines options précises.
*/
    QApplication martin(argc, argv);

    AGENDA agenda;


//Afficher la fenetre
    agenda.showFullScreen();
//    agenda.show();

//Executer le programme
    return martin.exec();
}

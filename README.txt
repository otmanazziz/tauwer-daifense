Tauwer Daifense - Projet LIFAP4

===== Noms / Projet =====
CAUTELA JULIAN 11706731
BEN OTHMAN SAMY 11707136
AZZIZ OTMAN 11706731
Project ID: 9144
Lien vers la forge: https://forge.univ-lyon1.fr/p1706731/lifap4

===== Présentation du projet =====
Bienvenue dans Tauwer Daifense, un jeu de Tower Defense dans laquelle vous allez devoir protéger votre base à l'aide de tours.
Ces tours vont vous êtes utiles pour éradiquer les vagues de zombies, qui deviendront de plus en plus puissants au fil des vagues anéanties.
Vous avez plusieurs niveaux possibles, comme les nuages, le désert, la lave, la terre et l'eau.

Ces niveaux changent au niveau du décor mais aussi au niveau des ennemis. Oui, selon la carte, les vagues d'ennemis changeront ainsi que leurs déplacements vers la base à défendre.
Si vous parvenez à détruire toutes les vagues d'une carte, eh bien vous avez gagné.

===== Un peu plus en détail =====
Les tours sont déja placées, donc le jeu aura sa difficulté basé sur le choix des tours à construire ou améliorer selon les vagues d'ennemis.
Les informations sur les vagues d'ennemis, les tours déja placées, la carte à choisir, les coordonnées de la base sont récupérées dans des fichiers *.map.

===== Fonctionnalités =====
Récupération des fichiers *.map (qui contient les informations sur la carte à utiliser, les tours, les vagues d'ennemis, les chemins et la base).
Génération de la carte sélectionnée ainsi que les autres informations contenus dans le bon fichier *.map.
Déplacement des ennemis vers la base (à travers une série de chemin).
Détection et attaque des tours sur les ennemis.
Possibilité d'améliorer les tours, comme par exemple la vitesse d'attaque, la portée, les dégats d'attaque et la zone de dégats.
Implémentation d'une musique de fond.
Système de victoire/défaite.

===== Contenu des documents =====
Les documents suivants contiennent
 - bin/ : Fichiers exécutables (sdl / txt) avec les librairies de la SDL

 - data/font/ : Police d'écriture.
 - data/image/ : Images utilisées dans le jeu (ainsi que les maps dans data/image/map/).
 - data/map/ : Fichiers *.map, servant d'informations sur la carte, les tours, les vagues d'ennemis, les chemins et la base selon le niveau
 - data/sound/ : Musique de fond utilisée dans le jeu.

 - doc/ : Documentation doxygen, diagramme des classes, diagramme de Gantt

 - obj/core/ : Fichiers objets générés à la compilation pour les classes de base.
 - obj/sdl2/ : Fichiers objets générés à la compilation pour l'affichage de la SDL.
 - obj/txt/ : Fichiers objets générés à la compilation pour l'affichage du texte.
 
 - src/core/ : Fichiers sources pour les classes de base.
 - src/sdl2/ : Fichiers sources pour l'affichage de la SDL.
 - src/txt/ : Fichiers sources pour l'affichage du texte.

===== Génération de la documentation doxygen =====
Pour la génération de la documentation doxygen, il faut:
 - Se mettre dans le dossier doc/
 - Taper la commande (à l'aide du terminal): doxygen doxyfile

La documentation est générée, vous pouvez la visualiser sur internet en le cherchant dans le fichier doc/html/index.html

===== Exécution / Lancement du programme =====
La compilation du programme se fait seulement sur Linux.

Avant de lancer la compilation, il faut avoir les librairies suivantes:
 - SDL2.dll
 - SDL2_image.dll
 - SDL2_mixer.dll
 - SDL2_ttf.dll
 - SDL.dll
 (Ces librairies sont inclus dans le fichier bin/)

Dans le cas ou vous ne possédez pas ces librairies, il faut:
 - Taper la commande (à l'aide du terminal): sudo apt install doxygenlibsdl2-dev libsdl2 libsdl2-image-dev libsdl2-ttf-dev libsdl2-mixer-dev

Pour compiler le programme, il faut:
 - Se mettre dans le dossier lifap4
 - Taper la commande (à l'aide du terminal): make

Pour lancer le programme (avec l'affichage du fichier texte), il faut:
 - Se mettre dans le dossier lifap4
 - Taper la commande (à l'aide du terminal): bin/txt

Pour lancer le programme (avec l'affichage de la SDL), il faut:
 - Se mettre dans le dossier lifap4
 - Taper la commande (à l'aide du terminal): bin/sdl

========================================================================




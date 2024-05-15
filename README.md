# Puissance5
 
Nous avonc commercer par créer une classe Plateau qui contient deux attributs privés qui sont "int ligne" et "int** grille". Cette classe contient également un attribut public à savoir "int col". En ce qui concerne les méthodes nous avons quatres méthodes, une nous permet d'afficher la grille du puissance5 ensuite une autre permet au joueur de placer le pion sur la grille. Il y a une méthode qui sert à vérifier lorsqu'un joueur a gagné la partie pour pouvoir stopper le jeu.
Enfin une dernière méthode qui est utilise lorsqu'un joueur essaie de placer un pion hors de la grille , la méthode va intervenir en empêchant le mouvement.

Par la suite nous avons crée une classe Joueur à laquelle nous avons intégré la classe Plateau dont nous avions besoin, cette classe a deux attributs qui sont pion et pseudo. Dans cette classe il y a une méthode virtuelle pure qui permet au joueur de choisir son pseudo pour jouer au puissance5 et une autre méthode virtuelle pure qui permet au joueur de choisir la colonne où il souhaite placer son pion.
Il y a deux classes qui héritent de la classe Joueur, à savoir les classes JoueurHumain et Ia_niv0.

Dans la classe JoueurHumain il y a une méthode qui permet au joueur humain de placer son pion dans la colonne de son choix

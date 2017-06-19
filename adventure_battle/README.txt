Since I program primarily in Linux, I use command line compilation. The Makefile
thrown in there was for easy compilation. Instead of typing out 19 filenames, I just
type "make all" and it compiles. Should have no problem just running then on Visual
Studio or a similar IDE.

These files were created as part of my last homework assignment for Computer
Programming II. All of the separate classes inherit from the enemy class, with the
exception of the boss class. The boss class inherits from hero, because the boss
can heal itself and throw fireballs like the hero can.

The emeny class contains all of the methods between all of the classes, except for
methods specific to the class (see bear.h or wolf.h for maul(), gouge(), bite(), etc.).
The reason for this is because the heterogeneous enemy* vector in main.cpp has issues
with enemy child object methods and boss methods being used.

I assumed that's because of any or all of three things about a heterogeneous vector:
1. Typeid or something similar doesn't ensure that the object at the specified index
   has access to a method specific to another class
2. The program freaks out because every possible object that could be in the vector
   needs access to a version of the method
3. Inheritance

I mostly thought it was 3, and I tried to do some typeid manipulation that ultimately
didn't work. So, to make it work correctly and to make the program look visually
appealing for the user, I included virtual functions like fireballs() and
max_fireballs() that the boss class overloads. The only functions that aren't virtual
are the functions that function the same for every enemy, regardless of type.

Each animal name is a different child of enemy. Most child classes have unique
modifiers like color, species, or gender. Adding a new enemy is as easy as copying the
.h and .cpp for a class, copying it, changing the names, adding/removing the unqiue
modifiers they've been given, and adding their chance to be encountered out of an
arbitrary number that the programmer chooses. For instance, a bear is least likely to
be encountered because they're the strongest enemy, and rats and birds are the most
common because they're the weakest.

The hero class needs almost no explanation. In main.cpp, the user chooses whether he
attacks, shields, heals, fireballs, or requests a tip on the enemy. The methods 
contained within hero.h then modify the basic enemy methods to make the player take
less damage, take negative damage to heal (I figured taking negative damage and adding
a >= 100 conditional was easier than creating a new method), or to do more damage by
accessing the base function with a higher number passed to it.


As a user going through the game, you are asked for a name and the number of enemies
you want to fight. I made sure the name used getline(), because it catches more than a
one word string if you want to have a longer name. The game then spits out instructions
on what each command actually does, and then the game begins. You encounter an enemy
and combat starts. Once combat ends, you encounter another enemy, and so on until you
reach the final boss. Then the boss has a choice chosen at random to attack, fireball,
or to shield. He heals when he's below half health, and that's about it. If you win,
the game congratulates you. Otherwise, the game just ends. That's all the user sees.
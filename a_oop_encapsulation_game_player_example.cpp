#include <iostream>
#include <string>

class Player {
private:
    std::string name;
    int level;
    int health;

public:
    Player(const std::string& playerName, int playerLevel, int playerHealth)
        : name(playerName), level(playerLevel), health(playerHealth) {}

    void displayPlayerInfo() {
        std::cout << "Player Name: " << name << "\n";
        std::cout << "Level: " << level << "\n";
        std::cout << "Health: " << health << "\n";
    }

    void increaseLevel() {
        level++;
    }

    void takeDamage(int damage) {
        health -= damage;
    }

    void heal(int amount) {
        health += amount;
    }
};

int main() {
    Player player("Hero", 1, 100);
    player.displayPlayerInfo();

    player.increaseLevel();
    player.takeDamage(20);
    player.heal(10);

    player.displayPlayerInfo();

    return 0;
}
/*

In the example above, we have a Player class that encapsulates the data and behavior of a game character.
The class has three private member variables: name, level, and health. These variables are not accessible
outside the class directly.

We provide public methods to interact with the encapsulated data. The displayPlayerInfo() method allows
us to display the player's information. The increaseLevel(), takeDamage(), and heal() methods provide
functionality to modify the player's level and health.

In the main() function, we create a Player object named player. We can access the public methods of the
Player class to perform actions like increasing the level, inflicting damage, and healing the player.
However, we cannot directly access or modify the private member variables.

The concept of encapsulation helps in organizing the code, preventing direct access to sensitive data,
and enforcing controlled access through well-defined methods. It ensures that the internal state of an
object is managed and modified in a consistent and controlled manner.

When explaining encapsulation to a child, you can compare it to a toy with buttons and switches. The
toy has a specific purpose, and you can interact with it using the available buttons and switches, but
you don't need to know how those buttons and switches work internally. The toy encapsulates its
functionality, and you can use it without worrying about the internal details.

Encapsulation provides benefits like data protection, code organization, and code reusability, making
it an essential concept in object-oriented programming.

The "&" symbol in the constructor parameter string& playerName is used to pass the playerName argument
by reference.

In C++, when a variable is passed by reference, it allows the function or constructor to directly access
and modify the original variable passed in, rather than creating a copy of it. This can be more efficient,
especially when working with large objects or when you want to modify the original object.

In the Player constructor, passing the playerName parameter by reference (string& playerName) allows the
constructor to directly access and assign the value of playerName to the private member variable name,
without creating a copy of the string.

If we didn't use the "&" symbol and instead used string playerName (passing by value), it would create a copy
of the playerName argument, and any modifications made within the constructor would only affect the local copy,
not the original variable.

So, using the "&" symbol in this case is necessary to efficiently assign the value of playerName to
the name member variable of the Player class.

*/

/* UNDER THE HOOD
If i chose not to use the & for the playerName, each object instantiated from
the player class would still have unique names correct. its only under the hood
in regard to performance that any noticable difference would present itself?

Yes, that's correct. Whether you choose to use a reference (&) for the playerName
parameter or not, each object instantiated from the Player class will still have
unique names.

Without using a reference, if you pass the playerName parameter by value (without &),
a copy of the string will be made during object construction. This means that the
name member variable will be initialized with a copy of the provided string, and any
subsequent modifications to the name member variable will only affect the copy,
not the original string passed to the constructor.

With a reference (&), the name member variable is directly initialized with the
reference to the original string passed to the constructor. This allows direct
modification of the original string and ensures that any changes made to the
name member variable will affect the original string.

So, while the choice of using a reference or not may have performance
implications, in terms of the uniqueness of the names assigned to each
Player object, it won't make a difference. Each object will have its
own unique name regardless of whether a reference is used or not.


*/


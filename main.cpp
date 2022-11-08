#include "SocialConnectionsGraph.h"
#include <iostream>

int main()
{
	SocialConnectionsGraph scg;

	scg.addPerson("Anna");
	scg.addPerson("Vika");
	scg.addPerson("Kirill");
	scg.addPerson("Fedor");
	scg.addPerson("Elena");
	scg.addPerson("Viktor");
	scg.addPerson("Dmitriy");
	scg.addPerson("Roman");
	scg.addPerson("Svetlana");
	scg.addPerson("Oleg");

	scg.addFriendship(1, 2);
	scg.addFriendship(2, 3);
	scg.addFriendship(3, 4);
	scg.addFriendship(4, 5);
	scg.addFriendship(5, 6);
	scg.addFriendship(6, 7);
	scg.addFriendship(7, 8);
	scg.addFriendship(8, 9);
	scg.addFriendship(9, 10);

	for (size_t i = 0; i < scg.getPersonsCount(); i++)
	{
		for (size_t j = i + 1; j < scg.getPersonsCount(); j++)
		{
			size_t distance = scg.findCouplesThroughThreeHandshakes(i, j);
			if (distance <= 3)
				std::cout << scg.findPersonByIndex(i) << " friend with " << scg.findPersonByIndex(j) << std::endl;
		}
	}
	return 0;
}
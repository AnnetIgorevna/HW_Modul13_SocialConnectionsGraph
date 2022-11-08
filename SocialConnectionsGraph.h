#pragma once
#include <iostream>

constexpr auto VERYBIGINT = 1000000000; // очень большое число;

constexpr auto SIZE = 20;

// Модель хранения графа социальных связей определенного круга людей
class SocialConnectionsGraph {
public:
    SocialConnectionsGraph();
    void addPerson(const std::string name); // добавить человека
    void addFriendship(int p1, int p2); // добавить дружбу между двумя людьми
    bool friendshipExists(int p1, int p2); // наличие дружбы между двумя людьми
    bool personExists(const std::string name); // наличие конкретного человека в графе
    size_t findPersonByName(const std::string name);
    std::string findPersonByIndex(int index);
    size_t getPersonsCount() const;
    size_t findCouplesThroughThreeHandshakes(int from, int to);
    void findMinWayInner(int current, int to, bool* visited, size_t& min, int currentDistance);

private:
    // структура Человек
    struct Person
    {
        std::string name;
    };
    int friendshipMatrix[SIZE][SIZE]; // матрица смежности, отражающая дружеские связи между людьми
    Person persons[SIZE]; // хранилище имен людей
    size_t personsCount; // количество добавленных людей


};
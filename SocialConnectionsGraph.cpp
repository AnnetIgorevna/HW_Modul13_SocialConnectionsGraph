#include "SocialConnectionsGraph.h"

SocialConnectionsGraph::SocialConnectionsGraph()
{
    for (size_t i = 0; i < SIZE; i++) {
        for (size_t j = 0; j < SIZE; j++)
            friendshipMatrix[i][j] = 0;
    }
    personsCount = 1;
}

void SocialConnectionsGraph::addPerson(const std::string name)
{
    persons[personsCount++].name = name;
}

void SocialConnectionsGraph::addFriendship(int p1, int p2)
{
    friendshipMatrix[p1][p2] = 1;
    friendshipMatrix[p2][p1] = 1;
}

bool SocialConnectionsGraph::friendshipExists(int p1, int p2)
{
    return friendshipMatrix[p1][p2] > 0;
}

bool SocialConnectionsGraph::personExists(const std::string name)
{
    for (size_t i = 0; i < personsCount; i++)
    {
        if (persons[i].name == name)
            return true;
    }
    return false;
}

size_t SocialConnectionsGraph::findPersonByName(const std::string name)
{
    for (size_t i = 0; i < personsCount; i++)
    {
        if (persons[i].name == name)
            return i;
    }
    return -1;
}

std::string SocialConnectionsGraph::findPersonByIndex(int index)
{
    return persons[index].name;
}

// алгоритм поиска всех пар знакомств через три рукопожатия на основе алгоритма поиска в глубину
size_t SocialConnectionsGraph::findCouplesThroughThreeHandshakes(int from, int to)
{
    bool visited[SIZE]{}; // массив пройденных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false;
    size_t min = VERYBIGINT; // начальное минимальное расстояние
    int currentDistance = 0;

    findMinWayInner(from, to, visited, min, currentDistance);
    return min;
}

void SocialConnectionsGraph::findMinWayInner(int current, int to, bool* visited, size_t& min, int currentDistance)
{
    if (current == to)
    {
        // если попали в целевую вершину, сравниваем текущий путь с минимальным
        if (min > currentDistance)
        {
            // если новое расстояние меньше, запоминаем
            min = currentDistance;
        }
        return;
    }
    visited[current] = true; // обозначем вершину посещенной
    for (int i = 0; i < SIZE; i++)
    {
        if (friendshipExists(current, i) && !visited[i])
        {
            // запускаем рекурсию для всех непосещенных смежных вершин
            int newDist = currentDistance + friendshipMatrix[current][i];
            findMinWayInner(i, to, visited, min, newDist);
        }
    }
    // отмечаем, что путь уже не содержит эту вершину
    visited[current] = false;
}

size_t SocialConnectionsGraph::getPersonsCount() const
{
    return personsCount;
}

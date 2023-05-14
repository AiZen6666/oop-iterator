#include <iostream>
#include <vector>
#include <string>

// Класс "Киберспортивная команда"
class CyberTeam {
public:
    CyberTeam(std::string name, std::string game)
        : m_name(name), m_game(game) {}

    std::string getName() const { return m_name; }
    std::string getGame() const { return m_game; }

private:
    std::string m_name; // Название команды
    std::string m_game; // Название игры
};

// Шаблонный контейнер "Киберспортивные команды"
template <typename T>
class CyberTeamContainer {
    // LegacyIterator требует использования типов-членов класса
public:
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using size_type = typename std::vector<T>::size_type;

    CyberTeamContainer() = default;

    // Добавление команды в контейнер
    void addTeam(T team) { m_teams.push_back(std::move(team)); }

    // Возвращает количество команд в контейнере
    size_type size() const { return m_teams.size(); }

    // Итераторы должны указывать на элементы контейнера
    iterator begin() { return m_teams.begin(); }
    iterator end() { return m_teams.end(); }
    const_iterator begin() const { return m_teams.begin(); }
    const_iterator end() const { return m_teams.end(); }

private:
    std::vector<T> m_teams;
};

int main() {
    CyberTeamContainer<CyberTeam> container;
    container.addTeam(CyberTeam("Astralis", "CS:GO"));
    container.addTeam(CyberTeam("Natus Vincere", "DOTA 2"));

    // Использование итератора для обхода контейнера
    for (const auto& team : container) {
        std::cout << "Team: " << team.getName() << ", Game: " << team.getGame() << "\n";
    }

    return 0;
}
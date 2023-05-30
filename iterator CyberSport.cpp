#include <iostream>
#include <vector>
#include <string>

// Êëàññ "Êèáåðñïîðòèâíàÿ êîìàíäà"
class CyberTeam {
public:
    CyberTeam(std::string name, std::string game)
        : m_name(name), m_game(game) {}

    std::string getName() const { return m_name; }
    std::string getGame() const { return m_game; }

private:
    std::string m_name; // Íàçâàíèå êîìàíäû
    std::string m_game; // Íàçâàíèå èãðû
};

// Øàáëîííûé êîíòåéíåð "Êèáåðñïîðòèâíûå êîìàíäû"
template <typename T>
class CyberTeamContainer {
    // LegacyIterator òðåáóåò èñïîëüçîâàíèÿ òèïîâ-÷ëåíîâ êëàññà
public:
    using value_type = T;
    using iterator = typename std::vector<T>::iterator;
    using const_iterator = typename std::vector<T>::const_iterator;
    using size_type = typename std::vector<T>::size_type;

    CyberTeamContainer() = default;

    // Äîáàâëåíèå êîìàíäû â êîíòåéíåð
    void addTeam(T team) { m_teams.push_back(std::move(team)); }

    // Âîçâðàùàåò êîëè÷åñòâî êîìàíä â êîíòåéíåðå
    size_type size() const { return m_teams.size(); }

    // Èòåðàòîðû äîëæíû óêàçûâàòü íà ýëåìåíòû êîíòåéíåðà
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

    // Èñïîëüçîâàíèå èòåðàòîðà äëÿ îáõîäà êîíòåéíåðà
    for (const auto& team : container) {
        std::cout << "Team: " << team.getName() << ", Game: " << team.getGame() << "\n";
    }

    return 0;
}

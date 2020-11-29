#pragma once

#include<string>
#include<iostream>
#include<iomanip>

class Civilizacion {
private:
	std::string name;
	int xPos;
	int yPos;
	int score;

public:
	Civilizacion();
	Civilizacion(const std::string&, const int&, const int&, const int&);

	void setName(const std::string&);
	void setXpos(const int&);
	void setYpos(const int&);
	void setScore(const int&);

	std::string getName();
	int getXpos();
	int getYpos();
	int getScore();

	friend std::ostream& operator << (std::ostream& out, Civilizacion c) {
		out << std::left;
		out << std::setw(20) << c.name;
		out << std::setw(20) << c.xPos;
		out << std::setw(20) << c.yPos;
		out << std::setw(20) << c.score;
		out << std::endl;

		return out;
	}

	friend std::istream& operator >> (std::istream& in, Civilizacion& c) {
		std::cin.ignore();
		std::cout << "Nombre de la civilizacion: ";
		std::getline(std::cin, c.name);

		std::cout << "Posicion en x: ";
		std::cin >> c.xPos;

		std::cout << "Posicion en y: ";
		std::cin >> c.yPos;

		std::cout << "Puntaje: ";
		std::cin >> c.score;

		return in;
	}

	bool operator == (const Civilizacion& c)const {
		return name == c.name;
	}

	bool operator < (const Civilizacion& c)const {
		return name < c.name;
	}

	bool operator != (const Civilizacion& c)const {
		return name != c.name;
	}
};

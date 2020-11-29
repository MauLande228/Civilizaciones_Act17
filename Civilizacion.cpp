#include "Civilizacion.h"

Civilizacion::Civilizacion() : name("NO_NAME"), score(0), xPos(-1), yPos(-1) {}

Civilizacion::Civilizacion(const std::string& name, const int& xPos, const int& yPos, const int& score) {
	this->name = name;
	this->xPos = xPos;
	this->yPos = yPos;
	this->score = score;
}

void Civilizacion::setName(const std::string& name) {
	this->name = name;
}

void Civilizacion::setXpos(const int& xPos) {
	this->xPos = xPos;
}

void Civilizacion::setYpos(const int& yPos) {
	this->yPos = yPos;
}

void Civilizacion::setScore(const int& score) {
	this->score = score;
}

std::string Civilizacion::getName() {
	return name;
}

int Civilizacion::getXpos() {
	return xPos;
}
int Civilizacion::getYpos() {
	return yPos;
}

int Civilizacion::getScore() {
	return score;
}
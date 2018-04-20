#pragma once

#include "SFML\Graphics.hpp"

class Fabrica{

public:
	
	sf::RectangleShape fab;
	float base, esquerda, direita, topo;

	Fabrica(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Color cor) {
	
		fab.setPosition(posicao);
		fab.setSize(tamanho);
		fab.setFillColor(cor);
	}

	void Update() {

		base = fab.getPosition().y + fab.getSize().y;
		esquerda = fab.getPosition().x;
		direita = fab.getPosition().x + fab.getSize().x;
		topo = fab.getPosition().y;

	}	
	






};
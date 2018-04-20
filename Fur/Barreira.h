#pragma once

#include "SFML\Graphics.hpp"

class Barreira {

public:

float base, esquerda, direita, topo;

public:

	sf::RectangleShape bar;

	void Update() {

		base = bar.getPosition().y + bar.getSize().y;
		esquerda = bar.getPosition().x;
		direita = bar.getPosition().x + bar.getSize().x;
		topo = bar.getPosition().y;

	}
	Barreira(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Color cor) {

		bar.setPosition(posicao);
		bar.setSize(tamanho);
		bar.setFillColor(cor);
	}


};
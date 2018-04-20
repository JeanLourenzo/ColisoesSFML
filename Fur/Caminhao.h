#pragma once

#pragma once

#include "SFML\Graphics.hpp"
#include "Todos.h"
#include <time.h>
#include <iostream>

#include "Barreira.h"
#include "Fabrica.h"
#include <random>
#include "Caminhao.h"






class Caminhao : public Todos {

public:

	sf::RectangleShape Cam;
	float base, esquerda, direita, topo;

	// Setando posição inicial do Carro.

	Caminhao(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Color cor) {

		Cam.setPosition(posicao);
		Cam.setSize(tamanho);
		Cam.setFillColor(cor);
	}



	// Função para dar movimento.

	void Movimento() {


		std::random_device rd; // obtain a random number from hardware
		std::mt19937 eng(rd()); // seed the generator
		std::uniform_int_distribution<> distr(1, 3); // define the range

		float x = 0, y = 0;



		if (distr(eng) == 1) {
			x = -1.0f;
		}

		if (distr(eng) == 2) {
			x = 0;
		}

		if (distr(eng) == 3) {
			x = 1.0f;
		}

		if (distr(eng) == 1) {
			y = -1.0f;
		}

		if (distr(eng) == 2) {
			y = 0;
		}

		if (distr(eng) == 3) {
			y = 1.0f;
		}

		Cam.move(x, y);

	}

	// Função para atualizar posição atual.

	void Update() {

		base = Cam.getPosition().y + Cam.getSize().y;
		esquerda = Cam.getPosition().x;
		direita = Cam.getPosition().x + Cam.getSize().x;
		topo = Cam.getPosition().y;
	}

	bool Colisor(Fabrica p)
	{

		return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

	}

	bool Colisor(Caminhao p)
	{

		return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

	}


	bool Colisor(Barreira p)
	{
		int a, b, c, d;
		if (direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo) {

			a = Cam.getPosition().y + Cam.getSize().y;
			b = Cam.getPosition().x;
			c = Cam.getPosition().x + Cam.getSize().x;
			d = Cam.getPosition().y;

			if (b <= 0) {
				Cam.setPosition(59, d);
			}
			if (b >= 60) {
				Cam.setPosition(1, d);
			}
			if (d <= 0) {
				Cam.setPosition(b, 29);
			}
			if (d >= 30) {
				Cam.setPosition(b, 1);
			}

		}
		return true;
	}





};


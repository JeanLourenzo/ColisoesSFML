#pragma once

#include "SFML\Graphics.hpp"
#include "Todos.h"
#include "Barreira.h"
#include "Fabrica.h"
#include <random>
#include "Caminhao.h"
#include "Carro.h"


class Moto : public Todos {

public:

	sf::RectangleShape Mot;
	float base, esquerda, direita, topo;

	// Setando posi��o inicial do Carro.

	Moto(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Color cor) {

		Mot.setPosition(posicao);
		Mot.setSize(tamanho);
		Mot.setFillColor(cor);
	}



	// Fun��o para dar movimento.

	void Movimento() {


		std::random_device rd; 
		std::mt19937 eng(rd());
		std::uniform_int_distribution<> distr(1, 3); 

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

		Mot.move(x, y);

	}

	// Fun��o para atualizar posi��o atual.

	void Update() {

		base = Mot.getPosition().y + Mot.getSize().y;
		esquerda = Mot.getPosition().x;
		direita = Mot.getPosition().x + Mot.getSize().x;
		topo = Mot.getPosition().y;
	}

	bool Colisor(Fabrica p)
	{

		return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

	}

	bool Colisor(Carro p)
	{

		return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

	}

	bool Colisor(Moto p)
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

			a = Mot.getPosition().y + Mot.getSize().y;
			b = Mot.getPosition().x;
			c = Mot.getPosition().x + Mot.getSize().x;
			d = Mot.getPosition().y;

			if (b <= 0) {
				Mot.setPosition(59, d);
			}
			if (b >= 60) {
				Mot.setPosition(1, d);
			}
			if (d <= 0) {
				Mot.setPosition(b, 29);
			}
			if (d >= 30) {
				Mot.setPosition(b, 1);
			}

		}
		return true;
	}





};


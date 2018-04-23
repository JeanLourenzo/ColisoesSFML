#pragma once

#include "SFML\Graphics.hpp"
#include "Todos.h"
#include <time.h>
#include <iostream>

#include "Barreira.h"
#include "Fabrica.h"
#include "Caminhao.h"
#include <random>





class Carro : public Todos {

public:

	sf::RectangleShape Car;
	float base, esquerda, direita, topo;

	// Setando posição inicial do Carro.

	Carro(sf::Vector2f posicao, sf::Vector2f tamanho, sf::Color cor) {

		Car.setPosition(posicao);
		Car.setSize(tamanho);
	    Car.setFillColor(cor);
	}



	// Função para dar movimento.

	void Movimento() {
		

		std::random_device rd;
		std::mt19937 eng(rd()); 
		std::uniform_int_distribution<> distr(1, 3); 
	
		float x = 0, y = 0;
	

		
			if (distr(eng) == 1) {
				x = -0.8f;
			}

			if (distr(eng) == 2) {
				x = 0;
			}

			if (distr(eng) == 3) {
				x = 0.8f;
			}

			if (distr(eng) == 1) {
				y = -0.8f;
			}

			if (distr(eng) == 2) {
				y = 0;
			}

			if (distr(eng) == 3) {
				y = 0.8f;
			}
						
				Car.move(x, y);
		
			

	}

	// Função para atualizar posição atual.

	void Update() {

		base = Car.getPosition().y  + Car.getSize().y;
		esquerda = Car.getPosition().x;
		direita = Car.getPosition().x + Car.getSize().x;
		topo = Car.getPosition().y;
	}

	bool Colisor(Fabrica p)
	{

		return !(direita <= p.esquerda || esquerda >= p.direita || topo >= p.base || base <= p.topo);

	}

	bool Colisor(Carro p)
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

			a = Car.getPosition().y + Car.getSize().y;
			b = Car.getPosition().x;
			c = Car.getPosition().x + Car.getSize().x;
			d = Car.getPosition().y;

			if (b <= 0) {
				Car.setPosition(59, d);
			}
			if (b >= 60) {
				Car.setPosition(1, d);
			}
			if (d <= 0) {
				Car.setPosition(b,29);
			}
			if (d >= 30) {
				Car.setPosition(b, 1);
			}

		}
		return true;
	}





};


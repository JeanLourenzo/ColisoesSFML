#include "SFML/Graphics.hpp"
#include <iostream>
#include "Carro.h"
#include "Fabrica.h"
#include "Barreira.h"
#include "Caminhao.h"
#include "Moto.h"
#include <vector>
#include <random>


using namespace std;




int main() {

	sf::RenderWindow window(sf::VideoMode(1024, 768), "Projeto P1");
	int i = 0, j = 0, x = 1, y = 1;


	sf::View view = window.getDefaultView();
	view.setCenter(30, 15);
	view.zoom(0.07f);

	std::random_device random; // obtain a random number from hardware
	std::mt19937 engine(random()); // seed the generator
	std::uniform_int_distribution<> xr(3, 57); // define the range
	std::uniform_int_distribution<> yr(3, 27); // define the range

	int mapa[30][60] = // Mapa:   0 = Vazio   1 = Barreira Horizontal   2 = Barreira Vertical    3 = Fábrica;

	{ { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };


	vector<Carro> cx;
	vector<Caminhao> camx;
	vector<Moto> mx;



	for (i = 0; i < 10; i++) {

		cx.push_back(Carro(sf::Vector2f(xr(engine), yr(engine)), sf::Vector2f(1, 1), sf::Color::Red));

	}


	for (i = 0; i < 10; i++) {

		mx.push_back(Moto(sf::Vector2f(xr(engine), yr(engine)), sf::Vector2f(1, 1), sf::Color::Magenta));

	}

	for (i = 0; i < 10; i++) {

		camx.push_back(Caminhao(sf::Vector2f(xr(engine), yr(engine)), sf::Vector2f(1, 1), sf::Color::Cyan));

	}


	Fabrica f1(sf::Vector2f(7, 7), sf::Vector2f(2, 2), sf::Color::Yellow);
	Fabrica f2(sf::Vector2f(52, 7), sf::Vector2f(2, 2), sf::Color::Yellow);
	Fabrica f3(sf::Vector2f(29, 14), sf::Vector2f(2, 2), sf::Color::Yellow);
	Fabrica f4(sf::Vector2f(7, 22), sf::Vector2f(2, 2), sf::Color::Yellow);
	Fabrica f5(sf::Vector2f(52, 22), sf::Vector2f(2, 2), sf::Color::Yellow);



	Barreira b1(sf::Vector2f(0, 0), sf::Vector2f(60, 1), sf::Color::White);
	Barreira b2(sf::Vector2f(0, 30), sf::Vector2f(60, 1), sf::Color::White);
	Barreira b3(sf::Vector2f(0, 0), sf::Vector2f(1, 30), sf::Color::White);
	Barreira b4(sf::Vector2f(59, 0), sf::Vector2f(1, 30), sf::Color::White);


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();

		}

		window.setView(view);


		for (int i = 0; i < cx.size(); i++) {


			cx[i].Movimento();
			cx[i].Update();
		}

		for (int i = 0; i < camx.size(); i++) {
			camx[i].Movimento();
			camx[i].Update();
		}

		for (int i = 0; i < mx.size(); i++) {
			mx[i].Movimento();
			mx[i].Update();
		}

		//system("Pause");
		

		f1.Update();
		f2.Update();
		f3.Update();
		f4.Update();
		f5.Update();

		b1.Update();
		b2.Update();
		b3.Update();
		b4.Update();


		for (i = 0; i < cx.size(); i++) {

			// Colisor Carro-Fabrica
			if (cx[i].Colisor(f1) || cx[i].Colisor(f2) || cx[i].Colisor(f3) || cx[i].Colisor(f4) || cx[i].Colisor(f5)) {
				cx.push_back(Carro(sf::Vector2f(xr(engine), yr(engine)), sf::Vector2f(1, 1), sf::Color::Red));
			}

			// Colisor Carro-Barreira
			if (cx[i].Colisor(b1) || cx[i].Colisor(b2) || cx[i].Colisor(b3) || cx[i].Colisor(b4)) {
			}

				for (int j = 0; j < camx.size(); j++) {
					if (cx[i].Colisor(camx[j])) {
						cx.erase(cx.begin() + i);
						break;
					}
				}
			}

		
			// Colisor Carro-Carro
		for (i = 0; i < cx.size(); i++) {
			for (int j = 0; j < cx.size(); j++) {

				if (i != j) {
					if (cx[i].Colisor(cx[j])) {

						cx.erase(cx.begin() + i);
						if (i < j) {
							cx.erase(cx.begin() + (j - 1));

						}
						else {
							cx.erase(cx.begin() + j);

						}

						break;
					}

				}
			}
		}
		
			//Colisor Moto-Fabrica
			for (i = 0; i < mx.size(); i++) {
				if (mx[i].Colisor(f1) || mx[i].Colisor(f2) || mx[i].Colisor(f3) || mx[i].Colisor(f4) || mx[i].Colisor(f5)) {
					mx.push_back(Moto(sf::Vector2f(xr(engine), yr(engine)), sf::Vector2f(1, 1), sf::Color::Magenta));
				}

				//Colisor Moto-Barreira
				if (mx[i].Colisor(b1) || mx[i].Colisor(b2) || mx[i].Colisor(b3) || mx[i].Colisor(b4)) {
				}

				// Colisor Moto-Caminhão
				for (int j = 0; j < camx.size(); j++) {
					if (mx[i].Colisor(camx[j])) {
						mx.erase(mx.begin() + i);
						break;
						//system("Pause");
					}
				}
			}

			// Colisor Moto-Carro
			for (i = 0; i < mx.size(); i++) {

				for (int j = 0; j < cx.size(); j++) {
					if (mx[i].Colisor(cx[j])) {
						mx.erase(mx.begin() + i);
						break;
						//system("Pause");
					}
				}
			}

			// Colisor Moto-Moto
			for (i = 0; i < mx.size(); i++) {
				for (int j = 0; j < mx.size(); j++) {

					if (i != j) {
						if (mx[i].Colisor(mx[j])) {

							mx.erase(mx.begin() + i);
							if (i < j) {
								mx.erase(mx.begin() + (j - 1));

							}
							else {
								mx.erase(mx.begin() + j);
							}

							break;
						}

					}
				}
				
			}



			for (int i = 0; i < camx.size(); i++) {

				// Colisor Caminhão-Fabrica
				if (camx[i].Colisor(f1) || camx[i].Colisor(f2) || camx[i].Colisor(f3) || camx[i].Colisor(f4) || camx[i].Colisor(f5)) {

					camx.push_back(Caminhao(sf::Vector2f(xr(engine), yr(engine)), sf::Vector2f(1, 1), sf::Color::Cyan));
					
				}

				// Colisor Caminhão-Barreira
				if (camx[i].Colisor(b1) || camx[i].Colisor(b2) || camx[i].Colisor(b3) || camx[i].Colisor(b4)) {
					//	system("Pause");
				}
			}

			// Colisor Caminhão-Caminhão
			for (i = 0; i < camx.size(); i++) {
				for (int j = 0; j < camx.size(); j++) {

					if (i != j) {
						if (camx[i].Colisor(camx[j])) {

							camx.erase(camx.begin() + i);
							if (i < j){
								camx.erase(camx.begin() + (j - 1));
								
						}
						else {
								camx.erase(camx.begin() + j);
							
						}

							break;
						}
						
					}
				}
			}


				window.clear(sf::Color::Black);


				for (int i = 0; i < cx.size(); i++) {

					window.draw(cx[i].Car);
				}

				for (int i = 0; i < mx.size(); i++) {

					window.draw(mx[i].Mot);
				}

				for (int i = 0; i < camx.size(); i++) {
					window.draw(camx[i].Cam);
				}

				window.draw(f1.fab);
				window.draw(f2.fab);
				window.draw(f3.fab);
				window.draw(f4.fab);
				window.draw(f5.fab);

				window.draw(b1.bar);
				window.draw(b2.bar);
				window.draw(b3.bar);
				window.draw(b4.bar);
				window.display();

			}




		




		}

	

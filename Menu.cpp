#include"Menu.h"

Menu::Menu(VideoGame& game) {
	UIManager(game);
}

void Menu::UIManager(VideoGame& game) {
	std::string myStr;
	Civilizacion civilizacion;
	size_t myInt;
	short opc;

	while (true) {
		//system("cls");
		std::cout << "*****************CIVILIZACIONES EL JUEGO*****************" << std::endl;
		std::cout << std::left;
		std::cout << std::setw(30) << "1)Registrate" << std::setw(30) << "2)Crear nueva civilizacion" << std::endl;
		std::cout << std::setw(30) << "3)Insertar civilizacion" << std::setw(30) << "4)Crear civilizaciones" << std::endl;
		std::cout << std::setw(30) << "5)Ver primera civilizacion" << std::setw(30) << "6)Ver ultima civilizacion" << std::endl;
		std::cout << std::setw(30) << "7)Ordenar civilizaciones" << std::setw(30) << "8)Eliminar civilizacion" << std::endl;
		std::cout << std::setw(30) << "9)Buscar civilizacion" << std::setw(30) << "10)Modificar civilizacion" << std::endl;
		std::cout << std::setw(30) << "11)Mostrar civilizaciones" << std::setw(30) << "12)Salir" << std::endl;
		std::cout << "Selecciona una de las opciones anteriores ";
		std::cin >> opc;

		switch (opc) {
		case 1:
			system("cls");
			std::cout << "Bienvenido a la comunidad mas grande de los juegos de civilizaciones en el mundo!!" << std::endl;
			std::cout << "Nuestra comunidad permanece creciendo dia con dia y se mantiene en constante actividad gracias a nuestros apasionados fans" << std::endl;
			std::cout << "\nTu tambien puedes ser parte de esta gran familia. Solo necesitas crear un nombre de usuario con el que podras acceder " << std::endl;
			std::cout << "a tus civilizaciones en cualquier momento y en cualquier dispositivo gracias al poder de la nube y nuestro servicio mauCloud" << std::endl;
			std::cin >> myStr;
			game.setUname(myStr);
			break;


		case 2:
			system("cls");
			std::cin >> civilizacion;
			game.agregarCivilizacion(civilizacion);

			break;


		case 3:
			std::cin >> civilizacion;
			std::cin >> myInt;

			if (myInt >= game.total()) {
				std::cout << "La posicon no es valida para insertar" << std::endl;
			}
			else {
				game.insertar(civilizacion, myInt);
			}
			break;


		case 4:
			system("cls");
			std::cin >> civilizacion;
			std::cout << "Cantidad: ";
			std::cin >> myInt;
			game.inicializar(civilizacion, myInt);
			break;


		case 5:
			if (game.total() > 0) {
				std::cout << game.primera() << std::endl;
			}
			else {
				std::cout << "La lista no tiene mas de un elemento";
			}
			break;


		case 6:
			if (game.total() > 0) {
				std::cout << game.ultima() << std::endl;
			}
			else {
				std::cout << "La lista no tiene mas de un elemento";
			}
			break;


		case 7:
			system("cls");
			std::cout << std::left;
			std::cout << "Selcciona como quieres ordenar tus civilizaciones: " << std::endl;
			std::cout << std::setw(20) << "1)Por nombre" << std::setw(20) << "2)Por posicion en X";
			std::cout << std::setw(20) << "3)Por posicion en Y" << std::setw(20) << "4)Por puntaje (descendente)";
			std::cout << std::endl;
			std::cin >> myInt;

			switch (myInt) {
			case 1:
				game.ordenarNombre();
				break;

			case 2:
				game.ordenarXpos();
				break;

			case 3:
				game.ordenarYpos();
				break;

			case 4:
				game.ordenarPuntaje();
				break;

			default: std::cout << "Opcion no valida" << std::endl;
			}
			break;


		case 8:
			system("cls");
			std::cout << "Ingresa el nombre de la civilizacion que deseas eliminar: ";
			std::cin >> myStr;

			game.eliminar(myStr);
			break;


		case 9: {
			system("cls");
			Civilizacion c;
			std::cout << "Ingresa el nombre de la civilizacion que deseas buscar: ";
			std::cin >> myStr;
			c.setName(myStr);

			Civilizacion* cDir = game.buscar(c);

			if (cDir == nullptr) std::cout << "No se encontra la civilizacion" << std::endl;
			else {
				std::cout << *cDir << std::endl;
			}

		}
			  break;


		case 10:
		{
			system("cls");
			Civilizacion c;
			std::cout << "Ingresa el nombre de la civilizacion que desea modificar: ";
			std::cin >> myStr;
			c.setName(myStr);

			Civilizacion* cDir = game.buscar(c);

			if (cDir == nullptr) std::cout << "No se encontra la civilizacion" << std::endl;
			else {
				//std::cin >> *cDir;
				std::cout << "Que atributo desea modificar?" << std::endl;
				std::cout << std::setw(20) << "1)Nombre" << std::setw(20) << "2)Posicion en x";
				std::cout << std::setw(20) << "3)Posicon en y" << std::setw(20) << "4)Puntaje";
				std::cout << std::setw(20) << "5)Todo" << std::endl;
				std::cin >> myInt;
				switch (myInt) {
				case 1:
					std::cout << "Ingrese el nuevo nombre de la civilizacion: ";
					std::cin >> myStr;
					cDir->setName(myStr);
						break;

				case 2:
					std::cout << "Ingresa la nueva posicion en x: ";
					std::cin >> myInt;
					cDir->setXpos(myInt);
					break;

				case 3:
					std::cout << "Ingresa la nueva posicon en y: ";
					std::cin >> myInt;
					cDir->setYpos(myInt);
					break;

				case 4:
					std::cout << "Ingresa el nuevo puntaje: ";
					std::cin >> myInt;
					cDir->setScore(myInt);
					break;

				case 5:
					std::cin >> *cDir;
					break;

				default: std::cout << "Opcion no valida" << std::endl;
				}
			}

		}
		break;

		case 11:
			system("cls");
			game.mostrar();
			break;

		case 12: return;
			break;

		default: std::cout << "Pruebe con otra opcion" << std::endl;
		}
	}
}
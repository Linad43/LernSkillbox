#include "..\header_modul28.h"

std::mutex mtxKitchen, mtxCourier, mtxCout2;
int numOrder = 1;

enum dish {
	PIZZA, SOUP, STEAK, SALAD, SUSHI
};
const std::map<int, std::string> dishMap = {
	{0,"PIZZA"},
	{1,"SOUP"},
	{2,"STEAK"},
	{3,"SALAD"},
	{4,"SUSHI"},
};

class Order {
	std::string name = "order " + std::to_string(numOrder++);
	dish food = static_cast<dish>(random(0, 4));
public:
	dish getFood() {
		return food;
	}
	std::string toString() {
		return name + " " + dishMap.find(food)->second;
	}
};

//class Courier {
//	std::vector<Order> readyOrders;
//	std::vector<Order> finishOrders;
//public:
//
//	void addFinishOrders(Order order) {
//		finishOrders.push_back(order);
//		mtxCout2.lock();
//		std::cout << "Order done\n";
//		std::cout << order.toString() << std::endl;
//		mtxCout2.unlock();
//	}
//	void driveOrder() {
//		Order order = *readyOrders.begin();
//		readyOrders.erase(readyOrders.begin());
//		std::this_thread::sleep_for(std::chrono::seconds(30));
//		addFinishOrders(order);
//	}
//};

//void driveOrderMain(Courier courier) {
//	courier.driveOrder();
//}

class Kitchen {
	std::vector<Order> orders;
	std::vector<Order> readyOrders;
	std::vector<Order> finishOrders;
	/*std::vector<std::thread> threadCooking;
	std::vector<std::thread> threadDrivers;*/
public:
	void addToOrders(Order order) {
		orders.push_back(order);
		mtxCout2.lock();
		std::cout << "Create order\n";
		std::cout << order.toString() << std::endl;
		mtxCout2.unlock();
		mtxKitchen.lock();
		//std::thread cook(this, &cooking);
		//threadCooking.emplace_back(&Kitchen::cooking);
		cooking();
		mtxKitchen.unlock();
	}
	void addReadyOrders(Order order) {
		readyOrders.push_back(order);
		mtxCout2.lock();
		std::cout << "Ready order\n";
		std::cout << order.toString() << std::endl;
		mtxCout2.unlock();
		mtxCourier.lock();
		//Courier courier = Courier();
		//threadDrivers.emplace_back(driveOrderMain, courier);
		driveOrder();
		mtxCourier.unlock();
	}
	void addFinishOrders(Order order) {
		finishOrders.push_back(order);
		mtxCout2.lock();
		std::cout << "Order done\n";
		std::cout << order.toString() << std::endl;
		mtxCout2.unlock();
	}
	void cooking() {
		Order order = *orders.begin();
		orders.erase(orders.begin());
		std::this_thread::sleep_for(std::chrono::seconds(random(5, 15)));
		addReadyOrders(order);
	}
	void driveOrder() {
		Order order = *readyOrders.begin();
		readyOrders.erase(readyOrders.begin());
		std::this_thread::sleep_for(std::chrono::seconds(30));
		addFinishOrders(order);
	}
};


void addToOrdersMain(Kitchen kitchen, Order order) {
	kitchen.addToOrders(order);
}
//void cookingMain(Kitchen kitchen) {
//	kitchen.cooking();
//}
//void driveOrderMain(Courier courier) {
//	courier.driveOrder();
//}

void mod28ex3() {
	std::cout << "3. Реализовать симуляцию работы кухни онлайн-ресторана.\n";
	int countOrders = 10;
	Kitchen kitchen = Kitchen();
	std::vector<std::thread> treadOrders;
	for (int i = 0; i < countOrders; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(random(5, 10)));
		Order order = Order();
		treadOrders.emplace_back(addToOrdersMain, kitchen, order);
	};
	for (int i = 0; i < treadOrders.size(); i++) {
		treadOrders[i].join();
	}
	/*for (int i = 0; i < treadOrders.size(); i++) {
		treadOrders[i].detach();
	}*/
}
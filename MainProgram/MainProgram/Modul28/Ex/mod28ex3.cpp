#include "..\header_modul28.h"

void wait_for_call() {
	std::this_thread::sleep_for(std::chrono::seconds(10));
	std::cout << "RING (COURIER)" << std::endl;

}

void mod28ex3() {
	std::cout << "3. Реализовать симуляцию работы кухни онлайн-ресторана.\n";
	std::thread call(wait_for_call);
	for (int i = 0; i < 10; i++) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << i + 1 << std::endl;
	}
	call.join();
}
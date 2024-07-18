#include<stdio.h>
#include<thread>
#include <iostream>
void Quadruple(int num) {
	num *= 4;
	std::cout << "thread id=" << std::this_thread::get_id() << std::endl;
	std::cout << "num*4=" << num << std::endl;
}
void AddFour(int num) {
	num += 4;
	std::cout << "thread id=" << std::this_thread::get_id() << std::endl;
	std::cout << "num+4=" << num << std::endl;
}
void SubtractFour(int num) {
	num -= 4;
	std::cout << "thread id=" << std::this_thread::get_id() << std::endl;
	std::cout << "num-4=" << num << std::endl;
}
int main() {
	int num = 5;

	std::thread thread1(Quadruple, num);
	thread1.join();

	std::thread thread2(AddFour, num);
	thread2.join();

	std::thread thread3(SubtractFour, num);
	thread3.join();
	return 0;
}
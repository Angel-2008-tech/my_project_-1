#include "pch.h"
#include "CppUnitTest.h"
// Увага: заміни "Назва_Твого_Проекту" на фактичну назву папки з твоїм основним кодом
#include "../oop_1.1/Pay.cpp"

// Якщо під час компіляції виникнуть помилки лінкування (LNK2019), 
// розкоментуй наступний рядок, щоб напряму підключити файл реалізації:
// #include "../Назва_Твого_Проекту/Pay.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PayUnitTests
{
	TEST_CLASS(PayUnitTests)
	{
	public:

		TEST_METHOD(TestSetFirst_ValidAndInvalid)
		{
			Pay p;
			// Перевірка коректного значення (додатне число)
			Assert::IsTrue(p.SetFirst(15000.5));
			Assert::AreEqual(15000.5, p.GetFirst());

			// Перевірка некоректного значення (від'ємне число)
			Assert::IsFalse(p.SetFirst(-500.0));
			Assert::AreEqual(1.0, p.GetFirst()); // Перевіряємо, чи встановилася 1.0 як захист
		}

		TEST_METHOD(TestSetSecond_ValidAndInvalid)
		{
			Pay p;
			// Перевірка коректного значення
			Assert::IsTrue(p.SetSecond(20));
			Assert::AreEqual(20, p.GetSecond());

			// Перевірка некоректного значення (нуль або від'ємне)
			Assert::IsFalse(p.SetSecond(0));
			Assert::AreEqual(1, p.GetSecond());
		}

		TEST_METHOD(TestInit)
		{
			Pay p;
			// Метод Init має повернути true, якщо обидва аргументи правильні
			Assert::IsTrue(p.Init(20000.0, 15));
			Assert::AreEqual(20000.0, p.GetFirst());
			Assert::AreEqual(15, p.GetSecond());
		}

		TEST_METHOD(TestSumma_Calculation)
		{
			Pay p;
			p.Init(22000.0, 10);
			// Оклад 22000, 22 робочих дні в місяці, відпрацьовано 10.
			// 22000 / 22 * 10 = 10000
			double expected = 10000.0;
			Assert::AreEqual(expected, p.summa(22));
		}

		TEST_METHOD(TestSumma_DivideByZeroProtection)
		{
			Pay p;
			p.Init(20000.0, 15);
			// Якщо передати 0 робочих днів у місяці, програма не повинна впасти
			// Вона має повернути 0, як ми прописали в логіці
			Assert::AreEqual(0.0, p.summa(0));
		}
	};
}
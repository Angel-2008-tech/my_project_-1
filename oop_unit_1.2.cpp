#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\AdminP\Desktop\C++\oop_1.2\Matrix.cpp" // Замініть на назву вашої папки з проектом

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MatrixUnitTest
{
	TEST_CLASS(MatrixTests)
	{
	public:

		// Тест ініціалізації з коректними даними
		TEST_METHOD(TestInitValid)
		{
			Matrix m;
			Assert::IsTrue(m.Init(2, 3));
			Assert::AreEqual(2, m.getRows());
			Assert::AreEqual(3, m.getCols());
		}

		// Тест ініціалізації з некоректними даними (має повернути false)
		TEST_METHOD(TestInitInvalid)
		{
			Matrix m;
			Assert::IsFalse(m.Init(-1, 5));
			Assert::IsFalse(m.Init(3, 0));
		}

		// Тест функцій запису та читання елементів
		TEST_METHOD(TestElements)
		{
			Matrix m;
			m.Init(2, 2);
			m.setElement(0, 0, 10.5f);
			m.setElement(1, 1, -5.0f);

			Assert::AreEqual(10.5f, m.getElement(0, 0));
			Assert::AreEqual(-5.0f, m.getElement(1, 1));
			Assert::AreEqual(0.0f, m.getElement(0, 1)); // Дефолтне значення
		}

		// Тест обчислювальних методів (Варіант 14)
		TEST_METHOD(TestCalculations)
		{
			Matrix m;
			m.Init(2, 2);
			m.setElement(0, 0, 1.0f);
			m.setElement(0, 1, 5.0f);
			m.setElement(1, 0, -2.0f);
			m.setElement(1, 1, 4.0f);

			Assert::AreEqual(-2.0f, m.getMin());   // Мінімум
			Assert::AreEqual(5.0f, m.getMax());    // Максимум
			Assert::AreEqual(8.0f, m.getSum());    // Сума: 1 + 5 + (-2) + 4 = 8
		}
	};
}
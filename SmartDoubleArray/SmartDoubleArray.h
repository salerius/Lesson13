#pragma once
#include <iostream>

using namespace std;


namespace MyArray
{

	template <class T>
	class SmartDoubleArray
	{

	public:
		SmartDoubleArray();
		~SmartDoubleArray();
		void SmartDoubleArray<T>::add(T value);
		void SmartDoubleArray<T>::insert(T value, int index);
		void SmartDoubleArray<T>::remove(int index);
		int SmartDoubleArray<T>::count(T value) const;
		int SmartDoubleArray<T>::findNext(T value, int index) const;
		int SmartDoubleArray<T>::getSize() const;
		int SmartDoubleArray<T>::getCapacity() const;
		T& SmartDoubleArray<T>::operator[](int index);
		T& SmartDoubleArray<T>::getAt(int index) const;
//		friend std::ostream& operator<<(std::ostream& os, const SmartDoubleArray<T>& chiefPointer);
		
	private:
		T& SmartDoubleArray<T>::geetValueOfIndex(int index) const;
		bool indexCheck(int index) const;
		T *chiefPointer;
		int size;
		int capacity;


	};

		template <class T>
		SmartDoubleArray<T>::SmartDoubleArray()
		{
			    capacity = 8;
			    size = 0;
			    chiefPointer = new T[capacity];
		}

		template <class T>
		SmartDoubleArray<T>::~SmartDoubleArray()
		{
			    if (chiefPointer != nullptr)
			        delete chiefPointer;
		}

		
		template <class T>
		void SmartDoubleArray<T>::add(T value)
		{
			T* tempArray = nullptr;
			if (size == capacity)
			{
				capacity *= 2;
				tempArray = new T[capacity];

				for (int i = 0; i < size; i++)
				{
					tempArray[i] = chiefPointer[i];
				}
				delete[] chiefPointer;
				chiefPointer = new T[capacity];

				for (int i = 0; i < size; i++)
				{
					chiefPointer[i] = tempArray[i];
				}
				delete[] tempArray;
			}
			chiefPointer[size] = value;
			size++;
		}

		
		
		template <class T>
		void SmartDoubleArray<T>::insert(T value, int index)
		{
			if (!indexCheck(index))
				return;
			T* tempArray = nullptr;
			if (size == capacity)
			{
				capacity *= 2;
				tempArray = new T[capacity];
				for (int i = size; i >= 0; --i)
				{
					if (i > index + 1)
					{
						tempArray[i] = chiefPointer[i - 1];
						continue;
					}
					if (i == index + 1)
					{
						tempArray[index + 1] = value;
						continue;
					}
					tempArray[i] = chiefPointer[i];
				}
				chiefPointer = nullptr;
				chiefPointer = tempArray;
				delete[] tempArray;
			}
			else
			{
				for (int i = size; i > index + 1; --i)
				{
					chiefPointer[i] = chiefPointer[i - 1];
				}
				chiefPointer[index + 1] = value;
			}

			size++;
		}

		template <class T>
		void SmartDoubleArray<T>::remove(int index)
		{
			if (!indexCheck(index))
				return;
			size--;
			T* tempArray = nullptr;
			tempArray = new int[capacity];

			for (int i = 0; i < index; i++)
			{
				tempArray[i] = chiefPointer[i];
			}
			for (int i = index; i < size; i++)
			{
				tempArray[i] = chiefPointer[i + 1];
			}
			delete[] chiefPointer;
			chiefPointer = tempArray;
		}

		template <class T>
		int SmartDoubleArray<T>::count(T value) const
		{
			int count = 0;
			for (int i = 0; i < size; i++)
			{
				if (chiefPointer[i] == value)
				{
					count++;
				}
			}
			return count;
		}

		template <class T>
		int SmartDoubleArray<T>::findNext(T value, int index) const
		{
			if (!indexCheck(index))
				return -1;
			for (int i = index; i < size; i++)
			{
				if (chiefPointer[i] == value)
				{
					return i;
				}
			}
			return -1;
		}

		template <class T>
		int SmartDoubleArray<T>::getSize() const
		{
			return size;
		}

		template <class T>
		int SmartDoubleArray<T>::getCapacity() const
		{
			return capacity;
		}




		template <class T>
		bool SmartDoubleArray<T>::indexCheck(int index) const
		{
			return !(index >= size || index < 0);
		}

		template <class T>
		T & SmartDoubleArray<T>::geetValueOfIndex(int index) const
		{
			if (!indexCheck(index))
				return 0;
			return chiefPointer[index];
		}



		template <class T>
		T & SmartDoubleArray<T>::operator[](int index)
		{
			return getValueOfIndex(index);
		}

		
		template <class T>
		T & SmartDoubleArray<T>::getAt(int index) const
		{
			return getValueOfIndex(index);
		}
	


		//template <class T>
		//std::ostream& operator<<(std::ostream& os, const SmartDoubleArray<T>& chiefPointer)
		//{
		//	for (int i = 0; i < chiefPointer.size; i++)
		//	{
		//		os << chiefPointer.getValueOfIndex(i) << " ";
		//	}
		//	return os;
		//}

//**********************//




	//template <class T>
		//friend std::ostream& operator<<(std::ostream& os, const SmartDoubleArray& chiefPointer)
		//{
		//	for (int i = 0; i < chiefPointer.size; i++)
		//	{
		//		os << chiefPointer.getValueOfIndex(i) << " ";
		//	}
		//	return os;
		//}




   

}

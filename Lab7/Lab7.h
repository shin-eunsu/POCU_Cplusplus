#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		int mapSize = std::min(keys.size(), values.size());

		for (int i = 0; i < mapSize; i++)
		{
			m[keys[i]] = values[i];
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}
		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		for (typename std::vector<T>::const_reverse_iterator iter = v.rbegin(); iter != v.rend(); ++iter)
		{
			rv.push_back(*iter);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;

		for (typename std::vector<T>::const_iterator iter = v1.begin(); iter != v1.end(); ++iter)
		{
			combined.push_back(*iter);
		}

		for (typename std::vector<T>::const_iterator iter2 = v2.begin(); iter2 != v2.end(); ++iter2)
		{
			bool bIsPush = true;
			for (typename std::vector<T>::iterator iterc = combined.begin(); iterc != combined.end(); ++iterc)
			{
				if (*iter2 == *iterc)
				{
					bIsPush = false;
					break;
				}
			}
			if (bIsPush)
			{
				combined.push_back(*iter2);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (typename std::map<K, V>::const_iterator iter = m1.begin(); iter != m1.end(); ++iter)
		{
			combined.insert(std::pair(iter->first, iter->second));
		}

		for (typename std::map<K, V>::const_iterator iter2 = m2.begin(); iter2 != m2.end(); ++iter2)
		{
			bool bIsInsert = true;
			for (typename std::map<K, V>::const_iterator iter = m1.begin(); iter != m1.end(); ++iter)
			{
				if (*iter == *iter2)
				{
					bIsInsert = false;
					break;
				}
			}
			combined.insert(std::pair(iter2->first, iter2->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (typename std::vector<T>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			os << *iter;
			if (iter != v.end() - 1)
			{
				os << ", ";
			}
		}
		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }";
			if (iter != --m.end())
			{
				os << std::endl;
			}
		}
		return os;
	}
}
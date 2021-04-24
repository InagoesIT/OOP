#include <stdio.h>
#include <iostream>

#define MAX_SIZE 100

using namespace std;

template <typename K, typename V>
struct Item
{
    K key;
    V val;
    int index;
};

template <class K, class V>
class Map
{
public:
    Item<K, V> items[MAX_SIZE];
    int size;

    Map: size(0) () {}

    void Set (const K& key, const V& value)
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i].key == key)
            {
                items[i].val = value;
                break;
            }
        }
    }

    bool Get(const K& key, V& value)
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i].key == key)
            {
                items[i].val = value;
                return true;
            }
        }
        return false;
    }

    int Count()
    {
        return size;
    }

    void Clear()
    {
        size = 0;
    }

    bool Delete(const K& key)
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i].key == key)
            {
                while (i < this->size) 
                {
                    items[i].key == items[i + 1].key;
                    items[i].val == items[i + 1].val;
                    ++i;
                }
                                       
                --size;
                return true;
            }
        }
        return false;
    }

    bool Includes(const Map<K, V>& map)
    {
        for (int i = 0; i < map.Count(); ++i)
        {
            bool found = 0;

            for (int j = 0; j < this->size; ++i)
            {
                if (this->items[j].key == map->items[i].key)
                {
                    found = 1;
                    break;
                }
            }

            if (!found)
                return false;
        }
        return true;
    }

    V& operator[](const K& key)
    {
        for (int i = 0; i < size; ++i)
        {
            if (items[i].key == key)
                return *items[i].val;
        }

        keyArr[size] = key;
        items[size].index = size;
        return *items[size++].val;
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";

    /*for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }*/

    cout << m.keyArr[0] << " " << m.keyArr[1] << " " << m.keyArr[2] << endl;
    cout << m.valArr[0] << " " << m.valArr[1] << " " << m.valArr[2] << endl;

    m[20] = "result";

    m.Delete(10);
  
    cout << m.keyArr[0] << " " << m.keyArr[1] << " " << endl;
    cout << m.valArr[0] << " " << m.valArr[1] << " " << endl;

    m.Set(30, "hei");

    cout << m.keyArr[0] << " " << m.keyArr[1] << " " << endl;
    cout << m.valArr[0] << " " << m.valArr[1] << " " << endl;

   /* for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }*/

    return 0;
}
// MinHeapConstruction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <math.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class CHeap
{
protected:
    vector<int> m_data;

    inline int parentIndex(int index) {
        return (index - 1) / 2;
    }

    inline int LeftIndex(int index) {
        return (2 * index + 1);
    }

    inline int RightIndex(int index) {
        return (2 * index + 2);
    }

public:
    bool IsEmpty()
    {
        return size() == 0;
    }

    int Top()
    {
        try
        {
            if (size() == 0) {
                throw out_of_range("Top() :: Heap underflow");
            }

            // replace the content of first element with last
            return m_data[0];
        }
        catch (const out_of_range& oor)
        {
            cout << oor.what() << "\n";
        }
    }

    void push(int ele)
    {
        m_data.push_back(ele);
        Rehipify_push(size() - 1);
    }

    int size()
    {
        return m_data.size();
    }

    void pop()
    {
        try
        {
            if (size() == 0) {
                throw out_of_range("Heap underflow");
            }

            // replace the content of first element with last
            m_data[0] = m_data.back();
            m_data.pop_back();
            Rehipify_pop(0);
        }
        catch (const out_of_range& oor)
        {
            cout << oor.what() << "\n";
        }
    }

public: 

    virtual void Rehipify_pop(int index) = 0;
    virtual void Rehipify_push(int index) = 0;
};

class CMinHeap : public CHeap
{
    void Rehipify_push(int index)
    {
        if (index && m_data[parentIndex(index)] > m_data[index])
        {
            std::swap(m_data[parentIndex(index)], m_data[index]);
            Rehipify_push(parentIndex(index));
        }
    }

    void Rehipify_pop(int index)
    {
        int leftIndex = LeftIndex(index);
        int rightIndex = RightIndex(index);

        int smallerEle = INT_MIN;
        if (leftIndex < size() && m_data[leftIndex] < m_data[index])
            smallerEle = leftIndex;

        if (rightIndex < size() && m_data[rightIndex] < m_data[index])
            smallerEle = rightIndex;

        if (smallerEle != INT_MIN)
        {
            std::swap(m_data[smallerEle], m_data[index]);
            Rehipify_pop(smallerEle);
        }
    }
};

class CMaxHeap : public CHeap
{
    vector<int> m_data;
private:


    void Rehipify_push(int index)
    {
        if (index && m_data[parentIndex(index)] < m_data[index])
        {
            std::swap(m_data[parentIndex(index)], m_data[index]);
            Rehipify_push(parentIndex(index));
        }
    }

    void Rehipify_pop(int index)
    {
        int leftIndex = LeftIndex(index);
        int rightIndex = RightIndex(index);

        int largerEle = INT_MIN;
        if (leftIndex < size() && m_data[leftIndex] > m_data[index])
            largerEle = leftIndex;

        if (rightIndex < size() && m_data[rightIndex] > m_data[index])
            largerEle = rightIndex;

        if (largerEle != INT_MIN)
        {
            std::swap(m_data[largerEle], m_data[index]);
            Rehipify_pop(largerEle);
        }
    }
};


int main()
{
    CMaxHeap obj;
    obj.push(12);
    obj.push(5);
    obj.push(787);

    obj.pop();

    obj.push(4);
    obj.push(23);
    obj.push(1);
    cout << endl;
}

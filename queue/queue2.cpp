#include <algorithm>
#include <iostream>
#include <vector>

class PriorityQueue
{
    struct Element
    {
        int value;
        int priority;
        int order;

        bool operator<(const Element &other) const
        {
            if (priority != other.priority)
            {
                return priority > other.priority;
            }

            return order < other.order;
        }
    };

    std::vector<Element> queue;
    int capacity; // Constraint of our queue
    int counter = 0;

  public:
    PriorityQueue(int limit) : capacity(limit) {};

    void enqueue(int value, int priority)
    {
        if (static_cast<std::size_t>(queue.size()) < this->capacity)
        {
            this->queue.push_back({value, priority, counter++});
        }
        else
        {
            int minPriority = queue[0].priority;
            std::size_t minIndex = 0;

            // Find lowest priority element
            for (std::size_t i = 1; i < static_cast<std::size_t>(queue.size()); ++i)
            {
                if (queue[i].priority < minPriority)
                {
                    minPriority = queue[i].priority;
                    minIndex = i;
                }
            }

            if (priority > minPriority)
            {
                queue[minIndex] = {value, priority, counter++};
            }
        }
    }

    void dequeue()
    {
        if (queue.empty())
        {
            return;
        }

        std::size_t bestIndex = 0;

        for (std::size_t i = 1; i < static_cast<std::size_t>(queue.size()); ++i)
        {
            // If a higher priority or the same priority with a lower order is available
            if ((queue[i].priority > queue[bestIndex].priority) ||
                (queue[i].priority == queue[bestIndex].priority && queue[i].order < queue[bestIndex].order))
            {
                bestIndex = i;
            }
        }

        queue.erase(queue.begin() + bestIndex);
    }

    void printAll()
    {
        std::vector<Element> sorted = queue;
        std::sort(sorted.begin(), sorted.end());

        for (Element &el : sorted)
        {
            std::cout << el.value << " " << el.priority << "\n";
        }
    }
};

int main()
{
    int limit;
    std::cin >> limit;
    PriorityQueue q(limit);

    std::string str;
    while (std::cin >> str)
    {
        if (str == "enqueue")
        {
            int value, priority;
            std::cin >> value >> priority;
            q.enqueue(value, priority);
        }
        else if (str == "dequeue")
        {
            q.dequeue();
        }
        else
        {
            std::cout << "Whoopa gangam style\n";
            break;
        }
    }

    q.printAll();
    return 0;
}

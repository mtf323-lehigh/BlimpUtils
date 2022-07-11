#pragma once

#include <deque>
#include <mutex>
#include <optional>
#include <vector>

template<typename T>
class Queue
{
private:
    std::deque<T> _store;
    std::mutex _mutex;

    typedef std::lock_guard<std::mutex> guard;

public:
    Queue() {}
    ~Queue() {}

    void push(T& item)
    {
        guard lg(_mutex);
        _store.push_back(item);
    }

    std::optional<T> pop()
    {
        guard lg(_mutex);
        if (_store.empty()) return {};                      // if queue is empty
        
        T item = _store.front();
        _store.pop_front();
        return item;
    }

    std::vector<T> all()
    {
        guard lg(_mutex);
        std::vector<T> vec;
        vec.reserve(_store.size());
        while (!_store.empty()) {
            vec.push_back(_store.front());
            _store.pop_front();
        }
        return vec;
    }

    void clear()
    {
        guard lg(_mutex);
        _store.clear();
    }

    void size()
    {
        guard lg(_mutex);
        return _store.size();
    }
};
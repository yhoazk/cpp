// Implement a list which is always ordered

#include <list>
#include <algorithm>
#include <iostream>

#include "gtest/gtest.h"

namespace sorted {

    struct list {
        std::list<int> data_{};
        list(){

        }

        void show() {
            for(const auto& e : data_) {
                std::cerr << e << " : ";
            }
            std::cerr << std::endl;
        }
        /*
            push:
            If value is smaller than top push front
            if value is bigger than tail push tail
            if neither find place and insert
        */
        void push(int n) {
            if (data_.empty()) {
                // std::cerr << "push empty" << std::endl;
                data_.push_back(n);
            } else if (n < data_.front() ) {
                // std::cerr << "push front: " << n << *data_.begin() <<  std::endl;
                data_.push_front(n);
            } else if ( n > data_.back()) {
                // std::cerr << "push back: " << n << *data_.end() <<  std::endl;
                data_.push_back(n);
            } else {
                // std::cerr << "push findif" << std::endl;
                auto p{std::find_if(std::begin(data_), std::end(data_), [&](const auto& v){return v>n;})};
                // std::cerr << "Val: " << *p << std::endl;
                data_.insert(p, n);
            }
            // show();
        }

        int pop() {
            data_.pop_front();            
        }

        int min() {
            return data_.front();
        }
        bool empty() {
            return data_.empty();
        }
    };
}

TEST(SortedList, ShouldStartAsEmpty) {
    sorted::list l;
    ASSERT_TRUE(l.empty());
}

TEST(SortedList, ShouldStoreWhenPush) {
    sorted::list l;
    int val{6};
    l.push(val);
    ASSERT_EQ(l.min(), val);
}

TEST(SortedList, ShouldKeepOrder) {
    sorted::list l;
    l.push(3);
    l.push(9);
    EXPECT_EQ(l.min(), 3);    
    l.pop();
    EXPECT_EQ(l.min(), 9);    
}

TEST(SortedList, ShouldInsertInOrder) {
    sorted::list l;

    l.push(2);
    l.push(8);
    l.push(7);
    l.push(1);

    EXPECT_EQ(l.min(), 1);
    l.pop();
    EXPECT_EQ(l.min(), 2);
    l.pop();
    EXPECT_EQ(l.min(), 7);
    l.pop();
    EXPECT_EQ(l.min(), 8);
    l.pop();
    EXPECT_TRUE(l.empty());
}

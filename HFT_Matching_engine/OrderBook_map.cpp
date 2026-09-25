#include<iostream>
#include<list>
#include<map>
#include<cstdint>


enum class Side
{
    uint8_t BUY,
    uint8_t SELL
};oghmd.a01



struct Order 
{
    uint64_t order_id;
    uint32_t price;
    uint32_t quantity;
    Side side;
};

struct PriceLevel 
{
    uint32_t price;
    uint32_t total_volume{0}; //no. of shares on this price
    std::list<Order>orders; // no. of orders  
};

class OrderBook
{
    private: 
        std::map<uint32_t, PriceLevel, std::greater<uint32_t>> bid_levels;
        std::map<uint32_t, PriceLevel, std::less<uint32_t>> ask_levels;
        std::unordered_map<ui
};

int main(void)
{
    std::cout << "--- HFT Engine: O(1) Data Structure Setup ---\n";

    return 0;
}
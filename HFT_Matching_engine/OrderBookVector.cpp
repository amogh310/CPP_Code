#include<iostream>
#include<vector>
#include<cstdint> //uint32_t and uint64_t


enum class Side : uint8_t
{
    BUY,
    SELL
};

//order structure
struct Order
{
    uint64_t order_id;
    uint32_t price;
    uint32_t quantity;
    Side side;
};

class OrderBook
{
    private:
        std::vector<Order>bids; // buying orders
        std::vector<Order>asks; // selling orders

    public:
        //segregates the order on bid or ask
        void add_order(const Order& order)
        {
            if(order.side == Side::BUY)
            {
                bids.push_back(order);
            }
            else
            {
                asks.push_back(order);
            }
        }

        //displays the current orders status
        void display()const
        {
            std::cout << "\n--- CURRENT ORDER BOOK ---\n";
            std::cout << "[ ASKS (Sellers) ]\n";
            for (const auto& ask : asks) {
                std::cout << "   Price: " << ask.price << " | Qty: " << ask.quantity << " (ID: " << ask.order_id << ")\n";
            }
            
            std::cout << "--------------------------\n";
            
            std::cout << "[ BIDS (Buyers) ]\n";
            for (const auto& bid : bids) {
                std::cout << "   Price: " << bid.price << " | Qty: " << bid.quantity << " (ID: " << bid.order_id << ")\n";
            }
            std::cout << "--------------------------\n\n";
        }
};

int main(void)
{
    std::cout<<("Welcome to HFT Engine !!!");

    OrderBook book;
    book.add_order({1,15000,10, Side::BUY});
    book.add_order({2,15100,10, Side::SELL});
    book.add_order({1,14590,10, Side::BUY});

    book.display();

    return 0;
}
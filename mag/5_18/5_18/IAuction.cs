
namespace _5_18
{
    public interface IAuction
    {
        void placeProduct(string product, int initialPrice);
        void addBid(string user, string product, int price);
        void removeBid(string user, string product);
        string sellProduct(string product);
    }
}
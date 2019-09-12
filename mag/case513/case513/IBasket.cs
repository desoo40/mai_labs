using System.Collections.Generic;

namespace case513
{
    public interface IBasket
    {
        void AddProduct(string product, int quantity);
        void RemoveProduct(string product);
        void UpdateProductQuantity(string product, int quantity);
        List<string> GetProducts();
    }
}
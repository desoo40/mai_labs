using System;
using System.Collections.Generic;
using System.Linq;

namespace case513
{
    public class Basket : IBasket
    {
        private Dictionary<string, int> dictProductsCnt = new Dictionary<string, int>();

        public void AddProduct(string product, int quantity)
        {
            if (string.IsNullOrEmpty(product.Trim(' ')))
                throw new ArgumentException("Название продукта не должно быть пустым");

            if (quantity <= 0)
                throw new ArgumentException("Количество должно быть больше нуля");

            if (dictProductsCnt.ContainsKey(product))
                dictProductsCnt[product] += quantity;
            else
                dictProductsCnt.Add(product, quantity);
        }

        public void RemoveProduct(string product)
        {
            if (!dictProductsCnt.Remove(product))
                throw new ArgumentException("Нет такого продукта в списке");
        }

        public void UpdateProductQuantity(string product, int quantity)
        {
            if (string.IsNullOrEmpty(product))
                throw new ArgumentException("Название продукта не должно быть пустым");

            if (quantity <= 0)
                throw new ArgumentException("Количество должно быть больше нуля");

            if (!dictProductsCnt.ContainsKey(product))
                throw new ArgumentException($"Продукта {product} нет в списке");

            dictProductsCnt.Add(product, quantity);
        }

        public List<string> GetProducts()
        {
            if (dictProductsCnt.Count == 0)
                throw new ArgumentNullException("Список пуст");

            return dictProductsCnt.Keys.ToList();
        }
    }
}
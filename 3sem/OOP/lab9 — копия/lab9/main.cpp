#include <cstdlib>
#include "BTree.h"
#include "figure.h"
#include "Triangle.h"
#include "quadro.h"
#include "rectangle.h"
using namespace std;
#include "figure.h"
#include "TStack.h"
#include <future>
#include <functional>
#include <random>
#include <thread>

typedef std::function<void(void)> command;

void detour(BTree<function<void()>> b_tree) {
    if (b_tree.getElem() == nullptr)
        return;

    std::shared_ptr<command> cmd = b_tree.getElem();
    std::future<void> ft = std::async(*cmd);
    ft.get();

    if (b_tree.getLeft())
        detour(*b_tree.getLeft());

    if (b_tree.getRight())
        detour(*b_tree.getRight());
}

int main(int argc, char** argv) {
    TStack<Figure> stack_figure;
    BTree<command> tree_cmd;
    command cmd_insert = [&]() {
        std::cout << "Command: Create triangles" << std::endl;
        std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(1, 1000);
        for (int i = 0; i < 10; i++) {
            int side = distribution(generator);
            stack_figure.push(new Triangle(side, side, side));
            stack_figure.push(new Quadro(side));
            stack_figure.push(new Rectangle(side, side));
            stack_figure.push(new Triangle(5, 5, 5));
            stack_figure.push(new Quadro(9));
            stack_figure.push(new Rectangle(4, 5));

        }
    };
    command cmd_print = [&]() {
        std::cout << "Command: Print stack" << std::endl;
        std::cout << stack_figure;
    };
    command cmd_reverse = [&]() {
        std::cout << "Command: Reverse stack" << std::endl;

        TStack<Figure> stack_tmp;
        while (!stack_figure.empty())
            stack_tmp.push(stack_figure.pop_last());
        while (!stack_tmp.empty()) stack_figure.push(stack_tmp.pop());
    };

    command cmd_del_by_sqr = [&]() {
        std::cout << "Command: Delete by square" << std::endl;

        TStack<Figure> stack_tmp;
        for (auto i : stack_figure) {
            if (i->Square() < 100)
                stack_figure.pop();
            else
                stack_tmp.push(stack_figure.pop());
        }

        auto cmd = cmd_reverse;
        std::future<void> ft = std::async(cmd);
        ft.get();

        stack_figure = stack_tmp;

    };

    tree_cmd.add(std::shared_ptr<command>(&cmd_insert, [](command*) {
    }));
    tree_cmd.add(std::shared_ptr<command>(&cmd_print, [](command*) {
    })); // using custom deleter
    tree_cmd.add(std::shared_ptr<command>(&cmd_del_by_sqr, [](command*) {
    })); // using custom deleter
    tree_cmd.add(std::shared_ptr<command>(&cmd_print, [](command*) {
    })); // using custom deleter

    detour(tree_cmd);
    std::cout << stack_figure << endl;

    return 0;
}

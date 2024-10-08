#ifndef __ORDER_H
#define __ORDER_H

#pragma once

#include "menuItemInOrder.h"

class Order
{
private:
	MenuItemInOrder **orderedItems;
	int numItems;

public:
	Order();
	Order(const Order& other);
	Order(Order &&other) noexcept;
	~Order();

	// const Order& operator=(const Order& other);
	Order &operator=(Order &&other) noexcept;
	MenuItemInOrder **getOrderedItems() const;
	bool addItemToOrder(const MenuItem &menuItem, int quantity, char *comments);
	int closeBill() const;
	void print() const;

private:
	void clear();
};
#endif // __ORDER_H
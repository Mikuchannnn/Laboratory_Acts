import numpy as np
import matplotlib.pyplot as plt

sales_price = 100
unit_sales = np.random.normal(500, 50, 100000)
unit_cost = np.random.normal(60, 10, 100000)
profit = (sales_price - unit_cost) * unit_sales

print(f"Estimated Average Profit: ${np.mean(profit):,.2f}")
print(f"Profit Standard Deviation: ${np.std(profit):,.2f}")

# Optional: Plot histogram
plt.hist(profit, bins=50, color='skyblue', edgecolor='black')
plt.title('Profit Distribution')
plt.xlabel('Profit')
plt.ylabel('Frequency')
plt.grid()
plt.show()
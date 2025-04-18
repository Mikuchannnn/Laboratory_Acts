import numpy as np
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error, mean_squared_error
import matplotlib.pyplot as plt

# Generate synthetic dataset
X = np.random.rand(100, 1) * 150 # Size in sqm
y = 30000 + 1500 * X + np.random.randn(100, 1) * 5000 # Price with noise

# Train model
model = LinearRegression()
model.fit(X, y)
predictions = model.predict(X)

# Evaluate model
mae = mean_absolute_error(y, predictions)
mse = mean_squared_error(y, predictions)
print(f"MAE: ${mae:.2f}")
print(f"MSE: ${mse:.2f}")

# Optional: Plot actual vs predicted
plt.scatter(X, y, color='blue', label='Actual')
plt.plot(X, predictions, color='red', label='Predicted')
plt.title('House Price Prediction')
plt.xlabel('Size (sqm)')
plt.ylabel('Price')
plt.legend()
plt.grid()
plt.show()
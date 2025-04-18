import matplotlib.pyplot as plt
import numpy as np

# Simulate 60 seconds
time = np.arange(0, 300, 1)  # Time in seconds

# Traffic inflow simulation (more vehicles over time with fluctuation)
traffic_flow = np.sin(0.1 * time) + 1  # Range stays positive

# Traffic signal logic: green for 20 sec, then red for 20, then green...
signal = [(1 if (t // 20) % 2 == 0 else 0) for t in time]

# Output flow: traffic that passes when signal is green
output_flow = [flow * sig for flow, sig in zip(traffic_flow, signal)]

# Plotting
plt.figure(figsize=(10, 6))
plt.plot(time, traffic_flow, label='Incoming Traffic')
plt.plot(time, signal, label='Traffic Signal (Green=1, Red=0)')
plt.plot(time, output_flow, label='Outgoing Traffic (Passed Vehicles)', linestyle='--')
plt.xlabel('Time (seconds)')
plt.ylabel('Traffic Flow Level')
plt.title('Traffic Flow Simulation at an Intersection')
plt.legend()
plt.grid(True)
plt.tight_layout()
plt.show()
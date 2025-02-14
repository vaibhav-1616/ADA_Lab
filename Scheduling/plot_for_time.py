import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

# Load CSV data
df = pd.read_csv("sort_times.csv")

# Extract data
x = df["num_activities"]
y1 = df["time_sort_by_start"]
y2 = df["time_sort_by_finish"]

# Theoretical O(n^2) time complexity
n_squared_times = [n * n for n in x]

# Theoretical O(n log n) time complexity
n_log_n_times = [n * np.log2(n) for n in x]

# Plot
plt.figure(figsize=(10, 6))

# Plot smoothed execution times
plt.plot(x, y1, marker="o", linestyle="-", label="Sort by Start Time", color="blue", linewidth=2)
plt.plot(x, y2, marker="o", linestyle="-", label="Sort by Finish Time", color="red", linewidth=2)


# Plot theoretical curves
plt.plot(x, n_log_n_times, linestyle="solid", label="O(n log n)", color="green", linewidth=2)
plt.plot(x, n_squared_times, linestyle="solid", label="O(n^2)", color="purple", linewidth=2)

# Labels and title
plt.xlabel("Number of Activities")
plt.ylabel("Execution Time (ms)")
plt.title("Time Complexity Comparison of Activity Selection")
plt.legend()
plt.grid(True)

# plt.xscale("log")  # Log scale for better visibility
plt.yscale("log")  # Log scale to match theoretical complexities

# Show plot
plt.show()

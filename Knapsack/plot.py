import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Read data from CSV file
df = pd.read_csv('knapsack_quickSort_runtime.csv')

# Extract input sizes and QuickSort runtimes from the CSV file
input_sizes = df['size'].tolist()
quickSort_times = df['time'].tolist()

# Theoretical O(n^2) time complexity
n_squared_times = [n * n for n in input_sizes]

# Theoretical O(n log n) time complexity
n_log_n_times = [n * np.log2(n) for n in input_sizes]

# Plotting the results
plt.figure(figsize=(10, 6))

# Plot the actual QuickSort runtime
plt.plot(input_sizes, quickSort_times, label="QuickSort Runtime", color="blue", linestyle="solid")

# Plot the O(n^2) time complexity
plt.plot(input_sizes, n_squared_times, label="O(n^2) Time Complexity", color="red", linestyle="solid")

# Plot the O(n log n) time complexity
plt.plot(input_sizes, n_log_n_times, label="O(n log n) Time Complexity", color="green", linestyle="solid")

# Labels and Title
plt.xlabel("Input Size (n)", fontsize=12)
plt.ylabel("Time (nanoseconds)", fontsize=12)
plt.title("QuickSort Runtime vs O(n^2) and O(n log n) Time Complexities", fontsize=14)
plt.yscale("log")  # Use log scale for better visualization of large differences
# plt.xscale("log")  # Log scale for x-axis to compare performance across large input sizes

# Add a grid and legend
plt.grid(True, which='both', linestyle="--", linewidth=0.5)
plt.legend()

# Show the plot
plt.tight_layout()
plt.show()

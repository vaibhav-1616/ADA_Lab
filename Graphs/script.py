import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

# Read CSV file containing QuickSort runtimes
df = pd.read_csv("quicksort_runtime.csv")

# Extract input sizes and runtimes
input_sizes = df["n"]
quicksort_times = df["runtime_microseconds"]

# Compute theoretical complexities
n_log_n_times = [n * np.log2(n) for n in input_sizes]
n_squared_times = [n ** 2 for n in input_sizes]


# Plot QuickSort runtime
plt.plot(input_sizes, quicksort_times, marker='o', linestyle="solid", color="blue", label="QuickSort Runtime")

# Plot theoretical complexities
plt.plot(input_sizes, n_log_n_times, linestyle='solid', color='green', label="O(n log n)")
plt.plot(input_sizes, n_squared_times, linestyle='solid', color='red', label="O(n²)")

# Labels and title
plt.xlabel("Input Size (n)")
plt.ylabel("Time (microseconds)")
plt.title("QuickSort Runtime vs. Complexity Analysis")
plt.yscale("log")  # Log scale for better visualization

plt.legend()
plt.grid(True)
plt.show()

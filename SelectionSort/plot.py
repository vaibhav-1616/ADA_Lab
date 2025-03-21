import pandas as pd
import matplotlib.pyplot as plt

# Read CSV file
df = pd.read_csv("selection_sort_times.csv")

# Plot graph
plt.figure(figsize=(10, 5))
plt.plot(df["Size"], df["Time"], marker='o', linestyle='-', color='b', label="Selection Sort Time")

plt.xlabel("Array Size (n)")
plt.ylabel("Time (seconds)")
plt.title("Selection Sort Time Complexity")
plt.legend()
plt.grid()
plt.show()
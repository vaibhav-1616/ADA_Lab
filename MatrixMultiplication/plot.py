import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

# Read data from CSV file
df = pd.read_csv("strassen_data.csv")

# Extract sizes and actual times (in microseconds)
sizes = df["size"].tolist()
strassen_times = df["time"].tolist()

# Theoretical time complexities
n_cubed = [n**3 for n in sizes]
n_281 = [n**2.81 for n in sizes]


# Plotting
plt.figure(figsize=(10, 6))

plt.plot(sizes, strassen_times, label="Strassen Runtime", color="red", linestyle="solid")
plt.plot(sizes, n_cubed, label="O(n³)", color="blue", linestyle="solid")
plt.plot(sizes, n_281, label="O(n^2.81)", color="green", linestyle="solid")

plt.xlabel("Matrix Size (n)", fontsize=12)
plt.ylabel("Time (microseconds)", fontsize=12)
plt.title("Strassen's Runtime ", fontsize=14)

plt.yscale("log")
# plt.xscale("log")  # Uncomment for log-log plot if desired

plt.grid(True, which='both', linestyle="", linewidth=0.5)
plt.legend()
plt.tight_layout()
plt.show()

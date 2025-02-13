import matplotlib.pyplot as plt
import pandas as pd

# Load the CSV file
data = pd.read_csv("quicksort_stack_analysis.csv")

# Extract data columns
sizes = data["Size"]
recursive_stack = data["Recursive_Stack"]
iterative_stack = data["Iterative_Stack"]

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(sizes, recursive_stack, label="Recursive QuickSort", marker="o", linestyle="-")
plt.plot(sizes, iterative_stack, label="Iterative QuickSort", marker="s", linestyle="--")

# Labels and title
plt.xlabel("Input Size (N)")
plt.ylabel("Max Stack Depth")
plt.title("Stack Depth Comparison: Recursive vs Iterative QuickSort")
plt.yscale("log")  # Use log scale for better visualization of large differences

plt.legend()
plt.grid(True)

# Show the plot
plt.show()
